add_library(logger_plugin SHARED logger_plugin.cpp)
target_include_directories(logger_plugin PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(logger_plugin pluginlib)

# 设置导出符号（必要时）
if (MSVC)
    target_compile_definitions(logger_plugin PRIVATE PLUGINLIB_EXPORTS)
endif ()

# 将插件输出到 plugins/ 目录
set_target_properties(logger_plugin PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
)
