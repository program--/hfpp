include(FetchContent)

FetchContent_Declare(
    immer
    GIT_REPOSITORY https://github.com/arximboldi/immer.git
    GIT_TAG        d0b79d5cbd8e300067a7761e3507bcd40976fd8f
)

FetchContent_GetProperties(immer)
if(NOT immer_POPULATED)
    FetchContent_Populate(immer)
endif()

add_library(immer INTERFACE IMPORTED)
target_include_directories(immer INTERFACE ${immer_SOURCE_DIR})

