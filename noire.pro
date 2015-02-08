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
    src/logic/models \
    src/presentation

HEADERS += \
    src/imgurapi.hh \
    src/presentation/window.hh \
    src/logic/models/imguraccount.hh \
    src/logic/models/imguraccountsettings.hh \
    src/logic/models/imguralbum.hh \
    src/sessionmanager.hh \
    src/settings.hh \
    src/logic/models/imgurjsonresponse.hh \
    src/logic/session.hh \
    src/application.hh

SOURCES += \
    src/imgurapi.cpp \
    src/presentation/window.cpp \
    src/sessionmanager.cpp \
    src/settings.cpp \
    src/logic/models/imgurjsonresponse.cpp \
    src/logic/session.cpp \
    src/application.cpp \
    src/noire.cpp

FORMS += \
    src/presentation/forms/window.ui

RESOURCES += \
    res/res.qrc

OTHER_FILES += \
    Makefile

include(noire.pri)
