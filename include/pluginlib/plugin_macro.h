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

#if defined(_WIN32)
  #define EXPORT_PLUGIN __declspec(dllexport)
#else
#define EXPORT_PLUGIN __attribute__((visibility("default")))
#endif

#define REGISTER_PLUGIN_FACTORY(FactoryClass)                          \
extern "C" EXPORT_PLUGIN pluginlib::IPluginFactory* create_plugin_factory() { \
return new FactoryClass();                                         \
}

#endif //PLUGIN_MACRO_H
