# Find the required packages
find_package(GTest REQUIRED)

# Include directories for Google Test and your project
include_directories(${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include) # Add include path to project

# Set test files for each class
set(TEST_FILES
        test_cell.cpp
        test_function.cpp
)

# Create the executable for tests
add_executable(runTests test_main.cpp ${TEST_FILES})

# Link the test executable to Google Test, pthread, wxWidgets, and your project library
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread ${wxWidgets_LIBRARIES} ${PROJECT_NAME}_lib)

# Define the test
add_test(NAME runTests COMMAND runTests)