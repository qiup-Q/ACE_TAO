// $Id$
#include "Plan_Launcher_Impl.h"

#include "ace/OS.h"
#include "ace/Get_Opt.h"
#include <iostream>

#include "ExecutionManager/ExecutionManagerC.h"

namespace CIAO
{
  namespace Plan_Launcher
  {
    // deployment plan URL
    const char* package_url = 0;
    bool use_naming = false;
    const char* ior_file = "file://em.ior";
    const char* dap_ior_filename = 0;
    const char* dap_ior = 0;
    enum mode_type { 
      pl_mode_start,
      pl_mode_stop,
      pl_mode_interactive
    };

    mode_type mode = pl_mode_interactive;

    static void
    usage (const ACE_TCHAR* program)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("[(%P|%t) Executor] Usage: %s\n")
                  ACE_TEXT ("-p <PACKAGE_URI>\n")
                  ACE_TEXT ("-k <EXECUTION_MANAGER_IOR>")
                  ACE_TEXT (" : Default file://em.ior\n")
                  ACE_TEXT ("-n : Use naming service to fetch")
                  ACE_TEXT (" Execution Manager IOR Alternative to -k\n")
                  ACE_TEXT ("-o <DOMAIN_APPLICATION_MANAGER_IOR_OUTPUT_FILE>\n")
                  ACE_TEXT ("-i <DOMAIN_APPLICATION_MANAGER_IOR_FOR_INPUT>\n")
                  ACE_TEXT ("-h : Show this usage information\n"),
                  program));
    }

    static bool
    parse_args (int argc,
                ACE_TCHAR *argv[])
    {
      ACE_Get_Arg_Opt<char> get_opt (argc,
                           argv,
                           ACE_TEXT ("p:nk:o:i:h"));
      int c;

      while ((c = get_opt ()) != EOF)
        {
          switch (c)
            {
            case 'p':
              package_url = get_opt.opt_arg ();
              break;
            case 'n':
              use_naming = true;
              break;
            case 'k':
              ior_file = get_opt.opt_arg ();
              break;
            case 'o':
              dap_ior_filename = get_opt.opt_arg ();
              mode = pl_mode_start;
              break;
            case 'i':
              dap_ior = get_opt.opt_arg ();
              mode = pl_mode_stop;
              break;
            case 'h':
            default:
              usage(argv[0]);
              return false;
            }
        }

      if ((mode != pl_mode_stop) && (package_url == 0))
        {
          usage (argv[0]);
          return false;
        }
      
      return true;
    }

    static ::Deployment::DomainApplicationManager_ptr
    read_dap_ior (CORBA::ORB_ptr orb
                  ACE_ENV_ARG_DECL)
    {
      CORBA::Object_var obj = orb->string_to_object (dap_ior
                                                     ACE_ENV_ARG_PARAMETER);
      return
        Deployment::DomainApplicationManager::_narrow (obj.in ()
                                                       ACE_ENV_ARG_PARAMETER);
    }

    static int
    write_dap_ior (CORBA::ORB_ptr orb,
                   ::Deployment::DomainApplicationManager_ptr dap
                   ACE_ENV_ARG_DECL)
    {
      CORBA::String_var ior = orb->object_to_string (dap);

      FILE* ior_output_file = ACE_OS::fopen (dap_ior_filename, "w");

      if (ior_output_file)
        {
          ACE_OS::fprintf (ior_output_file, "%s", ior.in ());
          ACE_OS::fclose (ior_output_file);

          return 0;
        }

      return -1;
    }

    static int
    run_main_implementation (int argc, char *argv[])
    {
      ACE_DECLARE_NEW_CORBA_ENV;

      ACE_TRY
        {
          CORBA::ORB_var orb =
            CORBA::ORB_init (argc,
                             argv,
                             ""
                             ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          if (parse_args (argc, argv) == false)
            return -1;
          
          
          Plan_Launcher_i launcher;
          
          if (!launcher.init (use_naming ? 0 : ior_file,
                              orb.in ()))
            {
              ACE_ERROR ((LM_ERROR, "(%P|%t) Plan_Launcher: Error initializing the EM.\n"));
              return -1;
            }
          
          ::Deployment::DomainApplicationManager_var dapp_mgr;
          
          if (mode != pl_mode_stop)
            {
              const char* uuid = launcher.launch_plan (package_url);
              
              if (uuid == 0)
                {
                  ACE_ERROR ((LM_ERROR, "(%P|%t) Plan_Launcher: Error launching plan\n"));
                  return -1;
                }
              
              ACE_DEBUG ((LM_DEBUG, "Plan_Launcher returned UUID is %s\n", uuid));
              dapp_mgr = launcher.get_dam (uuid);
              
              // Write out DAM ior if requested
              if (mode == pl_mode_start)
                write_dap_ior (orb.in (), dapp_mgr.in ());
              else // if (pl_mode_interactive)
                {
                  ACE_DEBUG ((LM_DEBUG,
                              "Press <Enter> to tear down application\n"));
                  char dummy [256];
                  std::cin.getline (dummy, 256);
                }
            }
          else
            {
              dapp_mgr = read_dap_ior (orb.in ()
                                       ACE_ENV_ARG_PARAMETER);
              ACE_TRY_CHECK;
            }
          
          if (CORBA::is_nil (dapp_mgr.in ()))
            {
              ACE_DEBUG ((LM_DEBUG,
                          "(%P|%t) CIAO_PlanLauncher:preparePlan call failed: "
                          "nil DomainApplicationManager reference\n"));
              return -1;
            }
          
          if (CIAO::debug_level () > 9)
            ACE_DEBUG ((LM_DEBUG,
                        "CIAO_PlanLauncher: Obtained DAM ref \n"));

          if (mode != pl_mode_start)
          {
            // Tear down the assembly
            ACE_DEBUG ((LM_DEBUG,
                        "Plan_Launcher: destroy the application....."));
            launcher.teardown_plan (dapp_mgr.in ());
          }

          orb->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
      ACE_CATCH (Plan_Launcher_i::Deployment_Failure, ex)
        {
          ACE_ERROR ((LM_ERROR,
                      "Deployment failed.  Plan_Launcher exiting.\n"));
        }
      ACE_CATCHANY
        {
          ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                               "(%P|%t) Plan_Launcher: ");

          return -1;
        }
      ACE_CATCHALL
        {
          ACE_ERROR ((LM_ERROR,
                      "(%P|%t) Plan_Launcher: Unknown exception.\n"));
          return -1;
        }
      ACE_ENDTRY;
      ACE_CHECK_RETURN (-1);

      return 0;
    }
  }
}

using namespace CIAO::Plan_Launcher;

int
ACE_TMAIN (int argc,
           ACE_TCHAR *argv[])
{
  ACE_DEBUG ((LM_DEBUG, "NEW PLAN LAUNCHER\n"));
  
  return run_main_implementation (argc, argv);
}
