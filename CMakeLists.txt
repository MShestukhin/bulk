cmake_minimum_required(VERSION 3.2)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

if($ENV{TRAVIS_BUILD_NUMBER})
    project(bulkmt VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(bulkmt VERSION 0.0.1)
endif()

add_custom_target(headers SOURCES ${LibFiles})
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

set_target_properties(bulkmt PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(bulkmt
    PRIVATE "${CMAKE_BINARY_DIR}"
)

install(TARGETS bulkmt RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)


