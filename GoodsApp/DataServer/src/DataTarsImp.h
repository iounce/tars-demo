#ifndef _DataTarsImp_H_
#define _DataTarsImp_H_

#include "servant/Application.h"
#include "DataTars.h"

/**
 *
 *
 */
class DataTarsImp : public GoodsApp::DataTars
{
public:
    /**
     *
     */
    virtual ~DataTarsImp() {}

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
    virtual tars::Int32 doData(const GoodsApp::DataReq & req, GoodsApp::DataRsp &rsp, tars::TarsCurrentPtr current);
};
/////////////////////////////////////////////////////
#endif
