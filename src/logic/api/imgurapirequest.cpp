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
#include "imgurapirequest.hh"
#include "imgurapi.hh"
#include <QNetworkAccessManager>

using noire::ImgurApiRequest;
using noire::ImgurApiGET;
using noire::ImgurApiPUT;
using noire::ImgurApiPOST;
using noire::ImgurApiDELETE;

/*!
 * \brief Instantiates an ImgurApiRequest object with the given type \a t and \a URL.
 */
ImgurApiRequest::ImgurApiRequest(const Type& t, const QUrl& URL) :
QNetworkRequest(URL),
type(t)
{
    setRawHeader("Authorization", ImgurApi::Authorization.header());
}
/*!
 * \brief Instantiates an ImgurApiGET object with the given \a URL.
 */
ImgurApiGET::ImgurApiGET(const QUrl& URL) :
ImgurApiRequest(Type::GET, URL)
{}
/*!
 * \brief Instantiates an ImgurApiPUT object with the given \a URL and \a data to send.
 */
ImgurApiPUT::ImgurApiPUT(const QUrl& URL, const QByteArray& data) :
ImgurApiRequest(Type::PUT, URL),
data_(data)
{
    setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
}
/*!
 * \brief Instantiates an ImgurApiPOST object with the given \a URL and \a data to send.
 */
ImgurApiPOST::ImgurApiPOST(const QUrl& URL, const QByteArray& data) :
ImgurApiRequest(Type::POST, URL),
data_(data)
{
    setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
}
/*!
 * \brief Instantiates an ImgurApiDELETE object with the given \a URL.
 */
ImgurApiDELETE::ImgurApiDELETE(const QUrl& URL) :
ImgurApiRequest(Type::DELETE, URL)
{}
/*!
 * \brief Returns the request in the form of a URL string.
 */
QString
ImgurApiRequest::toString() const
{
    return url().toString();
}
/*!
 * \brief Sends this HTTP GET request to the API server.
 */
QNetworkReply*
ImgurApiGET::operator()(QNetworkAccessManager& manager) const
{
    return manager.get(*this);
}
/*!
 * \brief Sends this HTTP PUT request to the API server.
 */
QNetworkReply*
ImgurApiPUT::operator()(QNetworkAccessManager& manager) const
{
    return manager.put(*this, data_);
}
/*!
 * \brief Sends this HTTP POST request to the API server.
 */
QNetworkReply*
ImgurApiPOST::operator()(QNetworkAccessManager& manager) const
{
    return manager.post(*this, data_);
}
/*!
 * \brief Sends this HTTP DELETE request to the API server.
 */
QNetworkReply*
ImgurApiDELETE::operator()(QNetworkAccessManager& manager) const
{
    return manager.deleteResource(*this);
}
