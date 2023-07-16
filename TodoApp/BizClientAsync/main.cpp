#include <iostream>
#include "servant/Communicator.h"
#include "TodoTarsObj.h"

using namespace std;
using namespace TodoApp;
using namespace tars;

class TodoCallback: public apiPrxCallback
{
public:
    TodoCallback() {}
    ~TodoCallback() {}

    virtual void callback_addTodo(tars::Int32 ret,  const TodoApp::TodoRsp& rsp)
    {
        cout << "callback_addTodo" << ret << "|" << rsp.writeToJsonString() << endl;
    }

    virtual void callback_addTodo_exception(tars::Int32 ret)
    {
        cout << "callback_addTodo_exception" << ret << endl;
    }

    virtual void callback_getTodo(tars::Int32 ret,  const TodoApp::TodoRsp& rsp)
    {
        cout << "callback_getTodo" << ret << "|" << rsp.writeToJsonString() << endl;
    }

    virtual void callback_getTodo_exception(tars::Int32 ret)
    {
        cout << "callback_addTodo_exception" << ret << endl;
    }
};
typedef tars::TC_AutoPtr<TodoCallback> TodoCallbackPtr;

int main(int argc,char ** argv)
{
    Communicator comm;

    try
    {
        apiPrx prx;
        comm.stringToProxy("TodoApp.BizServer.TodoTarsObjObj@tcp -h 172.25.0.5 -t 60000 -p 14295 -e 0", prx);

        try
        {
            TodoReq req;
            req.seqId = "1";
            req.userId = "15900010001";

            Todo todo;
            todo.title = "打篮球";
            todo.content = "明天晚上19:15去体育馆打篮球";
            req.todoList.push_back(todo);

            TodoCallbackPtr cb = new TodoCallback();

            prx->async_addTodo(cb, req);

            cout << "req: " << req.writeToJsonString() << endl;

        }
        catch(exception &ex)
        {
            cerr << "ex:" << ex.what() << endl;
        }
        catch(...)
        {
            cerr << "unknown exception." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "exception:" << e.what() << endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << endl;
    }

    getchar();

    return 0;
}