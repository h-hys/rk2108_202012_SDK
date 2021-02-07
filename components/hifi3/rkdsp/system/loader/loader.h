/*
 * Copyright (c) 2019 Rockchip Electronics Co. Ltd.
 * Author: Huaping Liao <huaping.liao@rock-chips.com>
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

#ifndef __LOADER_H__
#define __LOADER_H__

#include <stdint.h>

/* Image IDs, specific in FwConfig.xml */
#define IMAGE_3DNR_NR              0
#define IMAGE_3DNR_ME              1
#define IMAGE_LDW                  2
#define IMAGE_ODT                  3
#define IMAGE_IDC                  4
#define IMAGE_DVS                  5
#define IMAGE_RKFD                 11
#define IMAGE_RSFACE               21
#define IMAGE_RSBODY               22
#define IMAGE_RSFT                 23
#define IMAGE_RSFR                 24
#define IMAGE_RSLIVE               25
#define IMAGE_RSGLASS              26
#define IMAGE_TEST                 999

#define MAX_IMAGE                  16
#define IMAGE_NAME_SIZE            32
#define IMAGE_MAX_SECTION          4

#define CODE_INTERNAL              0x0
#define CODE_EXTERNAL              0x1
#define DATA_INTERNAL              0x2
#define DATA_EXTERNAL              0x3

struct section {
    uint32_t valid;
    uint32_t type;
    uint32_t size;
    uint32_t src;
    uint32_t dst;
};

struct image {
    uint32_t id;
    char name[IMAGE_NAME_SIZE];
    struct section sections[IMAGE_MAX_SECTION];
};

struct loader {
    struct image *current_image;
    uint32_t image_count;
    uint32_t images[MAX_IMAGE];
};

#ifdef __cplusplus
extern "C" {
#endif

int loader_init(uint32_t image_count, uint32_t *image);
int loader_request_image(const char *name);
int loader_request_image_by_id(uint32_t id);

#ifdef __cplusplus
}
#endif

#endif
