#pragma once
#ifndef BPLUS_H
#define BPLUS_H
#include <memory>
#include <new>
#define PAGESIZE 4096
namespace LeiSQL
{
    class BPlus
    {
    public:
        BPlus();
        void Insert(const char* username,const char* passwd);
        void Change(const char* username,const char* newPasswd);
        void Delete(const char* username);
        const char* Find(const char* username);
        ~BPlus();
    private:
        class TreeNode;
        class DataNode
        {
        public:
            DataNode(int uid,const char* username,const char* passwd,DataNode* nextNode=nullptr) :UID(uid),Username(username),Passwd(passwd),NextNode(nextNode)
            {

            }
            ~DataNode()
            {

            }
            int GetUID()
            {
                return UID;
            }
            DataNode* GetNext()
            {
                return NextNode;
            }
            void SetNext(DataNode* dataNode)
            {
                NextNode = dataNode;
            }
        private:
            long UID;//8
            const char* Username;//8
            const char* Passwd;//8
            DataNode* NextNode;//8
        };
        class TreeNode
        {
        public:
            class PointNode;
            TreeNode()
            {

            }
            void* Build(long uid, const char* username, const char* passwd)
            {
                
            }
            
            DataNode* Find(DataNode* firstNode, long uid)
            {
                
                
            }
            void Change(const char* username, const char* newPasswd)
            {

            }
            void Delete(const char* username)
            {

            }
            void Insert(const char* username, const char* passwd)
            {

            }
        private:
            class PointNode
            {
            public:
                PointNode():UID(0),ChildNode(nullptr)
                {

                }
                PointNode(long uid, TreeNode* childNode = nullptr) :UID(uid), ChildNode(childNode)
                {
                }
                long UID;//8
                TreeNode* ChildNode;//8
            };
            PointNode Nodes[256];
        };
        
        unsigned int  UID;
        TreeNode RootNode;
    };
}
#endif


