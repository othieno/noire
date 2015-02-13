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
#include "session.hh"
#include <QJsonObject>

using noire::Session;

/*!
 * \brief Instantiates an anonymous Session object.
 */
Session::Session() :
type(Session::Type::Anonymous)
{}
/*!
 * \brief Instantiates an Session object from the specified JSON \a object.
 */
Session::Session(const QJsonObject& object) :
Session()
{
    if (Session::isJsonObjectConvertible(object))
    {
        type = Type::Authorized;

        username = object["account_username"].toString();
        identifier = object["account_id"].toInt();

        tokenType = object["token_type"].toString();
        accessToken = object["access_token"].toString();
        refreshToken = object["refresh_token"].toString();

        expirationTime = QTime::currentTime().addSecs(object["expires_in"].toInt());
        scope = object["scope"].toString();
    }
}
/*!
 * \brief Returns true if the JSON \a object can be converted into a Session object, false otherwise.
 */
bool Session::isJsonObjectConvertible(const QJsonObject& object)
{
    return !object.isEmpty()
         && object.contains("access_token")
         && object.contains("expires_in")
         && object.contains("token_type")
         && object.contains("scope")
         && object.contains("refresh_token")
         && object.contains("account_id")
         && object.contains("account_username");
}
