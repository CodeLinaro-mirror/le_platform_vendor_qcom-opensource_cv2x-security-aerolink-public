cmake_minimum_required(VERSION 2.8.9)

# ---------------------------------------------
# adding config install
# ---------------------------------------------
install( DIRECTORY ccsa etsi ieee
         DESTINATION ${CMAKE_INSTALL_PREFIX}/../data/aerolink )
