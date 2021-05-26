/*  =========================================================================
    restapi_helpers - Helpers

    Copyright (C) 2018 - 2020 Eaton

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
    =========================================================================
*/

#include "helpers_security_wallet_rest.h"
#include <sstream>
#include <assert.h>

namespace restapi
{
    Path::Path(const std::string & pathStr)
        : m_pathStr(pathStr)
    {
        std::stringstream stream;
        stream << m_pathStr.substr (0, m_pathStr.find ("?"));

        std::string item;
        while(std::getline(stream, item, '/'))
        {
            if(!item.empty())
            {
                m_items.push_back(item);
            }
        }
    }

    const std::string & Path::getPathStr() const
    {
        return m_pathStr;
    }
    const std::string & Path::getItem(size_t index) const
    {
        return m_items.at(index);
    }

    std::size_t Path::getNumberOfItem() const
    {
        return m_items.size();
    }
}

void helpers_security_wallet_rest_test(bool /*verbose*/)
{
    using namespace restapi;

    {
        Path path0("");
        assert(path0.getNumberOfItem() == 0);

        Path path1("0");
        assert(path1.getNumberOfItem() == 1);

        Path path2("0?");
        assert(path2.getNumberOfItem() == 1);

        Path path3("0?a");
        assert(path3.getNumberOfItem() == 1);
    }

    {
        const std::string input{"0/1/2/3/4/5?abcd"};
        Path path{input};
        assert(path.getPathStr() == input);
        assert(path.getNumberOfItem() == 6);
        for (std::size_t i = 0; i < path.getNumberOfItem(); ++i) {
            assert(path.getItem(i) == std::to_string(i));
        }
    }
}
