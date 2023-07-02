#pragma once

#include "GcUIOptionListElement.h"
#include "TkFixedString.h"

template<typename T>
class cGcOption : public cGcUIOptionListElement
{
public:
	cGcOption() : cGcUIOptionListElement()
	{ 
		mTranslatedDescription = cTkFixedString<1024, char>();
	};
	T mOptionsMenuValue;
	T* mpValue;
	T mDefaultValue;
	bool mbAutoApply;
	const char* mpacOptionName;
	const char* mpacDescriptionLocKey;
	cTkFixedString<1024, char> mTranslatedDescription;
	void(__fastcall* mpOnUserChanged)();
	bool(__fastcall* mpVisibilityCondition)();
	bool(__fastcall* mpEnabledCondition)();

	void virtual Apply()
	{
		T* mpValue;
		mpValue = this->mpValue;
		
		if (mpValue)
			*mpValue = this->mOptionsMenuValue;
	}

	void virtual DiscardChanges()
	{
		T* mpValue;
		//void __fastcall** p_mpOnUserChanged;

		mpValue = this->mpValue;
		if (mpValue)
		{
			auto p_mpOnUserChanged = &this->mpOnUserChanged;

			bool v3 = this->mOptionsMenuValue != *mpValue && *p_mpOnUserChanged;
			bool v4 = !this->mbAutoApply;
			this->mOptionsMenuValue = *mpValue;
			if (!v4)
				this->Apply();
			if (v3)
				(*p_mpOnUserChanged)();
		}
	}

	bool virtual HasChanges()
	{
		bool result = false;
		T* mpValue;

		if (this->mbVisible)
		{
			mpValue = this->mpValue;
			if (mpValue)
			{
				if (this->mOptionsMenuValue != *mpValue)
				{
					return true;
				}
			}
		}

		return result;
	}

	bool virtual IsNonDefault()
	{
		T* mpValue;

		mpValue = this->mpValue;
		return mpValue && *mpValue != this->mDefaultValue;
	}

	void virtual ResetToDefault()
	{
		T mDefaultValue; // al
		void(__fastcall * *p_mpOnUserChanged)(); // rbx
		bool v3; // di
		bool v4; // zf

		mDefaultValue = this->mDefaultValue;
		p_mpOnUserChanged = &this->mpOnUserChanged;
		v3 = this->mOptionsMenuValue != mDefaultValue && *p_mpOnUserChanged;
		v4 = !this->mbAutoApply;
		this->mOptionsMenuValue = mDefaultValue;
		if (!v4)
			this->Apply();
		if (v3)
			(*p_mpOnUserChanged)();
	}

	void virtual CreateElement();
	void virtual TranslateDescription();
	void virtual CreateElement();
	cTkFixedString<32, char>* virtual GetTranslatedDefaultValue(cTkFixedString<32, char>* result);
};