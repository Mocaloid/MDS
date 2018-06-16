#ifndef M_QUEUE_H_INCLUDED
#define M_QUEUE_H_INCLUDED


#endif // M_QUEUE_H_INCLUDED
#include "MDSGeneral.h"


typedef struct MQNode
{
    Type data;
    MQNode * next;
}MQNode,*Qptr;

typedef struct
{
    Qptr fr;    //Head of the queue
    Qptr re;    //Tail of the queue
}MQ;

Status InitQueue(MQ&Q)
{
    Q.fr = Q.re = (Qptr)malloc(sizeof(MQNode));
    if(!Q.fr)return Fail;//exit(OVERFLOW);
    Q.fr->next = NULL;
    return Success;
}
Status DestoryQueue(MQ&Q)
{
    while(Q.fr)
    {
        Q.re = Q.fr->next;
        free(Q.fr);
        Q.fr=Q.re;
    }
    return Success;
}
Status Pushback(MQ& Q,Type e)
{
    Qptr p=(Qptr)malloc(sizeof(MQNode));
    if(!p)return Fail;//exit(OVERFLOW);
    p->data = e;  p->next = NULL;
    Q.re->next = p;
    Q.re = p;
    return Success;
}
Status Pophead(MQ& Q,Type&e)
{
    if(Q.fr == Q.re)return Fail;
    Qptr p = Q.fr->next;
    e = p->data;
    Q.fr->next = p->next;
    free(p);
    return Success;
}


/************Circulate Queue*************/
//*
#define MAX_QUEUESIZE 0xff
typedef struct
{
    Type *base;
    int fr,re;
}MCirQ;


Status InitCirQ(MCirQ&Q)
{
    Q.base = (Type*)malloc(MAX_QUEUESIZE * sizeof(Type));
    if(!Q.base)return Fail;//exit(OVERFLOW);
    Q.fr = Q.re = 0;
    return Success;
}
int QueueLen(MCirQ Q)
{
    return (Q.re - Q.fr + MAX_QUEUESIZE) % MAX_QUEUESIZE;
}
Status Pushback(MCirQ&Q,Type e)
{
    if((Q.re+1)%MAX_QUEUESIZE == Q.fr)return Fail;
    Q.base[Q.re] = e;
    Q.re = (Q.re+1)%MAX_QUEUESIZE;
    return Success;
}
Status Pophead(MCirQ&Q,Type&e)
{
    if(Q.fr == Q.re)return Fail;
    e = Q.base[Q.fr];
    Q.fr = (Q.fr+1)%MAX_QUEUESIZE;
    return Success;
}
//*/

