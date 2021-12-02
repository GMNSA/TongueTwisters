/* modelbreathing.cpp */

#include "modelbreathing.hpp"
#include "dbtype.hpp"

ModelBreathing::ModelBreathing(QObject* parent)
  : IModel(parent)
  , m_pReadData(new ReadData)
  , m_data(m_pReadData->request(gNameDbType[eDBType::BREATHING]))
{}

ModelBreathing::~ModelBreathing()
{
  if (m_pReadData)
    delete m_pReadData;
}

int
ModelBreathing::rowCount(const QModelIndex& parent) const
{
  Q_UNUSED(parent);
  return (m_data.size());
}

QVariant
ModelBreathing::data(const QModelIndex& index, int role) const
{
  Q_UNUSED(index);
  Q_UNUSED(role);

  if (!index.isValid() || index.row() > m_data.size() ||
      role != Qt::DisplayRole)
    return {};

  return QVariant::fromValue(m_data.at(index.row()));
}
