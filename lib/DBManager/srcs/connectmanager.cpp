/* connectmanager.cpp */

#include "connectmanager.hpp"

#include <QDebug>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlError>
#include <QStandardPaths>
#include <QString>

namespace db {

namespace {
struct DBRemove
{
  void operator()(QSqlDatabase* db_)
  {
    db_->removeDatabase(QSqlDatabase::defaultConnection);
    delete db_;
  }
};
}

struct ConnectManager::ConnectManagerPrivate
{
  QString dbname;

  std::unique_ptr<QSqlDatabase, DBRemove> database;
  QString filename;
  eError state{ eError::OK };
  bool isValid{ false };

  bool setup();
  /*!
   * \brief setupWorkSpace ->
   *    The result of the creation or existence of a workspace.
   * \return (bool)
   */
  bool setupWorkSpace();
  bool setupDatabase();
  // bool setupTables();
};

ConnectManager::ConnectManager()
  : m_db(std::make_unique<ConnectManagerPrivate>())
{
  m_db->isValid = m_db->setup();
  qDebug() << "[STATUS]: " << status();
}

ConnectManager::~ConnectManager()
{
  // dtor
}

QString
ConnectManager::status()
{
  switch (m_db->state) {
    case eError::OK:
      return "OK";
    case eError::ERROR_DRIVER:
      return ("ERROR DRIVER");
    case eError::ERROR_WORKSPACE:
      return ("ERROR WORKSPACE");
    case eError::ERROR_DATABASE_OPEN:
      return ("DATABASE OPEN");
    case eError::ERROR_DATABASE_COPY:
      return ("ERROR DATABASE COPY");
    default:
      return {};
  }

  return {};
}

ConnectManager&
ConnectManager::instance()
{
  static ConnectManager instance;
  return (instance);
}

bool
ConnectManager::isValid() const
{
  return (m_db->isValid);
}

bool
ConnectManager::ConnectManagerPrivate::setup()
{
  QString const driver("QSQLITE");

  if (!(QSqlDatabase::isDriverAvailable(driver))) {
    state = eError::ERROR_DRIVER;
    return (false);
  }

  if (!setupWorkSpace()) {
    state = eError::ERROR_WORKSPACE;
    return (false);
  }

  if (!setupDatabase()) {
    state = eError::ERROR_DATABASE_COPY;
    return (false);
  }

  database.reset((new QSqlDatabase(QSqlDatabase::addDatabase(driver))));
  database->setDatabaseName(filename);

  if (!database->open()) {
    state = eError::ERROR_DATABASE_OPEN;
    qCritical("Database didn't open: %s",
              qUtf8Printable(database->lastError().text()));
    return (false);
  }

  return (true);
}

bool
ConnectManager::ConnectManagerPrivate::setupWorkSpace()
{
  QString const dirName{ "TongueTwisters" };
  QString const fileName{ "tongueTwisters.db" };

  auto const localPath =
    QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);

  QString const pathToApp = localPath + "/" + dirName;

  qDebug() << "path: " << pathToApp;

  QDir dir{ pathToApp };

  if (!dir.exists()) {
    auto result = dir.mkdir(pathToApp);
    qInfo("Create to workspace.. [%i]\n", result);

    if (!result)
      return (false);
  }

  filename = pathToApp + "/" + fileName;

  qDebug() << "filename: " << filename;

  return (true);
}

bool
ConnectManager::ConnectManagerPrivate::setupDatabase()
{
  QFile file(filename);
  bool result{ true };
  bool resultPermission{ false };

  if (!file.exists()) {
    result = QFile::copy(":/tongueTwister.db", filename);
    resultPermission = QFile(filename).setPermissions(QFileDevice::ReadOwner |
                                                      QFileDevice::WriteOwner);

    if (resultPermission)
      qInfo("Set write and read to file %s", qUtf8Printable(filename));
    else
      qCritical("[ERROR] Write and read didn't set %s",
                qUtf8Printable(filename));

    if (result)
      qInfo("The database was copy [...] to %s", qUtf8Printable(filename));
    else
      qCritical("[ERROR] Database didn't copy to %s", qUtf8Printable(filename));
  } else
    file.close();

  return (result);
}

}
