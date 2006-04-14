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

#include "ObjectIdListA.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Sequence_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ORB_ObjectId (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/ORB_ObjectId:1.0",
    "ORB_ObjectId",
    &CORBA::_tc_string);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ORB_ObjectId =
    &_tao_tc_CORBA_ORB_ObjectId;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_CORBA_ORB_ObjectIdList_GUARD
#define _TAO_TYPECODE_CORBA_ORB_ObjectIdList_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      CORBA_ORB_ObjectIdList_0 (
        CORBA::tk_sequence,
        &CORBA::_tc_ORB_ObjectId,
        0U);

    ::CORBA::TypeCode_ptr const tc_CORBA_ORB_ObjectIdList_0 =
      &CORBA_ORB_ObjectIdList_0;

  }
}


#endif /* _TAO_TYPECODE_CORBA_ORB_ObjectIdList_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ORB_ObjectIdList (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/ORB_ObjectIdList:1.0",
    "ORB_ObjectIdList",
    &TAO::TypeCode::tc_CORBA_ORB_ObjectIdList_0);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ORB_ObjectIdList =
    &_tao_tc_CORBA_ORB_ObjectIdList;
}

