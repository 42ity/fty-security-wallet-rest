/*
    Copyright (C) 2014 - 2018 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#ifndef FTY_SCRIPTS_REST_HELPERS_H
#define FTY_SCRIPTS_REST_HELPERS_H

#include <stdexcept>
#include <string>
#include <vector>
#include <cxxtools/serializationinfo.h>

void operator>>=(const cxxtools::SerializationInfo &si, std::vector<std::string> &out);

const std::string SCRIPT_FILENAME_REGEX = "^[a-zA-Z0-9][a-zA-Z0-9_.-]{0,254}$";
const std::string SCRIPT_DIRECTORY = "/var/lib/fty/fty-scripts-rest/";

const int SCRIPT_FILE_MAX_SIZE = 64*1024;
const int SCRIPT_MAX_FILES = 256;

#endif
