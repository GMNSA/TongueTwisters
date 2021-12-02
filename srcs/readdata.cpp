#include "readdata.hpp"

#include "dbtype.hpp"
#include <QDebug>
#include <QVector>

ReadData::ReadData()
  : m_processor(new db::Processor)
{}

ReadData::~ReadData()
{
  if (m_processor)
    delete m_processor;
}

QVector<QString>
ReadData::request(QString const tablename_)
{
  eDBType type{};

  if (tablename_ == gNameDbType[eDBType::CLASSICS]) {
    type = eDBType::CLASSICS;
  } else if (tablename_ == gNameDbType[eDBType::BREATHING]) {
    type = eDBType::BREATHING;
  } else if (tablename_ == gNameDbType[eDBType::POEMS]) {
    type = eDBType::POEMS;
  } else if (tablename_ == gNameDbType[eDBType::VOICE]) {
    type = eDBType::VOICE;
  }

  auto [result, data] = m_processor->requestData(type);

  if (result) {
    size_t nData = data.at(0).count();
    m_data.reserve(nData);

    for (size_t i{ 0 }; i < nData; ++i) {
      m_data.push_back(data.at(0).at(i).toString());
    }
  } else {
    qCritical("[ERROR] Data didn't get.");
  }
  return { m_data };
}
