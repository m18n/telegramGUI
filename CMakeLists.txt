cmake_minimum_required(VERSION 3.0.2)
project(TelegramCloudGui)
#set(CMAKE_GENERATOR_PLATFORM Win32)
file(GLOB CPPS "*.cpp")

add_subdirectory(telegramCloud)
add_executable(${PROJECT_NAME} ${CPPS})


target_link_libraries(${PROJECT_NAME} TelegramCloud)

#file(COPY "assets" DESTINATION "./")
#target_link_libraries(${APP_NAME} PRIVATE TelegramCloud)

# Copy all binaries to target directory
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_directory  $<TARGET_FILE_DIR:TelegramCloud> $<TARGET_FILE_DIR:${PROJECT_NAME}>)  