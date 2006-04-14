// $Id$

#include "Reactive_Task.h"

#if ! defined (__ACE_INLINE__)
#include "Reactive_Task.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Notify, TAO_Notify_Reactive_Task, "$Id$")

#include "Timer_Reactor.h"

TAO_Notify_Reactive_Task::TAO_Notify_Reactive_Task (void)
  :timer_ (0)
{
}

TAO_Notify_Reactive_Task::~TAO_Notify_Reactive_Task ()
{
}

void
TAO_Notify_Reactive_Task::init (ACE_ENV_SINGLE_ARG_DECL)
{
  ACE_ASSERT (this->timer_.get() == 0);

  TAO_Notify_Timer_Reactor* timer = 0;
  ACE_NEW_THROW_EX (timer,
                    TAO_Notify_Timer_Reactor (),
                    CORBA::NO_MEMORY ());
  this->timer_.reset (timer);
}

void
TAO_Notify_Reactive_Task::release (void)
{
  delete this; //TODO: Release via factory.
}

void
TAO_Notify_Reactive_Task::shutdown (void)
{
}

void
TAO_Notify_Reactive_Task::execute (TAO_Notify_Method_Request& method_request ACE_ENV_ARG_DECL)
{
  method_request.execute (ACE_ENV_SINGLE_ARG_PARAMETER);
}

TAO_Notify_Timer*
TAO_Notify_Reactive_Task::timer (void)
{
  return this->timer_.get();
}
