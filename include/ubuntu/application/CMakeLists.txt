set(
  UBUNTU_APPLICATION_HEADERS
  archive.h
  description.h
  id.h
  instance.h
  lifecycle_delegate.h
  operation_mode.h
  options.h
  init.h
)

install(
  FILES ${UBUNTU_APPLICATION_HEADERS}
  DESTINATION include/ubuntu/application
)

add_subdirectory(sensors)
