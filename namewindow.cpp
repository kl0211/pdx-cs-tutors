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

#include "namewindow.hpp"

NameWindow::NameWindow(QWidget * parent) : QWidget(parent) {
  loginText = new QLabel("Enter your name below", parent);
  loginText->move(startXPos + 200, startYPos + 350);
  loginText->resize(400, 30);
  loginText->hide();

  loginButton = new QPushButton("Sign-in", parent);
  loginButton->move(startXPos + 400, startYPos + 400);
  loginButton->resize(200, 80);
  loginButton->hide();

  cancelButton = new QPushButton("Cancel", parent);
  cancelButton->move(startXPos + 250, startYPos + 550);
  cancelButton->resize(300, 80);
  cancelButton->hide();

  nameDialog = new QLineEdit(parent);
  nameDialog->move(startXPos + 200, startYPos + 400);
  nameDialog->resize(200, 80);
  nameDialog->setPlaceholderText("Name");
  nameDialog->setMaxLength(20);
  nameDialog->setValidator(new QRegExpValidator(QRegExp("(([a-z]|[A-Z])+\\s?([a-z]|[A-Z])+){3,20}")));
  nameDialog->hide();
}

void NameWindow::openWindow() {
  loginButton->show();
  loginText->show();
  cancelButton->show();
  nameDialog->show();
  nameDialog->setFocus();
}

void NameWindow::closeWindow() {
  loginButton->hide();
  loginText->hide();
  cancelButton->hide();
  nameDialog->hide();
  nameDialog->clear();
}
