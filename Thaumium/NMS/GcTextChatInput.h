#pragma once
#include "TkFixedString.h"

class cGcTextChatInput
{
public:
	typedef void(__fastcall* ParseTextForCommands) (cGcTextChatInput* _this, const cTkFixedString<1023, char> lMessageText);
};