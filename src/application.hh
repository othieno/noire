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
#ifndef APPLICATION_HH
#define APPLICATION_HH

#include <QApplication>
#include <QNetworkAccessManager>
#include "settings.hh"
#include "sessionmanager.hh"
#include "window.hh"

namespace noire {

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int& argc, char** argv);

    void show();
    void authenticate();

    static QString dataLocation();
    static bool createDataLocations();
private:
    void setApplicationStyle();

    Settings settings_;
    QNetworkAccessManager networkAccessManager_;
    SessionManager sessionManager_;
    Window window_;
private slots:
    void onAboutToQuit();
    void onAuthenticated(const QString& secret);
signals:
    void authenticated(const QString& secret);
    void authenticationFailed(const QString& errorMessage);
};

} // namespace noire

#endif // APPLICATION_HH
