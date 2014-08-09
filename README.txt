pdx-cs-tutors
=============

An electronic sign-in application for the CS Tutors at Portland State
University

Author(s): Rob Werfelmann - rob AT werfelmann DOT com


Description:

The purpose of this application is to replace the old pen-and-paper method
of signing students in to get CS tutoring. While signing students in with
paper has worked well in the past, the increase of students has led to the
following problems:

    - There are students who fail to write down important information such
      as the class they want help with. These are usually classes which are
      not supported by the CS tutors. This leads to the tutor having to
      explain that they might not be able to help them.

    - Some students sign in, and then cross their name off the list before
      they have been helped. This confuses other students who might think
      the tutors have helped that person and skipped others.

    - There is no easy way to generate any statistics with paper sign-ins
      without spending a great deal of time plotting the data manually.

With a this application, students will be able to sign-up without having to
write anything down. If they are registered, they can use their ID card
with a barcode reader to quickly sign-in without having to type anything
in. Tutors will also be able to quickly assign themselves to a student and
remove them from the waiting list.



Download/Build Instructions:

You can download the latest stable release at:
https://github.com/kl0211/pdx-cs-tutors/archive/master.zip

This application was written in C++ using the Qt5 frameworks. Make sure you
have the required libraries before building. If running on Debian or a
Debian derivative, an easy way to do this would be to use the following
command:

     # apt-get install qt5-default qt5-qmake

     or if using sudo

     $ sudo apt-get install qt5-default qt5-qmake

In the top-level directory, issue the commands:

     $ qmake -makefile
     $ make

And then to run the program, simple issue:

     $ ./pdx-cs-tutors
