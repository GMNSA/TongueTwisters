/* selector.cpp */

#include "selector.hpp"
#include <QSqlRecord>

namespace db {

Selector::Selector()
  : m_executor(std::make_unique<Executor>())
{
  // ctor
}

Selector::~Selector()
{
  // dtor
}

QPair<bool, QVector<QVariantList>>
Selector::classics(const QString& tablename_)
{
  QVector<QVariantList> returnData;
  QVariantList temp;

  QString query{ "SELECT " + gDBaseArgs[tablename_] + " FROM " + tablename_ };

  auto [result, data] = m_executor->executor(query);

  if (result) {
    auto nRecords{ data.record().count() };
    while (data.next()) {
      for (auto i{ 0 }; i < nRecords; ++i)
        temp.push_back(data.record().value(i));
    }
    returnData.push_back(temp);
    temp.clear();
  }

  return { result, returnData };
}

}
