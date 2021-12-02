/* modelvoice.cpp */

#include "modelvoice.hpp"

ModelVoice::ModelVoice(QObject* parent)
  : IModel(parent)
  , m_readData(new ReadData)
  , m_data(m_readData->request(gNameDbType[eDBType::VOICE]))
{}

ModelVoice::~ModelVoice()
{
  if (m_readData)
    delete m_readData;
}

int
ModelVoice::rowCount(const QModelIndex& parent) const
{
  Q_UNUSED(parent);
  return m_data.size();
}

QVariant
ModelVoice::data(const QModelIndex& index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole ||
      (unsigned long)index.row() > (unsigned long)m_data.size())
    return {};

  return QVariant::fromValue(m_data.at(index.row()));
}
