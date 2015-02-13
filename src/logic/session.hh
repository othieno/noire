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
#ifndef SESSION_HH
#define SESSION_HH

#include <QString>
#include <QTime>

class QJsonObject;

namespace noire {

class SessionManager;

struct Session
{
    friend class SessionManager;

    enum class Type
    {
        Anonymous,
        Authorized
    };

    static bool isJsonObjectConvertible(const QJsonObject& object);

    Type type;

    QString username;
    unsigned int identifier;

    QString tokenType;
    QString accessToken;
    QString refreshToken;

    QTime expirationTime;
    QString scope;
private:
    Session();
    explicit Session(const QJsonObject& object);
};

} // namespace noire

#endif // SESSION_HH
