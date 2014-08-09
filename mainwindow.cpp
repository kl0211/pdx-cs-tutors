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

Student::Student(QString name, QString klass, QString location, QString timeIn) {
    this->name = name;
    this->klass = klass;
    this->location = location;
    this->timeIn = timeIn;
    this->tutor = "";
    this->next = NULL;
}

Student::~Student() {
    delete next;
}

Queue::Queue() {
    this->head = NULL;
}

Queue::~Queue() {
    if (head) delete head;
}

void Queue::add(Student * toAdd) {
    if (!head)
        head = toAdd;
    else if (toAdd->klass.compare("Other") != 0 &&
             head->klass.compare("Other") == 0) {
        toAdd->next = head;
        head = toAdd;
    }
    else {
        if (toAdd->klass.compare("Other") == 0) {
            Student * current = head;
            while (current->next)
                current = current->next;
            current->next = toAdd;
        }
        else {
            Student * current = head, * previous = head;
            while (current && current->klass.compare("Other") != 0) {
                previous = current;
                current = current->next;
            }
            previous->next = toAdd;
            toAdd->next = current;
        }
    }
}

void Queue::remove(QString name) {
    if (!head)
        return;
    else if (head->name.compare(name) == 0) {
        Student * temp = head->next;
        head->next = NULL;
        delete head;
        head = temp;
    }
    else {
        Student * current = head, * previous = head;
        while (current && current->name.compare(name) != 0) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        current->next = NULL;
        delete current;
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
    theList = NULL;
    buildTable(numberOnList);

    signInWindow->openWindow();

    connect(signInWindow->loginButton, SIGNAL(clicked()), this, SLOT(signInLogInButtonPressed()));
    connect(signInWindow->loginDialog, SIGNAL(returnPressed()), this, SLOT(signInLogInButtonPressed()));
    connect(signInWindow->noIdButton, SIGNAL(clicked()), this, SLOT(signInNoRegLogInButtonPressed()));
    connect(signInWindow->tutorButton, SIGNAL(clicked()), this, SLOT(signInTutorButtonPressed()));

    connect(nameWindow->loginButton, SIGNAL(clicked()), this, SLOT(nameLogInButtonPressed()));
    connect(nameWindow->nameDialog, SIGNAL(returnPressed()), this, SLOT(nameLogInButtonPressed()));
    connect(nameWindow->cancelButton, SIGNAL(clicked()), this, SLOT(nameCancelButtonPressed()));

    connect(registerWindow->cancelButton, SIGNAL(clicked()), this, SLOT(registerCancelButtonPressed()));
    connect(registerWindow->regButton, SIGNAL(clicked()), this, SLOT(registerRegisterButtonPressed()));
    connect(registerWindow->IDDialog, SIGNAL(returnPressed()), this, SLOT(registerIDDialogEntered()));

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
    id = signInWindow->loginDialog->text();
    //Need to query database for json object holding login information
    //if idNumber is a tutor's ID, go to the tutorwindow.
    //if idNumber is a registered number, go to classWindow
    //otherwise, idNumber is not registered, go to RegisterWindow
    errorText->hide();
    theList->hide();
    signInWindow->closeWindow();
    registerWindow->openWindow();
}

void MainWindow::signInNoRegLogInButtonPressed() {
    errorText->hide();
    theList->hide();
    signInWindow->closeWindow();
    nameWindow->openWindow();
}

void MainWindow::signInTutorButtonPressed() {
    errorText->hide();
    signInWindow->closeWindow();
    tutorWindow->openWindow();
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
    if (registerWindow->IDDialog->cursorPosition() < 9) {
        registerWindow->IDDialog->clear();
        registerWindow->nameDialog->clear();
        registerWindow->IDDialog->setFocus();
        errorText->move(610, 330);
        errorText->setText("Please enter a valid 9-digit ODIN ID");
        errorText->show();
        return;
    }
    if (registerWindow->nameDialog->cursorPosition() < 3) {
        registerWindow->IDDialog->clear();
        registerWindow->nameDialog->clear();
        registerWindow->IDDialog->setFocus();
        errorText->move(610, 430);
        errorText->setText("Please enter a name with at least 3 characters");
        errorText->show();
        return;
    }
    id = registerWindow->IDDialog->text();
    name = registerWindow->nameDialog->text();
    //TODO: sent http post to add id -> name into database
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
    if (theList->currentItem() == NULL) return;
    Student * current = queue.head;
    QString name = theList->currentItem()->text();
    while (current && current->name.compare(name)) {
        current = current->next;
    }
    if (current) {
        if (current->tutor.compare("a Tutor") == 0)
            current->tutor = "";
        else
            current->tutor = "a Tutor";
        updateTable();
    }
}

void MainWindow::tutorRemoveButtonPressed() {

}

void MainWindow::tutorBackButtonPressed() {
    tutorWindow->closeWindow();
    signInWindow->openWindow();
}


/*
 * Confirm Window Button SLOTS
 */
void MainWindow::confirmConfirmButtonPressed() {
    url = "http://"; url += HOST; url+= ":"; url += PORT;
    url += "/applet/servlet?name=";
    url += name; url += "&klass="; url += klass;
    url += "&location="; url += location;
    QTextStream(stdout) << url << endl;

    queue.add(new Student(name, klass, location, QTime::currentTime().toString()));
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
    if (theList)
        theList->~QTableWidget();
    theList = new QTableWidget(rows, 5, this);
    theList->move(260, 100);
    theList->resize(850, 300);
    theList->setHorizontalHeaderLabels(QStringList() << "Name" << "Class" << "Location" << "Sign-in Time" << "Helped by");
    theList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    theList->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    theList->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    theList->setColumnWidth(0, 200);
    theList->setColumnWidth(1, 75);
    theList->setColumnWidth(2, 225);
    theList->setColumnWidth(4, 200);
}

void MainWindow::updateTable() {
    buildTable(numberOnList);
    Student * current = queue.head;
    int row = 0;
    while (current) {
        theList->setItem(row, 0, new QTableWidgetItem(current->name));
        theList->setItem(row, 1, new QTableWidgetItem(current->klass));
        theList->setItem(row, 2, new QTableWidgetItem(fullLocation(current->location)));
        theList->setItem(row, 3, new QTableWidgetItem(current->timeIn));
        theList->setItem(row, 4, new QTableWidgetItem(current->tutor));
        current = current->next;
        ++row;
    }
}
