/* executor.cpp */

#include "executor.hpp"
#include <QDebug>
#include <QSqlError>

namespace db {

Executor::Executor()
  : m_connectManager(ConnectManager::instance())
{
  // ctor
}

Executor::~Executor()
{
  // dtor
}

QPair<bool, QSqlQuery>
Executor::executor(const QString& textQuery_, const QVariantList& args_)
{
  Q_UNUSED(textQuery_);
  Q_UNUSED(args_);

  if (!m_connectManager.isValid()) {
    qCritical("Database is not valid.");
    return { false, QSqlQuery{} };
  }

  auto nArgs{ args_.size() };
  QSqlQuery query(textQuery_);

  for (auto i{ 0 }; i < nArgs; ++i) {
    query.bindValue(i, args_.at(i).toString());
  }

  if (!query.exec()) {
    qCritical("[ERROR] Query: %s \n %s",
              qUtf8Printable(query.lastQuery()),
              qUtf8Printable(query.lastError().text()));
    return { false, QSqlQuery() };
  }

  return { true, query };
}

}
