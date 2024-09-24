cmake_minimum_required(VERSION 3.10)
project(FoglioDiCalcolo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME}_lib
        include/Cell.h
        include/Function.h
        include/GridInterface.h
        include/Observer.h
        include/Subject.h
        src/Cell.cpp
        src/Function.cpp
        src/GridInterface.cpp
        src/Observer.cpp
        src/Subject.cpp

)

target_link_libraries(${PROJECT_NAME}_lib ${wxWidgets_LIBRARIES})

add_executable(FoglioDiCalcolo src/main.cpp
)

target_link_libraries(FoglioDiCalcolo ${PROJECT_NAME}_lib ${wxWidgets_LIBRARIES})

#add_subdirectory(tests)
