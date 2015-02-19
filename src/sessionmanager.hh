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
#ifndef SESSIONMANAGER_HH
#define SESSIONMANAGER_HH

#include <QObject>
#include "session.hh"

class QNetworkAccessManager;
class QNetworkReply;

namespace noire {

class Application;
class Settings;

class SessionManager final : public QObject
{
    Q_OBJECT
    friend class Application;
public:
    void setSession(const Session& session);
    /*!
     * \brief Returns the current session.
     */
    inline const Session& session() const { return session_; }
public slots:
    void authorizePIN(const QString& PIN);
    void authorizeRefreshToken(const QString& token);
private:
    SessionManager(Settings& settings, QNetworkAccessManager& networkAccessManager);

    void onHandleAuthorizationReply(QNetworkReply& reply);

    Settings& settings_;
    QNetworkAccessManager& networkAccessManager_;
    Session session_;
signals:
    void authorizationFailed(const QString& errorMessage);
    void sessionChanged(const Session& session);
};

} // namespace noire

#endif // SESSIONMANAGER_HH
