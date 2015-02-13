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
#include "imguraccount.hh"
#include <QJsonObject>

using noire::ImgurAccount;

/*!
 * \brief Instantiates an ImgurAccount object.
 */
ImgurAccount::ImgurAccount() :
identifier(0),
reputation(0),
isProUser(false)
{}
/*!
 * \brief Instantiates an ImgurAccount object.
 */
ImgurAccount::ImgurAccount(const QJsonObject& object) :
identifier(object["id"].toInt()),
url(object["url"].toString()),
bio(object["bio"].toString()),
reputation(object["reputation"].toDouble()),
creationDate(QDateTime::fromMSecsSinceEpoch(object["created"].toInt())),
isProUser(!object["pro_expiration"].isBool()), // If 'pro_expiration' is a boolean, it's always set to false.
proExpirationDate(!isProUser ? creationDate : QDateTime::fromMSecsSinceEpoch(object["pro_expiration"].toInt()))
{}
