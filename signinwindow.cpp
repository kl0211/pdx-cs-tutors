/*A sign-in program for CS Tutoring at Portland State University
  Copyright (C) 2014 Robert Werfelmann

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "signinwindow.hpp"

SignInWindow::SignInWindow(QWidget * parent) : QWidget(parent)
{
    regButton = new QPushButton("Register", parent);
    regButton->move(200, 500);
    regButton->resize(200, 50);

    loginButton = new QPushButton("Sign-in", parent);
    loginButton->move(300, 400);
    loginButton->resize(200, 30);

    noIdButton = new QPushButton("Sign-in without registering", parent);
    noIdButton->move(300, 440);
    noIdButton->resize(200, 30);

    loginDialog = new QLineEdit(parent);
    loginDialog->move(100, 400);
    loginDialog->resize(200, 30);
    loginDialog->setPlaceholderText("ODIN ID");

    nameDialog = new QLineEdit(parent);
    nameDialog->move(100, 440);
    nameDialog->resize(200, 30);
    nameDialog->setPlaceholderText("Name");

    logo = new QLabel("<img src='psulogo.gif' />", parent);
    logo->resize(1000,100);
}
