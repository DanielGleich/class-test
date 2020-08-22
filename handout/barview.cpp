#include "barview.h"

BarView::BarView( Model *m, QWidget *parent ) : QWidget( parent )
{
  model = m;
  colors = new QList<QColor>();

  colors->append(QColor(Qt::red));
  colors->append(QColor(158,224,144));
  colors->append(QColor(Qt::cyan));
  colors->append(QColor(151, 54, 255));
}

void BarView::paintBarGraph(QPainter& p )
{
  p.drawLine(GRAPH_ANCHOR.x(),
             GRAPH_ANCHOR.y(),
             GRAPH_ANCHOR.x()+270,
             GRAPH_ANCHOR.y());

  p.translate(GRAPH_ANCHOR);

  int heightPerPerson = -20;

  for(int i = 0; i < Model::get()->getCourseCount(); i++)
    {
      QBrush brush;
      brush.setStyle(Qt::SolidPattern);
      brush.setColor(colors->at(i));
      p.setBrush(brush);
      p.drawRect(BAR_WIDTH*i+MARGIN*i+MARGIN,0,BAR_WIDTH, Model::get()->getStudentCount(i+1)*heightPerPerson);

    }
}

void BarView::paintLegend( QPainter &p )
{
  p.setBrush(Qt::SolidPattern);
  QFont font;
  font.setBold(true);
  p.setPen(Qt::black);
  p.setFont(font);
  p.drawText(LEGEND_TITLE,"Statistik: Kurse");

  font.setBold(false);
  p.setFont(font);

  for(int i = 0; i < Model::get()->getCourseCount(); i++)
    {
      QBrush brush;
      brush.setColor(colors->at(i));
      brush.setStyle(Qt::SolidPattern);
      p.setBrush(brush);

      QString text = QString(Model::get()->getCourseName(i+1)+": "+ QString::number(Model::get()->getStudentCount(i+1)));

      p.drawRect(LEGEND_BODY.x(),
                 LEGEND_BODY.y()+i*TEXT_HEIGHT,
                 LEGEND_COLORBOX_SIZE.width(),
                 LEGEND_COLORBOX_SIZE.height());

      p.drawText(LEGEND_BODY.x()+25,MARGIN+LEGEND_BODY.y()+i*TEXT_HEIGHT,text);
    }
}

void BarView::paintEvent( QPaintEvent */*event*/ )
{
  QPainter painter( this );

  paintLegend( painter );
  paintBarGraph( painter );
}
