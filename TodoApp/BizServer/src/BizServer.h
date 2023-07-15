#ifndef _BizServer_H_
#define _BizServer_H_

#include <iostream>
#include "servant/Application.h"

using namespace tars;

/**
 *
 **/
class BizServer : public Application
{
public:
    /**
     *
     **/
    virtual ~BizServer() {};

    /**
     *
     **/
    virtual void initialize();

    /**
     *
     **/
    virtual void destroyApp();
};

extern BizServer g_app;

////////////////////////////////////////////
#endif
