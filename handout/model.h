#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "database.h"

class Model : public QObject
{
  Q_OBJECT
private:
  static Model*  singleton;
  Database* db;
protected:
  Model( QObject *parent = nullptr );
public:
  static Model* get();
  ~Model();
  int          getStudentCount( void ) const;
  int          getStudentCount( int courseId ) const;
  int          getCourseCount( void ) const;
  int          getCourseCount( int studentId ) const;
  int          getMaxStudentCountInACourse( void ) const;
  QList< int > getCourseIds( void ) const;
  QList< int > getStudentIds( void ) const;
  QString      getCourseName( int courseId ) const;
};



/// \file model.h
/// \brief Schnittstelle zwischen Datenbank und Programmcode
/// \class Model
/// Die Klasse Model ist der Kernbestandteil in Bezug zu Daten. Es lässt sich nur als Singleton erstellen,
/// was heißt, dass nur ein Model-Objekt generiert und gebraucht wird.
///
///\var static Model* Model::singleton
/// \brief maximal einmalig-vorhandene Model-Instanz
/// Zu Beginn des Quellcodes ist diese Model::singleton als Nullpointer gesetzt, da er erstmalig von \link static Model::Model* get() \endlink initialisiert werden muss.
///
///\var Database* Model::db
/// \brief maximal einmalig-vorhandene Database-Instanz
/// db ist ein Objekt, welches Daten direkt aus schooldata.db entnimmt.
///
///\fn int Model::getStudentCount( void ) const
/// \brief Methode, welche Anzahl von allen Schülern zurück
/// Diese Funktion ruft eine Methode von \link Model::db \endlink auf
/// \return Gesamtanzahl an Schülern
///
///\fn int Model::getStudentCount( int courseId ) const
/// \brief gibt Anzahl von allen Schülern eines bestimmten Kurses zurück
/// \param int courseId Bestimmung des Kurses
/// Diese Funktion ruft eine Methode von \link Model::db \endlink auf
/// \return Gesamtanzahl an Schülern eines bestimmten Kurses
///
///\fn int Model::getCourseCount( void ) const
/// \brief gibt Anzahl von allen Kursen zurück
/// Diese Funktion ruft eine Methode von \link Model::db \endlink auf
/// \return Gesamtanzahl an Kursen
///
///\fn int Model::getCourseCount( int studentId ) const
/// \brief gibt Anzahl von allen Kursen eines bestimmten Schülers zurück
/// \param int studentId Bestimmung des Schülers
/// Diese Funktion ruft eine Methode von \link Model::db \endlink auf
/// \return Gesamtanzahl an Kursen
///
/// \fn   int Model::getMaxStudentCountInACourse( void ) const;
/// \brief gibt Kurs-Id des Kurses mit den meisten Schüler zurück
/// \return Kurs-Id mit meisten Schülern
///
/// \fn QList< int > getCourseIds( void ) const
/// \brief gibt Liste mit allen existierenden Kursen zurück
/// \return Liste mit allen Kurs-Ids
///
/// \fn QList< int > getStudentIds( void ) const
/// \brief gibt Liste mit allen existierenden Schülern zurück
/// \return Liste mit allen Schüler-Ids
///
/// \fn QString getCourseName( int courseId ) const
/// \brief gibt Kursnamen zu gegebener Kurs-Id
/// \param int courseId Id des Kurses
/// \return Kursname
#endif // MODEL_H
