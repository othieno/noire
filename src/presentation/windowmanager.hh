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
    explicit WindowManager(QWidget* const parent = nullptr);
    void showEvent(QShowEvent* const event) final override;

    void setHeaderWidget(QWidget* const widget);
    void setContentWidget(QWidget* const widget);
    void setFooterWidget(QWidget* const widget);
    /*!
     * \brief Initializes the window's components.
     * This member function is called only once: when the window is shown for the first time.
     */
    virtual void initialize() = 0;
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
 * \brief Instantiates a WindowManager object that is a child of \a parent.
 */
template<class Window, class _>
WindowManager<Window, _>::WindowManager(QWidget* const parent) :
Window(parent),
isWindowInitialized_(false)
{
#ifdef TODO
    // Flags to make the window frameless so we can implement a custom window frame.
    // Note that when the window is a QDialog, an extra flag is needed to make it frameless.
    Qt::WindowFlags framelessWindowFlags = Qt::CustomizeWindowHint |  Qt::FramelessWindowHint;
    if (std::is_same<Window, QDialog>::value)
        framelessWindowFlags |= Qt::Dialog;

    Window::setWindowFlags(framelessWindowFlags);
#endif
}
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
        initialize();

        isWindowInitialized_ = true;
    }
    Window::showEvent(event);
}
/*!
 * Sets the header \a widget.
 */
template<class _, class WindowUi> void
WindowManager<_, WindowUi>::setHeaderWidget(QWidget* const widget)
{
    if (widget != nullptr && WindowUi::header_ != nullptr)
        WindowUi::header_->addWidget(widget);
}
/*!
 * Sets the content \a widget.
 */
template<class _, class WindowUi> void
WindowManager<_, WindowUi>::setContentWidget(QWidget* const widget)
{
    if (widget != nullptr && WindowUi::content_ != nullptr)
        WindowUi::content_->addWidget(widget);
}
/*!
 * Sets the footer \a widget.
 */
template<class _, class WindowUi> void
WindowManager<_, WindowUi>::setFooterWidget(QWidget* const widget)
{
    if (widget != nullptr && WindowUi::footer_ != nullptr)
        WindowUi::footer_->addWidget(widget);
}

} // namespace noire

#endif // WINDOWMANAGER_HH
