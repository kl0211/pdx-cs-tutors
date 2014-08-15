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
  assignButton = new QPushButton("Assign/Unassign me to\nthe selected student", parent);
  assignButton->move(300, 600);
  assignButton->resize(200, 75);
  assignButton->hide();

  removeButton = new QPushButton("Remove selected\nstudent from list", parent);
  removeButton->move(550, 600);
  removeButton->resize(200, 75);
  removeButton->hide();

  backButton = new QPushButton("Back", parent);
  backButton->move(800, 600);
  backButton->resize(200, 75);
  backButton->hide();
}

void TutorWindow::openWindow() {
  assignButton->show();
  removeButton->show();
  backButton->show();
}

void TutorWindow::closeWindow() {
  assignButton->hide();
  removeButton->hide();
  backButton->hide();
}
