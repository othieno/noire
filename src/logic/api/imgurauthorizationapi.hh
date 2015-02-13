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
#ifndef IMGURAUTHORIZATIONAPI_HH
#define IMGURAUTHORIZATIONAPI_HH

#include "imgurapiendpoint.hh"

namespace noire {

class ImgurAuthorizationApi final : public ImgurApiEndpoint
{
    friend class ImgurApi;
public:
    QNetworkReply* authorizePIN(const QString& PIN);
    QNetworkReply* authorizeRefreshToken(const QString& token);

    QString accessToken() const;
    void setAccessToken(const QString& accessToken);
    /*!
     * \brief Returns the current authorization header.
     */
    inline const QByteArray& header() const { return authorizationHeader_; }
    /*!
     * \brief Returns the client secret.
     */
    inline const QString& clientSecret() const { return clientSecret_; }
    /*!
     * \brief Sets the client \a secret.
     */
    inline void setClientSecret(const QString& secret){ clientSecret_ = secret; }
    /*!
     * \brief The maximum number of characters in a client identifier.
     */
    constexpr static int CLIENT_ID_MAXLENGTH = 32;        // 32 is a random value (that's less than INF).
    /*!
     * \brief The maximum number of characters in a client secret.
     */
    constexpr static int CLIENT_SECRET_MAXLENGTH = 256;    // 256 is a random value (that's less than INF).
private:
    explicit ImgurAuthorizationApi(const QString& clientId);

    QNetworkReply* authorize(const QString& key, const QString& grantType);

    const QString clientId_;
    QString clientSecret_;
    QByteArray authorizationHeader_;
};

} // namespace noire

#endif // IMGURAUTHORIZATIONAPI_HH
