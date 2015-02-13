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
#include "settings.hh"

using noire::Settings;

/*!
 * \brief Instantiates a Settings object with the file \a name.
 */
Settings::Settings(const QString& name) :
QSettings(name, Format::IniFormat)
{}
/*!
 * \brief Returns true if a refresh token should be stored to the settings file, false otherwise.
 */
bool
Settings::isRefreshTokenStorageEnabled() const
{
    return value(Key::SaveRefreshToken, false).toBool();
}
/*!
 * \brief Stores the refresh token if \a remember is set to true.
 */
void
Settings::enableRefreshTokenStorage(const bool save)
{
    setValue(Key::SaveRefreshToken, save);
}
/*!
 * \brief Returns true if a valid refresh token is stored, false otherwise.
 */
bool
Settings::hasRefreshToken() const
{
    return contains(Key::RefreshToken) && !refreshToken().isEmpty();
}
/*!
 * \brief Returns a refresh token if one was saved, an empty string otherwise.
 */
QString
Settings::refreshToken() const
{
    return value(Key::RefreshToken, QString()).toString();
}
/*!
 * \brief Stores the refresh \a token.
 */
void
Settings::setRefreshToken(const QString& token)
{
    setValue(Key::RefreshToken, token);
}
/*!
 * \brief Converts the settings \a key into a string.
 */
QString
Settings::keyToString(const Settings::Key& key)
{
    switch (key)
    {
        case Key::SaveRefreshToken:
            return "SaveRefreshToken";
        case Key::RefreshToken:
            return "RefreshToken";
        default:
            qFatal("[Noire::Settings] CRITICAL: Undefined key!");
    }
}
