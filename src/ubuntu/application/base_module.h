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
#ifndef BASE_MODULE_H_
#define BASE_MODULE_H_

#include <bridge.h>
#include <stdio.h>
#include <unistd.h>

/*
 * This is the base backend loader for the Platform API
 */

#define API_VERSION_MAJOR   "3"
#define API_VERSION_MINOR   "0"
#define API_VERSION_PATCH   "0"
#define SO_SUFFIX ".so." API_VERSION_MAJOR "." API_VERSION_MINOR "." API_VERSION_PATCH
#define PLATFORM_MODULE "touch_mirclient"

namespace internal
{
/* Programs can select a backend with $UBUNTU_PLATFORM_API_BACKEND,
 * which either needs to be a full path or just the file name (then it will be
 * looked up in the usual library search path, see dlopen(3)).
 */
struct HIDDEN_SYMBOL ToBackend
{
    static const char* path()
    {
        static char* cache = NULL;
        static char path[64];

        if (cache == NULL) {
            cache = secure_getenv("UBUNTU_PLATFORM_API_BACKEND");
            if (cache == NULL) {
			    cache = PLATFORM_MODULE;
            }
            strcpy(path, "libubuntu_application_api_");

            if (strlen(cache) > MAX_MODULE_NAME)
                exit_module("Selected module is invalid");

            strcat(path, cache);
            strcat(path, SO_SUFFIX);

            fprintf(stderr, "Loading module: '%s'\n", path);
        }

        return path;
    }
    
    static const char* override_path()
    {
        // Hardcoded for the testbackend
        const char *testlib = "test";
        static char path[64];

        strcpy(path, "libubuntu_application_api_");
        strcat(path, testlib);
        strcat(path, SO_SUFFIX);

        return path;
    }

    static void exit_module(const char* msg)
    {
        fprintf(stderr, "Ubuntu Platform API: %s -- Aborting\n", msg);
        abort();
    }

    static void* dlopen_fn(const char* path, int flags)
    {
        // We take a NULL path as an indication that we are running with a
        // null backend.
        if (not path)
            return NULL;

        void *handle = dlopen(path, flags);
        if (handle == NULL) {
            fprintf(stderr, "Unable to load selected module, using dummy.\n");
            fprintf(stderr, "Loading module: '%s'\n", override_path());
            handle = dlopen(override_path(), flags);
            if (handle == NULL)
                exit_module("Dummy module failed to load.");
        }

        return handle;
    }

    static void* dlsym_fn(void* handle, const char* symbol)
    {
        if (not handle)
            return NULL;
        return dlsym(handle, symbol);
    }
};
}

#define DLSYM(fptr, sym, module) if (*(fptr) == NULL) { *((void**)fptr) = (void *) internal::Bridge<internal::ToBackend>::instance().resolve_symbol(sym, module); }

#include <bridge_defs.h>

#endif // BASE_MODULE_H_
