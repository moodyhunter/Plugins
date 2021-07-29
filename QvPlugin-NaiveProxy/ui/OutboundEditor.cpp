#include "OutboundEditor.hpp"

OutboundEditor::OutboundEditor(QWidget *parent) : Qv2rayPlugin::Gui::PluginProtocolEditor(parent)
{
    setupUi(this);
}

void OutboundEditor::Load()
{
    const auto protocol = settings["protocol"].toString();

    textUsername->setText(settings["username"].toString());
    textPassword->setText(settings["password"].toString());
    comboProtocol->setCurrentText(protocol != "https" && protocol != "quic" ? "https" : settings["protocol"].toString());
    checkPadding->setChecked(settings["padding"].toBool());
}

void OutboundEditor::changeEvent(QEvent *e)
{

    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange: retranslateUi(this); break;
        default: break;
    }
}

void OutboundEditor::on_comboProtocol_currentTextChanged(const QString &arg1)
{
    root["protocol"] = arg1;
}

void OutboundEditor::on_textUsername_textEdited(const QString &arg1)
{
    root["username"] = arg1;
}

void OutboundEditor::on_textPassword_textEdited(const QString &arg1)
{
    root["password"] = arg1;
}

void OutboundEditor::on_checkPadding_stateChanged(int arg1)
{
    root["padding"] = arg1 == Qt::Checked;
}
