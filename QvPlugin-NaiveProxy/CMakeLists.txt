project(QvPlugin-NaiveProxy)
cmake_minimum_required(VERSION 3.1.0)

add_library(${PROJECT_NAME} SHARED
    SimplePlugin.hpp
    SimplePlugin.cpp
    core/Serializer.cpp
    core/Serializer.hpp
    core/Kernel.cpp
    core/Kernel.hpp
    ui/OutboundEditor.ui
    ui/OutboundEditor.cpp
    ui/OutboundEditor.hpp
    ui/SettingsWidget.cpp
    ui/SettingsWidget.hpp
    ui/SettingsWidget.ui
    ui/UIInterface.hpp
    resx.qrc)

qv2ray_configure_plugin(${PROJECT_NAME} Widgets HTTP_TO_SOCKS)
