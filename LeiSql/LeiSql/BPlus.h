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
            DataNode(char* username,char* passwd,DataNode* childNode=nullptr) :Username(username),Passwd(passwd),ChildNode(childNode)
            {

            }
            ~DataNode()
            {

            }
            int GetUID()
            {
                return UID;
            }
        private:
            int UID;
            char* Username;
            char* Passwd;
            DataNode* ChildNode;
        };
        class TreeNode
        {
        public:
            TreeNode():PtrStart(malloc(4096)),PtrNow(PtrStart),PtrEnd(PtrStart+4096)
            {
                
            }
            void* Build(int uid, const char* username, const char* passwd)
            {
                int length;
                if (PtrEnd - PtrNow < length)
                {

                }
                else
                {

                }
            }
        private:
            void* PtrStart;
            void* PtrNow;
            void* PtrEnd;
            DataNode* FirstNode;
        };
        
    public:
        BPlus();
        void Insert(const char* username,const char* passwd);
        void Change(const char* username,const char* newPasswd);
        void Delete(const char* username,const char* passwd);
        DataNode Find(const char* username);
        ~BPlus();
    private:
        unsigned int  UID;
        TreeNode RootNode;
    };
}
#endif


