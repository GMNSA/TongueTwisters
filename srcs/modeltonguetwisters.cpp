/* modeltonguetwisters.cpp */

#include "modeltonguetwisters.hpp"

ModelTongueTwisters::ModelTongueTwisters(QObject* parent)
  : QAbstractListModel(parent)
  , m_readData(new ReadData)
  , m_data(m_readData->request())
{
  // ctor
}

ModelTongueTwisters::~ModelTongueTwisters()
{
  if (m_readData)
    delete m_readData;
}

int
ModelTongueTwisters::rowCount(const QModelIndex& parent) const
{
  Q_UNUSED(parent);
  return (m_data.size());
}

QVariant
ModelTongueTwisters::data(const QModelIndex& index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole ||
      (unsigned long)index.row() > (unsigned long)m_data.size())
    return {};

  return QVariant::fromValue(m_data.at(index.row()));
}
