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

#include "mainwindow.hpp"
#include "signinwindow.hpp"
#include "registerwindow.hpp"

MainWindow::MainWindow() {
    signInWindow = new SignInWindow(this);
    registerWindow = new RegisterWindow(this);

    //pages->addWidget(signInWindow);
    //setCentralWidget(pages);
    signInWindow->openWindow();

    connect(signInWindow->regButton, SIGNAL(clicked()), this, SLOT(signInToRegister()));
    connect(registerWindow->cancelButton, SIGNAL(clicked()), this, SLOT(registerToSignIn()));

    setWindowTitle("PDX CS Tutors Sign in");
    resize(1280, 1024);
    //showFullScreen();
}

void MainWindow::signInToRegister() {
    signInWindow->closeWindow();
    registerWindow->openWindow();
}

void MainWindow::registerToSignIn() {
    registerWindow->closeWindow();
    signInWindow->openWindow();
}
