cmake_minimum_required(VERSION 2.8)

project(GoodsApp-GoodsServer)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/json)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lua)

link_libraries(liblua.a)

gen_server(GoodsApp GoodsServer)


#target_link_libraries(mysqlclient ssl crypto nghttp2-static)