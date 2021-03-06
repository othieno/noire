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
#include "window.hh"
#include "dialog.hh"
#include "sessionmanager.hh"
#include "application.hh"
#include "authorizationview.hh"

using noire::Window;

/*!
 * \brief Instantiates a Window object.
 */
Window::Window(Settings& settings, SessionManager& sessionManager) :
settings_(settings),
sessionManager_(sessionManager)
{}
/*!
 * \brief Initializes the window's components.
 */
void
Window::initialize()
{
    // Initialize the UI for the current session.
    onSessionChanged(sessionManager_.session());

    connect(&sessionManager_, &SessionManager::sessionChanged, this, &Window::onSessionChanged);
    connect(&sessionManager_, &SessionManager::authorizationFailed, this, &Window::onAuthorizationFailed);
    connect(authorizeButton_, &QPushButton::clicked, this, &Window::onAuthorizeButtonClicked);

    //TODO Load the window's saved configuration before displaying it.
}
/*!
 * \brief Handles the SessionManager's 'sessionChanged' signal.
 */
void
Window::onSessionChanged(const Session& session)
{
    const bool authorized = session.type == Session::Type::Authorized;

    usernameLabel_->setVisible(authorized);
    usernameLabel_->setText(authorized ? session.username : QString());
    authorizeButton_->setVisible(!authorized);
    logoutButton_->setVisible(authorized);
}
/*!
 * \brief Handles the SessionManager's 'authorizationFailed' signal.
 */
void
Window::onAuthorizationFailed(const QString& errorMessage)
{
    qDebug() << errorMessage;
    qCritical("[Window::onAuthorizationFailed] CRITICAL: Unimplemented member function.");
}
/*!
 * \brief Handles the authorizeButton_'s 'clicked' signal.
 */
void
Window::onAuthorizeButtonClicked()
{
    Dialog(new AuthorizationView(sessionManager_), this).exec();
}
