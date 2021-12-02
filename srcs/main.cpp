#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "imodel.hpp"
#include "modelbreathing.hpp"
#include "modelclassics.hpp"
#include "modelpoems.hpp"
#include "modelvoice.hpp"

int
main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.addImportPath(":/qml");

  qmlRegisterType<ModelClassics>("alpha.modelclassics", 1, 0, "ModelClassics");
  qmlRegisterType<ModelPoems>("alpha.modelpoems", 1, 0, "ModelPoems");
  qmlRegisterType<ModelVoice>("alpha.modelvoice", 1, 0, "ModelVoice");
  qmlRegisterType<ModelBreathing>(
    "alpha.modelbreathing", 1, 0, "ModelBreathing");

  const QUrl url(QStringLiteral("qrc:/main.qml"));

  QObject::connect(
    &engine,
    &QQmlApplicationEngine::objectCreated,
    &app,
    [url](QObject* obj, const QUrl& objUrl) {
      if (!obj && url == objUrl)
        QCoreApplication::exit(-1);
    },
    Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
