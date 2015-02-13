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

#include <QString>
#include <QNetworkRequest>

class QNetworkAccessManager;
class QNetworkReply;

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
    friend class ImgurApi;
    /*!
     * \brief Returns the API endpoint's base URL.
     */
    inline const QString& baseURL() const { return baseURL_; }
protected:
    explicit ImgurApiEndpoint(const QString& baseUrl);

    QNetworkReply* GET(const QString& path);
    QNetworkReply* POST(const QString& path, const QByteArray& parameters);
    QNetworkReply* DELETE(const QString& path);
    /*!
     * \brief Returns the Imgur API's base URL.
     */
    inline static QString apiBaseURL(){ return "https://api.imgur.com/3"; }
    /*!
     * \brief Returns the Imgur API's OAuth base URL.
     */
    inline static QString oAuthBaseURL() { return "https://api.imgur.com/oauth2"; }
private:
    QNetworkRequest createApiRequest(const QString& path) const;
    /*!
     * \brief The endpoint's base URL.
     */
    const QString baseURL_;
    /*!
     * \brief The network access manager.
     */
    static QNetworkAccessManager* networkAccessManager_;
};

} // namespace noire

#endif // IMGURAPIENDPOINT_HH
