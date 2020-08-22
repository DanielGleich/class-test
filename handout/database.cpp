#include "database.h"

Database* Database::singleton = nullptr;

Database::Database( QObject *parent ) : QObject( parent )
{}

Database *Database::get()
{
  if (singleton == nullptr)
    singleton = new Database();
  return singleton;
}

Database::~Database()
{
  if ( db.isOpen() )
    db.close();
}

bool Database::loadDB( void )
{
  bool result = false;

  db = QSqlDatabase::addDatabase( "QSQLITE" );
  db.setDatabaseName( file );
  if ( !db.isValid() )
    qDebug()<<"FEHLER: Datenbanktreiber ist fehlerhaft";
  else if ( !QFile::exists( file ) )
    qDebug()<<"FEHLER: Datenbankdatei ist nicht vorhanden";
  else if ( !db.open() )
    qDebug()<<"FEHLER: Datenbankdatei kann nicht geöffnet werden";
  else
    result = true;

  return result;
}

void Database::closeDB()
{
  if ( db.isOpen() )
    db.close();
}

// Gibt die Anzahl der Gesamtstudenten zurück
int Database::getStudentCount( void ) const
{
  QSqlQuery *query = new QSqlQuery(db);
  query->prepare("Select COUNT(*) FROM student;");
  query->exec();
  query->next();
  return query->value(0).toInt();
}

// Gibt die Anzahl der Gesamtkurse zurück
int Database::getCourseCount( void ) const
{
  QSqlQuery *query = new QSqlQuery(db);
  query->prepare("Select COUNT(*) FROM course;");
  query->exec();
  query->next();
  return query->value(0).toInt();
}

// Gibt die Anzahl der Studenten in Kurs X zurück
int Database::getStudentCount( int courseId ) const
{
  QSqlQuery *query = new QSqlQuery(db);
  query->prepare("Select count(*) FROM zuoStudentCourse WHERE courseId = :v ;");
  query->bindValue(":v",courseId);
  query->exec();
  query->next();
  return query->value(0).toInt();
}

// Gibt die Anzahl der Kurse eines Studenten X zurück
int Database::getCourseCount( int studentId ) const
{
  QSqlQuery *query = new QSqlQuery(db);
  query->prepare("Select count(*) FROM zuoStudentCourse WHERE studentId = :v ;");
  query->bindValue(":v",studentId);
  query->exec();
  query->next();
  return query->value(0).toInt();
}

// Gibt alls StudentenIds zurück
QList< int > Database::getStudentIds() const
{
  QSqlQuery *query = new QSqlQuery(db);
  query->prepare("Select id FROM student;");
  query->exec();
  QList<int> ids;
  while( !query->last() )
    ids << query->value(0).toInt();
  return ids;
}

// Gibt alls KursIds zurück
QList< int > Database::getCourseIds() const
{
  QSqlQuery *query = new QSqlQuery(db);
  query->prepare("Select id FROM course;");
  query->exec();
  QList<int> ids;
  while( query->next() )
    ids << query->value(0).toInt();
  return ids;

}

// Gibt die Zahl der Studenten in dem meist-gefülltestes Kurs zurück
int Database::getMaxStudentCountInACourse() const
{
  QSqlQuery *query = new QSqlQuery(db);
  query->prepare("Select courseId FROM zuoStudentCourse GROUP BY courseID ORDER BY count(studentId) DESC;");
  query->exec();
  query->next();
  return query->value(0).toInt();
}

// gibt des Kursnamen zu der KursId zurück
QString Database::getCourseName( int courseId ) const
{
  QSqlQuery *query = new QSqlQuery(db);
  query->prepare("SELECT name FROM course WHERE id = :v;");
  query->bindValue(":v",courseId);
  query->exec();
  query->next();
  return query->value(0).toString();
}
