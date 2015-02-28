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
#ifndef WINDOW_HH
#define WINDOW_HH

#include <QMainWindow>
#include "ui_window.h"
#include "windowmanager.hh"

namespace noire {

class Settings;
class Session;
class SessionManager;

class Window final : public WindowManager<QMainWindow, Ui::Window>
{
public:
    Window(Settings& settings, SessionManager& sessionManager);
private:
    void initialize() override;

    Settings& settings_;
    SessionManager& sessionManager_;
private slots:
    void onSessionChanged(const Session& session);
    void onAuthorizationFailed(const QString& errorMessage);
    void onAuthorizeButtonClicked();
};

} // namespace noire

#endif // WINDOW_HH
