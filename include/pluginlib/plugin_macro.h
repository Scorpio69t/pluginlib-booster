//
// Created by ryan on 2025/5/10.
//

#ifndef PLUGIN_MACRO_H
#define PLUGIN_MACRO_H

#include "plugin_interface.h"

#if defined(_WIN32)
    #define PLUGIN_EXT ".dll"
#elif defined(__APPLE__)
#define PLUGIN_EXT ".dylib"
#else
#define PLUGIN_EXT ".so"
#endif

#define REGISTER_PLUGIN_FACTORY(FactoryClass)                          \
extern "C"   \
PLUGINLIB_API pluginlib::PluginFactoryPtr create_plugin_factory() { \
return std::make_shared<FactoryClass>(); \
}

#endif //PLUGIN_MACRO_H
