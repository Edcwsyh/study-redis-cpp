CMAKE_MINIMUM_REQUIRED( VERSION 3.16 )

PROJECT( Vote CXX )

ADD_COMPILE_OPTIONS ( -std=c++17 )
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET ( CMAKE_CXX_FLAGS "-g" )

INCLUDE_DIRECTORIES( . )

AUX_SOURCE_DIRECTORY( ./article SRC_ARTICLE )
AUX_SOURCE_DIRECTORY( ./string SRC_STRING )
AUX_SOURCE_DIRECTORY( ./shell SRC_SHELL )
AUX_SOURCE_DIRECTORY( ./vote SRC_VOTE )

find_library(REDIS_PLUS_PLUS_LIB redis++)

add_executable( Vote
    main.cpp
    ${SRC_ARTICLE}
    ${SRC_STRING}
    ${SRC_SHELL}
    ${SRC_VOTE}
)

target_link_libraries( Vote
    protobuf
    stdc++
    ${REDIS_PLUS_PLUS_LIB}
    hiredis
    pthread
)
