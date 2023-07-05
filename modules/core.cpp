#include "core.h"

void Core::Init()
{
	cGcApplication* gApplcation = GCAPPLICATION;

	cGcApplication::GetNetworkManager getNetworkManager = (cGcApplication::GetNetworkManager)OFFSET(0x1C2910);

	cGcNetworkManager* network = getNetworkManager(gApplcation);

	TextChatHandler::Init();
	FrontendOptions::Init();
}