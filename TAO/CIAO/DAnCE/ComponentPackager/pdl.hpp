/* $Id$
 * This code was generated by the XML Schema Compiler.
 *
 * Changes made to this code will most likely be overwritten
 * when the handlers are recompiled.
 * 
 * If you find errors or feel that there are bugfixes to be made,
 * please contact the current XSC maintainer:
 *             Will Otte <wotte@dre.vanderbilt.edu>
 */


// Fixes the VC6 warning 4786.
#include "vc6-4786.h"
 
// Fix for Borland compilers, which seem to have a broken
// <string> include.
#ifdef __BORLANDC__
# include <string.h>
#endif


#include "ace/config-all.h"

#ifndef PDL_HPP
#define PDL_HPP

// Forward declarations.
//
namespace Package
{
  class PackageDescriptorsList;
}

#include <memory>
#include <vector>
#include <XMLSchema/Types.hpp>

namespace Package
{
  class PackageDescriptorsList : public ::XSCRT::Type
  {
    //@@ VC6 anathema
    typedef ::XSCRT::Type Base__;

    // desc
    // 
    public:
    typedef ::std::vector< ::XMLSchema::string< ACE_TCHAR > >::iterator desc_iterator;
    typedef ::std::vector< ::XMLSchema::string< ACE_TCHAR > >::const_iterator desc_const_iterator;
    desc_iterator begin_desc ();
    desc_iterator end_desc ();
    desc_const_iterator begin_desc () const;
    desc_const_iterator end_desc () const;
    void add_desc (::XMLSchema::string< ACE_TCHAR > const& );

    protected:
    ::std::vector< ::XMLSchema::string< ACE_TCHAR > > desc_;

    public:
    PackageDescriptorsList ();

    PackageDescriptorsList (::XSCRT::XML::Element< ACE_TCHAR > const&);
    PackageDescriptorsList (PackageDescriptorsList const& s);

    PackageDescriptorsList&
    operator= (PackageDescriptorsList const& s);

    private:
    char regulator__;
  };
}

namespace Package
{
  ::Package::PackageDescriptorsList
  packageDescriptorsList (xercesc::DOMDocument const*);
}

#endif // PDL_HPP
