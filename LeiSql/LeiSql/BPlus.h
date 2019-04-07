#pragma once
#ifndef BPLUS_H
#define BPLUS_H
#include <memory>
namespace LeiSQL
{
    class BPlus
    {
        class DataNode
        {
        public:
            DataNode(int data):Data(data),ChildNode(nullptr)
            {

            }
        private:
            int Data;
            
            DataNode* ChildNode;
        };
        class TreeNode
        {
        public:
            TreeNode():ptrStart(malloc(4096))
            {

            }
        private:
            void* ptrStart;
            void* ptrNow;
        };
        
    public:
        BPlus();
        void Insert(const char* username,const char* passwd);
        void Change(const char* username,const char* newPasswd);
        void Delete(const char* username,const char* passwd);
        DataNode Find(const char* username);
        ~BPlus();
    private:
        unsigned int  Uid;
    };
}
#endif


