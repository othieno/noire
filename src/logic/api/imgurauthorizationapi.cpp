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
#include "imgurauthorizationapi.hh"
#include <QNetworkRequest>
#include <QUrlQuery>

using noire::ImgurAuthorizationApi;
using noire::ImgurApiPOST;

/*!
 * \brief Instantiates an ImgurAuthorizationApi object with the client \a identifier.
 */
ImgurAuthorizationApi::ImgurAuthorizationApi(const QString& identifier) :
ImgurApiEndpoint(QString(), API_OAUTH_BASE_URL),
clientId_(identifier),
authorizationHeader_(QString("Client-ID %1").arg(clientId_).toUtf8())
{}
/*!
 * \brief Authorizes the \a code.
 */
ImgurApiPOST
ImgurAuthorizationApi::authorizeCode(const QString& code)
{
    return authorize(code, "authorization_code");
}
/*!
 * \brief Authorizes the \a PIN.
 */
ImgurApiPOST
ImgurAuthorizationApi::authorizePIN(const QString& PIN)
{
    return authorize(PIN, "pin");
}
/*!
 * \brief Authorizes the refresh \a token.
 */
ImgurApiPOST
ImgurAuthorizationApi::authorizeRefreshToken(const QString& token)
{
    return authorize(token, "refresh_token");
}
/*!
 * \brief Authorizes the \a key of the specified grant \a type.
 */
ImgurApiPOST
ImgurAuthorizationApi::authorize(const QString& key, const QString& type)
{
    QUrlQuery query;
    query.setQueryItems
    ({
        {"client_id", clientId_},
        {"client_secret", clientSecret_},
        {"grant_type", type},
        {type == "authorization_code" ? "code" : type, key},
    });

    return POST("token", query);
}
/*!
 * \brief Returns the current access token.
 * The current access token is retrieved from the authorization header if it was previously set.
 */
QString
ImgurAuthorizationApi::accessToken() const
{
    return QString::compare("Bearer", authorizationHeader_.left(6)) != 0 ?
           QString() :
           QString(authorizationHeader_.right(authorizationHeader_.length() - (6 + 1))); //+1 for the space between 'Bearer' and the token.
}
/*!
 * \brief Sets the access \a token and updates the authorization header.
 */
void
ImgurAuthorizationApi::setAccessToken(const QString& token)
{
    authorizationHeader_ = token.isEmpty() ?
                           QString("Client-ID %1").arg(clientId_).toUtf8() :
                           QString("Bearer %1").arg(token).toUtf8();
}
