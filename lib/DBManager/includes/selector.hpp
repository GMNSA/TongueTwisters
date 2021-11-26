/* selector.hpp */

#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include "executor.hpp"

namespace db {

class Selector
{
public:
  Selector();
  virtual ~Selector();

  QPair<bool, QVector<QVariantList>> classics(
    QString const& tablename_ = "Classics");

protected:
private:
  std::unique_ptr<Executor> m_executor;
};

}

#endif // SELECTOR_HPP
