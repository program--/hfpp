include(FetchContent)
FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    GIT_TAG        v2.4.11
    OVERRIDE_FIND_PACKAGE
)

FetchContent_MakeAvailable(doctest)
