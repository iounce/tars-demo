EXECUTE_PROCESS(COMMAND /usr/bin/cmake  -E echo upload tars all)
EXECUTE_PROCESS(COMMAND cmake -P /root/BizServer/build/src/run-upload-tars-BizServer.cmake)
