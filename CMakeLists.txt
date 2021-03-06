# Author: Jaco Malan (Code-Log) <jacomalan.12@gmail.com>
cmake_minimum_required(VERSION 3.12)
project(Stress++)
set(CMAKE_CXX_STANDARD 17)

# Configure the version number
set(Stress_VERSION_MAJOR 0)
set(Stress_VERSION_MINOR 2)
set(Stress_VERSION_PATCH 0)

# Add the configuration header file.
configure_file("${PROJECT_SOURCE_DIR}/StressConfig.h.in" "${PROJECT_BINARY_DIR}/StressConfig.h")
include_directories("${PROJECT_BINARY_DIR}")

# Create the exec.
add_executable(Stress++ main.h main.cpp menu_item.h menu_item.cpp )
target_link_libraries(Stress++ pthread)

# Copy the configuration header file.
install(TARGETS Stress++ DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/StressConfig.h" DESTINATION include)

# Set up the CPack stuff.
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${Stress_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Stress_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${Stress_VERSION_PATCH}")
include(CPack)
