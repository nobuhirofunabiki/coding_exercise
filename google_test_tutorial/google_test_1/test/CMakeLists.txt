find_package(GTest REQUIRED)
add_executable(gtest_myint gtest_myint.cpp)
target_link_libraries(gtest_myint
    PRIVATE
        GTest::GTest
        GTest::Main
        myint_library
)