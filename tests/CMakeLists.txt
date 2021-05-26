cmake_minimum_required(VERSION 3.13)
cmake_policy(VERSION 3.13)

etn_test_target(${PROJECT_NAME}
    INCLUDE_DIRS
        ../include
    SOURCES
        ../src/*.cc
        src/*.cc
    PREPROCESSOR -DCATCH_CONFIG_FAST_COMPILE
    USES
        stdc++fs
        Catch2::Catch2
)
