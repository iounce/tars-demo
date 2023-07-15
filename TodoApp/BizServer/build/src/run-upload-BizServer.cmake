EXECUTE_PROCESS(COMMAND /usr/bin/cmake -E echo http://web.tars.com/api/upload_and_publish -Fsuse=@BizServer.tgz -Fapplication=TodoApp -Fmodule_name=BizServer -Fcomment=developer-auto-upload)
EXECUTE_PROCESS(COMMAND curl http://web.tars.com/api/upload_and_publish?ticket= -Fsuse=@BizServer.tgz -Fapplication=TodoApp -Fmodule_name=BizServer -Fcomment=developer-auto-upload)
EXECUTE_PROCESS(COMMAND /usr/bin/cmake -E echo 
---------------------------------------------------------------------------)
