EXECUTE_PROCESS(COMMAND /usr/bin/cmake  -E echo upload k8s tars all)
EXECUTE_PROCESS(COMMAND cmake -P /root/BizServer/build/run-k8s-upload-tars-BizServer.cmake)
