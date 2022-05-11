cmake_minimum_required(VERSION 3.0.2)
project(TelegramCloudGui)
#set(CMAKE_GENERATOR_PLATFORM Win32)
include_directories("ultralight/include")
file(GLOB CPPS "*.cpp")
link_directories("./ultralight/lib")

add_subdirectory(telegramCloud)
add_executable(${PROJECT_NAME} ${CPPS})
if (APPLE)

   
  # Enable High-DPI on macOS through our custom Info.plist template
  set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in) 
endif()

if (MSVC)
    
    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

target_link_libraries(${PROJECT_NAME} TelegramCloud UltralightCore AppCore Ultralight WebCore)

#file(COPY "assets" DESTINATION "./")
#target_link_libraries(${APP_NAME} PRIVATE TelegramCloud)

# Copy all binaries to target directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_SOURCE_DIR}/ultralight/bin $<TARGET_FILE_DIR:${PROJECT_NAME}>)  
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_directory  $<TARGET_FILE_DIR:TelegramCloud> $<TARGET_FILE_DIR:${PROJECT_NAME}>)  