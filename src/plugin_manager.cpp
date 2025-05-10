//
// Created by ryan on 2025/5/10.
//

#include "pluginlib/plugin_manager.h"
#include "pluginlib/plugin_macro.h"
#include <iostream>

namespace pluginlib {
    void PluginManager::load_plugins(const std::string &directory) {
        namespace fs = boost::filesystem;

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
                const auto factory_loader = lib.get<PluginFactoryPtr<PluginInterface>(*)()>("create_plugin_factory");
                if (!factory_loader) {
                    std::cerr << "[PluginManager] Failed to load factory from " << path.string() << std::endl;
                    continue;
                }

                const PluginFactoryPtr<PluginInterface> factory = factory_loader();

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
