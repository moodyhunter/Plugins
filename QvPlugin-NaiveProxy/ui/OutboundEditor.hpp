#pragma once

#include "QvPlugin/Gui/QvGUIPluginInterface.hpp"
#include "ui_OutboundEditor.h"

class OutboundEditor
    : public Qv2rayPlugin::Gui::QvPluginEditor
    , private Ui::OutboundEditor
{
    Q_OBJECT

  public:
    explicit OutboundEditor(QWidget *parent = nullptr);

    void SetContent(const IOProtocolSettings &) override;
    const IOProtocolSettings GetContent() const override
    {
        return IOProtocolSettings{ root };
    }

  protected:
    void changeEvent(QEvent *e) override;

  private slots:
    void on_comboProtocol_currentTextChanged(const QString &arg1);
    void on_textUsername_textEdited(const QString &arg1);
    void on_textPassword_textEdited(const QString &arg1);
    void on_checkPadding_stateChanged(int arg1);

  private:
    QJsonObject root;
};
