/* tst_model.hpp */

#ifndef TST_MODEL_HPP
#define TST_MODEL_HPP


#include <QtTest>
#include "readdata.hpp"

class TestModel : public QObject
{
Q_OBJECT

public:
	TestModel();
	~TestModel();

private slots:
	void test_first();
	void test_readData();

private:
	ReadData m_data;
};

 
#endif // TST_MODEL_HPP
