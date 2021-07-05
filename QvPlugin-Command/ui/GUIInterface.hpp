#pragma once

#include "QvPlugin/Gui/QvGUIPluginInterface.hpp"
#include "ui/CommandPluginSettings.hpp"

using namespace Qv2rayPlugin;

class CommandGUIInterface : public Qv2rayPlugin::Gui::PluginGUIInterface
{
  public:
    QIcon Icon() const override
    {
        return QIcon(":/assets/qv2ray.png");
    }

    QList<Qv2rayPlugin::PLUGIN_GUI_COMPONENT_TYPE> GetComponents() const override
    {
        return { GUI_COMPONENT_SETTINGS };
    }

    std::unique_ptr<Qv2rayPlugin::Gui::PluginSettingsWidget> createSettingsWidgets() const override
    {
        return std::make_unique<CommandPluginSettings>();
    }

    QList<typed_plugin_editor> createInboundEditors() const override
    {
        return {};
    }

    QList<typed_plugin_editor> createOutboundEditors() const override
    {
        return {};
    }

    std::unique_ptr<Qv2rayPlugin::Gui::PluginMainWindowWidget> createMainWindowWidget() const override
    {
        return nullptr;
    }
};
