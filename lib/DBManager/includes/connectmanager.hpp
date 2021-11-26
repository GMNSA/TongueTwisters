/* connectmanager.hpp */

#ifndef CONNECTMANAGER_HPP
#define CONNECTMANAGER_HPP

#include "dbtype.hpp"
#include <QString>
#include <memory>

namespace db {

class ConnectManager
{
public:
  ConnectManager(ConnectManager& other) = delete;
  ConnectManager& operator=(ConnectManager& other) = delete;
  virtual ~ConnectManager();

  QString status();
  static ConnectManager& instance();

  bool isValid() const;

protected:
private:
  ConnectManager();

#ifdef FOR_TEST
public:
#endif

  struct ConnectManagerPrivate;
  std::unique_ptr<ConnectManagerPrivate> m_db;
};

}

#endif // CONNECTMANAGER_HPP
