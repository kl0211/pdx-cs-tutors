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

#include "confirmwindow.hpp"

ConfirmWindow::ConfirmWindow(QWidget * parent) : QWidget (parent) {
    font.setPointSize(24);
    text = new QLabel("Please confirm that the following information is correct", parent);
    text->move(100, 100);
    text->resize(1200, 300);
    text->hide();
    text->setFont(font);

    name = new QLabel("Name:", parent);
    name->move(300, 300);
    name->hide();

    nameOutput = new QLabel(parent);
    nameOutput->move(400, 265);
    nameOutput->resize(300, 100);
    nameOutput->hide();

    klass = new QLabel("Class:", parent);
    klass->move(300, 375);
    klass->hide();

    klassOutput = new QLabel(parent);
    klassOutput->move(400, 375);
    klassOutput->hide();

    location = new QLabel("Location:", parent);
    location->move(300, 450);
    location->hide();

    locationOutput = new QLabel(parent);
    locationOutput->move(400, 425);
    locationOutput->resize(200, 75);
    locationOutput->hide();

    confirmButton = new QPushButton("Confirm", parent);
    confirmButton->move(300, 600);
    confirmButton->resize(300, 75);
    confirmButton->hide();

    cancelButton = new QPushButton("Start Over", parent);
    cancelButton->move(800, 600);
    cancelButton->resize(300, 75);
    cancelButton->hide();
}

void ConfirmWindow::openWindow() {
    text->show();
    name->show();
    klass->show();
    location->show();
    nameOutput->show();
    klassOutput->show();
    locationOutput->show();
    confirmButton->show();
    cancelButton->show();
}

void ConfirmWindow::closeWindow() {
    text->hide();
    name->hide();
    klass->hide();
    location->hide();
    nameOutput->hide();
    klassOutput->hide();
    locationOutput->hide();
    confirmButton->hide();
    cancelButton->hide();
}
