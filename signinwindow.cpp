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
  font.setPointSize(32);
  font.setBold(true);

  buttonFont.setPointSize(20);
  buttonFont.setBold(true);

  loginText = new QLabel("Welcome! Please scan your PSU ID barcode or type in your ODIN ID below", parent);
  loginText->move(275, 425);
  loginText->resize(1300, 50);
  loginText->setFont(buttonFont);
  loginText->hide();

  loginButton = new QPushButton("Sign-in", parent);
  loginButton->move(700, 500);
  loginButton->resize(200, 80);
  loginButton->hide();
  loginButton->setFont(buttonFont);

  noIdButton = new QPushButton("Sign-in without\nregistering", parent);
  noIdButton->move(550, 650);
  noIdButton->resize(300, 80);
  noIdButton->setFont(buttonFont);
  noIdButton->hide();

  loginDialog = new QLineEdit(parent);
  loginDialog->move(500, 500);
  loginDialog->resize(200, 80);
  loginDialog->setPlaceholderText("ODIN ID");
  loginDialog->setMaxLength(9);
  loginDialog->setValidator(new QRegExpValidator(QRegExp("[0-9]{9}")));
  loginDialog->hide();

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
  loginDialog->show();
  loginDialog->setFocus();
}

void SignInWindow::closeWindow() {
  loginText->hide();
  loginButton->hide();
  noIdButton->hide();
  loginDialog->hide();
  loginDialog->clear();
}
