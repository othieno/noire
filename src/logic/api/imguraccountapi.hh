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

    ImgurApiGET    account(const QString& username);
    ImgurApiGET    galleryFavorites(const QString& username);
    ImgurApiGET    galleryFavorites(const QString& username, const int page, const bool getNewestFirst = true);
    ImgurApiGET    favorites(const QString& username);
    ImgurApiGET    submissions(const QString& username);
    ImgurApiGET    submissions(const QString& username, const int page);
    ImgurApiGET    settings(const QString& username);
    ImgurApiPOST   setSettings(const QString& username, const ImgurAccountSettings& settings);
    ImgurApiGET    galleryProfile(const QString& username);
    ImgurApiGET    verifyEmail(const QString& username);
    ImgurApiPOST   sendVerificationEmail(const QString& username);

    ImgurApiGET    albums(const QString& username);
    ImgurApiGET    albums(const QString& username, const int page);
    ImgurApiGET    album(const QString& username, const QString& albumId);
    ImgurApiGET    albumIds(const QString& username);
    ImgurApiGET    albumIds(const QString& username, const int page);
    ImgurApiGET    albumCount(const QString& username);
    ImgurApiDELETE deleteAlbum(const QString& username, const QString& albumId);

    ImgurApiGET    comments(const QString& username, const Sorting& sorting = Sorting::Newest, const int page = 0);
    ImgurApiGET    comment(const QString& username, const QString& commentId);
    ImgurApiGET    commentIds(const QString& username, const Sorting& sorting = Sorting::Newest, const int page = 0);
    ImgurApiGET    commentCount(const QString& username);
    inline int     commentCountPerPage() const { return 50; } // The Imgur API returns 50 comments per page.
    ImgurApiDELETE deleteComment(const QString& username, const QString& commentId);

    ImgurApiGET    images(const QString& username);
    ImgurApiGET    images(const QString& username, const int page);
    ImgurApiGET    image(const QString& username, const QString& imageId);
    ImgurApiGET    imageIds(const QString& username);
    ImgurApiGET    imageIds(const QString& username, const int page);
    ImgurApiGET    imageCount(const QString& username);
    ImgurApiDELETE deleteImage(const QString& username, const QString& deleteHash);

    ImgurApiGET    replies(const QString& username, const bool getViewedReplies = false);
private:
    ImgurAccountApi();
};

} // namespace noire

#endif // IMGURACCOUNTAPI_HH
