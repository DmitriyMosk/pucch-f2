# src/libs/matrix/CMakeLists.txt 

set(LD_NAME "matrix") 

add_library(${LD_NAME} STATIC 
    src/${LD_NAME}.cpp
) 

target_include_directories(${LD_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)