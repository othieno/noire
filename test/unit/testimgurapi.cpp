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
#include "testimgurapi.hh"
#include "imgurapi.hh"

using noire::TestImgurApi;

TestImgurApi::TestImgurApi(TestSuite& suite) :
Test(suite)
{}
/*!
 * \brief Tests API endpoint base URLs.
 */
void
TestImgurApi::testEndpointBaseURLs()
{
    QCOMPARE(ImgurApi::Authorization.baseURL, QString("https://api.imgur.com/oauth2"));
    QCOMPARE(ImgurApi::Account.baseURL,       QString("https://api.imgur.com/3/account"));
    QCOMPARE(ImgurApi::Album.baseURL,         QString("https://api.imgur.com/3/album"));
    QCOMPARE(ImgurApi::Comment.baseURL,       QString("https://api.imgur.com/3/comment"));
    QCOMPARE(ImgurApi::CustomGallery.baseURL, QString("https://api.imgur.com/3/g"));
    QCOMPARE(ImgurApi::Gallery.baseURL,       QString("https://api.imgur.com/3/gallery"));
    QCOMPARE(ImgurApi::Image.baseURL,         QString("https://api.imgur.com/3/image"));
    QCOMPARE(ImgurApi::Conversation.baseURL,  QString("https://api.imgur.com/3/conversations"));
    QCOMPARE(ImgurApi::Notification.baseURL,  QString("https://api.imgur.com/3/notification"));
    QCOMPARE(ImgurApi::Memegen.baseURL,       QString("https://api.imgur.com/3/memegen"));
}
