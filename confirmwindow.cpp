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
  textFont.setPointSize(24);

  buttonFont.setPointSize(24);
  buttonFont.setBold(true);

  text = new QLabel("Please confirm that the following information is correct", parent);
  text->move(100, 100);
  text->resize(1200, 300);
  text->hide();
  text->setFont(textFont);

  name = new QLabel("Name:", parent);
  name->resize(300, 50);
  name->move(300, 300);
  name->setFont(textFont);
  name->hide();

  nameOutput = new QLabel(parent);
  nameOutput->resize(1000, 50);
  nameOutput->move(500, 300);
  nameOutput->setFont(textFont);
  nameOutput->hide();

  klass = new QLabel("Class:", parent);
  klass->resize(300, 50);
  klass->move(300, 375);
  klass->setFont(textFont);
  klass->hide();

  klassOutput = new QLabel(parent);
  klassOutput->resize(1000, 50);
  klassOutput->move(500, 375);
  klassOutput->setFont(textFont);
  klassOutput->hide();

  location = new QLabel("Location:", parent);
  location->resize(300, 75);
  location->move(300, 450);
  location->setFont(textFont);
  location->hide();

  locationOutput = new QLabel(parent);
  locationOutput->resize(1000, 75);
  locationOutput->move(500, 450);
  locationOutput->setFont(textFont);
  locationOutput->hide();

  confirmButton = new QPushButton("Confirm", parent);
  confirmButton->resize(300, 75);
  confirmButton->move(300, 600);
  confirmButton->setFont(buttonFont);
  confirmButton->hide();

  cancelButton = new QPushButton("Start Over", parent);
  cancelButton->resize(300, 75);
  cancelButton->move(800, 600);
  cancelButton->setFont(buttonFont);
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
