#pragma once

#include <vector>

#include "../simulation/TkSeed.h"
#include "../metadata/TkID.h"
#include "../utilities/allocators/TkSTLAllocator.h"

class cTkResourceDescriptor
{
	//TODO: This is probably a sum of multiple inline funcs
	bool INLINE IsValid(cTkResourceDescriptor* descriptor, cTkResourceDescriptor* existing)
	{
		if (descriptor->mSeed.mbValid == existing->mSeed.mbValid)
		{
			if (descriptor->mSecondarySeed.mbValid == existing->mSecondarySeed.mbValid
				&& (!descriptor->mSeed.mbValid || !existing->mSeed.mbValid || descriptor->mSeed.mbValid == existing->mSeed.mbValid
					&& descriptor->mSeed.mu64SeedValue && existing->mSeed.mu64SeedValue)
				&& (!descriptor->mSeed.mbValid || !existing->mSeed.mbValid || descriptor->mSecondarySeed.mbValid == existing->mSecondarySeed.mbValid
					&& descriptor->mSecondarySeed.mu64SeedValue == existing->mSecondarySeed.mu64SeedValue)
				&& (existing->maDescriptors.size() == descriptor->maDescriptors.size())
				)
			{
				return true;
			}
		}

		return false;
	}

public:
	std::vector<TkID<256>, TkSTLAllocatorShim<TkID<256> > > maDescriptors;
	cTkSeed mSeed;
	cTkSeed mSecondarySeed;
};