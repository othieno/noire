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
#include <QNetworkAccessManager>
#include <QUrlQuery>

using noire::ImgurApiEndpoint;
using noire::ImgurApiGET;
using noire::ImgurApiPUT;
using noire::ImgurApiPOST;
using noire::ImgurApiDELETE;

/*!
 * \brief Instantiates an ImgurApiEndpoint object with the specified base \a path and base \a URL.
 */
ImgurApiEndpoint::ImgurApiEndpoint(const QString& path, const QString& URL) :
baseURL(path.isEmpty() ? URL : QString("%1/%2").arg(URL, path))
{}
/*!
 * \brief Creates an HTTP GET request to the specified \a path.
 */
ImgurApiGET
ImgurApiEndpoint::GET(const QString& path)
{
    return ImgurApiGET(QUrl(QString("%1/%2").arg(baseURL, path)));
}
/*!
 * \brief Creates an HTTP GET request to the specified \a path.
 * Additional \a query parameters may be appended.
 */
ImgurApiGET
ImgurApiEndpoint::GET(const QString& path, const QUrlQuery& query)
{
    QUrl url(QString("%1/%2").arg(baseURL, path));
    url.setQuery(query);

    return ImgurApiGET(url);
}
/*!
 * \brief Creates an HTTP PUT request to the specified \a path.
 */
ImgurApiPUT
ImgurApiEndpoint::PUT(const QString& path)
{
    return PUT(path, QByteArray());
}
/*!
 * \brief Creates an HTTP PUT request to the specified \a path.
 * Additional \a query parameters may be appended.
 */
ImgurApiPUT
ImgurApiEndpoint::PUT(const QString& path, const QUrlQuery& query)
{
    return PUT(path, query.toString(QUrl::FullyEncoded).toUtf8());
}
/*!
 * \brief Creates an HTTP PUT request to the specified \a path, with the \a data to send.
 */
ImgurApiPUT
ImgurApiEndpoint::PUT(const QString& path, const QByteArray& data)
{
    return ImgurApiPUT(QUrl(QString("%1/%2").arg(baseURL, path)), data);
}
/*!
 * \brief Creates an HTTP POST request to the specified \a path.
 */
ImgurApiPOST
ImgurApiEndpoint::POST(const QString& path)
{
    return POST(path, QByteArray());
}
/*!
 * \brief Creates an HTTP POST request to the specified \a path.
 * Additional \a query parameters may be appended.
 */
ImgurApiPOST
ImgurApiEndpoint::POST(const QString& path, const QUrlQuery& query)
{
    return POST(path, query.toString(QUrl::FullyEncoded).toUtf8());
}
/*!
 * \brief Creates an HTTP POST request to the specified \a path, with the \a data to send.
 */
ImgurApiPOST
ImgurApiEndpoint::POST(const QString& path, const QByteArray& data)
{
    return ImgurApiPOST(QUrl(QString("%1/%2").arg(baseURL, path)), data);
}
/*!
 * \brief Makes an HTTP DELETE request to the specified \a path.
 */
ImgurApiDELETE
ImgurApiEndpoint::DELETE(const QString& path)
{
    return ImgurApiDELETE(QUrl(QString("%1/%2").arg(baseURL, path)));
}
/*!
 * \brief Makes an HTTP DELETE request to the specified \a path.
 * Additional \a query parameters may be appended to the request.
 */
ImgurApiDELETE
ImgurApiEndpoint::DELETE(const QString& path, const QUrlQuery& query)
{
    QUrl url(QString("%1/%2").arg(baseURL, path));
    url.setQuery(query);

    return ImgurApiDELETE(url);
}
