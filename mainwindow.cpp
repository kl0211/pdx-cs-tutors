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

Student::Student(QString id, QString name, QString klass, QString location, QString timeIn) {
  this->id = id;
  this->name = name;
  this->klass = klass;
  this->location = location;
  this->signInTime = timeIn;
  this->tutor = "";
  this->next = nullptr;
}

Student::~Student() {
  if (next != nullptr) delete next;
}

Queue::Queue() {
  this->toBeHelped = nullptr;
  this->finished = nullptr;
}

/**
 * @brief Queue::~Queue
 *      Destructor for the class containing the lists of students to be helped and
 *      who have been helped. If there have been helped students when the program
 *      ends, it will create a comma separated value file containing the student's
 *      class, time-in and helped time.
 */
Queue::~Queue() {
  if (finished != nullptr) {
    QString fileName = QDateTime::currentDateTime().toString("yyyy-MM-dd-HH:mm");
    fileName += ".csv"; //append .csv file extension to name
    Student * current = finished;
    QFile data(fileName);
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
      QTextStream out(&data);
      while (current != nullptr) {
        out << current->name << ',' << current->klass << ',' <<
          current->location << ',' << current->signInTime << ',' <<
          current->tutor << '\n';
        current = current->next;
      }
    }
    delete finished;
  }
  if (toBeHelped != nullptr) delete toBeHelped;
}

/**
 * @brief Queue::add
 *      Adds a student to the list of students that need to be helped
 * @param toAdd
 *      The student node being added to the list
 */
void Queue::add(Student * toAdd) {
  if (toBeHelped == nullptr)
    toBeHelped = toAdd;
  else if (toAdd->klass.compare("Other") != 0 &&      //if the node being added is "better" than
           toBeHelped->klass.compare("Other") == 0) { //the head node, make it the new head
    toAdd->next = toBeHelped;
    toBeHelped = toAdd;
  }
  else {
    if (toAdd->klass.compare("Other") == 0) { //if class is 'other', move to the end
      Student * current = toBeHelped;
      while (current->next != nullptr)
        current = current->next;
      current->next = toAdd;
    }
    else {                                    //else, move to the end or until the first 'other'
      Student * current = toBeHelped, * previous = toBeHelped;
      while (current != nullptr && current->klass.compare("Other") != 0) {
        previous = current;
        current = current->next;
      }
      previous->next = toAdd;
      toAdd->next = current;
    }
  }
}

/**
 * @brief Queue::addToFinished
 *      Takes a Student node and adds it to the list of helped students
 * @param toAdd
 *      The Student node to add to the finished list
 */
void Queue::addToFinished(Student * toAdd) {
  if (finished == nullptr)
    finished = toAdd;
  else {
    toAdd->next = finished;
    finished = toAdd;
  }
}

/**
 * @brief Queue::containsId
 *      Determines if the student with the given ID is on the list
 * @param id
 *      Student's id number
 * @return
 *      True if list contains student
 */
bool Queue::containsId(QString id) {
  if (toBeHelped == nullptr)
    return false;
  else {
    Student * current = toBeHelped;
    while (current != nullptr) {
      if (current->id.compare(id) == 0) {
        return true;
      }
      current = current->next;
    }
  }
  return false;
}

/**
 * @brief Queue::containsName
 *      Determines if the student with the given name is on the list
 * @param name
 *      Student's name
 * @return
 *      True if list contains student's name
 */
bool Queue::containsName(QString name) {
  if (toBeHelped == nullptr) {
    return false;
  }
  else {
    Student * current = toBeHelped;
    while (current != nullptr) {
      if (current->name.toLower().compare(name.toLower()) == 0) {
        return true;
      }
      current = current->next;
    }
  }
  return false;
}

/**
 * @brief Queue::removeFromList
 *      Removes a student from the list and moves them to the finished list
 * @param name
 *      The name of the student
 */
