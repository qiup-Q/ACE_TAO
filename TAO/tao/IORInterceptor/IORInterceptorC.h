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
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_IORINTERCEPTORC_H_
#define _TAO_IDL_ORIG_IORINTERCEPTORC_H_

#include /**/ "ace/pre.h"


#ifndef TAO_IORINTERCEPTOR_SAFE_INCLUDE
#error "You should not include IORInterceptorC.h directly, use IORInterceptor.h"
#endif /* !TAO_IORINTERCEPTOR_SAFE_INCLUDE */
#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "iorinterceptor_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/PI/InterceptorC.h"
#include "tao/IORInterceptor/IORInfoC.h"
#include "tao/ObjRefTemplate/ObjectReferenceTemplateC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_IORInterceptor_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR__VAR_OUT_CH_
  
  class IORInterceptor;
  typedef IORInterceptor *IORInterceptor_ptr;
  
  typedef
    TAO_Objref_Var_T<
        IORInterceptor
      >
    IORInterceptor_var;
  
  typedef
    TAO_Objref_Out_T<
        IORInterceptor
      >
    IORInterceptor_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR_CH_
  
  class TAO_IORInterceptor_Export IORInterceptor
    : public virtual ::PortableInterceptor::Interceptor
  {
  public:
    typedef IORInterceptor_ptr _ptr_type;
    typedef IORInterceptor_var _var_type;
    
    // The static operations.
    static IORInterceptor_ptr _duplicate (IORInterceptor_ptr obj);
    
    static void _tao_release (IORInterceptor_ptr obj);
    
    static IORInterceptor_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static IORInterceptor_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static IORInterceptor_ptr _nil (void)
    {
      return static_cast<IORInterceptor_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void establish_components (
        ::PortableInterceptor::IORInfo_ptr info
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void components_established (
        ::PortableInterceptor::IORInfo_ptr info
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void adapter_manager_state_changed (
        ::PortableInterceptor::AdapterManagerId id,
        ::PortableInterceptor::AdapterState state
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void adapter_state_changed (
        const ::PortableInterceptor::ObjectReferenceTemplateSeq & templates,
        ::PortableInterceptor::AdapterState state
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    IORInterceptor (void);
    
    virtual ~IORInterceptor (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    IORInterceptor (const IORInterceptor &);
    
    void operator= (const IORInterceptor &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableInterceptor

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR__TRAITS_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR__TRAITS_CH_
  
  template<>
  struct TAO_IORInterceptor_Export Objref_Traits< ::PortableInterceptor::IORInterceptor>
  {
    static ::PortableInterceptor::IORInterceptor_ptr duplicate (
        ::PortableInterceptor::IORInterceptor_ptr
      );
    static void release (
        ::PortableInterceptor::IORInterceptor_ptr
      );
    static ::PortableInterceptor::IORInterceptor_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableInterceptor::IORInterceptor_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


