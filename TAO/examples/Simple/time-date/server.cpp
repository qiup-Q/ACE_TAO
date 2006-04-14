// $Id$

// ============================================================================
//
// = LIBRARY
//    examples/Simple/time-date
//
// = FILENAME
//    server.cpp
//
// = DESCRIPTION
//   This directory contains an example that illustrates how the ACE
//   Service Configurator can dynamically configure an ORB and its
//   servants from a svc.conf file.
//
// = AUTHOR
//    Doug Schmidt <schmidt@cs.wustl.edu>
//
// ============================================================================

#include "ace/Service_Config.h"
#include "ace/Reactor.h"
#include "ace/Log_Msg.h"
#include "ace/Argv_Type_Converter.h"

ACE_RCSID (time_date,
           server,
           "$Id$")

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_Argv_Type_Converter convert (argc, argv);

  if (ACE_Service_Config::open (convert.get_argc(), convert.get_TCHAR_argv()) == -1
      && errno != ENOENT)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("open")),
                      1);

  // Run forever, performing the configured services until we
  // shutdown.
  ACE_Reactor::run_event_loop ();
  return 0;
}
