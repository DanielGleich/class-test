#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include "barview.h"
#include "model.h"

class Widget : public QWidget
{
  Q_OBJECT
private:

public:
  Widget( Model *m, QWidget *parent = nullptr );
  ~Widget() override;

protected:
  void closeEvent( QCloseEvent *event ) override;

signals:
  void tryToExit();
};

#endif // WIDGET_H
