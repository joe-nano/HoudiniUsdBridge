/*
 * Copyright 2019 Side Effects Software Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Produced by:
 *	Side Effects Software Inc.
 *	123 Front Street West, Suite 1401
 *	Toronto, Ontario
 *      Canada   M5J 2M2
 *	416-504-9876
 *
 */

#ifndef __XUSD_PathPattern_h__
#define __XUSD_PathPattern_h__

#include "HUSD_API.h"
#include "HUSD_PathPattern.h"
#include "XUSD_PerfMonAutoCookEvent.h"
#include <pxr/usd/sdf/path.h>

PXR_NAMESPACE_OPEN_SCOPE

class XUSD_SpecialTokenData : public UT_SpecialTokenData
{
public:
		 XUSD_SpecialTokenData()
		 { }
    virtual	~XUSD_SpecialTokenData()
		 { }

    SdfPathSet	 myExpandedCollectionPathSet;
    SdfPathSet	 myCollectionPathSet;
    SdfPathSet	 myVexpressionPathSet;
};

class HUSD_API XUSD_PathPattern : public HUSD_PathPattern
{
public:
			 XUSD_PathPattern(const UT_StringArray &pattern_tokens,
				HUSD_AutoAnyLock &lock,
				HUSD_PrimTraversalDemands demands,
                                int nodeid);
			 XUSD_PathPattern(const UT_StringRef &pattern,
				HUSD_AutoAnyLock &lock,
				HUSD_PrimTraversalDemands demands,
				int nodeid,
				const HUSD_TimeCode &timecode);
			~XUSD_PathPattern();

    void		 getSpecialTokenPaths(SdfPathSet &collection_paths,
				SdfPathSet &expanded_collection_paths,
				SdfPathSet &vexpression_paths) const;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif

