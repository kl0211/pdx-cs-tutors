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
#include "confirmwindow.hpp"

MainWindow::MainWindow() {
    signInWindow = new SignInWindow(this);
    registerWindow = new RegisterWindow(this);
    classWindow = new ClassWindow(this);
    locationWindow = new LocationWindow(this);
    confirmWindow = new ConfirmWindow(this);

    signInWindow->openWindow();

    connect(signInWindow->regButton, SIGNAL(clicked()), this, SLOT(signInRegisterButtonPressed()));
    connect(signInWindow->loginButton, SIGNAL(clicked()), this, SLOT(signInLogInButtonPressed()));
    connect(signInWindow->noIdButton, SIGNAL(clicked()), this, SLOT(signInNoRegLogInButtonPressed()));

    connect(registerWindow->cancelButton, SIGNAL(clicked()), this, SLOT(registerCancelButtonPressed()));
    connect(registerWindow->regButton, SIGNAL(clicked()), this, SLOT(registerRegisterButtonPressed()));

    connect(classWindow->cs161, SIGNAL(clicked()), this, SLOT(classCS161ButtonPressed()));
    connect(classWindow->cs162, SIGNAL(clicked()), this, SLOT(classCS162ButtonPressed()));
    connect(classWindow->cs163, SIGNAL(clicked()), this, SLOT(classCS163ButtonPressed()));
    connect(classWindow->cs201, SIGNAL(clicked()), this, SLOT(classCS201ButtonPressed()));
    connect(classWindow->cs202, SIGNAL(clicked()), this, SLOT(classCS202ButtonPressed()));
    connect(classWindow->cs250, SIGNAL(clicked()), this, SLOT(classCS250ButtonPressed()));
    connect(classWindow->cs251, SIGNAL(clicked()), this, SLOT(classCS251ButtonPressed()));
    connect(classWindow->cs300, SIGNAL(clicked()), this, SLOT(classCS300ButtonPressed()));
    connect(classWindow->cs311, SIGNAL(clicked()), this, SLOT(classCS311ButtonPressed()));
    connect(classWindow->other, SIGNAL(clicked()), this, SLOT(classOtherButtonPressed()));
    connect(classWindow->cancelButton, SIGNAL(clicked()), this, SLOT(classCancelButtonPressed()));

    connect(locationWindow->frontArea, SIGNAL(clicked()), this, SLOT(locationFrontButtonPressed()));
    connect(locationWindow->printer, SIGNAL(clicked()), this, SLOT(locationPrinterButtonPressed()));
    connect(locationWindow->lockerRoom, SIGNAL(clicked()), this, SLOT(locationLockerButtonPressed()));
    connect(locationWindow->penguinLab, SIGNAL(clicked()), this, SLOT(locationPenguinButtonPressed()));
    connect(locationWindow->particleLab, SIGNAL(clicked()), this, SLOT(locationParticleButtonPressed()));
    connect(locationWindow->acm, SIGNAL(clicked()), this, SLOT(locationACMButtonPressed()));
    connect(locationWindow->cancelButton, SIGNAL(clicked()), this, SLOT(locationCancelButtonPressed()));

    connect(confirmWindow->confirmButton, SIGNAL(clicked()), this, SLOT(confirmConfirmButtonPressed()));
    connect(confirmWindow->cancelButton, SIGNAL(clicked()), this, SLOT(confirmCancelButtonPressed()));

    setWindowTitle("PDX CS Tutors Sign in");
    resize(1366, 768);
    //showFullScreen();
}

/*
 * Sign-in Window SLOTS
 */
void MainWindow::signInRegisterButtonPressed() {
    //do stuff
    signInWindow->closeWindow();
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
    //do stuff
    signInWindow->closeWindow();
    classWindow->openWindow();
}

/*
 * Register Window SLOTS
 */
void MainWindow::registerCancelButtonPressed() {
    //do stuff
    registerWindow->closeWindow();
    signInWindow->openWindow();
}

void MainWindow::registerRegisterButtonPressed() {
    //do stuff
    registerWindow->closeWindow();
    signInWindow->openWindow();
}

/*
 * Class Selection Window SLOTS
 */
void MainWindow::classCS161ButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS162ButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS163ButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS201ButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS202ButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS250ButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS251ButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS300ButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS311ButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classOtherButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCancelButtonPressed() {
    //do stuff
    classWindow->closeWindow();
    signInWindow->openWindow();
}

/*
 * Location Window Button SLOTS
 */
void MainWindow::locationFrontButtonPressed() {
    //do stuff
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationPrinterButtonPressed() {
    //do stuff
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationLockerButtonPressed() {
    //do stuff
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationPenguinButtonPressed() {
    //do stuff
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationParticleButtonPressed() {
    //do stuff
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationACMButtonPressed() {
    //do stuff
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationCancelButtonPressed() {
    //do stuff
    locationWindow->closeWindow();
    signInWindow->openWindow();
}

/*
 * Confirm Window Button SLOTS
 */
void MainWindow::confirmConfirmButtonPressed() {
    //do stuff
    confirmWindow->closeWindow();
    signInWindow->openWindow();
}

void MainWindow::confirmCancelButtonPressed() {
    //do stuff
    confirmWindow->closeWindow();
    signInWindow->openWindow();
}
