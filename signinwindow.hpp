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

#ifndef SIGNINWINDOW_HPP
#define SIGNINWINDOW_HPP

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QRegExpValidator>

class SignInWindow : public QWidget {
  Q_OBJECT

  static const int startXPos = 300;
  static const int startYPos = 100;

public:
  QPushButton * loginButton, * noIdButton;
  QLineEdit * loginDialog;
  QLabel * logo, * title, * loginText;
  QFont font;

  SignInWindow(QWidget * parent = 0);
  void openWindow();
  void closeWindow();
};

#endif
