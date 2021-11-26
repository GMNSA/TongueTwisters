/* manipulator.cpp */

#include "manipulator.hpp"
#include <QDebug>

namespace db {

Manipulator::Manipulator()
  : m_executor(std::make_unique<Executor>())
{
  // ctor
}

Manipulator::~Manipulator()
{
  // dtor
}

QPair<bool, int>
Manipulator::insertRow(const QString& tableName_,
                       const QVariantList& recordData_)
{
  auto const nRecordData{ recordData_.size() };
  QString const query{ generateInsertQuery(tableName_, nRecordData) };
  auto const result{ m_executor->executor(query, recordData_) };

  return { result.first, result.second.lastInsertId().toInt() };
}

QString
Manipulator::generateBindString(size_t nRecords_) const
{
  QString result;
  for (size_t i{ 0 }; i < nRecords_; ++i)
    if (i == (nRecords_ - 1))
      result += "?";
    else
      result += "?,";

  return (result);
}

QString
Manipulator::generateInsertQuery(const QString& tableName_,
                                 size_t nRecords_) const
{

  QString query{ "INSERT INTO " + tableName_ + " ( " + gDBaseArgs[tableName_] +
                 " ) VALUES ( " };

  query += generateBindString(nRecords_);
  query += " )";

  return (query);
}

}
