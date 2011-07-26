SET(WT_PROJECT_SOURCE hello.C hello.h )

SET(WT_PROJECT_TARGET hello.wt)

ADD_EXECUTABLE(hello.wt hello.C)

TARGET_LINK_LIBRARIES(hello.wt wthttp wt)

INCLUDE_DIRECTORIES(/usr/include)

