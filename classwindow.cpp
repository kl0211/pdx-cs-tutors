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

#include "classwindow.hpp"

ClassWindow::ClassWindow(QWidget * parent) : QWidget (parent) {
  font.setPointSize(24);
  text = new QLabel("Please select one of the supported classes below\n"
                    "NOTE: Supported classes will always have priority over non-supported classes\n"
                    "So by choosing \"Other\" your waiting time may be significantly extended", parent);
  text->move(100, 100);
  text->resize(1200, 300);
  text->hide();
  text->setFont(font);

  cs161 = new QPushButton("CS161", parent);
  cs161->move(50, 400);
  cs161->resize(200, 75);
  cs161->hide();

  cs162 = new QPushButton("CS162", parent);
  cs162->move(300, 400);
  cs162->resize(200, 75);
  cs162->hide();

  cs163 = new QPushButton("CS163", parent);
  cs163->move(550, 400);
  cs163->resize(200, 75);
  cs163->hide();

  cs201 = new QPushButton("CS201", parent);
  cs201->move(800, 400);
  cs201->resize(200, 75);
  cs201->hide();

  cs202 = new QPushButton("CS202", parent);
  cs202->move(1050, 400);
  cs202->resize(200, 75);
  cs202->hide();

  cs250 = new QPushButton("CS250", parent);
  cs250->move(50, 500);
  cs250->resize(200, 75);
  cs250->hide();

  cs251 = new QPushButton("CS251", parent);
  cs251->move(300, 500);
  cs251->resize(200, 75);
  cs251->hide();

  cs300 = new QPushButton("CS300", parent);
  cs300->move(550, 500);
  cs300->resize(200, 75);
  cs300->hide();

  cs311 = new QPushButton("CS311", parent);
  cs311->move(800, 500);
  cs311->resize(200, 75);
  cs311->hide();

  other = new QPushButton("Other", parent);
  other->move(1050, 500);
  other->resize(200, 75);
  other->hide();

  cancelButton = new QPushButton("Start Over", parent);
  cancelButton->move(1150, 650);
  cancelButton->resize(200, 75);
  cancelButton->hide();
}

void ClassWindow::openWindow() {
  text->show();
  cs161->show();
  cs162->show();
  cs163->show();
  cs201->show();
  cs202->show();
  cs250->show();
  cs251->show();
  cs300->show();
  cs311->show();
  other->show();
  cancelButton->show();
}

void ClassWindow::closeWindow() {
  text->hide();
  cs161->hide();
  cs162->hide();
  cs163->hide();
  cs201->hide();
  cs202->hide();
  cs250->hide();
  cs251->hide();
  cs300->hide();
  cs311->hide();
  other->hide();
  cancelButton->hide();
}
