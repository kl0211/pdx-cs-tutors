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
#include "namewindow.hpp"
#include "registerwindow.hpp"
#include "classwindow.hpp"
#include "locationwindow.hpp"
#include "tutorwindow.hpp"
#include "confirmwindow.hpp"

MainWindow::MainWindow() {
    signInWindow = new SignInWindow(this);
    nameWindow = new NameWindow(this);
    registerWindow = new RegisterWindow(this);
    classWindow = new ClassWindow(this);
    locationWindow = new LocationWindow(this);
    confirmWindow = new ConfirmWindow(this);

    errorText = new QLabel(this);
    errorText->move(910, 525);
    errorText->resize(400, 30);
    errorText->hide();

    signInWindow->openWindow();

    connect(signInWindow->loginButton, SIGNAL(clicked()), this, SLOT(signInLogInButtonPressed()));
    connect(signInWindow->loginDialog, SIGNAL(returnPressed()), this, SLOT(signInLogInButtonPressed()));
    connect(signInWindow->noIdButton, SIGNAL(clicked()), this, SLOT(signInNoRegLogInButtonPressed()));

    connect(nameWindow->loginButton, SIGNAL(clicked()), this, SLOT(nameLogInButtonPressed()));
    connect(nameWindow->nameDialog, SIGNAL(returnPressed()), this, SLOT(nameLogInButtonPressed()));
    connect(nameWindow->cancelButton, SIGNAL(clicked()), this, SLOT(nameCancelButtonPressed()));

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
void MainWindow::signInLogInButtonPressed() {
    if (signInWindow->loginDialog->text() == NULL) {
        signInWindow->closeWindow();
        signInWindow->openWindow();
        errorText->setText("Please enter a valid ODIN ID");
        errorText->show();
        return;
    }
    url = "http://";
    url += HOST;
    url += ":";
    url += PORT;
    url += "/list/by_id?id=";
    url += signInWindow->loginDialog->text();
    //Need to query database for json object holding login information
    //if idNumber is a tutor's ID, go to the tutorwindow.
    //if idNumber is a registered number, go to classWindow
    //otherwise, idNumber is not registered, go to RegisterWindow
    errorText->hide();
    signInWindow->closeWindow();
    classWindow->openWindow();
}

void MainWindow::signInNoRegLogInButtonPressed() {
    errorText->hide();
    signInWindow->closeWindow();
    nameWindow->openWindow();
}

/*
 * Name Window SLOTS
 */
void MainWindow::nameLogInButtonPressed() {
    if (nameWindow->nameDialog->text() == NULL) {
        nameWindow->closeWindow();
        nameWindow->openWindow();
        errorText->setText("You appear to have no name! Please consult your parents.");
        errorText->show();
        return;
    }
    url = "http://";
    url += HOST;
    url += ":";
    url += PORT;
    url += "/list/by_name?name=";
    url += nameWindow->nameDialog->text();
    errorText->hide();
    nameWindow->closeWindow();
    classWindow->openWindow();
}

void MainWindow::nameCancelButtonPressed() {
    errorText->hide();
    nameWindow->closeWindow();
    signInWindow->openWindow();
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
    url += "&class=CS161";
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS162ButtonPressed() {
    url += "&class=CS162";
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS163ButtonPressed() {
    url += "&class=CS163";
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS201ButtonPressed() {
    url += "&class=CS201";
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS202ButtonPressed() {
    url += "&class=CS202";
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS250ButtonPressed() {
    url += "&class=CS250";
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS251ButtonPressed() {
    url += "&class=CS251";
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS300ButtonPressed() {
    url += "&class=CS300";
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCS311ButtonPressed() {
    url += "&class=CS311";
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classOtherButtonPressed() {
    url += "&class=Other";
    classWindow->closeWindow();
    locationWindow->openWindow();
}

void MainWindow::classCancelButtonPressed() {
    classWindow->closeWindow();
    signInWindow->openWindow();
}

/*
 * Location Window Button SLOTS
 */
void MainWindow::locationFrontButtonPressed() {
    url += "&location=front";
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationPrinterButtonPressed() {
    url += "&location=printer";
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationLockerButtonPressed() {
    url += "&location=locker";
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationPenguinButtonPressed() {
    url += "&location=laba";
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationParticleButtonPressed() {
    url += "&location=labb";
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationACMButtonPressed() {
    url += "&location=acm";
    locationWindow->closeWindow();
    confirmWindow->openWindow();
}

void MainWindow::locationCancelButtonPressed() {
    locationWindow->closeWindow();
    signInWindow->openWindow();
}

/*
 * Confirm Window Button SLOTS
 */
void MainWindow::confirmConfirmButtonPressed() {
    QTextStream(stdout) << url << endl;

    confirmWindow->closeWindow();
    signInWindow->openWindow();
}

void MainWindow::confirmCancelButtonPressed() {
    confirmWindow->closeWindow();
    signInWindow->openWindow();
}
