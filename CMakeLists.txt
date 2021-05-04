cmake_minimum_required(VERSION 3.13)
cmake_policy(VERSION 3.13)

project(fty_security_wallet_rest
  VERSION 1.0.0
  DESCRIPTION "Security wallet REST API for 42ity project"
  LANGUAGES CXX)

##############################################################################################################
find_package(fty-cmake PATHS ${CMAKE_BINARY_DIR}/fty-cmake)
##############################################################################################################

# Define the servlet
etn_target(shared ${PROJECT_NAME}
  SOURCES
    src/*.cc
  INCLUDE_DIRS
    include
  USES
    fty-cmake-rest
    cxxtools
    tntdb
    tntnet
    fty_common
    fty_common_logging
    fty_common_rest
    fty_common_socket
    fty_security_wallet
)

# Get the ecpp
file(GLOB ECPP_FILES
  ecpp/*.ecpp
)

# Transform ecpp files
fty_ecppbuilder(
  TARGET ${PROJECT_NAME}
  WORKDIR src
  ECPP
    ${ECPP_FILES}
)

add_subdirectory(tests)

# Install tntnet mapping file in etc/tntnet/bios.d/
install(FILES ${PROJECT_SOURCE_DIR}/resources/41_secw-rest.xml DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/tntnet/bios.d/)
