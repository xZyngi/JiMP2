
project(netsjson)

set(HEDEAR_FILES SimpleJson.h)
set(SOURCE_FILES SimpleJson.cpp)

add_library(libnetsjson STATIC ${SOURCE_FILES})
target_include_directories(libnetsjson PUBLIC .)

add_executable(netsjson ${SOURCE_FILES} main.cpp)

target_link_libraries(netsjson libnetsjson)

