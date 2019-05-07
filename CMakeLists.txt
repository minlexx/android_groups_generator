project(android_groups_generator)

cmake_minimum_required(VERSION 3.3)

include(GNUInstallDirs)

option(USE_BUNDLED_ANDROID_7_HEADERS "Use android headers from this repo instead of manually setting ANDROID_HEADERS_ROOT" ON)

# Where to take android headers from
if (USE_BUNDLED_ANDROID_7_HEADERS)
    set(ANDROID_HEADERS_ROOT
        ${CMAKE_CURRENT_LIST_DIR}/platform_system_core_android-24/include
    )
else()
    if (NOT ANDROID_HEADERS_ROOT)
        message(FATAL_ERROR "You must manually point ANDROID_HEADERS_ROOT to a valid location!")
    endif()
endif()

add_executable(${PROJECT_NAME}
    "android_groups_generator.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${ANDROID_HEADERS_ROOT}
)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
