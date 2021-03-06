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
#ifndef IMGURCOMMENTAPI_HH
#define IMGURCOMMENTAPI_HH

#include "imgurapiendpoint.hh"

namespace noire {

class ImgurCommentApi final : public ImgurApiEndpoint
{
    friend class ImgurApi;
public:
    enum class Vote
    {
        Up,
        Down
    };

    ImgurApiGET    comment(const QString& commentId);
    ImgurApiPOST   createComment(const QString& imageId, const QString& comment);
    ImgurApiPOST   createComment(const QString& imageId, const QString& comment, const QString& parentId);
    ImgurApiDELETE deleteComment(const QString& commentId);
    ImgurApiGET    replies(const QString& commentId);
    ImgurApiPOST   reply(const QString& commentId, const QString& imageId, const QString& comment);
    ImgurApiPOST   vote(const QString& commentId, const Vote& vote);
    ImgurApiPOST   report(const QString& commentId);
private:
    ImgurCommentApi();
};

} // namespace noire

#endif // IMGURCOMMENTAPI_HH
