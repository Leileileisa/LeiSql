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
        class TreeNode;
        class DataNode
        {
        public:
            DataNode(int uid,const char* username,const char* passwd,TreeNode* childNode=nullptr) :UID(uid),Username(username),Passwd(passwd),ChildNode(childNode)
            {

            }
            ~DataNode()
            {

            }
            int GetUID()
            {
                return UID;
            }
            TreeNode* GetChild()
            {
                return ChildNode;
            }
            void SetChild(TreeNode* dataNode)
            {
                ChildNode = dataNode;
            }
        private:
            long UID;//8
            const char* Username;//8
            const char* Passwd;//8
            TreeNode* ChildNode;//8
        };
        class TreeNode
        {
        public:
            TreeNode():PtrStart(malloc(PAGESIZE)),PtrNow(PtrStart)
            {
                PtrEnd = (void*)(long(PtrStart)+PAGESIZE);
            }
            void* Build(long uid, const char* username, const char* passwd)
            {
                int length;
                if ((long)PtrEnd-(long)PtrNow<sizeof(DataNode))
                {
                    DataNode* node = Find(FirstNode, uid);
                    LastNode = new(PtrNow) DataNode(uid,username,passwd);
                }
                else
                {

                }
            }
            
            DataNode* Find(DataNode* firstNode, long uid)
            {
                DataNode* node = firstNode;
                DataNode* nextNode = node + sizeof(DataNode);
                DataNode* lastNode = firstNode + PAGESIZE - sizeof(DataNode);
                while ((node->GetUID() < uid)&&(nextNode<lastNode))
                {
                    node+=sizeof(DataNode);
                    nextNode += sizeof(DataNode);
                    if (nextNode->GetUID() > uid)
                    {
                        break;
                    }
                }
                if (nextNode == lastNode&&)
                {

                }
                
            }
        private:
            void* PtrStart;
            void* PtrNow;
            void* PtrEnd;
            DataNode* FirstNode;
            DataNode* LastNode;
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


