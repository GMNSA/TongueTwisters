/* testdbmanager.cpp */

#include "testdbmanager.hpp"
#include <QFile>

TestDBManager::TestDBManager() {}

TestDBManager::~TestDBManager() {}

void
TestDBManager::test_case1()
{
  QVERIFY(true == true);
}

void
TestDBManager::test_driver()
{
  // auto res = m_executor.executor("SELECT * FROM Classics");

  // qDebug() << res.first;
}

void
TestDBManager::test_selector()
{
  //  auto result = m_selector.classics();
  //  QVERIFY(result.first == true);
  //  QVERIFY(result.second.size() != 0);
}

void
TestDBManager::test_manipulator()
{
  //  QVERIFY(m_manipulator.generateBindString(4) == "?,?,?,?");
  //  QVERIFY(m_manipulator.generateBindString(2) == "?,?");
  //  QVERIFY(m_manipulator.generateBindString(0) == "");

  //   QFile file("/home/_who/WORK/tongueTwisters/TongueTwisters/tests/"
  //              "test_dbmanager/srcs/words.txt");
  //
  //   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
  //     return;
  //
  //   QTextStream in(&file);
  //
  //   while (!in.atEnd()) {
  //     m_manipulator.insertRow("Classics", { in.readLine() });
  //   }
  //
  //   // ToDO save data to db.
  //
  //   file.close();
  //
  //   QFile file2("/home/_who/WORK/tongueTwisters/TongueTwisters/tests/"
  //               "test_dbmanager/srcs/words2.txt");
  //
  //   if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
  //     return;
  //
  //   QTextStream in2(&file2);
  //
  //   while (!in2.atEnd()) {
  //     m_manipulator.insertRow("Poems", { in2.readLine() });
  //   }
  //
  //   file2.close();
  //
  //   QFile file3("/home/_who/WORK/tongueTwisters/TongueTwisters/tests/"
  //               "test_dbmanager/srcs/words3.txt");
  //
  //   if (!file3.open(QIODevice::ReadOnly | QIODevice::Text))
  //     return;
  //
  //   QTextStream in3(&file3);
  //
  //   while (!in3.atEnd()) {
  //     m_manipulator.insertRow("Voice", { in3.readLine() });
  //   }
  //
  //   file3.close();
  //
  //   QFile file4("/home/_who/WORK/tongueTwisters/TongueTwisters/tests/"
  //               "test_dbmanager/srcs/words4.txt");
  //
  //   if (!file4.open(QIODevice::ReadOnly | QIODevice::Text))
  //     return;
  //
  //   QTextStream in4(&file3);
  //
  //   while (!in4.atEnd()) {
  //     m_manipulator.insertRow("Breathing", { in4.readLine() });
  //   }
  //
  //   file4.close();
}

void
TestDBManager::test_processor()
{
  auto result = m_processor.requestData(eDBType::POEMS);
  QVERIFY(result.first == true);
  QVERIFY(result.second.isEmpty() == false);

  result = m_processor.requestData(eDBType::BREATHING);
  QVERIFY(result.first == true);
  QVERIFY(result.second.isEmpty() == false);

  result = m_processor.requestData(eDBType::VOICE);
  QVERIFY(result.first == true);
  QVERIFY(result.second.isEmpty() == false);

  result = m_processor.requestData(eDBType::CLASSICS);
  QVERIFY(result.first == true);
  QVERIFY(result.second.isEmpty() == false);
}

QTEST_APPLESS_MAIN(TestDBManager)
