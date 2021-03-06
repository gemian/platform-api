set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")

add_subdirectory(hybris)

add_library(
  ubuntu_application_api_touch_mirclient SHARED

  module.cpp
  module_version.h
)

target_link_libraries(
  ubuntu_application_api_touch_mirclient

  "-Wl,--whole-archive"
  ubuntu_application_api_mirclient
  ubuntu_application_api_hybris
  "-Wl,--no-whole-archive"
  #TODO: Alarms
)

set_target_properties(
  ubuntu_application_api_touch_mirclient
  PROPERTIES
  VERSION ${UBUNTU_PLATFORM_API_VERSION_MAJOR}.${UBUNTU_PLATFORM_API_VERSION_MINOR}.${UBUNTU_PLATFORM_API_VERSION_PATCH}
  SOVERSION ${UBUNTU_PLATFORM_API_VERSION_MAJOR}
)

install(
  TARGETS ubuntu_application_api_touch_mirclient
  # this is not a development library to compile against, users should always
  # specify the SONAME; so don't build a *.so
  LIBRARY DESTINATION "${LIB_INSTALL_DIR}" NAMELINK_SKIP
)
