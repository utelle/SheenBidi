/*
 * Copyright (C) 2016 Muhammad Tayyab Akram
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _SB_INTERNAL_RUN_ADAPTER_H
#define _SB_INTERNAL_RUN_ADAPTER_H

#include <SBBase.h>
#include <SBParagraph.h>
#include <SBRunAdapter.h>

enum {
    _SBRunAdapterTypeNone = 0,
    _SBRunAdapterTypeParagraph = 1
};
typedef SBUInteger _SBRunAdapterType;

struct _SBRunAdapter {
    SBParagraphRef _paragraph;
    _SBRunAdapterType _type;
    SBUInteger _index;
    SBRunAgent agent;
    SBUInteger _retainCount;
};

#endif