void Queue::removeFromList(QString name) {
  if (toBeHelped == nullptr) //if the list is empty
    return;
  else if (toBeHelped->name.compare(name) == 0) { //if the head ptr is being removed
    Student * temp = toBeHelped->next;
    toBeHelped->next = nullptr;
    addToFinished(toBeHelped);
    toBeHelped = temp;
  }
  else {
    Student * current = toBeHelped, * previous = toBeHelped;
    while (current != nullptr && current->name.compare(name) != 0) {
      previous = current;
      current = current->next;
    }
    if (current != nullptr) { //ensure that current has not gone beyond the last node
      previous->next = current->next;
      current->next = nullptr;
      addToFinished(current);
    }
  }
}

/**
 * @brief Queue::deleteFromList
 *      Removes a student from the list without adding them to the finished list
 * @param name
 *      The name of the student
 */
void Queue::deleteFromList(QString name) {
  if (toBeHelped == nullptr) //if the list is empty
    return;
  else if (toBeHelped->name.compare(name) == 0) { //if the head ptr is being removed
    Student * temp = toBeHelped->next;
    toBeHelped->next = nullptr;
    delete toBeHelped;
    toBeHelped = temp;
  }
  else {
    Student * current = toBeHelped, * previous = toBeHelped;
    while (current != nullptr && current->name.compare(name) != 0) {
      previous = current;
      current = current->next;
    }
    if (current != nullptr) { //ensure that current has not gone beyond the last node
      previous->next = current->next;
      current->next = nullptr;
      delete current;
    }
  }
}

RegInfo::RegInfo(QString id, QString name) {
  this->id = id;
  this->name = name;
  this->next = nullptr;
}

RegInfo::~RegInfo() {
  if (next) delete next;
}

Database::Database() {
  tableSize = 21;
  tutors = nullptr;
  table = new RegInfo * [tableSize];
  for (int i = 0; i < tableSize; ++i) {
    table[i] = nullptr;
  }
  QFile tutors("TutorList.txt");
  if (tutors.open(QFile::ReadOnly)) {
    QTextStream in(&tutors);
    QString id, name;
    while (!in.atEnd()) {
      QString line = in.readLine();
      QStringList fields = line.split(',');
      if (fields.size() == 2) {
        id = fields.takeFirst();
        name = fields.takeFirst();
      }
      addTutor(new RegInfo(id, name));
    }
  }
  QFile data("RegInfo.dat");
  if (data.open(QIODevice::ReadOnly)) {
    QDataStream in(&data);
    QString id, name;
    while (!in.atEnd()) {
      in >> id >> name;
      add(id, name);
    }
  }
}

Database::~Database() {
  writeOut();
  for (int i = 0; i < tableSize; ++i) {
    if (table[i]) delete table[i];
  }
}

void Database::add(QString id, QString name) {
  int key = hash(id);
  if (table[key] == nullptr) {
    table[key] = new RegInfo(id, name);
  }
  else {
    RegInfo * current = table[key];
    while (current->next) {
      current = current->next;
    }
    current->next = new RegInfo(id, name);
  }
  writeOut();
}

RegInfo * Database::getStudent(QString id) {
  int key = hash(id);
  if (table[key] == nullptr)
    return nullptr;
  else {
    RegInfo * current = table[key];
    while (current && current->id.compare(id) != 0) {
      current = current->next;
    }
    if (current) {
      return current;
    }
  }
  return nullptr;
}

RegInfo * Database::getTutor(QString id) {
  if (!tutors) {
    return nullptr;
  }
  else {
    RegInfo * current = tutors;
    while (current && current->id.compare(id) != 0) {
      current = current->next;
    }
    return current;
  }
}

void Database::addTutor(RegInfo * toAdd) {
  if (!tutors) {
    tutors = toAdd;
  }
  else {
    toAdd->next = tutors;
    tutors = toAdd;
  }
}

int Database::hash(QString id) {
  int sum = 0;
  int length = id.length();

  if (id.compare("") == 0)    //If the string is NULL
    return -1;  //Nothing to hash

  for (int i = 0; i < length; ++i)
    sum += id.at(i).digitValue() *                  //sum the string char * 7 powered to string length - index - 1
      abs(pow(float(7), float((length - i - 1))));    //absolute value to prevent negative numbers

  return sum % tableSize; //return the sum modulous the hash table size
}

void Database::writeOut() {
  QFile data("RegInfo.dat");
  if (data.open(QFile::WriteOnly)) {
    QDataStream out(&data);
    for (int i = 0; i < tableSize; ++i) {
      RegInfo * current = table[i];
      while (current) {
        out << current->id;
        out << current->name;
        current = current->next;
      }
    }
  }
}

MainWindow::MainWindow() {    
  signInWindow = new SignInWindow(this);
  nameWindow = new NameWindow(this);
  registerWindow = new RegisterWindow(this);
  classWindow = new ClassWindow(this);
  locationWindow = new LocationWindow(this);
  tutorWindow = new TutorWindow(this);
  confirmWindow = new ConfirmWindow(this);

  errorText = new QLabel(this);
  errorText->resize(400, 40);
  errorText->hide();

  numberOnList = 0;
  theList = new QTableWidget(0, 5, this);
  buildTable(numberOnList);

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
  connect(locationWindow->conference, SIGNAL(clicked()), this, SLOT(locationConferenceButtonPressed()));
  connect(locationWindow->cancelButton, SIGNAL(clicked()), this, SLOT(locationCancelButtonPressed()));

  connect(tutorWindow->assignButton, SIGNAL(clicked()), this, SLOT(tutorAssignButtonPressed()));
  connect(tutorWindow->removeButton, SIGNAL(clicked()), this, SLOT(tutorRemoveButtonPressed()));
  connect(tutorWindow->backButton, SIGNAL(clicked()), this, SLOT(tutorBackButtonPressed()));

  connect(confirmWindow->confirmButton, SIGNAL(clicked()), this, SLOT(confirmConfirmButtonPressed()));
  connect(confirmWindow->cancelButton, SIGNAL(clicked()), this, SLOT(confirmCancelButtonPressed()));

  setWindowTitle("PDX CS Tutors Sign in");
  resize(XRES, YRES);
  //showFullScreen();
}

/*
 * Sign-in Window SLOTS
 */
void MainWindow::signInLogInButtonPressed() {
  if (signInWindow->loginDialog->cursorPosition() < 9) {
    signInWindow->closeWindow();
    signInWindow->openWindow();
    errorText->move(910, 525);
    errorText->setText("Please enter a valid\n9-digit ODIN ID");
    errorText->show();
    return;
  }
  errorText->hide();
  id = signInWindow->loginDialog->text();
  RegInfo * tutor = database.getTutor(id);
  if (tutor) {
    name = tutor->name;
    theList->show();
    signInWindow->closeWindow();
    tutorWindow->openWindow();
  }
  else {
    RegInfo * student = database.getStudent(id);
    if (!student) { //if id is not in the database
      theList->hide();
      signInWindow->closeWindow();
      registerWindow->openWindow();
    }
    else { //if the id is registered, go to class window
      if (queue.containsId(student->id)) {
        errorText->move(910, 525);
        errorText->setText("You are already on queue");
        errorText->show();
        signInWindow->closeWindow();
        signInWindow->openWindow();
        return;
      }
      name = student->name;
      theList->hide();
      signInWindow->closeWindow();
      classWindow->openWindow();
    }
  }
}

void MainWindow::signInNoRegLogInButtonPressed() {
  errorText->hide();
  theList->hide();
  signInWindow->closeWindow();
  nameWindow->openWindow();
}

/*
 * Name Window SLOTS
 */
void MainWindow::nameLogInButtonPressed() {
  if (nameWindow->nameDialog->cursorPosition() < 3) {
    nameWindow->closeWindow();
    nameWindow->openWindow();
    errorText->move(910, 525);
    errorText->setText("Please enter a name with at least 3 characters");
    errorText->show();
    return;
  }
  name = nameWindow->nameDialog->text();
  if (queue.containsName(name)) {
    errorText->move(910, 525);
    errorText->setText("The name entered is already on the list.\nPlease choose a different name or register");
    errorText->show();
    nameWindow->closeWindow();
    theList->show();
    signInWindow->openWindow();
    return;
  }
  errorText->hide();
  nameWindow->closeWindow();
  classWindow->openWindow();
}

