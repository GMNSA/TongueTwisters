/* modelpoems.hpp */

#ifndef MODELPOEMS_HPP
#define MODELPOEMS_HPP

#include "imodel.hpp"
#include "readdata.hpp"

class ModelPoems : public IModel
{
  Q_OBJECT
public:
  ModelPoems(QObject* parent = nullptr);
  virtual ~ModelPoems();
  Q_DISABLE_COPY_MOVE(ModelPoems);

  // IModel interface
  Q_INVOKABLE virtual void sorting() override;

public:
  virtual int rowCount(const QModelIndex& parent) const override;
  virtual QVariant data(const QModelIndex& index, int role) const override;

protected:
private:
  ReadData* m_readData;
  QVector<QString> m_poems;

  int m_table{ 5 };
};
#endif // MODELPOEMS_HPP
