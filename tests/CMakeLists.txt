cmake_minimum_required(VERSION 3.13)
cmake_policy(VERSION 3.13)

etn_test_target(${PROJECT_NAME}
    INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
    SOURCES
        ../src/*
        src/main.cc
    PREPROCESSOR
        -DCATCH_CONFIG_FAST_COMPILE
    USES
        Catch2::Catch2
)
