cmake_minimum_required(VERSION 3.24)
project(Accountant)

if (POLICY CMP0077)
	cmake_policy(SET CMP0077 NEW)
endif ()

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_compile_options("/std:c++17")
	add_compile_options("/bigobj")
endif()

file(GLOB_RECURSE SOURCES "src/*.*")
list(REMOVE_ITEM SOURCES "src/main.cpp")

add_library(AccountantLib STATIC ${SOURCES})
add_executable(${PROJECT_NAME} "src/main.cpp")
target_link_libraries(${PROJECT_NAME} AccountantLib)

set_target_properties(${PROJECT_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} 
	RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}
	RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})


#### UNITTESTS

include(FetchContent)
FetchContent_Declare(googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG release-1.12.1
		)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
file(GLOB_RECURSE TEST_SOURCES "tests/*.*")

add_executable(AccountantTests ${TEST_SOURCES})

target_link_libraries(AccountantTests AccountantLib gtest gmock)

set_target_properties(AccountantTests PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
		RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}
		RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})
include(GoogleTest)
gtest_discover_tests(AccountantTests)