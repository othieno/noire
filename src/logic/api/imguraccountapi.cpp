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
#include "imguraccountapi.hh"
#include <QUrlQuery>

using noire::ImgurAccountApi;
using noire::ImgurApiGET;
using noire::ImgurApiPOST;

/*!
 * \brief Instantiates an ImgurAccountApi object.
 */
ImgurAccountApi::ImgurAccountApi() :
ImgurApiEndpoint("account")
{}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiGET
ImgurAccountApi::account(const QString& username)
{
    return GET(username);
}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiGET
ImgurAccountApi::galleryFavorites(const QString& username)
{
    return GET(QString("%1/gallery_favorites").arg(username));
}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiGET
ImgurAccountApi::galleryFavorites(const QString& username, const int page, const bool newestFirst)
{
    return GET(QString("%1/gallery_favorites/%2/%3").arg(username, QString::number(page), newestFirst ? "newest" : "oldest"));
}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiGET
ImgurAccountApi::favorites(const QString& username)
{
    return GET(QString("%1/favorites").arg(username));
}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiGET
ImgurAccountApi::submissions(const QString& username)
{
    return GET(QString("%1/submissions").arg(username));
}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiGET
ImgurAccountApi::submissions(const QString& username, const int page)
{
    return GET(QString("%1/submissions/%2").arg(username, QString::number(page)));
}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiGET
ImgurAccountApi::settings(const QString& username)
{
    return GET(QString("%1/settings").arg(username));
}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiPOST
ImgurAccountApi::setSettings(const QString& username, const ImgurAccountSettings& settings)
{
    Q_UNUSED(settings);
    qCritical("[ImgurAccountApi::setSettings] CRITICAL: Unimplemented member function.");
/*
    QUrlQuery query;
    query.setQueryItems(
    {
        {"bio","???"},
        {"public_images","???"},
        {"messaging_enabled","???"},
        {"album_privacy","???"},
        {"accepted_gallery_terms","???"},
        {"username","???"},
    });
*/
    return POST(QString("%1/settings").arg(username));
}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiGET
ImgurAccountApi::galleryProfile(const QString& username)
{
    return GET(QString("%1/gallery_profile").arg(username));
}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiGET
ImgurAccountApi::verifyEmail(const QString& username)
{
    return GET(QString("%1/verifyemail").arg(username));
}
/*!
 * TODO Explain me.
 * \brief
 */
ImgurApiPOST
ImgurAccountApi::sendVerificationEmail(const QString& username)
{
    return POST(QString("%1/verifyemail").arg(username));
}
