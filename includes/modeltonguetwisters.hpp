/* modeltonguetwisters.hpp */

#ifndef MODELTONGUETWISTERS_HPP
#define MODELTONGUETWISTERS_HPP

#include "readdata.hpp"
#include <QAbstractListModel>

class ModelTongueTwisters : public QAbstractListModel
{
  Q_OBJECT
public:
  ModelTongueTwisters(QObject* parent = nullptr);
  virtual ~ModelTongueTwisters();
  Q_DISABLE_COPY_MOVE(ModelTongueTwisters);

  // QAbstractItemModel interface
public:
  virtual int rowCount(const QModelIndex& parent) const override;
  virtual QVariant data(const QModelIndex& index, int role) const override;

protected:
private:
  ReadData* m_readData;
  QVector<QString> m_data;
};

#endif // MODELTONGUETWISTERS_HPP
