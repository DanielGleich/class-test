#include <QtTest>
#include "model.h"
#include "test_data.h"

class DataExtraction : public QObject
{
  Q_OBJECT

private:
  Model *m = nullptr;

public:
  DataExtraction();
  ~DataExtraction();

private slots:
  void init();
  void cleanup();
  void testCourseCount();
  void testStudentCount();
  void testMaxStudentsInACourse();
  void testCourseIds();
  void testStudentIds();
};

DataExtraction::DataExtraction()
{
  m = Model::get();
}

DataExtraction::~DataExtraction()
{}

void DataExtraction::init()
{}

void DataExtraction::cleanup()
{}

void DataExtraction::testCourseCount()
{
  // elegante Lösung mittels QMaps aus test_data.h
  QCOMPARE( m->getCourseCount(), COURSES.size() );
  foreach( int studentId, STUDENTS.keys() )
    QCOMPARE( m->getCourseCount( studentId ), STUDENTS_COURSES.values( studentId ).size() );

  // "einfache" Lösung

  QCOMPARE( m->getCourseCount(),            4 );
  QCOMPARE( m->getCourseCount( 1 ),         2 );
  QCOMPARE( m->getCourseCount( 2 ),         3 );
  QCOMPARE( m->getCourseCount( 3 ),         4 );
  QCOMPARE( m->getCourseCount( 4 ),         2 );
  QCOMPARE( m->getCourseCount( 5 ),         2 );
  QCOMPARE( m->getCourseCount( 6 ),         3 );
}

void DataExtraction::testStudentCount() // 2
{
  QCOMPARE( m->getStudentCount(), STUDENTS.count());
  QCOMPARE( m->getStudentCount( 1 ),         5 );
  QCOMPARE( m->getStudentCount( 2 ),         2 );
  QCOMPARE( m->getStudentCount( 3 ),         6 );
  QCOMPARE( m->getStudentCount( 4 ),         4 );
}

void DataExtraction::testMaxStudentsInACourse()// 3
{
  QCOMPARE(m->getMaxStudentCountInACourse(),3);
}

void DataExtraction::testCourseIds() // 4
{
  foreach(int id, m->getCourseIds())
    QVERIFY(COURSES.contains(id));
}

void DataExtraction::testStudentIds() // 5
{
  foreach(int id, m->getStudentIds())
    QVERIFY(STUDENTS.contains(id));
}

QTEST_APPLESS_MAIN( DataExtraction )

#include "tst_dataextraction.moc"
