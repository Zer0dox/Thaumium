#pragma once
#include "TkID.h"

class cTkHashedNGuiElement
{
	TkID<128> mID;
	unsigned __int64 mHash;
};