# geanyastyle

# Debug - Build
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    # add defines
    add_definitions(-Wall -Wextra)
endif(CMAKE_BUILD_TYPE STREQUAL Debug)

# Devel - Build
if(CMAKE_BUILD_TYPE STREQUAL Release)
    # add defines
    add_definitions(-s -w)
endif(CMAKE_BUILD_TYPE STREQUAL Release)

# geanyastyle sources
set(geanyastyleSources
    geanyastyle.cpp)

# geanyastyle headers
set(geanyastyleHeaders
    geanyastyle.hpp)

# add new executable
add_library(geanyastyle MODULE
            ${geanyastyleSources}
            ${geanyastyleHeaders})

# overwrite lib prefix
set_target_properties(geanyastyle PROPERTIES PREFIX "")

# install plugin
install(TARGETS geanyastyle
        LIBRARY DESTINATION geany)
