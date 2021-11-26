/* processor.hpp */

#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "dbtype.hpp"
#include <QVariantList>
#include <memory>

namespace db {
class Processor
{
public:
  Processor();
  virtual ~Processor();
  Q_DISABLE_COPY_MOVE(Processor);

  QPair<bool, QVector<QVariantList>> requestData(eDBType typeDb_);

private:
  struct ProcessorPrivate;
  std::unique_ptr<ProcessorPrivate> m_processor;
};

}

#endif // PROCESSOR_HPP
