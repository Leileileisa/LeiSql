#pragma once
#ifndef ORDERANALYZE_H
#define ORDERANALYZE_H
#include "DataStorage.h"
namespace LeiSQL
{
    class OrderAnalyze
    {
    public:
        OrderAnalyze();
        ~OrderAnalyze();
        void Process(const char* order);
    };
}
#endif


