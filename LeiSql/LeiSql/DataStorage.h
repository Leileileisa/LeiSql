#pragma once
#ifndef DATASTROAGE_H
#define DATASTROAGE_H
#include "BPlus.h"
namespace LeiSQL
{
    class DataStorage
    {
    public:
        DataStorage();
        ~DataStorage();
        void Insert(const char* username,const char* passwd);
        const char* Find(const char* username);
        void Delete(const char* username);
        void Change(const char* username,const char* newPasswd);
    private:
        BPlus bPlusTree;
    };
}
#endif // !DATASTROAGE_H

