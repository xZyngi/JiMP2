
project(microdvdsubtitles)

set(HEDEAR_FILES MicroDvdSubtitles.h)
set(SOURCE_FILES MicroDvdSubtitles.cpp)

add_library(libmicrodvdsubtitles STATIC ${SOURCE_FILES})
target_include_directories(libmicrodvdsubtitles PUBLIC .)

add_executable(microdvdsubtitles ${SOURCE_FILES} main.cpp)

target_link_libraries(microdvdsubtitles libmicrodvdsubtitles)

