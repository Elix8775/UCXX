#include "../Surface.h"
#include "../../Platform/Platform.h"
#include <vulkan/vulkan_xlib.h>
#include <X11/Xlib.h>

static const char* REQUIRED_EXTENSIONS[] = {
    VK_KHR_SURFACE_EXTENSION_NAME,
    VK_KHR_XLIB_SURFACE_EXTENSION_NAME
};

const char** window_get_required_extensions(uint32_t* count) 
{
    *count = 2;
    return REQUIRED_EXTENSIONS;
}

VkResult window_create_surface(UWXX* win, VkInstance instance, VkSurfaceKHR* out_surface) 
{
    UWXX_Platform* p = win->platform;

    VkXlibSurfaceCreateInfoKHR info = {};
    info.sType  = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
    info.dpy    = p->display;
    info.window = p->window;

    return vkCreateXlibSurfaceKHR(instance, &info, nullptr, out_surface);
}