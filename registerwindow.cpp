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
    IDLabel->move(100, 200);
    IDLabel->resize(400, 30);
    IDLabel->setText("Scan your PSU ID barcode or enter ODIN ID #");
    IDLabel->hide();

    nameLabel = new QLabel(parent);
    nameLabel->move(100, 300);
    nameLabel->resize(400, 30);
    nameLabel->setText("Enter your name");
    nameLabel->hide();

    IDDialog = new QLineEdit(parent);
    IDDialog->move(100, 240);
    IDDialog->resize(200, 30);
    IDDialog->setPlaceholderText("ODIN ID");
    IDDialog->hide();

    nameDialog = new QLineEdit(parent);
    nameDialog->move(100, 340);
    nameDialog->resize(200, 30);
    nameDialog->setPlaceholderText("Name");
    nameDialog->hide();

    regButton = new QPushButton("Register", parent);
    regButton->move(0, 500);
    regButton->resize(300, 75);
    regButton->hide();

    cancelButton = new QPushButton("Cancel", parent);
    cancelButton->move(500, 500);
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
