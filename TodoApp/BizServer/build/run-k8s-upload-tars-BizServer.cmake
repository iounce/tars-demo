EXECUTE_PROCESS(COMMAND /usr/bin/cmake -E echo http://tars-tarsweb:3000/k8s/api/upload_tars_file -Fsuse=@BizServer-merge.tars -Fapplication=TodoApp -Fserver_name=BizServer)
EXECUTE_PROCESS(COMMAND curl http://tars-tarsweb:3000/k8s/api/upload_tars_file?ticket= -Fsuse=@BizServer-merge.tars -Fapplication=TodoApp -Fserver_name=BizServer)
EXECUTE_PROCESS(COMMAND /usr/bin/cmake -E echo 
---------------------------------------------------------------------------)
