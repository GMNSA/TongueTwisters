/* testdbmanager.hpp */

#ifndef TESTDBMANAGER_HPP
#define TESTDBMANAGER_HPP

#include "connectmanager.hpp"
#include "executor.hpp"
#include "manipulator.hpp"
#include "processor.hpp"
#include "selector.hpp"

#include <QtTest>

class TestDBManager : public QObject
{
  Q_OBJECT
public:
  TestDBManager();
  virtual ~TestDBManager();

private slots:
  void test_case1();
  void test_driver();
  void test_selector();
  void test_manipulator();
  void test_processor();

protected:
private:
  // db::ConnectManager& m_data;
  db::Executor m_executor;
  db::Selector m_selector;
  db::Manipulator m_manipulator;
  db::Processor m_processor;
};

#endif // TESTDBMANAGER_HPP
