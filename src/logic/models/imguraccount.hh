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
#ifndef IMGURACCOUNT_HH
#define IMGURACCOUNT_HH

#include "imgurresponse.hh"
#include <QDateTime>

namespace noire {

struct ImgurAccount final : public ImgurResponse
{
    ImgurAccount();
    explicit ImgurAccount(const QJsonObject& jsonObject);
    /*!
     * \brief Returns the account username, which is identical to the account URL.
     */
    inline const QString& username() const { return url; }
    /*!
     * \brief The account identifier.
     */
    const int identifier;
    /*!
     * \brief The account URL.
     */
    const QString url;
    /*!
     * \brief A basic description the user has filled out.
     */
    const QString bio;
    /*!
     * \brief The account reputation, in its numerical format.
     */
    const double reputation;
    /*!
     * \brief The account's date and time of creation.
     */
    const QDateTime creationDate;
    /*!
     * \brief Is the account a Pro user?
     */
    const bool isProUser;
    /*!
     * \brief The account's Pro expiration date and time.
     */
    const QDateTime proExpirationDate;
};

} // namespace noire

#endif // IMGURACCOUNT_HH

