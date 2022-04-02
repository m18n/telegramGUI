cmake_minimum_required(VERSION 3.16.3)
project(TelegramCloudGui)
set(APP_NAME TelegramCloudGui)
include_directories("ultralight/include")

link_libraries(UltralightCore AppCore Ultralight WebCore)
file(GLOB CPPS "*.cpp")


if (APPLE)

   
  # Enable High-DPI on macOS through our custom Info.plist template
  set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in) 
endif()

if (MSVC)
    link_directories("ultralight/lib")
  # Tell MSVC to use main instead of WinMain for Windows subsystem executables
  set_target_properties(${APP_NAME} PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
else()
    link_directories("ultralight/bin")  
endif()
add_subdirectory(telegramCloud)

add_executable(${APP_NAME} WIN32 MACOSX_BUNDLE ${CPPS})
file(COPY "assets" DESTINATION "./")
target_link_libraries(${APP_NAME} PRIVATE TelegramCloud)
# Copy all binaries to target directory
add_custom_command(TARGET ${APP_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_directory  "../../ultralight/bin" $<TARGET_FILE_DIR:${APP_NAME}>)  
