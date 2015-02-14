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
#include "imgurimageapi.hh"

using noire::ImgurImageApi;

/*!
 * \brief Instantiates an ImgurImageApi object.
 */
ImgurImageApi::ImgurImageApi() :
ImgurApiEndpoint("image")
{}
#ifdef FIXME
/*!
 * \brief Requests information about the image with the specified identifier \a id.
 */
QNetworkReply*
ImgurApi::image(const QString& id)
{
    return id.isEmpty() ? nullptr : httpRequest(QString("image/%1").arg(id));
}
/*!
 * \brief Updates the \a title and \a description of the image with the specified identifier \a id.
 */
QNetworkReply*
ImgurApi::setImage(const QString& id, const QString& title, const QString& description)
{
    QNetworkReply* reply = nullptr;
    if (!id.isEmpty())
    {
        QUrlQuery query;
        query.setQueryItems
        ({
            {"title", title},
            {"description", description}
        });

        reply = httpRequest(QString("image/%1").arg(id), RequestType::POST, query.toString(QUrl::FullyEncoded).toUtf8());
    }
    return reply;
}

/*!
 * \brief Uploads the image with the specified file \a name.
 */
QNetworkReply*
ImgurApi::uploadImageFile(const QString& name)
{
    qFatal("ImgurApi::uploadImage not implemented.");

    QNetworkReply* reply = nullptr;
    QFile file(name);
    if (file.open(QIODevice::ReadOnly))
    {
        //TODO Make sure the file size is less than or equal to 10MB.
//        file.size()
//        const auto& data = file.readAll().toBase64();


    /*
        data.setAttribute("image", file.readAll().toBase64());

        QNetworkRequest request(QUrl("http://api.imgur.com/2/upload"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    */

    }
    else
        qWarning("[ImgurApi::uploadImage] WARN: Could not open '%s'.", qPrintable(name));

    return reply;
}
/*!
 * \brief Deletes the image with the specified identifier \a id.
 * In the case of an anonymous upload, \a id should be the image's delete hash.
 */
QNetworkReply*
ImgurApi::deleteImage(const QString& id)
{
    qFatal("ImgurApi::deleteImage not implemented.");
    Q_UNUSED(id);
    return nullptr;
//    return deleteResource(createRequest(QString("image/%1").arg(id)));
}
#endif
