#ifndef BARVIEW_H
#define BARVIEW_H

#include <QtWidgets>
#include "model.h"

class BarView : public QWidget
{
  Q_OBJECT
private:
  Model *model;
  QList<QColor> *colors;
  void paintBarGraph( QPainter& p );
  void paintLegend(QPainter& p );

protected:
  void paintEvent( QPaintEvent * );

public:
  BarView( Model *m, QWidget *parent = nullptr );
};

#endif // BARVIEW_H
