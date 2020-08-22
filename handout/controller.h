#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model.h"
#include "widget.h"

class Controller : public QObject
{
  Q_OBJECT
private:
  static Controller *singleton;

  Controller( QObject *parent = nullptr );
  Widget    *widget;
  Model     *model;
  QSettings *settings;
  void exit();
  void loadSettings();

public:
  static Controller *get();
};

#endif // CONTROLLER_H
