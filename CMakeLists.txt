cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(my_app)

set(CMAKE_BUILD_TYPE Debug) 

include_directories(C:\\Development\\Tools\\vcpkg\\installed\\x64-windows\\include)
link_directories(C:\\Development\\Tools\\vcpkg\\installed\\x64-windows\\lib)

find_package(GTest CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(my_app 
    src/app/app.cpp
    src/config/config.cpp
    src/vector/vector.cpp
    src/perceptron/perceptron.cpp
    src/layer/layer.cpp
    src/neural_network/neural_network.cpp
)
target_link_libraries(my_app PRIVATE fmt::fmt)

enable_testing()

# so we have to create a seperate executable for each test file to make em show at least a bit seperate in vscode testexplorer
add_executable(tests
    tests/main.cpp
    src/vector/vector.cpp
    tests/vector_test.cpp
    src/matrix/matrix.cpp
    tests/matrix_test.cpp
    src/perceptron/perceptron.cpp
    tests/perceptron_test.cpp
    src/layer/layer.cpp
    tests/layer_test.cpp
)

target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main fmt::fmt)
add_test(AllTests tests)