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

#include "loader.h"

#include <asm-dsp.h>
#include <string.h>

#include "error.h"
#include "section.h"
#include "trace.h"

#define INVALID_IMAGE_ID 0xffffffff

__sys_data__ struct loader g_loader;

#if 0
static __sys__ struct image *loader_find_image_by_name(const char *name)
{
    int i;

    for (i = 0; i < MAX_IMAGE; i++) {
        struct image *img = (struct image *)g_loader.images[i];
        if (strcmp(img->name, name) == 0)
        return img;
    }

    LOGE("Cannot found image, name=%s\n", name);
    return NULL;
}

static __sys__ struct image *loader_find_image_by_id(uint32_t id)
{
    int i;

    for (i = 0; i < MAX_IMAGE; i++) {
        struct image *img = (struct image *)g_loader.images[i];
        if (img->id == id)
        return img;
    }

    LOGE("Cannot found image, id=%d\n", id);
    return NULL;
}

__sys__ int loader_request_image_by_id(uint32_t id)
{
    struct image *img = 0;
    int i;

    if (g_loader.current_image && g_loader.current_image->id == id)
    return 0;

    img = loader_find_image_by_id(id);
    if (!img)
    return -ENOFOUND;

    for (i = 0; i < IMAGE_MAX_SECTION; i++) {
        if (!img->sections[i].valid)
        continue;

        if (img->sections[i].type == CODE_INTERNAL)
        pdma_transfer_sync(img->sections[i].src, img->sections[i].dst, img->sections[i].size);
        else if (img->sections[i].type == DATA_INTERNAL)
        ddma_transfer_1d(img->sections[i].src, img->sections[i].dst, img->sections[i].size, DMA_DIR_EXTERNAL_INTERNAL, 0, 1);
    }

    LOGI("Load an image, name=%s\n", img->name);
    g_loader.current_image = img;

    return 0;
}

__sys__ int loader_request_image(const char *name)
{
    struct image *img = 0;
    int i;

    if (g_loader.current_image && strcmp(g_loader.current_image->name, name) == 0)
    return 0;

    img = loader_find_image_by_name(name);
    if (!img)
    return -ENOFOUND;

    for (i = 0; i < IMAGE_MAX_SECTION; i++) {
        if (!img->sections[i].valid)
        continue;

        if (img->sections[i].type == CODE_INTERNAL)
        pdma_transfer_sync(img->sections[i].src, img->sections[i].dst, img->sections[i].size);
        else if (img->sections[i].type == DATA_INTERNAL)
        ddma_transfer_1d(img->sections[i].src, img->sections[i].dst, img->sections[i].size, DMA_DIR_EXTERNAL_INTERNAL, 0, 1);
    }

    LOGI("Load an image, name=%s\n", img->name);
    g_loader.current_image = img;

    return 0;
}
#endif
__sys__ int loader_init(uint32_t image_count, uint32_t *image)
{
    int i = 0;

    g_loader.current_image = NULL;
    g_loader.image_count = image_count;

    for (i = 0; i < MAX_IMAGE; i++)
        g_loader.images[i] = image[i];

    return 0;
}
