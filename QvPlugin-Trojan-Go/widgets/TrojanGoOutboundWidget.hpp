#pragma once

#include "QvPlugin/Gui/QvGUIPluginInterface.hpp"
#include "core/Common.hpp"
#include "ui_TrojanGoOutboundWidget.h"

class TrojanGoOutboundWidget
    : public Qv2rayPlugin::Gui::QvPluginEditor
    , private Ui::TrojanGoOutboundWidget
{
    Q_OBJECT

  public:
    explicit TrojanGoOutboundWidget(QWidget *parent = nullptr);

    void SetContent(const IOProtocolSettings &o) override
    {
        config.loadJson(o);
        sniTxt->setText(config.sni);
        hostTxt->setText(config.host);
        pathTxt->setText(config.path);
        typeCombo->setCurrentText(TRANSPORT_TYPE_STRING_MAP[config.type]);
        encryptionTxt->setText(config.encryption);
        passwordTxt->setText(config.password);
        muxCB->setChecked(config.mux);
        on_typeCombo_currentIndexChanged(typeCombo->currentIndex());
    }

    const IOProtocolSettings GetContent() const override
    {
        return IOProtocolSettings{ config.toJson() };
    }

  protected:
    TrojanGoShareLinkObject config;
    void changeEvent(QEvent *e) override;

  private slots:
    void on_sniTxt_textEdited(const QString &arg1);
    void on_typeCombo_currentIndexChanged(const QString &arg1);
    void on_hostTxt_textEdited(const QString &arg1);
    void on_pathTxt_textEdited(const QString &arg1);
    void on_encryptionTxt_textEdited(const QString &arg1);
    void on_passwordTxt_textEdited(const QString &arg1);
    void on_typeCombo_currentIndexChanged(int index);
    void on_muxCB_stateChanged(int arg1);
};
