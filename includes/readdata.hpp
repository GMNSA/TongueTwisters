#ifndef READDATA_HPP
#define READDATA_HPP

#include <QString>
#include <QVector>

class ReadData
{
public:
  ReadData();
  virtual ~ReadData();

  QVector<QString> request();

private:
};

#endif // READDATA_HPP