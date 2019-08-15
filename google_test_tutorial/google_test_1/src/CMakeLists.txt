add_library(myint_library
    SHARED
        myint.cpp
)

target_include_directories(myint_library
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
