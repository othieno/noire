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

# The project relies on features introduced in Qt 5.4.
#greaterThan(QT_MAJOR_VERSION, 4):greaterThan(QT_MINOR_VERSION, 3) {

# Include the necessary modules.
QT *= widgets webkitwidgets network sql

# Locate and include the OpenSSL package.
#CONFIG *= link_pkgconfig
#PKGCONFIG *= openssl

# Set build output directories.
DESTDIR      = .
OBJECTS_DIR  = $$DESTDIR/obj
MOC_DIR      = $$DESTDIR/moc
RCC_DIR      = $$DESTDIR/rcc
UI_DIR       = $$DESTDIR/ui

# Enable C++11 support and add compiler flags that promote extra error checking.
CONFIG *= c++11
QMAKE_CXXFLAGS *= -g -Wall -Wextra -Werror -pedantic-errors -ansi

# Use the clang compiler (for debug purposes).
#QMAKE_CXX = clang++-3.6

#} else: error(The current Qt version ($$QT_VERSION) is unsupported. Please update your Qt installation to version 5.4 or later.)
