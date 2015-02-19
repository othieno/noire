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
#include "testimguraccountapi.hh"
#include "imgurapi.hh"
#include "imguraccountsettings.hh"

using noire::TestImgurAccountApi;

TestImgurAccountApi::TestImgurAccountApi(TestSuite& suite) :
Test(suite)
{}
/*!
 * \brief Creates data used by the testRequestURLs function.
 */
void
TestImgurAccountApi::testRequestURLs_data()
{
    QTest::addColumn<QUrl>("requestURL");
    QTest::addColumn<QString>("requestURLString");

    QTest::newRow("Account base")
    << ImgurApi::Account.account("supranove").url()
    << "https://api.imgur.com/3/account/supranove";

    QTest::newRow("Account gallery favorites without page and sorting")
    << ImgurApi::Account.galleryFavorites("supranove").url()
    << "https://api.imgur.com/3/account/supranove/gallery_favorites";

    QTest::newRow("Account gallery favorites with specified page and sorted by newest first")
    << ImgurApi::Account.galleryFavorites("supranove", 2).url()
    << "https://api.imgur.com/3/account/supranove/gallery_favorites/2/newest";

    QTest::newRow("Account gallery favorites with specified page and sorted by oldest first")
    << ImgurApi::Account.galleryFavorites("supranove", 2, false).url()
    << "https://api.imgur.com/3/account/supranove/gallery_favorites/2/oldest";

    QTest::newRow("Account gallery favorites with specified page and explicitly sorted by newest first")
    << ImgurApi::Account.galleryFavorites("supranove", 2, true).url()
    << "https://api.imgur.com/3/account/supranove/gallery_favorites/2/newest";

    QTest::newRow("Account favorites")
    << ImgurApi::Account.favorites("supranove").url()
    << "https://api.imgur.com/3/account/supranove/favorites";

    QTest::newRow("Account submissions without specified page")
    << ImgurApi::Account.submissions("supranove").url()
    << "https://api.imgur.com/3/account/supranove/submissions";

    QTest::newRow("Account submissions with specified page")
    << ImgurApi::Account.submissions("supranove", 32).url()
    << "https://api.imgur.com/3/account/supranove/submissions/32";

    QTest::newRow("Account settings")
    << ImgurApi::Account.settings("supranove").url()
    << "https://api.imgur.com/3/account/supranove/settings";

    QTest::newRow("Change account settings")
    << ImgurApi::Account.setSettings("supranove", ImgurAccountSettings()).url()
    << "https://api.imgur.com/3/account/supranove/settings";

    QTest::newRow("Account gallery profile")
    << ImgurApi::Account.galleryProfile("supranove").url()
    << "https://api.imgur.com/3/account/supranove/gallery_profile";

    QTest::newRow("Verify user's email")
    << ImgurApi::Account.verifyEmail("supranove").url()
    << "https://api.imgur.com/3/account/supranove/verifyemail";

    QTest::newRow("Send verification email")
    << ImgurApi::Account.sendVerificationEmail("supranove").url()
    << "https://api.imgur.com/3/account/supranove/verifyemail";
}
/*!
 * \brief Tests created request URLs.
 */
void
TestImgurAccountApi::testRequestURLs()
{
    QFETCH(QUrl, requestURL);
    QFETCH(QString, requestURLString);

    QCOMPARE(requestURL.toString(), requestURLString);
}
