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
#include "authorizationview.hh"
#include "sessionmanager.hh"
#include "imgurapi.hh"

using noire::AuthorizationView;

/*!
 * \brief Instantiates an AuthorizationView object.
 */
AuthorizationView::AuthorizationView(SessionManager& sessionManager) :
View(QIcon()), //TODO Change to an appropriate icon.
authorizationURL_(QString("%1/authorize?client_id=%2&response_type=code").arg(ImgurApi::Authorization.baseURL, ImgurApi::Authorization.clientIdentifier())),
sessionManager_(sessionManager)
{}
/*!
 * \brief Initializes the view's user interface.
 */
void
AuthorizationView::initializeUi()
{
    if (webView_ != nullptr && info_ != nullptr)
    {
        connect(webView_, &QWebView::urlChanged,  this, &AuthorizationView::onWebViewUrlChanged);
        webView_->load(authorizationURL_);

        info_->setText(tr("Disclaimer: Noire does not store your username, email or password."));
    }
}
/*!
 * \brief Handles the 'urlChanged' signal emitted by the web view.
 */
void
AuthorizationView::onWebViewUrlChanged(const QUrl& url)
{
    if (url != authorizationURL_)
    {
        webView_->stop();

        const auto& urlString = url.toString();
        if (urlString == "https://imgur.com/?error=access_denied")
            reject();
        else if (!urlString.left(urlString.indexOf('=') + 1).compare("https://imgur.com/?code="))
        {
            sessionManager_.authorizeCode(urlString.right(urlString.length() - (urlString.indexOf('=') + 1)));
            accept();
        }
        else
        {
            if (urlString == "https://imgur.com/tos")
                info_->setText(tr("Link disabled! You can view Imgur's Terms of Service at https://imgur.com/tos"));
            else if (urlString == "https://imgur.com/signin/forgotpassword")
                info_->setText(tr("Link disabled! You can request a new Imgur password at https://imgur.com/signin/forgotpassword"));

            webView_->back();
        }
    }
}
