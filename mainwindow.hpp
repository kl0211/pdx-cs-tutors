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
#include <QTextStream>
#include <QFile>
#include <QLabel>
#include <QTime>
#include <QTableWidget>
#include <QHeaderView>
#include <cmath>

using namespace std;

class SignInWindow;
class NameWindow;
class RegisterWindow;
class ClassWindow;
class LocationWindow;
class TutorWindow;
class ConfirmWindow;

struct Student {
  Student(QString, QString, QString, QString, QTime);
  ~Student();

  QString id, name, klass, location, tutor;
  QTime signInTime, helpedTime, finishedTime;
  Student * next;
};

struct Queue {
  Queue();
  ~Queue();
  void add(Student *);
  bool containsId(QString);
  bool containsName(QString);
  void removeFromList(QString);
  void deleteFromList(QString);
  void addToFinished(Student *);
  Student * toBeHelped;
  Student * finished;
};

struct Tutor {
    Tutor(QString, QString);
    ~Tutor();

    QString id, name;
    Tutor * next;
};

struct TutorsOnDuty {
    TutorsOnDuty();
    ~TutorsOnDuty();
    void add(Tutor *);
    void remove(QString);
    bool containsId(QString);
    Tutor * head;
};

struct RegInfo {
  RegInfo(QString, QString);
  ~RegInfo();
  QString id;
  QString name;
  RegInfo * next;
};

struct Database {
  Database();
  ~Database();
  void addStudent(QString, QString);
  RegInfo * getStudent(QString);
  RegInfo * getTutor(QString);

private:
  int tableSize;
  RegInfo * tutors;
  RegInfo ** table;
  void addTutor(RegInfo *);
  int hash(QString);
  void writeOut();
};

const int XRES = 1366, YRES = 768;

class MainWindow : public QMainWindow {
  Q_OBJECT

  int numberOnList;
  int numberOfTutorsOnDuty;
  QString url, id, name, klass, location;
  QLabel * errorText;
  QTableWidget * theList, * tutorsOnDutyList;
  TutorsOnDuty tutorsOnDuty;
  Queue queue;
  Database database;
  SignInWindow * signInWindow;
  NameWindow * nameWindow;
  RegisterWindow * registerWindow;
  ClassWindow * classWindow;
  LocationWindow * locationWindow;
  TutorWindow * tutorWindow;
  ConfirmWindow * confirmWindow;

  void showConfirm();
  void hideConfirm();
  QString fullLocation(QString);
  void buildTable(int);
  void updateTable();
  void buildTutorList(int);
  void updateTutorList();

private slots:
  void signInLogInButtonPressed();
  void signInNoRegLogInButtonPressed();

  void nameLogInButtonPressed();
  void nameCancelButtonPressed();

  void registerRegisterButtonPressed();
  void registerCancelButtonPressed();
  void registerIDDialogEntered();

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
  void locationConferenceButtonPressed();
  void locationCancelButtonPressed();

  void tutorAssignButtonPressed();
  void tutorRemoveButtonPressed();
  void tutorSignInButtonPressed();
  void tutorBackButtonPressed();

  void confirmConfirmButtonPressed();
  void confirmCancelButtonPressed();

public:
  MainWindow();
};

#endif
