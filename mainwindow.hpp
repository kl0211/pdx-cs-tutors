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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <QTextStream>
#include <QLabel>
using namespace std;
using namespace cURLpp;

class SignInWindow;
class NameWindow;
class RegisterWindow;
class ClassWindow;
class LocationWindow;
class ConfirmWindow;

class MainWindow : public QMainWindow {
    Q_OBJECT

    Easy * handle;
    QString url;
    QLabel * errorText;
    SignInWindow * signInWindow;
    NameWindow * nameWindow;
    RegisterWindow * registerWindow;
    ClassWindow * classWindow;
    LocationWindow * locationWindow;
    ConfirmWindow * confirmWindow;

private slots:
    void signInLogInButtonPressed();
    void signInNoRegLogInButtonPressed();

    void nameLogInButtonPressed();
    void nameCancelButtonPressed();

    void registerCancelButtonPressed();
    void registerRegisterButtonPressed();

    void classCS161ButtonPressed();
    void classCS162ButtonPressed();
    void classCS163ButtonPressed();
    void classCS201ButtonPressed();
    void classCS202ButtonPressed();
    void classCS250ButtonPressed();
    void classCS251ButtonPressed();
    void classCS300ButtonPressed();
    void classCS311ButtonPressed();
    void classOtherButtonPressed();
    void classCancelButtonPressed();

    void locationFrontButtonPressed();
    void locationPrinterButtonPressed();
    void locationLockerButtonPressed();
    void locationPenguinButtonPressed();
    void locationParticleButtonPressed();
    void locationACMButtonPressed();
    void locationCancelButtonPressed();

    void confirmConfirmButtonPressed();
    void confirmCancelButtonPressed();

public:
    MainWindow();
};

#endif
