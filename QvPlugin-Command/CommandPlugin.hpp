#pragma once

#include "QvPlugin/PluginInterface.hpp"
#include "core/CommandConfig.hpp"
#include "core/EventHandler.hpp"

#include <QObject>
#include <QtPlugin>

using namespace Qv2rayPlugin;

class CommandPlugin
    : public QObject
    , public Qv2rayInterface
{
    Q_INTERFACES(Qv2rayPlugin::Qv2rayInterface)
    Q_PLUGIN_METADATA(IID Qv2rayInterface_IID)
    Q_OBJECT
  public:
    //
    // Basic metainfo of this plugin
    const QvPluginMetadata GetMetadata() const override
    {
        return QvPluginMetadata{ "Qv2ray Command Plugin",                             //
                                 "Qv2ray Workgroup",                                  //
                                 PluginId{ "qvplugin_command" },                      //
                                 "Run any command when an event from Qv2ray occurs.", //
                                 "",                                                  //
                                 {
                                     COMPONENT_EVENT_HANDLER, //
                                     COMPONENT_GUI            //
                                 } };
    }
    bool InitializePlugin() override;
    void SettingsUpdated() override{};

  signals:
    void PluginLog(QString) override;
    void PluginErrorMessageBox(QString, QString) override;
};
