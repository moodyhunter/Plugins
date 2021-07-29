#pragma once

#include "QvPlugin/PluginInterface.hpp"

#include <QObject>
#include <QtPlugin>

using namespace Qv2rayPlugin;

namespace Qv2rayBase::BuiltinPlugins::Latency
{
    class BuiltinLatencyTesterPlugin
        : public QObject
        , public Qv2rayInterface<BuiltinLatencyTesterPlugin>
    {
        Q_OBJECT
        QV2RAY_PLUGIN(BuiltinLatencyTesterPlugin)

      public:
        const QvPluginMetadata GetMetadata() const override;
        bool InitializePlugin() override;
        void SettingsUpdated() override;
    };
} // namespace Qv2rayBase::StaticPlugin
