#pragma once

#include "../pch.h"
#include "../Utilities/Memory/TkLinearHashTable.h"
#include "../Utilities/Memory/TkSTLAllocatorShim.h"
#include "../Utilities/TkStrongType.h"
#include "../Utilities/TkStrongTypeIDs.h"
#include "TkResourceDescriptor.h"
#include "TkResource.h"

class cTkResourceManagerBase
{
public:
	virtual ~cTkResourceManagerBase() = 0;
};

class cTkResourceManager : public cTkResourceManagerBase
{
	robin_hood::detail::Table<false, 80, int, cTkLinearHashTable<unsigned __int64, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, 6, 0, cTkLinearHashTableHash<unsigned __int64> >, robin_hood::hash<int, void>, std::equal_to<int> > mLookup;
	std::vector<cTkResource*, TkSTLAllocatorShim<cTkResource*> > mResources;
	std::vector<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, TkSTLAllocatorShim<TkStrongType<int, TkStrongTypeIDs::TkResHandleID> > > mFreeResourceHandles;
	std::unordered_map<cTkResource*, cTkResourceManager::cTkKillResource, std::hash<cTkResource*>, std::equal_to<cTkResource*>, TkSTLAllocatorShim<std::pair<cTkResource* const, cTkResourceManager::cTkKillResource>, 8, 6> > mKillMap;
	robin_hood::detail::Table<0, 80, int, cTkResourceRegistryEntry, robin_hood::hash<int, void>, std::equal_to<int> > mRegistry;
	robin_hood::detail::Table<1, 80, int, void, robin_hood::hash<int, void>, std::equal_to<int> > mResourcesLoading;
	std::vector<std::pair<cTkResource*, cTkResourceDescriptor const*>, TkSTLAllocatorShim<std::pair<cTkResource*, cTkResourceDescriptor const*>, 8, 6> > mGeometryWaitingForStream;
	int miDebugResourceType;
	bool mbForceReload;
	bool mbIgnoreTimestamp;
	bool mbAllowLazyDeletions;
	std::recursive_mutex mMutex;
	__int64 miLastHotReloadTime;
	unsigned __int16 muHotReloadRequestNumber;

	~cTkResourceManager()
	{ };
};