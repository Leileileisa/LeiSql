#include "DataStorage.h"

namespace LeiSQL
{
    DataStorage::DataStorage()
    {
    }


    DataStorage::~DataStorage()
    {
    }

    void DataStorage::Insert(const char* username, const char* passwd)
    {
        bPlusTree.Insert(username,passwd);
    }

    const char* DataStorage::Find(const char* username)
    {
        return bPlusTree.Find(username);
    }

    void DataStorage::Delete(const char* username)
    {
        bPlusTree.Delete(username);
    }

    void DataStorage::Change(const char* username, const char* newPasswd)
    {
        bPlusTree.Change(username, newPasswd);
    }

}
