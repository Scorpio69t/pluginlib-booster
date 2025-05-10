add_executable(plugin_test main.cpp)
target_include_directories(plugin_test PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(plugin_test pluginlib Boost::filesystem Boost::system)

set_target_properties(plugin_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
