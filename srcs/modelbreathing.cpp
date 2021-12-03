/* modelbreathing.cpp */

#include "modelbreathing.hpp"
#include "dbtype.hpp"
#include <random>

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

void
ModelBreathing::sorting()
{
  beginResetModel();
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(
    std::begin(m_data), std::end(m_data), std::default_random_engine(seed));
  // std::random_shuffle(std::begin(m_data), std::end(m_data));
  emit dataChanged(createIndex(0, 0), createIndex(m_data.size(), 0));
  endResetModel();
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
