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

#ifndef FLB_FILTER_NOMAD_META_H
#define FLB_FILTER_NOMAD_META_H

#include "nomad_props.h"

struct flb_nomad;

struct flb_nomad_meta {
    int fields;

    int namespace_len;
    int jobname_len;
    int cache_key_len;
    int task_name_len;
    int group_name_len;
    int container_hash_len;
    int container_image_len;

    char *namespace;
    char *jobname;
    char *task_name;
    char *container_image;
    char *group_name;

    char *container_hash;   /* set only on Systemd mode */

    char *cache_key;
};

/* Constant Nomad paths */
//#define FLB_NOMAD_NAMESPACE "/var/run/secrets/kubernetes.io/serviceaccount/namespace"
//#define FLB_NOMAD_TOKEN "/var/run/secrets/kubernetes.io/serviceaccount/token"
#define FLB_NOMAD_CA "/var/run/secrets/kubernetes.io/serviceaccount/ca.crt"
#define FLB_NOMAD_API_HOST "localhost"
#define FLB_NOMAD_API_PORT 4646
#define FLB_NOMAD_API_FMT "/v1/allocation/%s"
#define FLB_NOMAD_ALLOCS "/v1/allocations"
#define FLB_NOMAD_HEALTH "/v1/agent/health"

int flb_nomad_meta_init(struct flb_nomad *ctx, struct flb_config *config);
int flb_nomad_meta_fetch(struct flb_nomad *ctx);
int flb_nomad_dummy_meta_get(char **out_buf, size_t *out_size);
int flb_nomad_meta_get(struct flb_nomad *ctx,
                      const char *tag, int tag_len,
                      const char *data, size_t data_size,
                      const char **out_buf, size_t *out_size,
                      struct flb_nomad_meta *meta,
                      struct flb_nomad_props *props);
int flb_nomad_meta_release(struct flb_nomad_meta *meta);

#endif
