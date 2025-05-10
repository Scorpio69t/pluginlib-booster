# 🔌 pluginlib-booster

> 一个轻量、高效、跨平台的 C++ 插件管理库，支持 Boost 动态加载、插件自动注册、元信息描述，**不依赖 Qt**，适合构建可扩展系统架构。

---

## ✨ 特性亮点

- ✅ **纯 C++ 实现**，兼容 C++17 / C++20
- 🚀 **Boost.DLL** 实现跨平台动态加载（.so/.dylib/.dll）
- 🔄 **插件自动注册机制**（无需手动显式调用）
- 📦 **插件元信息支持**：JSON 描述插件元数据（名称、版本、作者等）
- 🪟 **Windows/macOS/Linux** 全平台兼容
- 🧩 支持多个插件同时加载运行，热插拔接口可扩展

---

## 📁 项目结构
```bash
.
├── CMakeLists.txt
├── include
│   ├── nlohmann
│   │   ├── json_fwd.hpp
│   │   └── json.hpp
│   └── pluginlib
│       ├── plugin_interface.h
│       ├── plugin_macro.h
│       ├── plugin_manager.h
│       └── plugin_metadata.h
├── LICENSE
├── plugins
│   ├── CMakeLists.txt
│   ├── logger_plugin.cpp
│   └── logger_plugin.json
├── README.md
├── src
│   ├── CMakeLists.txt
│   └── plugin_manager.cpp
└── tests
    ├── CMakeLists.txt
    └── main.cpp

7 directories, 16 files
```

---

## ⚙️ 编译与运行

### 依赖

- [Boost 1.70+](https://www.boost.org/)
- CMake 3.14+
- 编译器支持 C++17（Clang / GCC / MSVC）

### 构建示例

```bash
git clone https://github.com/yourname/pluginlib-booster.git
cd pluginlib-booster
mkdir build && cd build
cmake ..
make -j
./tests/plugin_test
```

