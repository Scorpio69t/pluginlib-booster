//
// Created by ryan on 2025/5/10.
//

#include "pluginlib/plugin_interface.h"
#include "pluginlib/plugin_macro.h"
#include <iostream>

using namespace pluginlib;

class LoggerPlugin final : public PluginInterface {
public:
    [[nodiscard]] std::string name() const override { return "Logger"; }
    [[nodiscard]] std::string version() const override { return "1.0.0"; }
    [[nodiscard]] std::string description() const override { return "A simple console logger plugin"; }
    [[nodiscard]] std::string author() const override { return "Ryan"; }

    bool initialize() override {
        std::cout << "[LoggerPlugin] Initialized successfully.\n";
        return true;
    }
};

REGISTER_PLUGIN_FACTORY(LoggerPlugin)
