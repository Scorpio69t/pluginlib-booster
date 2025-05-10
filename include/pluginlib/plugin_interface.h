//
// Created by ryan on 2025/5/10.
//

#ifndef PLUGIN_INTERFACE_H
#define PLUGIN_INTERFACE_H

#include <string>

namespace pluginlib {
    class PluginInterface {
        public:
virtual ~PluginInterface() = default;
virtual std::string name() const = 0;
virtual std::string version() const = 0;
virtual std::string description() const = 0;
vitual std::string author() const = 0;
virtual bool initialize() = 0;
    };
} // namespace pluginlib

#endif //PLUGIN_INTERFACE_H
