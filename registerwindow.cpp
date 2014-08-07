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
    IDLabel = new QLabel(parent);
    IDLabel->move(startXPos + 100, startYPos + 200);
    IDLabel->resize(400, 30);
    IDLabel->setText("Scan your PSU ID barcode or enter ODIN ID #");
    IDLabel->hide();

    nameLabel = new QLabel(parent);
    nameLabel->move(startXPos + 100, startYPos + 300);
    nameLabel->resize(400, 30);
    nameLabel->setText("Enter your name");
    nameLabel->hide();

    IDDialog = new QLineEdit(parent);
    IDDialog->move(startXPos + 100, startYPos + 240);
    IDDialog->resize(200, 30);
    IDDialog->setPlaceholderText("ODIN ID");
    IDDialog->setMaxLength(9);
    IDDialog->setValidator(new QRegExpValidator(QRegExp("[0-9]{9}")));
    IDDialog->hide();

    nameDialog = new QLineEdit(parent);
    nameDialog->move(startXPos + 100, startYPos + 340);
    nameDialog->resize(200, 30);
    nameDialog->setPlaceholderText("Name");
    nameDialog->setMaxLength(20);
    nameDialog->setValidator(new QRegExpValidator(QRegExp("(([a-z]|[A-Z])+\\s?([a-z]|[A-Z])+){3,20}")));
    nameDialog->hide();

    regButton = new QPushButton("Register", parent);
    regButton->move(startXPos + 0, startYPos + 500);
    regButton->resize(300, 75);
    regButton->hide();

    cancelButton = new QPushButton("Cancel", parent);
    cancelButton->move(startXPos + 500, startYPos + 500);
    cancelButton->resize(300, 75);
    cancelButton->hide();

}

void RegisterWindow::openWindow() {
    IDLabel->show();
    nameLabel->show();
    IDDialog->show();
    IDDialog->setFocus();
    nameDialog->show();
    regButton->show();
    cancelButton->show();
}

void RegisterWindow::closeWindow() {
    IDLabel->hide();
    nameLabel->hide();
    IDDialog->hide();
    IDDialog->clear();
    nameDialog->hide();
    nameDialog->clear();
    regButton->hide();
    cancelButton->hide();
}
