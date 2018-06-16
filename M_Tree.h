#ifndef M_TREE_H_INCLUDED
#define M_TREE_H_INCLUDED


#endif // M_TREE_H_INCLUDED
#include "MDSGeneral.h"

/***************Binary Only*****************/

typedef struct MTreeNode
{
    int key;
    MTreeNode*lchild;
    MTreeNode*rchild;
    MTreeNode*parent;

    //For Threaded Binary Tree
    short LTag;
    short RTag;

    Type data;
}MTreeNode,*NodePtr;

Status InitTree(NodePtr&Root)
{
    Root = new(MTreeNode);
    //if(&Root)return Fail;
    Root->lchild = Root->rchild = NULL;Root->data=-1;
    Root->key=0;
    return Success;
}
//*
Status Traverse(NodePtr&Root)   //Root-Left-Right
{
    printf("%d ",Root->data);
    if(Root->lchild)Traverse(Root->lchild);
    if(Root->rchild)Traverse(Root->rchild);
    return Success;
}
//*/
/*
Status Traverse(NodePtr&Root)   //Left-Root-Right
{
    if(Root->lchild)Traverse(Root->lchild);
    printf("%d ",Root->data);
    if(Root->rchild)Traverse(Root->rchild);
    return Success;
}
//*/
/*
Status Traverse(NodePtr&Root)   //Left-Right-Root
{
    if(Root->lchild)Traverse(Root->lchild);
    if(Root->rchild)Traverse(Root->rchild);
    printf("%d ",Root->data);
    return Success;
}
//*/
//*//存疑
Status SearchNode(NodePtr&Root,int k,NodePtr&p)
{
    if(Root->key == k){p=Root;return Success;}//这里return了没用，整个函数不会马上停下（虽然除浪费时间外没危险）
    if(Root->lchild)SearchNode(Root->lchild,k,p);
    if(Root->rchild)SearchNode(Root->rchild,k,p);
    return Fail;
}//*/
Status AddChild(NodePtr&Root,NodePtr&Child,char lr,int key)
{
    NodePtr p;
    if(SearchNode(Root,key,p)==Success)
    {
        if(lr == 'l')p->lchild = Chlid;
        else if(lr == 'r')p->rchild = Child;
        return Success;
    }
    return Fail;
}



Status Thread(NodePtr&Root)     //SKIPPED(懒)
{
    return Fail;
}


