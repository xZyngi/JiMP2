
project(metodyskladowe)

set(HEDEAR_FILES MetodySkladowe.h)
set(SOURCE_FILES MetodySkladowe.cpp)

add_library(libmetodyskladowe STATIC ${SOURCE_FILES})
target_include_directories(libmetodyskladowe PUBLIC .)

add_executable(metodyskladowe ${SOURCE_FILES} main.cpp)

target_link_libraries(metodyskladowe libmetodyskladowe)

