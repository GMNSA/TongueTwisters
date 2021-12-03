/* modeltonguetwisters.cpp */

#include "modelclassics.hpp"
#include "dbtype.hpp"
#include "random"

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

void
ModelClassics::sorting()
{
  beginResetModel();
  std::random_shuffle(std::begin(m_classics), std::end(m_classics));
  emit dataChanged(createIndex(0, 0), createIndex(m_classics.size(), 0));
  endResetModel();
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
