#ifndef _GoodsTarsImp_H_
#define _GoodsTarsImp_H_

#include "servant/Application.h"
#include "GoodsTars.h"

/**
 *
 *
 */
class GoodsTarsImp : public GoodsApp::api
{
public:
    /**
     *
     */
    virtual ~GoodsTarsImp() {}

    /**
     *
     */
    virtual void initialize();

    /**
     *
     */
    virtual void destroy();

    /**
     *
     */
    virtual tars::Int32 doCommon(const GoodsApp::CommonReq &req, GoodsApp::CommonRsp &rsp, tars::TarsCurrentPtr current);
};
/////////////////////////////////////////////////////
#endif
