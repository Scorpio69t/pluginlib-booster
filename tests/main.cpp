//
// Created by ryan on 2025/5/10.
//

#include "pluginlib/plugin_manager.h"
#include <iostream>

int main() {
    pluginlib::PluginManager manager;
    manager.load_plugins("./plugins");

    if (auto logger = manager.get_plugin<pluginlib::PluginInterface>("Logger")) {
        std::cout << "[Main] Plugin loaded: " << logger->name() << std::endl;
    }

    return 0;
}

