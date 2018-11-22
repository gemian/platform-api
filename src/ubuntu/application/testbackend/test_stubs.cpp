/*
 * Copyright (C) 2014 Canonical Ltd
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
 * Authored by: Ricardo Mendoza <ricardo.mendoza@canonical.com>
 */

#include <ubuntu/application/lifecycle_delegate.h>
#include <ubuntu/application/id.h>
#include <ubuntu/application/description.h>
#include <ubuntu/application/instance.h>
#include <ubuntu/application/options.h>
#include <ubuntu/application/sensors/haptic.h>

#include <ubuntu/application/init.h>

// Application Module Config
void u_application_init(void*)
{
}

void u_application_finish()
{
}

// Lifecycle helpers
UApplicationLifecycleDelegate* u_application_lifecycle_delegate_new()
{
    return NULL;
}

void u_application_lifecycle_delegate_set_context (UApplicationLifecycleDelegate*, void*)
{
}

void u_application_lifecycle_delegate_ref (UApplicationLifecycleDelegate*)
{
}

void u_application_lifecycle_delegate_unref (UApplicationLifecycleDelegate*)
{
}

void u_application_lifecycle_delegate_set_application_resumed_cb (UApplicationLifecycleDelegate*, u_on_application_resumed)
{
}

void u_application_lifecycle_delegate_set_application_about_to_stop_cb (UApplicationLifecycleDelegate*, u_on_application_about_to_stop)
{
}

// Application Helpers

// UApplicationId
UApplicationId* u_application_id_new_from_stringn(const char*, size_t)
{
    return NULL;
}

void u_application_id_destroy(UApplicationId*)
{
}

int u_application_id_compare(UApplicationId*, UApplicationId*)
{
}

// UApplicationDescription
UApplicationDescription* u_application_description_new()
{
    return NULL;
}

void u_application_description_destroy (UApplicationDescription*)
{
}

void u_application_description_set_application_id (UApplicationDescription*, UApplicationId*)
{
}

void u_application_description_set_application_lifecycle_delegate (UApplicationDescription*, UApplicationLifecycleDelegate*)
{
}

// UApplicationOptions
UApplicationOptions* u_application_options_new_from_cmd_line(int, char**)
{
    return NULL;
}

void u_application_options_destroy(UApplicationOptions*)
{
}

// UApplicationInstance
UApplicationInstance* u_application_instance_new_from_description_with_options(UApplicationDescription*, UApplicationOptions*)
{
    return NULL;
}

// Sensors
UASensorsHaptic* ua_sensors_haptic_new()
{
    return NULL;
}

// Sensors
void ua_sensors_haptic_destroy(UASensorsHaptic*)
{
}

UStatus ua_sensors_haptic_enable(UASensorsHaptic*)
{
    return U_STATUS_ERROR;
}

UStatus ua_sensors_haptic_disable(UASensorsHaptic*)
{
    return U_STATUS_ERROR;
}

UStatus ua_sensors_haptic_vibrate_once(UASensorsHaptic*, uint32_t)
{
    return U_STATUS_ERROR;
}

UStatus ua_sensors_haptic_vibrate_with_pattern(UASensorsHaptic*, uint32_t*, uint32_t)
{
    return U_STATUS_ERROR;
}
