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

#include <SBConfig.h>
#include <stddef.h>

#include "SBAssert.h"
#include "SBBase.h"
#include "SBBidiLink.h"

SB_INTERNAL void SBBidiLinkMakeEmpty(SBBidiLinkRef link)
{
    link->next = NULL;
    link->offset = SBInvalidIndex;
    link->length = 0;
    link->type = SBCharTypeNil;
    link->level = SBLevelInvalid;
}

SB_INTERNAL void SBBidiLinkAbandonNext(SBBidiLinkRef link)
{
    link->next = link->next->next;
}

SB_INTERNAL void SBBidiLinkReplaceNext(SBBidiLinkRef link, SBBidiLinkRef next)
{
    link->next = next;
}

SB_INTERNAL void SBBidiLinkMergeNext(SBBidiLinkRef link)
{
    SBBidiLinkRef firstNext;
    SBBidiLinkRef secondNext;

    firstNext = link->next;
    secondNext = firstNext->next;

    link->next = secondNext;
    link->length += firstNext->length;
}
