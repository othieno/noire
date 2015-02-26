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
#ifndef WINDOWMANAGER_HH
#define WINDOWMANAGER_HH

#include "titlebar.hh"
#include "sizegrip.hh"

namespace noire {

/*!
 * The WindowManager class implements a consistent look-and-feel to the application's
 * windows, across different operating systems.
 */
template<class Window, class WindowUi>
class WindowManager : public Window, protected WindowUi
{
    static_assert(std::is_base_of<QWidget, Window>::value, "Window must inherit from QWidget.");
protected:
    WindowManager();
    void showEvent(QShowEvent* const event) final override;
    /*!
     * \brief Initializes the window's user interface.
     * This member function is called only once: when the window is shown for the first time.
     */
    virtual void onInitializeUi() = 0;
private:
    /*!
     * \brief The window's title bar.
     */
    TitleBar titleBar_;
    /*!
     * \brief The window's size grip.
     */
    SizeGrip sizeGrip_;
    /*!
     * \brief True if the Window's user interface has been initialized, false otherwise.
     */
    bool isWindowInitialized_;
};

/*!
 * \brief Instantiates a WindowManager object.
 */
template<class _, class __>
WindowManager<_, __>::WindowManager() :
isWindowInitialized_(false)
{}
/*!
 * Handles the show \a event.
 * This override initializes the window's components the first time it's displayed.
 */
template<class Window, class WindowUi> void
WindowManager<Window, WindowUi>::showEvent(QShowEvent* const event)
{
    if (!isWindowInitialized_)
    {
        WindowUi::setupUi(this);
        onInitializeUi();

        isWindowInitialized_ = true;
    }
    Window::showEvent(event);
}

} // namespace noire

#endif // WINDOWMANAGER_HH
