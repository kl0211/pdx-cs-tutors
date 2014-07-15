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

SignInWindow::SignInWindow(QWidget * parent) : QWidget(parent) {
    regButton = new QPushButton("Register", parent);
    regButton->move(250, 450);
    regButton->resize(200, 50);
    regButton->hide();

    loginButton = new QPushButton("Sign-in", parent);
    loginButton->move(350, 350);
    loginButton->resize(200, 30);
    loginButton->hide();

    noIdButton = new QPushButton("Sign-in without registering", parent);
    noIdButton->move(350, 390);
    noIdButton->resize(200, 30);
    noIdButton->hide();

    loginDialog = new QLineEdit(parent);
    loginDialog->move(150, 350);
    loginDialog->resize(200, 30);
    loginDialog->setPlaceholderText("ODIN ID");
    loginDialog->hide();

    nameDialog = new QLineEdit(parent);
    nameDialog->move(150, 390);
    nameDialog->resize(200, 30);
    nameDialog->setPlaceholderText("Name");
    nameDialog->hide();

    logo = new QLabel("<img src='psulogo.gif' />", parent);
    logo->resize(1000,100);
}

void SignInWindow::openWindow() {
    regButton->show();
    loginButton->show();
    noIdButton->show();
    loginDialog->show();
    loginDialog->setFocus();
    nameDialog->show();
}

void SignInWindow::closeWindow() {
    regButton->hide();
    loginButton->hide();
    noIdButton->hide();
    loginDialog->hide();
    loginDialog->clear();
    nameDialog->hide();
    nameDialog->clear();
}
