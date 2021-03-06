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
View(tr("Authorization"), QIcon()), //TODO Change to an appropriate icon.
authorizationURL_(QString("%1/authorize?client_id=%2&response_type=pin").arg(ImgurApi::Authorization.baseURL, ImgurApi::Authorization.clientIdentifier())),
sessionManager_(sessionManager)
{}
/*!
 * \brief Initializes the view's components.
 */
void
AuthorizationView::initialize()
{
    setupUi(this);
    if (webView_ != nullptr && info_ != nullptr)
    {
        connect(webView_, &QWebView::urlChanged,  this, &AuthorizationView::onWebViewUrlChanged);
        connect(webView_, &QWebView::loadStarted, this, &AuthorizationView::onWebViewLoadStarted);
        connect(webView_, &QWebView::loadFinished, this, &AuthorizationView::onWebViewLoadFinished);

        webView_->load(authorizationURL_);
        info_->setText(tr("Disclaimer: Noire does not store your email or password."));
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
        const auto& pinIndex  = urlString.indexOf('=') + 1;
        const auto& pinLength = urlString.length() - pinIndex;

        if (urlString == "https://imgur.com/?error=access_denied")
            emit reject();
        else if (!urlString.left(pinIndex).compare("https://api.imgur.com/oauth2/pin?pin="))
        {
            sessionManager_.authorizePIN(urlString.right(pinLength));
            emit accept();
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
/*!
 * \brief Handles the 'loadStarted' signal emitted by the web view.
 */
void
AuthorizationView::onWebViewLoadStarted()
{
//    info_->setText(tr("Loading the Imgur authorization page ..."));
}
/*!
 * \brief Handles the 'loadFinished' signal emitted by the web view.
 */
void
AuthorizationView::onWebViewLoadFinished(const bool ok)
{
    Q_UNUSED(ok);
/*
    const auto& status = ok ?
                         tr("Disclaimer: Noire does not store your email or password.") :
                         tr("Error: Could not load the Imgur authorization page. Please try again later.");

    info_->setText(status);
*/
}
