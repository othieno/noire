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
#ifndef IMGURCONVERSATIONAPI_HH
#define IMGURCONVERSATIONAPI_HH

#include "imgurapiendpoint.hh"

namespace noire {

class ImgurConversationApi final : public ImgurApiEndpoint
{
    friend class ImgurApi;
public:
    QNetworkReply* conversation(const QString& conversationId, const int page = 1, const int offset = 0);
    QNetworkReply* conversations();
    QNetworkReply* createMessage(const QString& recipientUsername, const QString& message);
    QNetworkReply* deleteConversation(const QString& conversationId);
    QNetworkReply* reportSender(const QString& username);
    QNetworkReply* blockSender(const QString& username);
private:
    ImgurConversationApi();
};

} // namespace noire

#endif // IMGURCONVERSATIONAPI_HH
