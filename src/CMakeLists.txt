file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(pluginlib STATIC ${SRC_FILES})
target_link_libraries(pluginlib Boost::filesystem Boost::system)

target_include_directories(pluginlib PUBLIC ${CMAKE_SOURCE_DIR}/include)
