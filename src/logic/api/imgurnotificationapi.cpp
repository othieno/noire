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
#include "imgurnotificationapi.hh"

using noire::ImgurNotificationApi;

/*!
 * \brief Instantiates an ImgurNotificationApi object.
 */
ImgurNotificationApi::ImgurNotificationApi() :
ImgurApiEndpoint(apiBaseURL().append("notification"))
{}





#ifdef FIXME
/*!
 * \brief Returns information about the notification with the given identifier \a id.
 */
QNetworkReply*
ImgurNotificationApi::notification(const QString& id)
{
    return id.isEmpty() ? nullptr : httpRequest(QString("notification/%1").arg(id));
}
/*!
 * \brief Returns all non-viewed notifications for the user that's currently logged in.
 * If \a getViewedNotifications is set to true, then all notifications are returned.
 */
QNetworkReply*
ImgurNotificationApi::notifications(const bool getViewedNotifications)
{
//    new (optional) boolean - false for all notifications, true for only non-viewed notification. Default is true.

//    return get(createApiRequest("notification"));
    Q_UNUSED(getViewedNotifications);
    qFatal("[ImgurApi::notifications] not implemented.");
}
#endif
