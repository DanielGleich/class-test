#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include "config.h"

class Database : public QObject
{
  Q_OBJECT
private:
  static Database* singleton;
  QSqlDatabase db;

protected:
  Database( QObject *parent = nullptr );

public:
  static Database* get();
  ~Database( void );
  bool         loadDB( void );
  void         closeDB( void );
  int          getStudentCount( void ) const;
  int          getCourseCount( void ) const;
  int          getStudentCount( int courseId ) const;
  int          getCourseCount( int studentId ) const;
  QList< int > getStudentIds( void ) const;
  QList< int > getCourseIds( void ) const;
  int          getMaxStudentCountInACourse( void ) const;
  QString      getCourseName( int courseId ) const;
};

#endif // DATABASE_H
