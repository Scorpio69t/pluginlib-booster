//
// Created by ryan on 2025/5/10.
//

#ifndef PLUGIN_METADATA_H
#define PLUGIN_METADATA_H


#include <string>

namespace pluginlib {
    struct PluginMeta {
        std::string name;
        std::string version;
        std::string author;
        std::string description;
        std::string library;
    };
}


#endif //PLUGIN_METADATA_H
