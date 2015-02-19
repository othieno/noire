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
#include "application.hh"
#include "imgurapi.hh"
#include <QTextStream>
#include <QDir>
#include <QStandardPaths>

using noire::Application;

/*!
 * \brief Instantiates an Application object.
 */
Application::Application(int& argc, char** argv) :
QApplication(argc, argv),
settings_(QString("%1/configuration.ini").arg(dataLocation())),
sessionManager_(settings_, networkAccessManager_),
window_(settings_, sessionManager_)
{
    connect(this, &Application::authenticated, this, &Application::onAuthenticated);
    connect(this, &Application::aboutToQuit, this, &Application::onAboutToQuit);

    setApplicationStyle();
}
/*!
 * \brief Displays the application's main window.
 */
void
Application::show()
{
    window_.show();
}
/*!
 * \brief Attempts to download the application's client secret. If successful, the
 * secret will be used to authorize all future users. However if the client secret cannot
 * be obtained, then the application can only be used by an anonymous user.
 */
void
Application::authenticate()
{
    //TODO Find a secure and modular way of storing and accessing the client secret.
    QFile file(":/credentials/client_secret");
    if (file.open(QIODevice::ReadOnly))
    {
        const auto& secret = QTextStream(&file).read(ImgurAuthorizationApi::CLIENT_SECRET_MAXLENGTH).trimmed();
        file.close();

        emit authenticated(secret);
    }
    else
    {
        qWarning("[Noire::Application] WARN: Could not authenticate the application.");
        emit authenticationFailed("Could not authenticate the application.");
    }
}
/*!
 * \brief Returns the root location where the application stores its persistent data.
 */
QString
Application::dataLocation()
{
    //TODO Remove the following statement when done debugging.
    return QString("data.user");

//TODO This is a temporary fix to support systems that don't have Qt 5.4 yet (e.g. Debian GNU/Linux as of Feb 8, 2015) and should be removed when it's readily available.
#if QT_VERSION >= 0x050400
    return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
#else
    return QStandardPaths::writableLocation(QStandardPaths::DataLocation);
#endif
}
/*!
 * \brief Creates the application's data directory tree.
 */
bool
Application::createDataLocations()
{
    const auto& locations =
    {
        Application::dataLocation(),
    };
    for (const auto& location : locations)
    {
        const QDir directory(location);
        if (!directory.exists() && !directory.mkpath("."))
        {
            qWarning("[Noire::Application] WARN: Could not create the data directory '%s'", qPrintable(location));
            return false;
        }
    }
    return true;
}
/*!
 * \brief Sets the application's fonts and stylesheet.
 */
void Application::setApplicationStyle()
{
/*
 * TODO Set font faces.
    for (const auto& path :
    {
        ":/font/Lato",
        ":/font/Raleway",
        ":/font/OpenSans",
        ":/font/Montserrat"
    }) QFontDatabase::addApplicationFont(path);
*/
    // Set the default stylesheet if none was already specified in the command line arguments.
    if (styleSheet().isEmpty())
    {
        QFile file(":/qss/noire");
        if (file.open(QIODevice::ReadOnly))
        {
            setStyleSheet(QTextStream(&file).readAll());
            file.close();
        }
        else
            qWarning("[Noire::Application] WARN: Could not load the default stylesheet!");
    }
}
/*!
 * \brief Performs last-second operations before the application quits.
 */
void Application::onAboutToQuit()
{
    //TODO Implement me.
}
/*!
 * \brief Handles the 'authenticated' signal.
 */
void
Application::onAuthenticated(const QString& secret)
{
    if (!secret.isEmpty())
    {
        ImgurApi::Authorization.setClientSecret(secret);

        // Authorize the application to access a user's data if we have a refresh token.
        if (settings_.hasRefreshToken())
            sessionManager_.authorizeRefreshToken(settings_.refreshToken());
    }
}
