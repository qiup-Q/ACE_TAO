//=============================================================================
/**
 *  @file   amh_ss.h
 *
 *  $Id$
 *
 *  Specialized interface visitor for AMH.
 *
 *  @author Darrell Brunsch <brunsch@cs.wustl.edu>
 */
//=============================================================================

#ifndef AMH_INTERFACE_SS_H
#define AMH_INTERFACE_SS_H


class be_visitor_amh_interface_ss : public be_visitor_interface_ss
{
public:
  be_visitor_amh_interface_ss (be_visitor_context *ctx);

  ~be_visitor_amh_interface_ss (void);

protected:
  virtual void this_method (be_interface *node);
  virtual void dispatch_method (be_interface *node);
};

#endif /* AMH_INTERFACE_SS_H */
