//
// Created by ryan on 2025/5/10.
//

#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include "plugin_interface.h"
#include <boost/dll/import.hpp>
#include <boost/dll/shared_library.hpp>
#include <boost/filesystem.hpp>
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>

namespace pluginlib {
    class PluginManager {
    public:
        void load_plugins(const std::string &directory);

        void unload_plugins();

        void run_all();

        template<typename Plugin>
        std::shared_ptr<Plugin> get_plugin(const std::string &name) {
            auto it = plugins_.find(name);
            if (it != plugins_.end()) {
                auto plugin = std::dynamic_pointer_cast<Plugin>(it->second);
                if (plugin) {
                    return plugin;
                }
                throw std::runtime_error("Plugin found but type mismatch");
            }
            throw std::runtime_error("Plugin not found");
        }

    private:
        std::unordered_map<std::string, std::shared_ptr<PluginInterface> > plugins_;
        std::vector<boost::dll::shared_library> loaded_libraries_;
    };
}


#endif //PLUGIN_MANAGER_H
