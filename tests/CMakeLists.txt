cmake_minimum_required(VERSION 3.13)
cmake_policy(VERSION 3.13)

if (BUILD_TESTING)

    etn_test(${PROJECT_NAME}-test
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

    #enable coverage
    etn_coverage(${PROJECT_NAME}-test)

endif()
