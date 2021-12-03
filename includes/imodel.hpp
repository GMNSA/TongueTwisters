/* imodel.hpp */

#ifndef IMODEL_HPP
#define IMODEL_HPP

#include <QAbstractListModel>

class IModel : public QAbstractListModel
{
public:
  IModel(QObject* parent = nullptr);
  virtual ~IModel();

  virtual void sorting() = 0;

public:
  virtual int rowCount(const QModelIndex& parent) const = 0;
  virtual QVariant data(const QModelIndex& index, int role) const = 0;

protected:
private:
};
#endif // IMODEL_HPP
