/* modelpoems.cpp */

#include "modelpoems.hpp"
#include <random>

ModelPoems::ModelPoems(QObject* parent)
  : IModel(parent)
  , m_readData(new ReadData)
  , m_poems(m_readData->request(gNameDbType[eDBType::POEMS]))
{}

ModelPoems::~ModelPoems()
{
  if (m_readData)
    delete m_readData;
}

void
ModelPoems::sorting()
{
  beginResetModel();
  std::random_shuffle(std::begin(m_poems), std::end(m_poems));
  emit dataChanged(createIndex(0, 0), createIndex(m_poems.size(), 0));
  endResetModel();
}

int
ModelPoems::rowCount(const QModelIndex& parent) const
{
  Q_UNUSED(parent);
  return m_poems.size();
}

QVariant
ModelPoems::data(const QModelIndex& index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole ||
      (unsigned long)index.row() > (unsigned long)m_poems.size())
    return {};

  return QVariant::fromValue(m_poems.at(index.row()));
}
