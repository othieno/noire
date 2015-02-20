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
#ifndef VIEW_HH
#define VIEW_HH

class QIcon;
class QShowEvent;

namespace noire {

template<class Widget, class WidgetUi>
class View : public Widget, protected WidgetUi
{
protected:
    View(const QIcon& icon);

    void showEvent(QShowEvent* const event) override;

    virtual void initializeUi() = 0;
private:
    bool isUiInitialized_;
};

/*!
 * \brief Instantiates a View object with the specified \a icon and \a parent.
 */
template<class Widget, class _>
View<Widget, _>::View(const QIcon& icon) :
isUiInitialized_(false)
{
/*
    // Window flags to make the widget frameless. Note that when the widget is a QDialog,
    // an extra flag is needed to make it frameless.
    Qt::WindowFlags framelessWindowFlags = Qt::CustomizeWindowHint |  Qt::FramelessWindowHint;
    if (std::is_same<Widget, QDialog>::value)
        framelessWindowFlags |= Qt::Dialog;

    Widget::setWindowFlags(framelessWindowFlags);
*/
    Widget::setWindowIcon(icon);
}
/*!
 * \brief Handles the show \a event.
 * This reimplementation initializes the view's UI the first time it is displayed.
 */
template<class Widget, class WidgetUi> void
View<Widget, WidgetUi>::showEvent(QShowEvent* const event)
{
    if (!isUiInitialized_)
    {
        WidgetUi::setupUi(this);
        initializeUi();
        isUiInitialized_ = true;
    }
    Widget::showEvent(event);
}

} // namespace noire

#endif // VIEW_HH
