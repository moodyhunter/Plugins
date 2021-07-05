#pragma once

#include "QvPlugin/PluginInterface.hpp"

#include <QObject>
#include <QtPlugin>

using namespace Qv2rayPlugin;

namespace Qv2rayBase::BuiltinPlugins::Latency
{
    class BuiltinLatencyTesterPlugin
        : public QObject
        , public Qv2rayInterface
    {
        Q_INTERFACES(Qv2rayPlugin::Qv2rayInterface)
        Q_PLUGIN_METADATA(IID Qv2rayInterface_IID)
        Q_OBJECT

      public:
        const QvPluginMetadata GetMetadata() const override;
        ~BuiltinLatencyTesterPlugin();
        bool InitializePlugin() override;
        void SettingsUpdated() override;

      signals:
        void PluginLog(QString) override;
        void PluginErrorMessageBox(QString, QString) override;
    };
} // namespace Qv2rayBase::StaticPlugin
