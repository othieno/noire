# Noire, an Imgur desktop client.
# Copyright (c) 2015 Jeremy Othieno.
#
# This file is part of Noire.
#
# Noire is free software: you can redistribute it and/or modify it under the terms
# of the GNU General Public License as published by the Free Software Foundation,
# either version 3 of the License, or (at your option) any later version.
#
# Noire is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
# PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with Noire.
# If not, see <http://www.gnu.org/licenses/>.

TEMPLATE = app
TARGET = noire

INCLUDEPATH += \
    src \
    src/logic \
    src/logic/api \
    src/logic/models \
    src/presentation/views \
    src/presentation

HEADERS += \
    src/presentation/window.hh \
    src/logic/models/imguraccount.hh \
    src/logic/models/imguraccountsettings.hh \
    src/logic/models/imguralbum.hh \
    src/sessionmanager.hh \
    src/settings.hh \
    src/logic/session.hh \
    src/application.hh \
    src/logic/models/imgurresponse.hh \
    src/logic/models/imgurbasicresponse.hh \
    src/logic/api/imgurapi.hh \
    src/logic/api/imguraccountapi.hh \
    src/logic/api/imgurapiendpoint.hh \
    src/logic/api/imguralbumapi.hh \
    src/logic/api/imgurcustomgalleryapi.hh \
    src/logic/api/imgurgalleryapi.hh \
    src/logic/api/imgurimageapi.hh \
    src/logic/api/imgurmemegenapi.hh \
    src/logic/api/imgurnotificationapi.hh \
    src/logic/api/imgurcommentapi.hh \
    src/logic/api/imgurconversationapi.hh \
    src/logic/api/imgurauthorizationapi.hh \
    src/logic/api/imgurapirequest.hh \
    src/presentation/views/authorizationview.hh \
    src/presentation/views/view.hh \
    src/presentation/windowmanager.hh \
    src/presentation/titlebar.hh \
    src/presentation/sizegrip.hh

SOURCES += \
    src/presentation/window.cpp \
    src/sessionmanager.cpp \
    src/settings.cpp \
    src/logic/session.cpp \
    src/application.cpp \
    src/noire.cpp \
    src/logic/models/imgurresponse.cpp \
    src/logic/models/imgurbasicresponse.cpp \
    src/logic/models/imguraccount.cpp \
    src/logic/api/imgurapi.cpp \
    src/logic/api/imguraccountapi.cpp \
    src/logic/api/imgurapiendpoint.cpp \
    src/logic/api/imguralbumapi.cpp \
    src/logic/api/imgurauthorizationapi.cpp \
    src/logic/api/imgurcommentapi.cpp \
    src/logic/api/imgurconversationapi.cpp \
    src/logic/api/imgurcustomgalleryapi.cpp \
    src/logic/api/imgurgalleryapi.cpp \
    src/logic/api/imgurimageapi.cpp \
    src/logic/api/imgurmemegenapi.cpp \
    src/logic/api/imgurnotificationapi.cpp \
    src/logic/api/imgurapirequest.cpp \
    src/presentation/views/authorizationview.cpp \
    src/presentation/titlebar.cpp \
    src/presentation/sizegrip.cpp

FORMS += \
    src/presentation/forms/window.ui \
    src/presentation/forms/authorizationview.ui

RESOURCES += \
    res/res.qrc

include(noire.pri)
