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

#include "registerwindow.hpp"

RegisterWindow::RegisterWindow(QWidget * parent) : QWidget(parent) {
  font.setPointSize(24);
  text = new QLabel("Looks like this is your first time signing in.\n"
                    "Please enter your name below to associate your ID number with.\n"
                    "Make sure you spell your name correctly. You won't be able to change it later.", parent);
  text->move(100, 100);
  text->resize(1200, 300);
  text->hide();
  text->setFont(font);

  nameLabel = new QLabel("Enter your name below", parent);
  nameLabel->move(startXPos + 200, startYPos + 350);
  nameLabel->resize(400, 30);
  nameLabel->hide();

  regButton = new QPushButton("Sign-in", parent);
  regButton->move(startXPos + 400, startYPos + 400);
  regButton->resize(200, 80);
  regButton->hide();

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

void RegisterWindow::openWindow() {
  text->show();
  nameLabel->show();
  nameDialog->show();
  regButton->show();
  cancelButton->show();
  nameDialog->setFocus();
}

void RegisterWindow::closeWindow() {
  text->hide();
  nameLabel->hide();
  nameDialog->hide();
  nameDialog->clear();
  regButton->hide();
  cancelButton->hide();
}
