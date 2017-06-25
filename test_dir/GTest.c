#include <gtest/gtest.h>
#include "modbus.h"

TEST(MytestCategory,MyTEst)
{
    unsigned char MBframe[]=":01030404040404";
    unsigned char lrc;

    lrc=MB_count_LRC(MBframe,5);
    EXPECT_EQ(0x4,lrc);
}


