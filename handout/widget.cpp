#include "widget.h"

Widget::Widget( Model *m, QWidget *parent )
  : QWidget( parent )
{
  QVBoxLayout *layout     = new QVBoxLayout;
  QHBoxLayout *exitLayout = new QHBoxLayout;
  QPushButton *pbExit     = new QPushButton( "Be&enden" );
  BarView     *barview    = new BarView( m );

  exitLayout->addStretch();
  exitLayout->addWidget( pbExit );

  layout->addWidget( barview );
  layout->addLayout( exitLayout );
  setLayout( layout );

  setFixedSize( WIDTH, HEIGHT );

  connect( pbExit, &QPushButton::clicked, this, &Widget::tryToExit );
}

Widget::~Widget()
{}

void Widget::closeEvent( QCloseEvent *event )
{
  event->ignore();
  emit tryToExit();
}
