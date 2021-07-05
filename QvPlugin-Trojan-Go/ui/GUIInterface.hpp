#pragma once
#include "QvPlugin/Gui/QvGUIPluginInterface.hpp"
#include "widgets/TrojanGoOutboundWidget.hpp"
#include "widgets/TrojanGoSettingsWidget.hpp"

using namespace Qv2rayPlugin;
class TrojanGoGUIInterface : public Qv2rayPlugin::Gui::PluginGUIInterface
{
    QIcon Icon() const override
    {
        return QIcon(":/assets/qv2ray.png");
    }

    QList<Qv2rayPlugin::PLUGIN_GUI_COMPONENT_TYPE> GetComponents() const override
    {
        return { GUI_COMPONENT_SETTINGS, GUI_COMPONENT_OUTBOUND_EDITOR };
    }

    std::unique_ptr<Qv2rayPlugin::Gui::PluginSettingsWidget> createSettingsWidgets() const override
    {
        return std::make_unique<TrojanGoSettingsWidget>();
    }

    QList<typed_plugin_editor> createInboundEditors() const override
    {
        return {};
    }

    QList<typed_plugin_editor> createOutboundEditors() const override
    {
        return { Qv2rayPlugin::Gui::make_editor_info<TrojanGoOutboundWidget>("trojan-go", "Trojan Go") };
    }

    std::unique_ptr<Qv2rayPlugin::Gui::PluginMainWindowWidget> createMainWindowWidget() const override
    {
        return nullptr;
    }
};
