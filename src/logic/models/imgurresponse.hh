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
#ifndef IMGURRESPONSE_HH
#define IMGURRESPONSE_HH

#include <QString>

class QJsonObject;

namespace noire {

struct ImgurResponse
{
    static QString error(const QJsonObject& object, const bool showHttpStatusCode = false);
    static bool isJsonObjectConvertible(const QJsonObject& object);
    /*!
     * \brief The response's HTTP request success flag.
     * It is set to true if the request was successful, false otherwise.
     */
    const bool success;
    /*!
     * \brief The response's HTTP status code.
     */
    const bool status;
protected:
    ImgurResponse();
    explicit ImgurResponse(const QJsonObject& jsonObject);
};

} // namespace noire

#endif // IMGURRESPONSE_HH
