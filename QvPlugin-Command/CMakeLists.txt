project(QvPlugin-Command)
cmake_minimum_required(VERSION 3.1.0)

add_library(${PROJECT_NAME} SHARED
    CommandPlugin.hpp
    CommandPlugin.cpp
    core/EventHandler.cpp
    core/EventHandler.hpp
    core/CommandConfig.hpp
    ui/GUIInterface.hpp
    ui/CommandPluginSettings.cpp
    ui/CommandPluginSettings.hpp
    ui/CommandPluginSettings.ui
    resx.qrc
    )
qv2ray_configure_plugin(${PROJECT_NAME} Widgets)
