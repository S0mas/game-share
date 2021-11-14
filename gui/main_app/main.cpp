#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>
#include <loguru/loguru.hpp>
#include <interface/interface.hpp>

int main(int argc, char *argv[])
{
  loguru::init(argc, argv);
  loguru::add_file("everything_autoupdater.log", loguru::Append, loguru::Verbosity_MAX);
  loguru::add_file("latest_autoupdater.log", loguru::Truncate, loguru::Verbosity_MAX);
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  interface backend_interface;

  engine.rootContext()->setContextProperty("backend_interface", &backend_interface);

  const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
