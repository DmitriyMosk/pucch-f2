cmake_minimum_required(VERSION 3.28)
project(pucch_f2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDART_REQUIRED True) 

configure_file(${CMAKE_SOURCE_DIR}/src/codec_matrix.txt ${CMAKE_BINARY_DIR}/codec_matrix.txt COPYONLY)

add_subdirectory(src/libs/matrix)
add_subdirectory(src/libs/avx_wrap)

set(SHARED_SRC
    src/shared/awgn.cpp
    src/shared/b_codec.cpp
    src/shared/orchest.cpp
    src/shared/fmath/fmath.cpp
)

add_executable(${CMAKE_PROJECT_NAME} 
    ${SHARED_SRC}
    src/app/main.cpp
) 
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src/shared
    ${CMAKE_SOURCE_DIR}/src/shared/fmath
    ${CMAKE_SOURCE_DIR}/src/app
)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    matrix
)