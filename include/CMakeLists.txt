cmake_minimum_required(VERSION 2.8.9)

project (aerolink)


# ---------------------------------------------
# adding header file install
# ---------------------------------------------
file( GLOB AEROLINK_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h" )
install( FILES ${AEROLINK_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )

