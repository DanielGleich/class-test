#include "model.h"

Model* Model::singleton = nullptr;

Model::Model( QObject *parent ) : QObject( parent )
{
  db = Database::get();
  db->loadDB();
}

Model *Model::get()
{
  if (singleton == nullptr)
    singleton = new Model();
  return singleton;
}

Model::~Model()
{
  db->closeDB();
  delete db;
}

int Model::getStudentCount() const
{
  return db->getStudentCount();
}

int Model::getStudentCount( int courseId ) const
{
  return db->getStudentCount( courseId );
}

int Model::getCourseCount() const
{
  return db->getCourseCount();
}

int Model::getCourseCount( int studentId ) const
{
  return db->getCourseCount( studentId );
}

int Model::getMaxStudentCountInACourse() const
{
  return db->getMaxStudentCountInACourse();
}

QList< int > Model::getCourseIds() const
{
  return db->getCourseIds();
}

QList< int > Model::getStudentIds() const
{
  return db->getStudentIds();
}

QString Model::getCourseName( int courseId ) const
{
  return db->getCourseName( courseId );
}
