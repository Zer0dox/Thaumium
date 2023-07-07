#pragma once

template <typename T>
class cTkDynamicArray
{
public:
	union cTkDynamicArrayPointer
	{
		T* mpaArray;
		__int64 miOffset;
	};
	cTkDynamicArray<T>::cTkDynamicArrayPointer mArray;
	int miSize;
	bool mbAllocatedFromData;
	unsigned __int8 macMagicPad[3];
};