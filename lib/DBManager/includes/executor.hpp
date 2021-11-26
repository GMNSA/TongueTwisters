/* executor.hpp */

#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <QSqlQuery>
#include <QVariantList>

#include "connectmanager.hpp"

namespace db {

class Executor
{
public:
  Executor();
  virtual ~Executor();

  QPair<bool, QSqlQuery> executor(QString const& textQuery_,
                                  QVariantList const& args_ = {});

protected:
private:
  ConnectManager& m_connectManager;
};

}

#endif // EXECUTOR_HPP
