// $Id$

# include "Collocation_Tester.h"
#include "ace/Argv_Type_Converter.h"

ACE_RCSID (tests, client, "$Id$")

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_Argv_Type_Converter convert (argc, argv);

  ACE_DECLARE_NEW_CORBA_ENV;

  ACE_TRY
    {
      // ORB Initialization
      CORBA::ORB_var orb = CORBA::ORB_init (convert.get_argc(), convert.get_ASCII_argv(), "TAO" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Object_var object;

      // Get The IOR from a file
      object = orb->string_to_object ("file://s.ior" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (object.in ()))
        {
          ACE_DEBUG ((LM_DEBUG, "Invalid IOR file\n"));
          return 1;
        }

      Collocation_Tester tester (object.in ());
      tester.run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "CORBA Exception Raised");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}
