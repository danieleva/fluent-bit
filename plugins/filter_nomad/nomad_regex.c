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

#include <fluent-bit/flb_info.h>
#include <fluent-bit/flb_regex.h>

#include "nomad_conf.h"
#include "nomad_regex.h"

int flb_nomad_regex_init(struct flb_nomad *ctx)
{
    /* If a custom parser is not set, use the defaults */
    if (!ctx->parser) {
        if (ctx->use_journal == FLB_TRUE) {
            ctx->regex = flb_regex_create(NOMAD_JOURNAL_TO_REGEX);
        }
        else {
            ctx->regex = flb_regex_create(NOMAD_TAG_TO_REGEX);
        }
    }

    if (!ctx->regex) {
        return -1;
    }

    return 0;
}