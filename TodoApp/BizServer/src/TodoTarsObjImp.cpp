#include "TodoTarsObjImp.h"
#include "servant/Application.h"

using namespace std;

//////////////////////////////////////////////////////
void TodoTarsObjImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void TodoTarsObjImp::destroy()
{
    //destroy servant here:
    //...
}

tars::Int32 TodoTarsObjImp::addTodo(const TodoApp::TodoReq & req, TodoApp::TodoRsp & rsp, tars::TarsCurrentPtr current)
{
    rsp.errCode = "0";
    rsp.errMsg = "OK";

    rsp.seqId = req.seqId;
    rsp.userId = req.userId;
    rsp.todoList = req.todoList;

    return 0;
}

tars::Int32 TodoTarsObjImp::getTodo(const TodoApp::TodoReq & req, TodoApp::TodoRsp & rsp, tars::TarsCurrentPtr current)
{
    return 0;
}