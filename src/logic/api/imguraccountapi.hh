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
#ifndef IMGURACCOUNTAPI_HH
#define IMGURACCOUNTAPI_HH

#include "imgurapiendpoint.hh"

namespace noire {

/*!
 * \brief The ImgurAccountApi class implements the Account Imgur API endpoint.
 */
class ImgurAccountApi final : public ImgurApiEndpoint
{
    friend class ImgurApi;
public:
    /*!
     * \brief An enumeration of all possible ways of sorting comments.
     */
    enum class Sorting
    {
        Best,
        Worst,
        Oldest,
        Newest
    };

    QNetworkReply* account(const QString& username);
    QNetworkReply* galleryFavorites(const QString& username);
    QNetworkReply* galleryFavorites(const QString& username, const int page, const bool getNewestFirst = true);
    QNetworkReply* favorites(const QString& username);
    QNetworkReply* submissions(const QString& username);
    QNetworkReply* submissions(const QString& username, const int page);
    QNetworkReply* settings(const QString& username);
    QNetworkReply* changeSettings(const QString& username, const ImgurAccountSettings& settings);
    QNetworkReply* galleryProfile(const QString& username);
    QNetworkReply* verifyEmail(const QString& username);
    QNetworkReply* sendVerificationEmail(const QString& username);

    QNetworkReply* albums(const QString& username);
    QNetworkReply* albums(const QString& username, const int page);
    QNetworkReply* album(const QString& username, const QString& albumId);
    QNetworkReply* albumIds(const QString& username);
    QNetworkReply* albumIds(const QString& username, const int page);
    QNetworkReply* albumCount(const QString& username);
    QNetworkReply* deleteAlbum(const QString& username, const QString& albumId);

    QNetworkReply* comments(const QString& username, const Sorting& sorting = Sorting::Newest, const int page = 0);
    QNetworkReply* comment(const QString& username, const QString& commentId);
    QNetworkReply* commentIds(const QString& username, const Sorting& sorting = Sorting::Newest, const int page = 0);
    QNetworkReply* commentCount(const QString& username);
    inline int     commentCountPerPage() const { return 50; } // The Imgur API returns 50 comments per page.
    QNetworkReply* deleteComment(const QString& username, const QString& commentId);

    QNetworkReply* images(const QString& username);
    QNetworkReply* images(const QString& username, const int page);
    QNetworkReply* image(const QString& username, const QString& imageId);
    QNetworkReply* imageIds(const QString& username);
    QNetworkReply* imageIds(const QString& username, const int page);
    QNetworkReply* imageCount(const QString& username);
    QNetworkReply* deleteImage(const QString& username, const QString& deleteHash);

    QNetworkReply* replies(const QString& username, const bool getViewedReplies = false);
private:
    ImgurAccountApi();
};

} // namespace noire

#endif // IMGURACCOUNTAPI_HH
