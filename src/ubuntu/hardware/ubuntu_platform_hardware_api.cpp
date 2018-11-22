/*
 * Copyright (C) 2012 Canonical Ltd
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
#include <ubuntu/hardware/alarm.h>
#include <ubuntu/hardware/booster.h>

#include "android_hw_module.h"

IMPLEMENT_OPTIONAL_FUNCTION0(
    UHardwareBooster*,
    u_hardware_booster_new,
    NULL);

IMPLEMENT_OPTIONAL_VOID_FUNCTION1(
    u_hardware_booster_ref,
    UHardwareBooster*);

IMPLEMENT_OPTIONAL_VOID_FUNCTION1(
    u_hardware_booster_unref,
    UHardwareBooster*);

IMPLEMENT_OPTIONAL_VOID_FUNCTION2(
    u_hardware_booster_enable_scenario,
    UHardwareBooster*,
    UHardwareBoosterScenario);

IMPLEMENT_OPTIONAL_VOID_FUNCTION2(
    u_hardware_booster_disable_scenario,
    UHardwareBooster*,
    UHardwareBoosterScenario);
