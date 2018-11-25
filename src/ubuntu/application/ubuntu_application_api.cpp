/*
 * Copyright (C) 2014-2015 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Thomas Voss <thomas.voss@canonical.com>
 *              Ricardo Mendoza <ricardo.mendoza@canonical.com>
 */

// C APIs
#include <ubuntu/application/id.h>
#include <ubuntu/application/description.h>
#include <ubuntu/application/instance.h>
#include <ubuntu/application/options.h>
#include <ubuntu/application/lifecycle_delegate.h>
#include <ubuntu/application/sensors/accelerometer.h>
#include <ubuntu/application/sensors/proximity.h>
#include <ubuntu/application/sensors/light.h>
#include <ubuntu/application/sensors/orientation.h>
#include <ubuntu/application/sensors/haptic.h>

#include <ubuntu/application/init.h>

#include "base_module.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MirConnection MirConnection;

// Application Module Config
IMPLEMENT_VOID_FUNCTION3(init, u_application_module_version, uint32_t*, uint32_t*, uint32_t*);
IMPLEMENT_VOID_FUNCTION1(init, u_application_init, void*);
IMPLEMENT_VOID_FUNCTION0(init, u_application_finish);

// Lifecycle helpers
IMPLEMENT_CTOR0(lifecycle, UApplicationLifecycleDelegate*, u_application_lifecycle_delegate_new);
IMPLEMENT_VOID_FUNCTION2(lifecycle, u_application_lifecycle_delegate_set_context, UApplicationLifecycleDelegate*, void*);
IMPLEMENT_VOID_FUNCTION1(lifecycle, u_application_lifecycle_delegate_ref, UApplicationLifecycleDelegate*);
IMPLEMENT_VOID_FUNCTION1(lifecycle, u_application_lifecycle_delegate_unref, UApplicationLifecycleDelegate*);
IMPLEMENT_VOID_FUNCTION2(lifecycle, u_application_lifecycle_delegate_set_application_resumed_cb, UApplicationLifecycleDelegate*, u_on_application_resumed);
IMPLEMENT_VOID_FUNCTION2(lifecycle, u_application_lifecycle_delegate_set_application_about_to_stop_cb, UApplicationLifecycleDelegate*, u_on_application_about_to_stop);

// Application Instance Helpers

// UApplicationId
IMPLEMENT_FUNCTION2(instance, UApplicationId*, u_application_id_new_from_stringn, const char*, size_t);
IMPLEMENT_VOID_FUNCTION1(instance, u_application_id_destroy, UApplicationId*);
IMPLEMENT_FUNCTION2(instance, int, u_application_id_compare, UApplicationId*, UApplicationId*);

// UApplicationDescription
IMPLEMENT_FUNCTION0(instance, UApplicationDescription*, u_application_description_new);
IMPLEMENT_VOID_FUNCTION1(instance, u_application_description_destroy, UApplicationDescription*);
IMPLEMENT_VOID_FUNCTION2(instance, u_application_description_set_application_id, UApplicationDescription*, UApplicationId*);
IMPLEMENT_VOID_FUNCTION2(instance, u_application_description_set_application_lifecycle_delegate, UApplicationDescription*, UApplicationLifecycleDelegate*);

// UApplicationOptions
IMPLEMENT_FUNCTION2(instance, UApplicationOptions*, u_application_options_new_from_cmd_line, int, char**);
IMPLEMENT_VOID_FUNCTION1(instance, u_application_options_destroy, UApplicationOptions*);

// UApplicationInstance
IMPLEMENT_FUNCTION2(instance, UApplicationInstance*, u_application_instance_new_from_description_with_options, UApplicationDescription*, UApplicationOptions*);
IMPLEMENT_FUNCTION1(connection, MirConnection*, u_application_instance_get_mir_connection, UApplicationInstance*);

// Ubuntu Application Sensors

// Acceleration Sensor
IMPLEMENT_CTOR0(sensors, UASensorsAccelerometer*, ua_sensors_accelerometer_new);
IMPLEMENT_FUNCTION1(sensors, UStatus, ua_sensors_accelerometer_enable, UASensorsAccelerometer*);
IMPLEMENT_FUNCTION1(sensors, UStatus, ua_sensors_accelerometer_disable, UASensorsAccelerometer*);
IMPLEMENT_FUNCTION1(sensors, uint32_t, ua_sensors_accelerometer_get_min_delay, UASensorsAccelerometer*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_accelerometer_get_min_value, UASensorsAccelerometer*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_accelerometer_get_max_value, UASensorsAccelerometer*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_accelerometer_get_resolution, UASensorsAccelerometer*, float*);
IMPLEMENT_VOID_FUNCTION3(sensors, ua_sensors_accelerometer_set_reading_cb, UASensorsAccelerometer*, on_accelerometer_event_cb, void*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_accelerometer_set_event_rate, UASensorsAccelerometer*, uint32_t);

