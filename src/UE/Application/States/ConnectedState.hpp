#pragma once

#include "BaseState.hpp"

namespace ue
{

class ConnectedState : public BaseState
{
public:
    ConnectedState(Context& context);
    void handleDisconnect() override;
    void handleSmsReceived(common::PhoneNumber from, std::string text) override;
};

}
