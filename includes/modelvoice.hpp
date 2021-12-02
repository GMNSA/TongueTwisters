/* modelvoice.hpp */

#ifndef MODELVOICE_HPP
#define MODELVOICE_HPP

#include "imodel.hpp"
#include "readdata.hpp"

class ModelVoice : public IModel
{
  Q_OBJECT
public:
  ModelVoice(QObject* parent = nullptr);
  virtual ~ModelVoice();
  Q_DISABLE_COPY_MOVE(ModelVoice);

public:
  virtual int rowCount(const QModelIndex& parent) const override;
  virtual QVariant data(const QModelIndex& index, int role) const override;

protected:
private:
  ReadData* m_readData;
  QVector<QString> m_data;

  int m_table{ 5 };
};

#endif // MODELVOICE_HPP
