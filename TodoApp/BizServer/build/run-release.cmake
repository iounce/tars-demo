EXECUTE_PROCESS(COMMAND /usr/bin/cmake -E echo release all)
EXECUTE_PROCESS(COMMAND /usr/bin/cmake -P /root/BizServer/build/src/run-release-BizServer.cmake)
