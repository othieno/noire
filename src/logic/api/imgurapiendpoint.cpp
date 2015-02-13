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
#include "imgurapiendpoint.hh"
#include "imgurapi.hh"
#include <QNetworkAccessManager>

using noire::ImgurApiEndpoint;

// This value is assigned in the noire::Application constructor.
QNetworkAccessManager* ImgurApiEndpoint::networkAccessManager_ = nullptr;

/*!
 * \brief Instantiates an ImgurAccountApi object with the specified base \a URL.
 */
ImgurApiEndpoint::ImgurApiEndpoint(const QString& URL) :
baseURL_(URL)
{}
/*!
 * \brief Makes an HTTP GET request to the specified \a path.
 */
QNetworkReply*
ImgurApiEndpoint::GET(const QString& path)
{
    QNetworkReply* reply = nullptr;
    if (!path.isEmpty() && networkAccessManager_ != nullptr)
        reply = networkAccessManager_->get(createApiRequest(path));

    return reply;
}
/*!
 * \brief Makes an HTTP POST request to the specified \a path.
 * Additional \a parameters may be appended to the request.
 */
QNetworkReply*
ImgurApiEndpoint::POST(const QString& path, const QByteArray& parameters)
{
    QNetworkReply* reply = nullptr;
    if (!path.isEmpty() && networkAccessManager_ != nullptr)
    {
        auto request = createApiRequest(path);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        reply = networkAccessManager_->post(request, parameters);
    }
    return reply;
}
/*!
 * \brief Makes an HTTP DELETE request to the specified \a path.
 */
QNetworkReply*
ImgurApiEndpoint::DELETE(const QString& path)
{
    QNetworkReply* reply = nullptr;
    if (!path.isEmpty() && networkAccessManager_ != nullptr)
        reply = networkAccessManager_->deleteResource(createApiRequest(path));

    return reply;
}
/*!
 * \brief Constructs a correctly-formed HTTP request to the specified \a path.
 */
QNetworkRequest
ImgurApiEndpoint::createApiRequest(const QString& path) const
{
    QNetworkRequest request(QUrl(QString("%1/%2").arg(baseURL_, path)));
    request.setRawHeader("Authorization", ImgurApi::Authorization.header());

    return request;
}
