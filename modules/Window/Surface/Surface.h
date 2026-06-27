#ifndef UCXX_WINDOW_SURFACE_H
#define UCXX_WINDOW_SURFACE_H

#include "../Init/Init.h"
#include <vulkan/vulkan.h>
#include <stdint.h>

const char** window_get_required_extensions(uint32_t* count);
VkResult     window_create_surface(UWXX* win, VkInstance instance, VkSurfaceKHR* out_surface);

#endif