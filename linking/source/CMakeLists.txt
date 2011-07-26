ADD_EXECUTABLE(dbo.wt login.C)
TARGET_LINK_LIBRARIES(dbo.wt wthttp wt wtdbo wtdbosqlite3)
#set(CMAKE_CXX_FLAGS "-Wall -ggdb -DNDEBUG")        # Maximize debugging
set(CMAKE_CXX_FLAGS "-Wall -ggdb")     
