// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:291


#include "TypeCodeFactoryC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::TypeCodeFactory.

CORBA::TypeCodeFactory_ptr
TAO::Objref_Traits<CORBA::TypeCodeFactory>::duplicate (
    CORBA::TypeCodeFactory_ptr p
  )
{
  return CORBA::TypeCodeFactory::_duplicate (p);
}

void
TAO::Objref_Traits<CORBA::TypeCodeFactory>::release (
    CORBA::TypeCodeFactory_ptr p
  )
{
  CORBA::release (p);
}

CORBA::TypeCodeFactory_ptr
TAO::Objref_Traits<CORBA::TypeCodeFactory>::nil (void)
{
  return CORBA::TypeCodeFactory::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<CORBA::TypeCodeFactory>::marshal (
    CORBA::TypeCodeFactory_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

CORBA::TypeCodeFactory::TypeCodeFactory (void)
{}

CORBA::TypeCodeFactory::~TypeCodeFactory (void)
{}

void 
CORBA::TypeCodeFactory::_tao_any_destructor (void *_tao_void_pointer)
{
  TypeCodeFactory *_tao_tmp_pointer =
    static_cast<TypeCodeFactory *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return TypeCodeFactory::_nil ();
    }
  
  TypeCodeFactory_ptr proxy =
    dynamic_cast<TypeCodeFactory_ptr> (_tao_objref);
  
  return TypeCodeFactory::_duplicate (proxy);
}

CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return TypeCodeFactory::_nil ();
    }
  
  TypeCodeFactory_ptr proxy =
    dynamic_cast<TypeCodeFactory_ptr> (_tao_objref);
  
  return TypeCodeFactory::_duplicate (proxy);
}

CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory::_duplicate (TypeCodeFactory_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
CORBA::TypeCodeFactory::_tao_release (TypeCodeFactory_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
CORBA::TypeCodeFactory::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/TypeCodeFactory:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* CORBA::TypeCodeFactory::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/TypeCodeFactory:1.0";
}

CORBA::Boolean
CORBA::TypeCodeFactory::marshal (TAO_OutputCDR &)
{
  return false;
}
