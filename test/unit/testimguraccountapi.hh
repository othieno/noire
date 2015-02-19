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
#ifndef TESTIMGURACCOUNTAPI_HH
#define TESTIMGURACCOUNTAPI_HH

#include "test.hh"
#include <QNetworkAccessManager>

namespace noire {

class TestImgurAccountApi : public Test
{
    Q_OBJECT
public:
    explicit TestImgurAccountApi(TestSuite& suite);
private slots:
    void testRequestURLs_data();
    void testRequestURLs();
};

} // namespace noire

#endif // TESTIMGURACCOUNTAPI_HH
