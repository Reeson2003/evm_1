cmake_minimum_required(VERSION 3.12)
project(evm_1)
project(evm_2)
project(evm_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/src/linux-headers-4.15.0-38-generic/include/)

add_executable(evm_1 task_1/task_1.cpp)
add_executable(evm_2 task_2/task_2.cpp)
add_executable(evm_5 task_5/task_5.cpp)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
if (CURSES_FOUND AND CURSES_HAVE_NCURSES_H)
    include_directories(${CURSES_INCLUDE_DIR})
    target_link_libraries (evm_2 ${CURSES_LIBRARIES})
endif()