void MainWindow::nameCancelButtonPressed() {
  errorText->hide();
  nameWindow->closeWindow();
  theList->show();
  signInWindow->openWindow();
}

/*
 * Register Window SLOTS
 */
void MainWindow::registerRegisterButtonPressed() {
  if (registerWindow->nameDialog->cursorPosition() < 3) {
    registerWindow->nameDialog->clear();
    registerWindow->nameDialog->setFocus();
    errorText->move(910, 525);
    errorText->setText("Please enter a name with at least 3 characters");
    errorText->show();
    return;
  }
  name = registerWindow->nameDialog->text();
  database.add(id, name);
  errorText->hide();
  registerWindow->closeWindow();
  classWindow->openWindow();
}

void MainWindow::registerCancelButtonPressed() {
  errorText->hide();
  registerWindow->closeWindow();
  theList->show();
  signInWindow->openWindow();
}

void MainWindow::registerIDDialogEntered() {
  registerWindow->nameDialog->setFocus();
}

/*
 * Class Selection Window SLOTS
 */
void MainWindow::classCS161ButtonPressed() {
  klass = "CS161";
  classWindow->closeWindow();
  locationWindow->openWindow();
}

void MainWindow::classCS162ButtonPressed() {
  klass = "CS162";
  classWindow->closeWindow();
  locationWindow->openWindow();
}

void MainWindow::classCS163ButtonPressed() {
  klass = "CS163";
  classWindow->closeWindow();
  locationWindow->openWindow();
}

void MainWindow::classCS201ButtonPressed() {
  klass = "CS201";
  classWindow->closeWindow();
  locationWindow->openWindow();
}

void MainWindow::classCS202ButtonPressed() {
  klass = "CS202";
  classWindow->closeWindow();
  locationWindow->openWindow();
}

void MainWindow::classCS250ButtonPressed() {
  klass = "CS250";
  classWindow->closeWindow();
  locationWindow->openWindow();
}

void MainWindow::classCS251ButtonPressed() {
  klass = "CS251";
  classWindow->closeWindow();
  locationWindow->openWindow();
}

void MainWindow::classCS300ButtonPressed() {
  klass = "CS300";
  classWindow->closeWindow();
  locationWindow->openWindow();
}

void MainWindow::classCS311ButtonPressed() {
  klass = "CS311";
  classWindow->closeWindow();
  locationWindow->openWindow();
}

void MainWindow::classOtherButtonPressed() {
  klass = "Other";
  classWindow->closeWindow();
  locationWindow->openWindow();
}

void MainWindow::classCancelButtonPressed() {
  classWindow->closeWindow();
  theList->show();
  signInWindow->openWindow();
}

/*
 * Location Window Button SLOTS
 */
void MainWindow::locationFrontButtonPressed() {
  location = "front";
  locationWindow->closeWindow();
  confirmWindow->openWindow();
  showConfirm();
}

void MainWindow::locationPrinterButtonPressed() {
  location = "printer";
  locationWindow->closeWindow();
  confirmWindow->openWindow();
  showConfirm();
}

void MainWindow::locationLockerButtonPressed() {
  location = "locker";
  locationWindow->closeWindow();
  confirmWindow->openWindow();
  showConfirm();
}

void MainWindow::locationPenguinButtonPressed() {
  location = "laba";
  locationWindow->closeWindow();
  confirmWindow->openWindow();
  showConfirm();
}

void MainWindow::locationParticleButtonPressed() {
  location = "labb";
  locationWindow->closeWindow();
  confirmWindow->openWindow();
  showConfirm();
}

void MainWindow::locationACMButtonPressed() {
  location = "acm";
  locationWindow->closeWindow();
  confirmWindow->openWindow();
  showConfirm();
}

