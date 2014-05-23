#ifndef buildconfig_h__
#define buildconfig_h__

#define AEON_CONSOLE_OUTPUT_DEBUG_MSGS
#define AEON_CONSOLE_BUFFER_SIZE			(10 * 1024)
#define AEON_DEFAULT_CONSOLE_LOG_LEVEL		console::log_level::info

#define AEON_STREAM_MAX_TEXT_LINE_LENGTH	2048
#define AEON_STREAM_DEFAULT_NAME			"<UNNAMED>"

#define AEON_USE_PNG
#define AEON_USE_GLFW_PLATFORM

#define AEON_DEFAULT_SCREEN_WIDTH			1280
#define AEON_DEFAULT_SCREEN_HEIGHT			720

#endif // buildconfig_h__