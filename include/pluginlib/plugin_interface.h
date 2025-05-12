//
// Created by ryan on 2025/5/10.
//

#ifndef PLUGIN_INTERFACE_H
#define PLUGIN_INTERFACE_H

#include <string>
#include <memory>

#ifdef WIN32
#define PLUGINLIB_API __declspec(dllexport)
#else
#define PLUGINLIB_API
#endif // WIN32


namespace pluginlib {
    class PluginInterface {
    public:
        PluginInterface() = default;

        virtual ~PluginInterface() = default;

        [[nodiscard]] virtual std::string name() const = 0;

        [[nodiscard]] virtual std::string version() const = 0;

        [[nodiscard]] virtual std::string description() const = 0;

        [[nodiscard]] virtual std::string author() const = 0;

        virtual bool initialize() = 0;
    };

    using PluginInterfacePtr = std::shared_ptr<PluginInterface>;

    class IPluginFactory {
    public:
        virtual ~IPluginFactory() = default;

        virtual PluginInterfacePtr create() = 0;
    };

    using PluginFactoryPtr = std::shared_ptr<IPluginFactory>;
} // namespace pluginlib

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

PLUGINLIB_API pluginlib::PluginFactoryPtr create_plugin_factory();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //PLUGIN_INTERFACE_H
