cmake_minimum_required(VERSION 3.10)

# C Shared Project
project(ae2f_Dice VERSION 1.0 LANGUAGES C)

# Sources List for Project
set(SOURCES
    src/Dice.c
)

# Headers for library
set(HEADERS
    include/ae2fLib/Dice/Dice.h
)

# lib build set
add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# include directory
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# install set
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(FILES ${HEADERS} DESTINATION include/ae2fLib/Dice)