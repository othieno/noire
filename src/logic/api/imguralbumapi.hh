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
#ifndef IMGURALBUMAPI_HH
#define IMGURALBUMAPI_HH

#include "imgurapiendpoint.hh"

namespace noire {

class ImgurAlbumApi final : public ImgurApiEndpoint
{
    friend class ImgurApi;
public:
    QNetworkReply* album(const QString& albumId);

    QNetworkReply* images(const QString& albumId);
    QNetworkReply* image(const QString& albumId, const QString& imageId);

    QNetworkReply* createAlbum(const ImgurAlbum& album);
    QNetworkReply* updateAlbum(const QString& albumId, const ImgurAlbum& album);
    QNetworkReply* deleteAlbum(const QString& albumId);

    QNetworkReply* favorite(const QString& albumId);

    QNetworkReply* setImages(const QString& albumId, const QStringList& imageIds);
    QNetworkReply* addImages(const QString& albumId, const QStringList& imageIds);
    QNetworkReply* deleteImages(const QString& albumId, const QStringList& imageIds);
private:
    ImgurAlbumApi();
};

} // namespace noire

#endif // IMGURALBUMAPI_HH
