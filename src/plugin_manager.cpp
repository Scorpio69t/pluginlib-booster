//
// Created by ryan on 2025/5/10.
//

#include "pluginlib/plugin_manager.h"
#include "pluginlib/plugin_macro.h"
#include "pluginlib/plugin_metadata.h"
#include <nlohmann/json.hpp>
#include <iostream>

namespace pluginlib {
    namespace fs = boost::filesystem;
    using json = nlohmann::json;

    void PluginManager::load_plugins(const std::string &directory) {
        if (!fs::exists(directory) || !fs::is_directory(directory)) {
            throw std::runtime_error("Directory does not exist or is not a directory: " + directory);
        }

        int count = 0;
        for (const auto &entry: fs::directory_iterator(directory)) {
            const auto &path = entry.path();
            if (!fs::is_regular_file(path)) {
                continue;
            }

            if (path.extension() != PLUGIN_EXT) {
                continue;
            }

            try {
                boost::dll::shared_library lib(path.string(), boost::dll::load_mode::append_decorations);
                auto factory_fn = lib.get<IPluginFactory*(*)()>("create_plugin_factory");
                auto* factory = factory_fn();

                if (PluginInterfacePtr plugin = factory->create(); plugin && plugin->initialize()) {
                    std::string plugin_name = plugin->name();
                    plugins_[plugin_name] = plugin;
                    loaded_libraries_.push_back(std::move(lib));
                    std::cout << "[PluginManager] Loaded plugin: " << plugin_name << std::endl;
                    count++;
                }
            } catch (const std::exception &e) {
                std::cerr << "[PluginManager] Failed to load " << path.string() << ": " << e.what() << std::endl;
            }
        }

        std::cout << "[PluginManager] Loaded " << count << " plugins" << std::endl;
    }

    void PluginManager::unload_plugins() {
        plugins_.clear();
        loaded_libraries_.clear();
        std::cout << "[PluginManager] Unloaded all plugins" << std::endl;
    }

    void PluginManager::run_all() {
        for (const auto &[name, plugin]: plugins_) {
            std::cout << "[Plugin] " << name
                    << " | Version: " << plugin->version()
                    << " | Author: " << plugin->author() << std::endl
                    << "Description: " << plugin->description() << std::endl;
        }
    }
}
