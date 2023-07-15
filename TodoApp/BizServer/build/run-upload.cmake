EXECUTE_PROCESS(COMMAND /usr/bin/cmake -E echo upload all)
EXECUTE_PROCESS(COMMAND /usr/bin/cmake -P /root/BizServer/build/src/run-upload-BizServer.cmake)
