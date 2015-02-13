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
#ifndef IMGURIMAGEAPI_HH
#define IMGURIMAGEAPI_HH

#include "imgurapiendpoint.hh"

namespace noire {

class ImgurImageApi final : public ImgurApiEndpoint
{
    friend class ImgurApi;
public:
    QNetworkReply* image(const QString& imageId);
    QNetworkReply* uploadImageFile(const QString& filename, const QString& albumId = QString(), const QString& title = QString(), const QString& description = QString());
    QNetworkReply* uploadImageURL(const QString& url, const QString& albumId = QString(), const QString& title = QString(), const QString& description = QString());
    QNetworkReply* deleteImage(const QString& imageId);
    QNetworkReply* updateImage(const QString& imageId, const QString& title = QString(), const QString& description = QString());
    QNetworkReply* favorite(const QString& imageId);
private:
    ImgurImageApi();
};

} // namespace noire

#endif // IMGURIMAGEAPI_HH
