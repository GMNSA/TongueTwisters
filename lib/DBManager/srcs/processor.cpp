/* processor.cpp */

#include "processor.hpp"
#include "selector.hpp"

namespace db {

struct Processor::ProcessorPrivate
{
  Selector selector;
};

Processor::Processor()
  : m_processor(std::make_unique<ProcessorPrivate>())
{
  // ctor
}

Processor::~Processor()
{
  // dtor
}

QPair<bool, QVector<QVariantList>>
Processor::requestData(eDBType typeDb_)
{
  switch (typeDb_) {
    case eDBType::CLASSICS:
      return m_processor->selector.classics(gNameDbType[typeDb_]);
      break;
    case eDBType::BREATHING:
      return m_processor->selector.classics(gNameDbType[typeDb_]);
      break;
    case eDBType::POEMS:
      return m_processor->selector.classics(gNameDbType[typeDb_]);
      break;
    case eDBType::VOICE:
      return m_processor->selector.classics(gNameDbType[typeDb_]);
      break;
    default:
      return { false, {} };
  }
}

}
