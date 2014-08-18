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

#include "tutorwindow.hpp"

TutorWindow::TutorWindow(QWidget * parent) : QWidget(parent) {
  buttonFont.setPointSize(16);
  buttonFont.setBold(true);

  assignButton = new QPushButton("Assign/Unassign me to\nthe selected student", parent);
  assignButton->move(300, 425);
  assignButton->resize(300, 100);
  assignButton->setFont(buttonFont);
  assignButton->hide();

  removeButton = new QPushButton("Remove selected\nstudent from list", parent);
  removeButton->move(650, 425);
  removeButton->resize(300, 100);
  removeButton->setFont(buttonFont);
  removeButton->hide();

  signInButton = new QPushButton("Sign me in/out", parent);
  signInButton->move(1075, 425);
  signInButton->resize(200, 75);
  signInButton->setFont(buttonFont);
  signInButton->hide();

  backButton = new QPushButton("Back", parent);
  backButton->move(1150, 650);
  backButton->resize(200, 75);
  backButton->setFont(buttonFont);
  backButton->hide();
}

void TutorWindow::openWindow() {
  assignButton->show();
  removeButton->show();
  signInButton->show();
  backButton->show();
}

void TutorWindow::closeWindow() {
  assignButton->hide();
  removeButton->hide();
  signInButton->hide();
  backButton->hide();
}
