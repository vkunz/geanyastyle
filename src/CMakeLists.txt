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
    AstyleConfig.cpp
    Config.cpp
    GeanyAstyle.cpp)

# geanyastyle headers
set(geanyastyleHeaders
    AstyleConfig.hpp
    Config.hpp
    GeanyAstyle.hpp)

# add new executable
add_library(geanyastyle MODULE
            ${geanyastyleSources}
            ${geanyastyleHeaders})

# overwrite lib prefix
set_target_properties(geanyastyle PROPERTIES PREFIX "")

# link against libconfig++
target_link_libraries(geanyastyle ${LIBCONFIGPP_LIBRARIES})

# link against Boost
target_link_libraries(geanyastyle ${Boost_LIBRARIES})

# link against AStyle
target_link_libraries(geanyastyle ${ASTYLE_LIBRARIES})

# install plugin
install(TARGETS geanyastyle
        LIBRARY DESTINATION geany)
