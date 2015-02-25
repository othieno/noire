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
#ifndef IMGURACCOUNTSETTINGS_HH
#define IMGURACCOUNTSETTINGS_HH

#include <QString>
#include <QVariantList>

class QJsonObject;

namespace noire {

struct ImgurAccountSettings
{
    ImgurAccountSettings() = default;
    explicit ImgurAccountSettings(const QJsonObject& object);
    /*!
     * \brief The user's email address.
     */
    QString email;
    /*!
     * \brief Can the user upload higher quality images?
     */
    bool canUploadHighQualityImages;
    /*!
     * \brief Are the user's images publicly available?
     */
    bool areUserImagesPublic;





    QString             albumPrivacy;
    bool                isProUser;
    unsigned int        proExpirationDate;
    bool                acceptedGalleryTAC;
    QStringList         activeEmails;
    bool                isMessagingEnabled;
    QVariantList        blockedUsers;
};

} // namespace noire

#endif // IMGURACCOUNTSETTINGS_HH
