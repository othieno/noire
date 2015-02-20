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
#ifndef AUTHORIZATIONVIEW_HH
#define AUTHORIZATIONVIEW_HH

#include "view.hh"
#include "ui_authorizationview.h"

namespace noire {

class SessionManager;

class AuthorizationView : public View<QDialog, Ui::AuthorizationView>
{
    Q_OBJECT
public:
    explicit AuthorizationView(SessionManager& sessionManager);
private:
    void initializeUi() override;
    const QUrl authorizationURL_;
    SessionManager& sessionManager_;
private slots:
    void onWebViewUrlChanged(const QUrl& url);
};

} // namespace noire

#endif // AUTHORIZATIONVIEW_HH
