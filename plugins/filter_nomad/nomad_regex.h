/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2022 The Fluent Bit Authors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_FILTER_NOMAD_REGEX_H
#define FLB_FILTER_NOMAD_REGEX_H

#include "nomad_conf.h"

#define NOMAD_TAG_TO_REGEX "(?<alloc_id>[a-f0-9\\-]{36})\\.alloc\\.logs\\.(?<task_name>.+)\\.(?<output>(?:stdout)|(?:stderr))\.0$"

#define NOMAD_JOURNAL_TO_REGEX "^(?<name_prefix>[^_]+)_(?<container_name>[^\\._]+)(\\.(?<container_hash>[^_]+))?_(?<pod_name>[^_]+)_(?<namespace_name>[^_]+)_[^_]+_[^_]+$"

int flb_nomad_regex_init(struct flb_nomad *ctx);

#endif
