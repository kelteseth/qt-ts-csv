#include "tst_Csv2ts.hpp"
#include "tst_Ts2csv.hpp"

#include <QtTest>

int main()
{
    int ret = 0;

    {
        tst_Ts2Csv test;
        ret |= QTest::qExec(&test);
    }

    {
        tst_Csv2ts test;
        ret |= QTest::qExec(&test);
    }

    return ret;
}
