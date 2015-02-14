/*
 * Noire, an Imgur desktop client.
 * Copyright (c) 2015 Jeremy Othieno.
 *
 * This file is part of Noire.
 *
 * Noire is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * Noire is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with Noire.
 * If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TESTIMGURAPI_HH
#define TESTIMGURAPI_HH

#include "test.hh"

namespace noire {

class TestImgurApi : public Test
{
    Q_OBJECT
public:
    explicit TestImgurApi(TestSuite& suite);
private slots:
    void testEndpointBaseURLs();
};

} // namespace noire

#endif // TESTIMGURAPI_HH
