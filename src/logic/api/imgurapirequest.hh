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
#ifndef IMGURAPIREQUEST_HH
#define IMGURAPIREQUEST_HH

#include <QNetworkRequest>

class QNetworkReply;
class QNetworkAccessManager;

namespace noire {

class ImgurApiRequest : public QNetworkRequest
{
public:
    /*!
     * \brief An enumeration of possible HTTP requests that can be made to the Imgur API server.
     */
    enum class Type
    {
        GET,
        PUT,
        POST,
        DELETE
    };

    QString toString() const;
    virtual QNetworkReply* operator()(QNetworkAccessManager& manager) const = 0;
    /*!
     * \brief The HTTP request type.
     */
    const Type type;
protected:
    ImgurApiRequest(const Type& type, const QUrl& url);
};
/*!
 * \brief The ImgurApiGET class encapsulates an HTTP GET request to the Imgur API server.
 */
class ImgurApiGET final : public ImgurApiRequest
{
public:
    explicit ImgurApiGET(const QUrl& url);

    QNetworkReply* operator()(QNetworkAccessManager& manager) const override;
};
/*!
 * \brief The ImgurApiPUT class encapsulates an HTTP PUT request to the Imgur API server.
 */
class ImgurApiPUT final : public ImgurApiRequest
{
public:
    ImgurApiPUT(const QUrl& url, const QByteArray& data);

    QNetworkReply* operator()(QNetworkAccessManager& manager) const override;
private:
    /*!
     * \brief The data to put.
     */
    const QByteArray data_;
};
/*!
 * \brief The ImgurApiPOST class encapsulates an HTTP POST request to the Imgur API server.
 */
class ImgurApiPOST final : public ImgurApiRequest
{
public:
    ImgurApiPOST(const QUrl& url, const QByteArray& data);

    QNetworkReply* operator()(QNetworkAccessManager& manager) const override;
private:
    /*!
     * \brief The data to post.
     */
    const QByteArray data_;
};
/*!
 * \brief The ImgurApiDELETE class encapsulates an HTTP DELETE request to the Imgur API server.
 */
class ImgurApiDELETE final : public ImgurApiRequest
{
public:
    explicit ImgurApiDELETE(const QUrl& url);

    QNetworkReply* operator()(QNetworkAccessManager& manager) const override;
};

} // namespace noire

#endif // IMGURAPIREQUEST_HH
