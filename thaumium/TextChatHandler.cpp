#include "../pch.h"
#include "TextChatHandler.h"
#include "../engine/TkEngineUtils.h"

cGcTextChatInput::ParseTextForCommands fpParseTextForCommands = NULL;

using CommandFunction = void(*)(cGcTextChatInput*, const cTkFixedString<1023, char>&);

static std::unordered_map<std::string, CommandFunction> commandLookup;

void RegisterCommand(const std::string& command, CommandFunction func) {
    commandLookup[command] = func;
}

CommandFunction GetCommandFunction(const std::string& command) {
    auto it = commandLookup.find(command);
    if (it != commandLookup.end())
        return it->second;
    else
        return nullptr;
}

void __fastcall ParseTextForCommandsHook(cGcTextChatInput* _this, const cTkFixedString<1023, char> lMessageText) {
    std::string text = lMessageText.macBuffer;
    if (text.length() < 2 || text[0] != '/')
        return fpParseTextForCommands(_this, lMessageText); // avoid death

    std::string command = text.substr(1); // get the command name after '/'

    CommandFunction func = GetCommandFunction(command);
    if (func != nullptr) {
        func(_this, lMessageText); 
        return;
    }

    return fpParseTextForCommands(_this, lMessageText);
}
void TextChatHandler::Init()
{
    ADDHOOK(OFFSET(0x949870), ParseTextForCommandsHook, reinterpret_cast<LPVOID*>(&fpParseTextForCommands), cGcTextChatInput::ParseTextForCommands);
}

void TextChatHandler::RegisterStockCommands()
{
    // should use lookup tables, too lazy atm
}

