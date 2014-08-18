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

#include "locationwindow.hpp"

LocationWindow::LocationWindow(QWidget * parent) : QWidget (parent) {
  textFont.setPointSize(24);

  buttonFont.setPointSize(16);
  buttonFont.setBold(true);

  text = new QLabel("Please select the approximate location where a tutor can find you", parent);
  text->move(100, 100);
  text->resize(1200, 300);
  text->hide();
  text->setFont(textFont);

  frontArea = new QPushButton("Front entrance\narea", parent);
  frontArea->move(225, 350);
  frontArea->resize(200, 75);
  frontArea->setFont(buttonFont);
  frontArea->hide();

  printer = new QPushButton("Back area\nnear printer", parent);
  printer->move(575, 350);
  printer->resize(200, 75);
  printer->setFont(buttonFont);
  printer->hide();

  lockerRoom = new QPushButton("Locker room", parent);
  lockerRoom->move(925, 350);
  lockerRoom->resize(200, 75);
  lockerRoom->setFont(buttonFont);
  lockerRoom->hide();

  penguinLab = new QPushButton("FAB 88-10\n(GNU/Linux Lab A)", parent);
  penguinLab->move(50, 500);
  penguinLab->resize(200, 75);
  penguinLab->setFont(buttonFont);
  penguinLab->hide();

  particleLab = new QPushButton("FAB 88-09\n(GNU/Linux Lab B)", parent);
  particleLab->move(400, 500);
  particleLab->resize(200, 75);
  particleLab->setFont(buttonFont);
  particleLab->hide();

  acm = new QPushButton("ACM room", parent);
  acm->move(750, 500);
  acm->resize(200, 75);
  acm->setFont(buttonFont);
  acm->hide();

  conference = new QPushButton("Conference room", parent);
  conference->move(1100, 500);
  conference->resize(200, 75);
  conference->setFont(buttonFont);
  conference->hide();

  cancelButton = new QPushButton("Start Over", parent);
  cancelButton->move(1150, 650);
  cancelButton->resize(200, 75);
  cancelButton->setFont(buttonFont);
  cancelButton->hide();
}

void LocationWindow::openWindow() {
  text->show();
  frontArea->show();
  printer->show();
  lockerRoom->show();
  penguinLab->show();
  particleLab->show();
  acm->show();
  conference->show();
  cancelButton->show();
}

void LocationWindow::closeWindow() {
  text->hide();
  frontArea->hide();
  printer->hide();
  lockerRoom->hide();
  penguinLab->hide();
  particleLab->hide();
  acm->hide();
  conference->hide();
  cancelButton->hide();
}
