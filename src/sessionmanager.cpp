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
#include "sessionmanager.hh"
#include "settings.hh"
#include "imgurapi.hh"
#include "imgurresponse.hh"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

using noire::SessionManager;

/*!
 * \brief Instantiates a SessionManager object that references the application \a settings and network access \a manager.
 */
SessionManager::SessionManager(Settings& settings, QNetworkAccessManager& manager) :
settings_(settings),
networkAccessManager_(manager)
{}
/*!
 * \brief Sets a new \a session.
 */
void
SessionManager::setSession(const Session& session)
{
    session_ = session;
    emit sessionChanged(session_);

    // Save the refresh token for later use.
    if (settings_.isRefreshTokenStorageEnabled())
        settings_.setRefreshToken(session_.refreshToken);
}
/*!
 * \brief Authorizes a user with the specified \a PIN code.
 */
void
SessionManager::authorizePIN(const QString& PIN)
{
    auto* const reply = ImgurApi::Authorization.authorizePIN(PIN)(networkAccessManager_);
    if (reply != nullptr)
        onHandleAuthorizationReply(*reply);
}
/*!
 * \brief Refreshes the access token using the specified refresh \a token.
 */
void
SessionManager::authorizeRefreshToken(const QString& token)
{
    auto* const reply = ImgurApi::Authorization.authorizeRefreshToken(token)(networkAccessManager_);
    if (reply != nullptr)
        onHandleAuthorizationReply(*reply);
}
/*!
 * \brief Extracts and stores a Session object from a valid authorization response.
 */
void
SessionManager::onHandleAuthorizationReply(QNetworkReply& reply)
{
    connect(&reply, &QNetworkReply::finished, [this, &reply]()
    {
        const auto& document = QJsonDocument::fromJson(reply.readAll());
        if (!document.isEmpty())
        {
            const auto& object = document.object();
            if (Session::isJsonObjectConvertible(object))
                setSession(Session(object));
            else
                emit authorizationFailed(ImgurResponse::error(object));
        }
        else
            emit authorizationFailed("Empty JSON response.");

        reply.close();
        reply.deleteLater();
    });
}
