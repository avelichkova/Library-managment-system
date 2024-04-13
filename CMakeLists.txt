cmake_minimum_required(VERSION 3.0.0)
project(library VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(library main.cpp ISBN.cpp Book.cpp BookAllocator.cpp Person.cpp PersonAllocator.cpp Commands.cpp SingletonCommands.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
