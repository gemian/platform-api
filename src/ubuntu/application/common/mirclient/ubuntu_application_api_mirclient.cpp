/*
 * Copyright (C) 2013 Canonical Ltd
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
 * Authored by: Robert Carr <robert.carr@canonical.com>
 */

#include <ubuntu/application/lifecycle_delegate.h>
#include <ubuntu/application/sensors/accelerometer.h>
#include <ubuntu/application/sensors/proximity.h>
#include <ubuntu/application/sensors/light.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

namespace
{

typedef struct MirConnection MirConnection;
typedef int MirLifecycleState;
typedef void UApplicationInstance;
typedef void UApplicationDescription;

static void dispatch_callback(MirConnection* conn, MirLifecycleState state, void* context)
{
	printf("ubuntu_application_api_mirclient - dispatch_callback - state: %d",state);
}
};

extern "C"
{

void u_application_init(void *args)
{
    (void) args;
}

void u_application_finish()
{
}

UApplicationInstance* u_application_instance_new_from_description_with_options(UApplicationDescription* description, UApplicationOptions* options)
{
    printf("ubuntu_application_api_mirclient - u_application_instance_new_from_description_with_options");

    return nullptr;
}

void
u_application_instance_ref(UApplicationInstance *u_instance)
{
    printf("ubuntu_application_api_mirclient - u_application_instance_ref");
}

void
u_application_instance_unref(UApplicationInstance *u_instance)
{
    printf("ubuntu_application_api_mirclient - u_application_instance_unref");
}

void
u_application_instance_destroy(UApplicationInstance *u_instance)
{
    printf("ubuntu_application_api_mirclient - u_application_instance_destroy");
}

void
u_application_instance_run(UApplicationInstance *instance)
{
    printf("ubuntu_application_api_mirclient - u_application_instance_run");
}

MirConnection*
u_application_instance_get_mir_connection(UApplicationInstance *u_instance)
{
    printf("ubuntu_application_api_mirclient - u_application_instance_get_mir_connection");

    return nullptr;
}

}
