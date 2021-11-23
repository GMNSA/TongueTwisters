/* tst_model.cpp */

#include "tst_model.hpp"
 
TestModel::TestModel()
{
//ctor 
}
 
 
TestModel::~TestModel()
{
//dtor 
}

void TestModel::test_first()
{
	QVERIFY(true == true);
}

void TestModel::test_readData()
{
	auto data = m_data.request();

	QVERIFY(data.isEmpty() == false);
}

QTEST_APPLESS_MAIN(TestModel)
