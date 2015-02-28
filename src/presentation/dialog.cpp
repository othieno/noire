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
#include "dialog.hh"
#include "view.hh"
#include "window.hh"

using noire::Dialog;

/*!
 * \brief Instantiates a Dialog object with the specified \a view, and is a child of \a parent.
 */
Dialog::Dialog(View* const view, QWidget* const parent) :
WindowManager(parent),
view_(view)
{
    if (view_ != nullptr)
    {
        view_->setParent(this);
        connect(view_, &View::accept, this, &Dialog::accept);
        connect(view_, &View::reject, this, &Dialog::reject);
    }
}
/*!
 * \brief Initializes the Dialog's components.
 */
void
Dialog::initialize()
{
    if (view_ != nullptr)
    {
        view_->initialize();
        setWindowTitle(view_->windowTitle());
        setWindowIcon(view_->windowIcon());
        setContentWidget(view_);
    }
}