void MainWindow::locationConferenceButtonPressed() {
  location = "conference";
  locationWindow->closeWindow();
  confirmWindow->openWindow();
  showConfirm();
}

void MainWindow::locationCancelButtonPressed() {
  locationWindow->closeWindow();
  theList->show();
  signInWindow->openWindow();
  showConfirm();
}

/*
 * Tutor Window Button SLOTS
 */
void MainWindow::tutorAssignButtonPressed() {
  if (theList->currentItem() == nullptr) return;
  Student * current = queue.toBeHelped;
  QString name = theList->currentItem()->text();
  while (current && current->name.compare(name)) {
    current = current->next;
  }
  if (current) {
    if (current->tutor.compare(this->name) == 0)
      current->tutor = "";
    else
      current->tutor = this->name;
    updateTable();
  }
}

void MainWindow::tutorRemoveButtonPressed() {
  if (theList->currentItem() == nullptr) return;
  QString name = theList->currentItem()->text();
  queue.removeFromList(name);
  --numberOnList;
  updateTable();
}

void MainWindow::tutorBackButtonPressed() {
  tutorWindow->closeWindow();
  signInWindow->openWindow();
}


/*
 * Confirm Window Button SLOTS
 */
void MainWindow::confirmConfirmButtonPressed() {
  if (id.compare("") != 0)
    queue.add(new Student(id, name, klass, location, QTime::currentTime().toString()));
  else
    queue.add(new Student("0", name, klass, location, QTime::currentTime().toString()));
  ++numberOnList;
  updateTable();
  confirmWindow->closeWindow();
  hideConfirm();
  theList->show();
  signInWindow->openWindow();
}

void MainWindow::confirmCancelButtonPressed() {
  confirmWindow->closeWindow();
  hideConfirm();
  theList->show();
  signInWindow->openWindow();
}

/*
 * Private MainWindow functions
 */
void MainWindow::showConfirm() {
  confirmWindow->nameOutput->setText(name);
  confirmWindow->klassOutput->setText(klass);
  confirmWindow->locationOutput->setText(fullLocation(location));
}

void MainWindow::hideConfirm() {
  confirmWindow->nameOutput->setText("");
  confirmWindow->klassOutput->setText("");
  confirmWindow->locationOutput->setText("");
}

QString MainWindow::fullLocation(QString loc) {
  if (loc.compare("front") == 0) return QString("Front entrance area");
  else if (loc.compare("printer") == 0) return QString("Back area near printer");
  else if (loc.compare("locker") == 0) return QString("Locker room");
  else if (loc.compare("laba") == 0) return QString("FAB 88-10\n(GNU/Linux Lab A)");
  else if (loc.compare("labb") == 0) return QString("FAB 88-09\n(GNU/Linux Lab B)");
  else if (loc.compare("acm") == 0) return QString("ACM Room");
  else return QString("Conference room");
}

void MainWindow::buildTable(int rows) {
  theList->removeRow(rows);
  theList->insertRow(rows);
  theList->move(260, 100);
  theList->resize(850, 300);
  theList->setHorizontalHeaderLabels(QStringList() << "Name" << "Class" << "Location" << "Sign-in Time" << "Being Helped by");
  theList->setEditTriggers(QAbstractItemView::NoEditTriggers);
  theList->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
  theList->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
  theList->setColumnWidth(0, 200);
  theList->setColumnWidth(1, 75);
  theList->setColumnWidth(2, 225);
  theList->setColumnWidth(4, 200);
}

void MainWindow::updateTable() {
  theList->clearContents();
  buildTable(numberOnList);
  Student * current = queue.toBeHelped;
  int row = 0;
  while (current) {
    theList->setItem(row, 0, new QTableWidgetItem(current->name));
    theList->setItem(row, 1, new QTableWidgetItem(current->klass));
    theList->setItem(row, 2, new QTableWidgetItem(fullLocation(current->location)));
    theList->setItem(row, 3, new QTableWidgetItem(current->signInTime));
    theList->setItem(row, 4, new QTableWidgetItem(current->tutor));
    current = current->next;
    ++row;
  }
}
