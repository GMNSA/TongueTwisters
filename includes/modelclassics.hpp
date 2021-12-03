/* modeltonguetwisters.hpp */

#ifndef MODEL_CLASSICS_HPP
#define MODEL_CLASSICS_HPP

#include "imodel.hpp"
#include "readdata.hpp"
#include <QAbstractListModel>
#include <QDebug>

class ModelClassics : public IModel
{
  Q_OBJECT
public:
  ModelClassics(QObject* parent = nullptr);
  virtual ~ModelClassics();
  Q_DISABLE_COPY_MOVE(ModelClassics);

  Q_INVOKABLE void sorting();

public:
  virtual int rowCount(const QModelIndex& parent) const override;
  virtual QVariant data(const QModelIndex& index, int role) const override;

protected:
private:
  ReadData* m_readData;
  QVector<QString> m_classics;

  int m_table{ 5 };
};

#endif // MODEL_CLASSICS_HPP
