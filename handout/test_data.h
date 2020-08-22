#ifndef TEST_DATA_H
#define TEST_DATA_H

#include <QtCore>
#include "config.h"

typedef int StudentId;
typedef QString StudentName;
typedef int CourseId;
typedef QString CourseName;

const QMap< StudentId, StudentName > STUDENTS = {
  { 1, "Müller" },
  { 2, "Meier" },
  { 11, "Staundörfer" },
  { 12, "Wölkchen" },
  { 13, "Walkes" },
  { 14, "Schweiger" },
  { 3, "Antonidas" },
  { 4, "Berghaus" },
  { 5, "Dörfer" },
  { 6, "Schmalweg" },
  { 7, "Müller" },
  { 8, "Wegmeister" },
  { 9, "Stollenhausen" },
  { 10, "Schmidt" },
  { 15, "Horn" }
};
const QMap< CourseId, CourseName >   COURSES            = {
  { 3, "Mathematik" },
  { 1, "Deutsch" },
  { 2, "Englisch" },
  { 4, "Software" }
};

const QMultiMap< StudentId, CourseId > STUDENTS_COURSES = {
  { 1, 1 },
  { 1, 3 },
  { 2, 1 },
  { 2, 3 },
  { 2, 4 },
  { 3, 2 },
  { 3, 3 },
  { 3, 4 },
  { 3, 1 },
  { 4, 1 },
  { 4, 3 },
  { 7, 1 },
  { 5, 3 },
  { 5, 4 },
  { 6, 2 },
  { 6, 3 },
  { 6, 4 }
};
#endif // TEST_DATA_H
