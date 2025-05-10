add_executable(plugin_test main.cpp)
target_include_directories(plugin_test PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(plugin_test pluginlib Boost::filesystem Boost::system)

# 复制插件目录路径（运行时要从 ./plugins 目录加载）
add_custom_command(TARGET plugin_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_BINARY_DIR}/plugins $<TARGET_FILE_DIR:plugin_test>/plugins)
