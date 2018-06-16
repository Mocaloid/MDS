#ifndef M_STACK_H_INCLUDED
#define M_STACK_H_INCLUDED

#endif // M_STACK_H_INCLUDED
#include "MDSGeneral.h"

int const STACK_SIZE = 0xff;
typedef char Type;


typedef struct
{
    Type * base;
    Type * top;
    int stacksize;
}MStack;

Status InitStack(MStack& s)
{
    s.base = (Type*)malloc(STACK_SIZE * sizeof(Type));
    if(!s.base)return Fail;
    s.top = s.base;
    s.stacksize = STACK_SIZE;
    return Success;
}
Status Gettop(MStack s,Type& e)
{
    if(s.base == s.top)return Fail;
    e = *(s.top-1);
    return Success;
}

Status Push (MStack& s,Type e)
{
    if(!s.base || s.top-s.base >= s.stacksize)return Fail;
    *(s.top++) = e; return Success;
}
Status Pop (MStack& s,Type& e)
{
    if(!s.base || s.top == s.base)return Fail;
    e = *(--s.top); return Success;
}
