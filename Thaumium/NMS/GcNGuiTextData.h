#pragma once
#include "GcNGuiElementData.h"
#include "TkFixedString.h"
#include "TkNGuiTextStyle.h"
#include "TkNGuiGraphicStyle.h"

class cGcNGuiTextData
{
public:
	cGcNGuiElementData mElementData;
	cTkNGuiTextStyle mStyle;
	cTkNGuiGraphicStyle mGraphicStyle;
	cTkFixedString<512, char> macText;
	cTkFixedString<128, char> macImage;
	float mfForcedOffset;
	cTkDynamicArray</*cGcVROverride_Text*/char[0x8]> maVROverrides;
	cTkDynamicArray</*cGcAccessibleOverride_Text*/char[0x8]> maAccessibleOverrides;
	bool mbSpecial;
	bool mbForcedAllowScroll;
};