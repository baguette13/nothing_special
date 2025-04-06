#include "ConnectedState.hpp"
#include "NotConnectedState.hpp"


namespace ue
{

ConnectedState::ConnectedState(Context &context)
    : BaseState(context, "ConnectedState")
{
    context.user.showConnected();
}

void ConnectedState::handleDisconnect()
{
    context.user.showNotConnected();
    context.setState<NotConnectedState>();
}

void ConnectedState::handleSmsReceived(common::PhoneNumber from, std::string text)
{

    logger.logInfo("SMS received from: ", from, ", with text: ", text);

    // Store the SMS in the database
    std::size_t smsIndex = context.smsDb.addSms(from, text);
    logger.logDebug("SMS stored at index: ", smsIndex);

    // Notify the user about new SMS
    context.user.showNewSms();
}

}
