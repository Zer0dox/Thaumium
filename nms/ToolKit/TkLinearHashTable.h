#pragma once

#include <utility>

#pragma pack(8)
template<typename T, typename U>
class cTkLinearHashTable
{
	class cTkListNode
	{
		std::pair<T, U> mValue;
		unsigned __int64 mHash;
		cTkLinearHashTable<T, U>::cTkListNode* mpNext;
		cTkLinearHashTable<T, U>::cTkListNode* mpPrev;
		bool mbUsed;
	};

	cTkLinearHashTable<T, U>::cTkListNode* mpNodes;
	cTkLinearHashTable<T, U>::cTkListNode** mapBucketTable;
	cTkLinearHashTable<T, U>::cTkListNode* mpFirstFreeNode;

	int miCapacity;
	int miSize;
	int miTableSize;
};
#pragma pack()