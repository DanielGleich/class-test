#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore>
#include <QtSql>

const bool    DEBUG               = true;
const QString file                = "schooldata.db";

const int    WIDTH                = 600;                        // fixe Breite des Fensters
const int    HEIGHT               = 400;                        // fixe Höhe des Fensters
const int    MARGIN               = 10;                         // genereller Abstand
const QPoint GRAPH_ANCHOR         = QPoint( 170, 310 );         // linker unterer Punkt der Balkengrafik
const int    BAR_WIDTH            = 55;                         // Breite eines Balkens
const int    TEXT_HEIGHT          = 20;                         // Abstand der Zeilen der Legend
const QRect  LEGEND_TITLE         = QRect( 20, 10, 150, 20 );   // Position des Legenden-Titels
const QPoint LEGEND_BODY          = QPoint( 20, 40 );           // Position der Legende
const QSize  LEGEND_COLORBOX_SIZE = QSize( 15, 10 );            // Größe eines Farbrechtecks in der Legende

template< class T >
bool lesserThan( const T z1, const T z2 );

void sort( QList< int > &list );
void sort( QStringList &list );

void debugLastQueryInfos( QSqlQuery &query );

#endif // CONFIG_H
