#ifndef _GoodsServer_H_
#define _GoodsServer_H_

#include <iostream>
#include "servant/Application.h"

using namespace tars;

/**
 *
 **/
class GoodsServer : public Application
{
public:
    /**
     *
     **/
    virtual ~GoodsServer() {};

    /**
     *
     **/
    virtual void initialize();

    /**
     *
     **/
    virtual void destroyApp();
};

extern GoodsServer g_app;

////////////////////////////////////////////
#endif
