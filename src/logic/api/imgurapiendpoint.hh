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
#ifndef IMGURAPIENDPOINT_HH
#define IMGURAPIENDPOINT_HH

#include "imgurapirequest.hh"

namespace noire {

class ImgurApi;
class ImgurResponse;
class ImgurAccount;
class ImgurAccountSettings;
class ImgurAlbum;
class ImgurBasicResponse;
class ImgurComment;
class ImgurConversation;
class ImgurCustomGallery;
class ImgurGalleryAlbum;
class ImgurGalleryImage;
class ImgurGalleryProfile;
class ImgurImage;
class ImgurMemeMetadata;
class ImgurMessage;
class ImgurNotification;
class ImgurTag;
class ImgurTagVote;
class ImgurVote;

class ImgurApiEndpoint
{
public:
    /*!
     * \brief The endpoint's base URL.
     */
    const QString baseURL;
    /*!
     * \brief The Imgur API's base URL.
     */
    constexpr static const char* const API_BASE_URL = "https://api.imgur.com/3";
    /*!
     * \brief The Imgur API's OAuth base URL.
     */
    constexpr static const char* const API_OAUTH_BASE_URL = "https://api.imgur.com/oauth2";
protected:
    ImgurApiEndpoint(const QString& basePath, const QString& baseURL = API_BASE_URL);

    ImgurApiGET GET(const QString& path);
    ImgurApiGET GET(const QString& path, const QUrlQuery& query);

    ImgurApiPUT PUT(const QString& path);
    ImgurApiPUT PUT(const QString& path, const QUrlQuery& query);
    ImgurApiPUT PUT(const QString& path, const QByteArray& data);

    ImgurApiPOST POST(const QString& path);
    ImgurApiPOST POST(const QString& path, const QUrlQuery& query);
    ImgurApiPOST POST(const QString& path, const QByteArray& data);

    ImgurApiDELETE DELETE(const QString& path);
    ImgurApiDELETE DELETE(const QString& path, const QUrlQuery& query);
};

} // namespace noire

#endif // IMGURAPIENDPOINT_HH
