/* manipulator.hpp */

#ifndef MANIPULATOR_HPP
#define MANIPULATOR_HPP

#include "dbtype.hpp"
#include "executor.hpp"

namespace db {

class Manipulator
{
public:
  Manipulator();
  virtual ~Manipulator();

  Q_DISABLE_COPY_MOVE(Manipulator);

  QPair<bool, int> insertRow(QString const& tableName_,
                             QVariantList const& recordData_);

#ifdef FOR_TEST
public:
#else
private:
#endif
  std::unique_ptr<Executor> m_executor;

  QString generateBindString(size_t nRecords_) const;
  QString generateInsertQuery(QString const& tableName_,
                              size_t nRecords_) const;
};

}

#endif // MANIPULATOR_HPP
