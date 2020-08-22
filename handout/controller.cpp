#include "controller.h"

Controller* Controller::singleton = nullptr;

Controller::Controller( QObject *parent ) : QObject( parent )
{
  model  = Model::get();
  widget = new Widget( model );

  settings = new QSettings("settings.conf");
  loadSettings();
  widget->show();

  connect( widget, &Widget::tryToExit, this, &Controller::exit );
}

void Controller::exit()
{
  settings->setValue("Position",widget->geometry());
  QCoreApplication::exit();
}

void Controller::loadSettings()
{
  if(!settings->value("Position").isNull())
    widget->setGeometry(settings->value("Position").toRect());
}

Controller *Controller::get()
{
  if (singleton == nullptr)
    singleton = new Controller();
  return singleton;
}
