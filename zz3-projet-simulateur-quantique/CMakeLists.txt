cmake_minimum_required(VERSION 3.6)

project(zz3-project-simulateur-quantique
        VERSION 1.0
        LANGUAGES CXX
        DESCRIPTION "Projet ZZ3 F2 M2 ICS 3: État de l’art sur l’avancement de l’informatique quantique")

# Options
option(DEBUG "Enable debug for all targets" OFF)
if(DEBUG)
    add_compile_options(-g)
endif()
option(WARNING "Enable compilation warnings for all targets" ON)
if(WARNING)
    if(MSVC)
        add_compile_options(/W4)
    else()
        add_compile_options(-Wall -Wextra)
    endif()
endif()

# Variables for the whole project
set(CMAKE_CXX_STANDARD 11) # use C++11
set(CMAKE_CXX_STANDARD_REQUIRED TRUE) # do not fall back on older version
set(CMAKE_CXX_EXTENSIONS OFF) # strict c++.. instead of gnu++..

# Third party libraries
find_package(Boost 1.36 REQUIRED)

# Binaries to build
add_library(my_headers INTERFACE)
target_include_directories(my_headers INTERFACE include)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE Boost::boost my_headers)

# Tests to build and register
enable_testing()

add_executable(test_boost_ublas_example tests/boost_ublas_example.cpp)
target_link_libraries(test_boost_ublas_example PRIVATE Boost::boost my_headers)
add_test(test_boost_ublas_example test_boost_ublas_example)

add_executable(kronecker_test tests/kronecker_test.cpp)
target_link_libraries(kronecker_test PRIVATE Boost::boost my_headers)
add_test(kronecker_test kronecker_test)

add_executable(cnot_toffoli_test tests/cnot_toffoli_test.cpp)
target_link_libraries(cnot_toffoli_test PRIVATE Boost::boost my_headers)
add_test(cnot_toffoli_test cnot_toffoli_test)

add_executable(addition_test tests/addition_test.cpp)
target_link_libraries(addition_test PRIVATE Boost::boost my_headers)
add_test(addition_test addition_test)
