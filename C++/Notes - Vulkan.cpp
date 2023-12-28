//==================== ==================== Vulkan

// General
// Initialisation
//      Extensions
//      macOS
//      Validation Layers
//      InfoStruct
//      Create/Destroy


//==================== General

#include <vulkan/vulkan.h>
#include <algorithm>
#include <vector>

//==================== Initialisation

//---------- Extensions
uint32_t supportedExtensionCount { 0 };
vkEnumerateInstanceExtensionProperties(nullptr, &supportedExtensionCount, nullptr);                     // get number of extensions
std::vector<VkExtensionProperties> supportedExtensions(supportedExtensionCount);
vkEnumerateInstanceExtensionProperties(nullptr, &supportedExtensionCount, supportedExtensions.data());  // get the names of extenstions

VK_EXT_DEBUG_UTILS_EXTENSION_NAME                                   // macro set to "VK_EXT_debug_utils" allowing message callbacks


//---------- macOS
uint32_t glfwExtensionCount { 0 };
const char **glfwExtensions { glfwGetRequiredInstanceExtensions(&glfwExtensionCount) };
std::vector<const char *> requiredExtensions;
std::copy(glfwExtensions, glfwExtensions+glfwExtensionCount, std::back_inserter(requiredExtensions));
requiredExtensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);     // necessary for MoltenVK on macOS


//---------- Validation Layers
uint32_t layerCount { 0 };
vkEnumerateInstanceLayerProperties(&layerCount, nullptr);           // get the number of layers
std::vector<VkLayerProperties> available(layerCount);
vkEnumerateInstanceLayerProperties(&layerCount, available.data());  // get the names of layers

std::vector<const char *> validationLayers {"VK_LAYER_KHRONOS_validation"};     // validation layer

auto static VKAPI_ATTR debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,         // speciffied below
    VkDebugUtilsMessageTypeFlagsEXT messageType,                    // speciffied below
    const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,      // speciffied below; struct containing details
    void *pUserData                                                 // ptr with user data that was specified during the set-up
) -> VkBool32 VKAPI_CALL;                                           // returns bool if the caller of validation should be aborted
                                                                    //  -> only for testing the layers VK_ERROR_VALIDATION_FAILED_EXT, else VK_FALSE

// VkDebugUtilsMessageSeverityFlagBitsEXT   is one of the following:
    VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT;                // diagnostic msg
    VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;                   // informational msg e.g. creation of a resource
    VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;                // msg about behavior that is very likely a bug in the application
    VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;                  // msg about behavior that is invalid and may cause crashes

// VkDebugUtilsMessageTypeFlagsEXT          is one of the following:
    VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;                    // an event unrelated to the specs or performance has happened
    VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;                 // sth that violates the specs or indicates a possible mistake has happened
    VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;                // potential non-optimal use of vulkan

// VkDebugUtilsMessengerCallbackDataEXT     is a struct containing details:
    pMessage;                                                       // The debug message as a null-terminated string
    pObjects;                                                       // Array of Vulkan object handles related to the message
    objectCount;                                                    // Number of objects in array

VkDebugUtilsMessengerEXT debugMessenger;                            // used to register the debugCallback fn

VkDebugUtilsMessengerCreateInfoEXT createInfo {                                     // struct for debug messenger
    .sType           = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,     // the type
    .messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT                 // types of severities to call the callback for
                     | VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT
                     | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT
                     | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
    .messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT                      // types of messages the callback is notified about
                 | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT
                 | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
    .pfnUserCallback = debugCallback,                                               // the pointer to the callback fn
    .pUserData       = nullptr,                                                     // could be the class itself (this ptr)
};

VkResult CreateDebugUtilsMessengerEXT(                                              // helper to create a debug messenger
  VkInstance instance,
  const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
  const VkAllocationCallbacks *pAllocator,
  VkDebugUtilsMessengerEXT *pDebugMessenger)
{
    auto vkCreateDebugUtilsMessengerEXT = reinterpret_cast<PFN_vkCreateDebugUtilsMessengerEXT>(
      vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT"));           // load the extension fn to create utils msgr
    if (vkCreateDebugUtilsMessengerEXT != nullptr) {
        return vkCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pDebugMessenger);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

void DestroyDebugUtilsMessengerEXT(                                                 // helper to destroy a debug messenger
  VkInstance instance,
  VkDebugUtilsMessengerEXT debugMessenger,
  const VkAllocationCallbacks *pAllocator)
{
    auto vkDestroyDebugUtilsMessengerEXT = reinterpret_cast<PFN_vkDestroyDebugUtilsMessengerEXT>(
      vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT"));          // load the extension fn to destroy utils msgr
    if (vkDestroyDebugUtilsMessengerEXT != nullptr) {
        vkDestroyDebugUtilsMessengerEXT(instance, debugMessenger, pAllocator);
    }
}

//---------- InfoStruct
VkApplicationInfo appInfo{                                          // structure used for passing additional info to initialisation
    .sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO,
    .pNext              = nullptr,
    .pApplicationName   = "Hello Triangle",
    .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
    .pEngineName        = "No Engine",
    .engineVersion      = VK_MAKE_VERSION(1, 0, 0),
    .apiVersion         = VK_API_VERSION_1_3
};

VkInstanceCreateInfo createInfo{                                    // structure used for initialisation of vulkan library
    .sType =                   VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    .pNext =                   nullptr,
    .flags =                   VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR,    // necessary for MoltenVK on macOS
    .pApplicationInfo =        &appInfo,
    .enabledLayerCount =       static_cast<uint32_t>(validationLayers.size()),      // validation layers only provided in debug mode
    .ppEnabledLayerNames =     validationLayers.data(),                             // validation layers only provided in debug mode
    .enabledExtensionCount =   requiredExtensions.size(),
    .ppEnabledExtensionNames = requiredExtensions.data()
};

//---------- Create/Destroy
vkCreateInstance(                                                   // return VkResult and creates a vulkan instance
    &createInfo,                                                    // creation info
    nullptr,                                                        // custom allocator callback
    &instance                                                       // handle where the new object is stored
);
vkDestroyInstance(instance, nullptr);                               // destroys the vulkan instance






//==================== ==================== GLFW

// General
// Window

//==================== General

#define GLFW_INCLUDE_VULKAN                                         // tells glfw to include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

glfwInit();                                                         // initialises the glfw library
glfwTerminate();                                                    // cleans-up resources



//==================== Window

glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);                       // tells glfw not to create OpenGL context
glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);                         // makes window not resizable

glfwCreateWindow(width, height, title, monitor, nullptr);           // return GLFWwindow ptr
glfwDestroyWindow(window);                                          // frees resources from window allocation

glfwWindowShouldClose(window);                                      // returns bool if a close event was triggered; coordinate with glfwPollEvents()



//==================== Events

glfwPollEvents();                                                   // check for events
