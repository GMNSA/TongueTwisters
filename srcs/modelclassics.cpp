/* modeltonguetwisters.cpp */

#include "modelclassics.hpp"
#include "dbtype.hpp"

ModelClassics::ModelClassics(QObject* parent)
  : IModel(parent)
  , m_readData(new ReadData)
  , m_classics(m_readData->request(gNameDbType[eDBType::CLASSICS]))
{}

ModelClassics::~ModelClassics()
{
  if (m_readData)
    delete m_readData;
}

int
ModelClassics::rowCount(const QModelIndex& parent) const
{
  Q_UNUSED(parent);
  return m_classics.size();
}

QVariant
ModelClassics::data(const QModelIndex& index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole ||
      (unsigned long)index.row() > (unsigned long)m_classics.size())
    return {};

  return QVariant::fromValue(m_classics.at(index.row()));
}
