cmake_minimum_required(VERSION 3.0.0)
project(singleResponsibility VERSION 0.1.0)

include(CTest)
enable_testing()

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(singleResponsibility main.cpp)

TARGET_LINK_LIBRARIES(singleResponsibility LINK_PUBLIC ${Boost_LIBRARIES} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
