set(
  UBUNTU_HARDWARE_HEADERS
  alarm.h
  booster.h
)

install(
  FILES ${UBUNTU_HARDWARE_HEADERS}
  DESTINATION include/ubuntu/hardware
)
