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
#include "classwindow.hpp"
#include "locationwindow.hpp"
#include "tutorwindow.hpp"

MainWindow::MainWindow() {
    signInWindow = new SignInWindow(this);
    registerWindow = new RegisterWindow(this);
    classWindow = new ClassWindow(this);
    locationWindow = new LocationWindow(this);

    signInWindow->openWindow();

    connect(signInWindow->regButton, SIGNAL(clicked()), this, SLOT(signInRegisterButtonPressed()));
    connect(signInWindow->loginButton, SIGNAL(clicked()), this, SLOT(signInLogInButtonPressed()));
    connect(signInWindow->noIdButton, SIGNAL(clicked()), this, SLOT(signInNoRegLogInButtonPressed()));

    connect(registerWindow->cancelButton, SIGNAL(clicked()), this, SLOT(registerCancelButtonPressed()));
    connect(registerWindow->regButton, SIGNAL(clicked()), this, SLOT(registerRegisterButtonPressed()));

    connect(classWindow->cs161, SIGNAL(clicked()), this, SLOT(classCS161ButtonPressed()));
    connect(classWindow->cancelButton, SIGNAL(clicked()), this, SLOT(classCancelButtonPressed()));

    connect(locationWindow->frontArea, SIGNAL(clicked()), this, SLOT(locationFrontButtonPressed()));
    connect(locationWindow->printer, SIGNAL(clicked()), this, SLOT(locationPrinterButtonPressed()));
    connect(locationWindow->lockerRoom, SIGNAL(clicked()), this, SLOT(locationLockerButtonPressed()));
    connect(locationWindow->penguinLab, SIGNAL(clicked()), this, SLOT(locationPenguinButtonPressed()));
    connect(locationWindow->particleLab, SIGNAL(clicked()), this, SLOT(locationParticleButtonPressed()));
    connect(locationWindow->acm, SIGNAL(clicked()), this, SLOT(locationACMButtonPressed()));
    connect(locationWindow->cancelButton, SIGNAL(clicked()), this, SLOT(locationCancelButtonPressed()));

    setWindowTitle("PDX CS Tutors Sign in");
    resize(800, 600);
    //showFullScreen();
}

/*
 * Sign-in Window SLOTS
 */
void MainWindow::signInRegisterButtonPressed() {
    signInWindow->closeWindow();
    //do stuff
    registerWindow->openWindow();
}

void MainWindow::signInLogInButtonPressed() {
    signInWindow->closeWindow();
    /* If a tutor is signing in, open tutorWindow.
     * otherwise, open to classWindow
     */
    classWindow->openWindow();
}

void MainWindow::signInNoRegLogInButtonPressed() {
    signInWindow->closeWindow();
    //do stuff
    classWindow->openWindow();
}

/*
 * Register Window SLOTS
 */
void MainWindow::registerCancelButtonPressed() {
    registerWindow->closeWindow();
    //do stuff
    signInWindow->openWindow();
}

void MainWindow::registerRegisterButtonPressed() {
    registerWindow->closeWindow();
    //do stuff
    signInWindow->openWindow();
}

/*
 * Class Selection Window SLOTS
 */
void MainWindow::classCS161ButtonPressed() {
    classWindow->closeWindow();
    //do stuff
    locationWindow->openWindow();
}

void MainWindow::classCancelButtonPressed() {
    classWindow->closeWindow();
    //do stuff
    signInWindow->openWindow();
}

/*
 * Location Window Button SLOTS
 */
void MainWindow::locationFrontButtonPressed() {
    locationWindow->closeWindow();
    //do stuff
    signInWindow->openWindow();
}

void MainWindow::locationPrinterButtonPressed() {
    locationWindow->closeWindow();
    //do stuff
    signInWindow->openWindow();
}

void MainWindow::locationLockerButtonPressed() {
    locationWindow->closeWindow();
    //do stuff
    signInWindow->openWindow();
}

void MainWindow::locationPenguinButtonPressed() {
    locationWindow->closeWindow();
    //do stuff
    signInWindow->openWindow();
}

void MainWindow::locationParticleButtonPressed() {
    locationWindow->closeWindow();
    //do stuff
    signInWindow->openWindow();
}

void MainWindow::locationACMButtonPressed() {
    locationWindow->closeWindow();
    //do stuff
    signInWindow->openWindow();
}

void MainWindow::locationCancelButtonPressed() {
    locationWindow->closeWindow();
    //do stuff
    signInWindow->openWindow();
}
