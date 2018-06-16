#ifndef M_GRAPH_H_INCLUDED
#define M_GRAPH_H_INCLUDED



#endif // M_GRAPH_H_INCLUDED
#include "MDSGeneral.h"


//Adjacency List mod
typedef struct MArcNode
{
    int from;   //from who
    int to;     //to who
    MArcNode*NextArc;
}MArcNode;

#define LISTSIZE 0xff
typedef struct MVNode
{
    int Vex;
    Type data;
    int Id;int Od;
    MArcNode*FirstArc;
}MVNode,*VNodePtr,AdjList[LISTSIZE];

Status CreateV (int Vex,Type data,VNodePtr&p)
{
    if(Vex >= LISTSIZE)return Fail;
    p = new(MVNode);
    p->Vex = Vex;
    p->data = data;
    p->Id = p->Od = 0;
    p->FirstArc = NULL;
    return Success;
}

Status Adjoin(MVNode&A,MVNode&B,bool isoriented) // A---->B
{
    MArcNode*Arc = new(MArcNode);
    Arc->from = A.Vex;
    Arc->to = B.Vex;
    Arc->NextArc=NULL;
    A.Od++;B.Id++;
    if(!A.FirstArc)A.FirstArc = Arc;
    else
    {
        MArcNode*p = A.FirstArc;
        for(1;p->NextArc;p=p->NextArc);
        p->NextArc = Arc;
    }
    if(!isoriented)Adjoin(B,A,true);
    return Success;
}

//Status Traverse(MVNode R); //skipped

//Minimum Cost Spanning Tree skipped.(Prim/Kruskal)

Status TopoSort(AdjList L,int len,AdjList&rst)
{
    bool flg[len];memset(flg,0,sizeof(flg));
    for(int I=0;I<len;I++)
    {
        int i=0;for(i;flg[i] || i<len && L[i].Id>0;i++);
        if(L[i].Id!=0)return Fail;  //none of VNode's indegree is 0 (There must a circuit included)
        flg[i]=1;
        for(MArcNode*p = L[i].FirstArc;p;p=p->NextArc) L[p->to].Id--;
        rst[I]=L[i];
    }
    for(int I=0;I<len;I++)L[I]=rst[I];
    return Success;
}
