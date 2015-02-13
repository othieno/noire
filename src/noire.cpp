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
#include "application.hh"

using noire::Application;

int main(int argc, char** argv)
{
    Application::setApplicationName("noire");
    Application::setApplicationDisplayName("Noire");
    Application::setOrganizationName(QString());
    Application::setOrganizationDomain(QString());
    Application::setApplicationVersion("0.0");

    if (Application::createDataLocations())
    {
        Application application(argc, argv);

        application.show();
        application.authenticate();

        return application.exec();
    }
    else
        qCritical("[Noire] CRITICAL: Could not create the data directory hierarchy.");
}
