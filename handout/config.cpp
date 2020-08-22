#include "config.h"

template< class T >
bool lesserThan( const T z1, const T z2 )
{
  return z1<z2;
}

void sort( QList< int >& list )
{
  std::sort( list.begin(), list.end(), lesserThan< int > );
}

void sort( QStringList& list )
{
  std::sort( list.begin(), list.end(), lesserThan< QString > );
}

void debugLastQueryInfos( QSqlQuery &query )
{
  if ( query.lastError().isValid() )
  {
    qDebug()<<query.lastQuery();
    qDebug()<<"Fehler: "<<query.lastError();
  }
}
