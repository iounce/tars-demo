#ifndef _TodoTarsObjImp_H_
#define _TodoTarsObjImp_H_

#include "servant/Application.h"
#include "TodoTarsObj.h"

using namespace TodoApp;

/**
 *
 *
 */
class TodoTarsObjImp : public TodoApp::api
{
public:
    /**
     *
     */
    virtual ~TodoTarsObjImp() {}

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
    virtual tars::Int32 addTodo(const TodoApp::TodoReq & req, TodoApp::TodoRsp & rsp, tars::TarsCurrentPtr current);
    virtual tars::Int32 getTodo(const TodoApp::TodoReq & req, TodoApp::TodoRsp & rsp, tars::TarsCurrentPtr current);
};
/////////////////////////////////////////////////////
#endif
