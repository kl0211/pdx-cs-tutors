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
    loginText = new QLabel("Welcome! Please scan your barcode or type in your ODIN ID below", parent);
    loginText->move(startXPos + 200, startYPos + 350);
    loginText->resize(400, 30);
    loginText->hide();

    loginButton = new QPushButton("Sign-in", parent);
    loginButton->move(startXPos + 400, startYPos + 400);
    loginButton->resize(200, 80);
    loginButton->hide();

    noIdButton = new QPushButton("Sign-in without registering", parent);
    noIdButton->move(startXPos + 250, startYPos + 550);
    noIdButton->resize(300, 80);
    noIdButton->hide();

    tutorButton = new QPushButton(" ", parent);
    tutorButton->move(1250, 0);
    tutorButton->hide();

    loginDialog = new QLineEdit(parent);
    loginDialog->move(startXPos + 200, startYPos + 400);
    loginDialog->resize(200, 80);
    loginDialog->setPlaceholderText("ODIN ID");
    loginDialog->setMaxLength(9);
    loginDialog->setValidator(new QRegExpValidator(QRegExp("[0-9]{9}")));
    loginDialog->hide();

    font.setPointSize(32);
    font.setBold(true);

    logo = new QLabel("<img src='psulogo.gif' />", parent);
    logo->resize(300,100);

    title = new QLabel("CS Tutor Sign-In", parent);
    title->setFont(font);
    title->move(550, 0);
    title->resize(600, 100);
}

void SignInWindow::openWindow() {
    loginText->show();
    loginButton->show();
    noIdButton->show();
    tutorButton->show();
    loginDialog->show();
    loginDialog->setFocus();
}

void SignInWindow::closeWindow() {
    loginText->hide();
    loginButton->hide();
    noIdButton->hide();
    tutorButton->hide();
    loginDialog->hide();
    loginDialog->clear();
}
