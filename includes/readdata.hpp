#ifndef READDATA_HPP
#define READDATA_HPP

#include "processor.hpp"
#include <QString>
#include <QVector>

class ReadData
{
public:
  ReadData();
  virtual ~ReadData();

  QVector<QString> request(QString const tablename_);

private:
  db::Processor* m_processor;
  QVector<QString> m_data;
};

#endif // READDATA_HPP