// Acceleration Sensor Event
IMPLEMENT_FUNCTION1(sensors, uint64_t, uas_accelerometer_event_get_timestamp, UASAccelerometerEvent*);
IMPLEMENT_FUNCTION2(sensors, UStatus, uas_accelerometer_event_get_acceleration_x, UASAccelerometerEvent*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, uas_accelerometer_event_get_acceleration_y, UASAccelerometerEvent*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, uas_accelerometer_event_get_acceleration_z, UASAccelerometerEvent*, float*);

// Proximity Sensor
IMPLEMENT_CTOR0(sensors, UASensorsProximity*, ua_sensors_proximity_new);
IMPLEMENT_FUNCTION1(sensors, UStatus, ua_sensors_proximity_enable, UASensorsProximity*);
IMPLEMENT_FUNCTION1(sensors, UStatus, ua_sensors_proximity_disable, UASensorsProximity*);
IMPLEMENT_FUNCTION1(sensors, uint32_t, ua_sensors_proximity_get_min_delay, UASensorsProximity*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_proximity_get_min_value, UASensorsProximity*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_proximity_get_max_value, UASensorsProximity*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_proximity_get_resolution, UASensorsProximity*, float*);
IMPLEMENT_VOID_FUNCTION3(sensors, ua_sensors_proximity_set_reading_cb, UASensorsProximity*, on_proximity_event_cb, void*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_proximity_set_event_rate, UASensorsProximity*, uint32_t);

// Proximity Sensor Event
IMPLEMENT_FUNCTION1(sensors, uint64_t, uas_proximity_event_get_timestamp, UASProximityEvent*);
IMPLEMENT_FUNCTION1(sensors, UASProximityDistance, uas_proximity_event_get_distance, UASProximityEvent*);

// Ambient Light Sensor
IMPLEMENT_CTOR0(sensors, UASensorsLight*, ua_sensors_light_new);
IMPLEMENT_FUNCTION1(sensors, UStatus, ua_sensors_light_enable, UASensorsLight*);
IMPLEMENT_FUNCTION1(sensors, UStatus, ua_sensors_light_disable, UASensorsLight*);
IMPLEMENT_FUNCTION1(sensors, uint32_t, ua_sensors_light_get_min_delay, UASensorsLight*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_light_get_min_value, UASensorsLight*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_light_get_max_value, UASensorsLight*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_light_get_resolution, UASensorsLight*, float*);
IMPLEMENT_VOID_FUNCTION3(sensors, ua_sensors_light_set_reading_cb, UASensorsLight*, on_light_event_cb, void*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_light_set_event_rate, UASensorsLight*, uint32_t);

// Ambient Light Sensor Event
IMPLEMENT_FUNCTION1(sensors, uint64_t, uas_light_event_get_timestamp, UASLightEvent*);
IMPLEMENT_FUNCTION2(sensors, UStatus, uas_light_event_get_light, UASLightEvent*, float*);

// Haptic Sensor
IMPLEMENT_CTOR0(sensors, UASensorsHaptic*, ua_sensors_haptic_new);
IMPLEMENT_VOID_FUNCTION1(sensors, ua_sensors_haptic_destroy, UASensorsHaptic*);
IMPLEMENT_FUNCTION1(sensors, UStatus, ua_sensors_haptic_enable, UASensorsHaptic*);
IMPLEMENT_FUNCTION1(sensors, UStatus, ua_sensors_haptic_disable, UASensorsHaptic*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_haptic_vibrate_once, UASensorsHaptic*, uint32_t);
IMPLEMENT_FUNCTION3(sensors, UStatus, ua_sensors_haptic_vibrate_with_pattern, UASensorsHaptic*, uint32_t*, uint32_t);

// Orientation Sensor
IMPLEMENT_CTOR0(sensors, UASensorsOrientation*, ua_sensors_orientation_new);
IMPLEMENT_FUNCTION1(sensors, UStatus, ua_sensors_orientation_enable, UASensorsOrientation*);
IMPLEMENT_FUNCTION1(sensors, UStatus, ua_sensors_orientation_disable, UASensorsOrientation*);
IMPLEMENT_FUNCTION1(sensors, uint32_t, ua_sensors_orientation_get_min_delay, UASensorsOrientation*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_orientation_get_min_value, UASensorsOrientation*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_orientation_get_max_value, UASensorsOrientation*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_orientation_get_resolution, UASensorsOrientation*, float*);
IMPLEMENT_VOID_FUNCTION3(sensors, ua_sensors_orientation_set_reading_cb, UASensorsOrientation*, on_orientation_event_cb, void*);
IMPLEMENT_FUNCTION2(sensors, UStatus, ua_sensors_orientation_set_event_rate, UASensorsOrientation*, uint32_t);

// Orientation Sensor Event
IMPLEMENT_FUNCTION1(sensors, uint64_t, uas_orientation_event_get_timestamp, UASOrientationEvent*);
IMPLEMENT_FUNCTION2(sensors, UStatus, uas_orientation_event_get_azimuth, UASOrientationEvent*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, uas_orientation_event_get_pitch, UASOrientationEvent*, float*);
IMPLEMENT_FUNCTION2(sensors, UStatus, uas_orientation_event_get_roll, UASOrientationEvent*, float*);

#ifdef __cplusplus
}
#endif
