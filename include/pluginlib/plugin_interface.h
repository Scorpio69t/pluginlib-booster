//
// Created by ryan on 2025/5/10.
//

#ifndef PLUGIN_INTERFACE_H
#define PLUGIN_INTERFACE_H

#include <string>
#include <memory>

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

using PluginInterfacePtr = std::shared_ptr<PluginInterface>;

    template<typename T>
    class PluginFactory {
        public:
            virtual ~PluginFactory() = default;
            virtual std::shared_ptr<T> create() = 0;
            virtual void destroy(std::shared_ptr<T> instance) = 0;
    };

    template<typename T>
    using PluginFactoryPtr = std::shared_ptr<PluginFactory<T>>;
} // namespace pluginlib

#endif //PLUGIN_INTERFACE_H
