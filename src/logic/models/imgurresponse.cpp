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
#include "imgurresponse.hh"
#include <QJsonObject>

using noire::ImgurResponse;

/*!
 * \brief Instantiates an ImgurResponse object.
 */
ImgurResponse::ImgurResponse() :
success(false),
status(0)
{}
/*!
 * \brief Constructs an ImgurResponse from the specified JSON \a object.
 */
ImgurResponse::ImgurResponse(const QJsonObject& object) :
success(object["success"].toBool()),
status(object["status"].toInt())
{}
/*!
 * \brief Returns the error message contained in the JSON \a object, or an empty string if none exists.
 * If \a showHttpStatus is set to true, then the HTTP status is appended to the error message.
 * If the response is ill-formed, then an 'Invalid JSON response' message is returned.
 */
QString
ImgurResponse::error(const QJsonObject& object, const bool showHttpStatus)
{
    QString message;

    if (!ImgurResponse::isJsonObjectConvertible(object))
        message = "Incompatible JSON object.";
    else
    {
        const ImgurResponse response(object);
        const auto& data = object["data"].toObject();
        if (!response.success && data.contains("error"))
        {
            message = data["error"].toString().append(".");
            if (showHttpStatus)
                message = QString("(HTTP Status: %1) %2").arg(QString::number(response.status), message);
        }
    }

    return message;
}
/*!
 * \brief Returns true if the JSON \a object can be converted into an ImgurResponse object, false otherwise.
 */
bool
ImgurResponse::isJsonObjectConvertible(const QJsonObject& object)
{
    return !object.isEmpty()
         && object.contains("data")
         && object.contains("success")
         && object.contains("status");
}
