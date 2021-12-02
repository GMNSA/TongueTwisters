/* modelbreathing.hpp */

#ifndef MODELBREATHING_HPP
#define MODELBREATHING_HPP

#include "imodel.hpp"
#include "readdata.hpp"

class ModelBreathing : public IModel
{
public:
  ModelBreathing(QObject* parent = nullptr);
  virtual ~ModelBreathing();
  Q_DISABLE_COPY_MOVE(ModelBreathing);

  // IModel interface
public:
  virtual int rowCount(const QModelIndex& parent) const override;
  virtual QVariant data(const QModelIndex& index, int role) const override;

private:
  ReadData* m_pReadData;
  QVector<QString> m_data;
};
#endif // MODELBREATHING_HPP
