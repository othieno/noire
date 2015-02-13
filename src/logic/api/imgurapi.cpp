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
#include "imgurapi.hh"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QFile>

using noire::ImgurApi;

noire::ImgurAuthorizationApi ImgurApi::Authorization("869bf5c79379dcb");
noire::ImgurAccountApi       ImgurApi::Account;
noire::ImgurAlbumApi         ImgurApi::Album;
noire::ImgurCommentApi       ImgurApi::Comment;
noire::ImgurCustomGalleryApi ImgurApi::CustomGallery;
noire::ImgurGalleryApi       ImgurApi::Gallery;
noire::ImgurImageApi         ImgurApi::Image;
noire::ImgurConversationApi  ImgurApi::Conversation;
noire::ImgurNotificationApi  ImgurApi::Notification;
noire::ImgurMemegenApi       ImgurApi::Memegen;
/*!
 * \brief Sets the network access \a manager used by the API.
 */
void
ImgurApi::setNetworkAccessManager(QNetworkAccessManager& manager)
{
    ImgurApiEndpoint::networkAccessManager_ = &manager;
}
