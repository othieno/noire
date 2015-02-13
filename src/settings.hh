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
#ifndef SETTINGS_HH
#define SETTINGS_HH

#include <QSettings>
#include <QString>

namespace noire {

class Application;

class Settings : public QSettings
{
    friend class Application;
public:
    enum class Key
    {
        SaveRefreshToken,
        RefreshToken
    };
    static QString keyToString(const Key& key);

    bool isRefreshTokenStorageEnabled() const;
    void enableRefreshTokenStorage(const bool enable);

    bool hasRefreshToken() const;
    QString refreshToken() const;
    void setRefreshToken(const QString& token);
private:
    explicit Settings(const QString& fileName);
    /*!
     * \brief Returns the value of the stored \a key.
     * If the key does not exist, then the default value \a defaultValue is returned.
     */
    inline QVariant value(const Key& key, const QVariant& defaultValue = QVariant()) const
    {
        return QSettings::value(Settings::keyToString(key), defaultValue);
    }
    /*!
     * \brief Returns true if the settings \a key exists, false otherwise.
     */
    inline bool contains(const Key& key) const
    {
        return QSettings::contains(Settings::keyToString(key));
    }
    /*!
     * \brief Stores the \a value with the specified \a key.
     */
    inline void setValue(const Key& key, const QVariant& value)
    {
        QSettings::setValue(Settings::keyToString(key), value);
    }
};

} // namespace noire

#endif // SETTINGS_HH
