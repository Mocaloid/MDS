#ifndef M_LINKEDLIST_H_INCLUDED
#define M_LINKEDLIST_H_INCLUDED



#endif // M_LINKEDLIST_H_INCLUDED

#include "MDSGeneral.h"
typedef int M_Type

/////////////////////////////////////////------- Linked_List --------////////////////////////////////////////////////////

struct M_Node
{
    M_Type Value;
    M_Node* Next;
    M_Node* Prev;

};

M_Node * CreateList()
{
    //initiate
    M_Node Head = new M_Node;
    Head.Prev = Head.Next=NULL;
    Head.Value = -0xffff;

    M_Node* p = &Head;
    //Connect
    while(1)
    {
        char c = 'y';
        if(c == 'N' || c == 'n')break;
        if(c == 'Y' || c == 'y')
        {
            M_Node nd = new M_Node;
            printf("Please input the element you wanna Add into\n");
            cin << Node.Value;
            p->Next = &nd;
            nd.Prev = p;
            nd.Next = NULL;
            p = &nd;
        }
        else continue;

        printf("Continue?\n");
        c = getchar();
    }
    return Head;
}
M_Node * CreateCircularList()
{
    //initiate
    M_Node Head = new M_Node;
    Head.Prev = Head.Next= &Head;
    Head.Value = -0xffff;
    M_Node* h,p;
    h = p = &Head;
    //Connect
    while(1)
    {
        char c = 'y';
        if(c == 'N' || c == 'n')break;
        if(c == 'Y' || c == 'y')
        {
            M_Node nd = new M_Node;
            printf("Please input the element you wanna Add into\n");
            cin << Node.Value;
            M_Node* n = &nd;
            p->Next = n;
            n->Prev = p;
            n->Next = h;
            h->Prev = n;
            p = n;
        }
        else continue;
        printf("Continue?\n");
        c = getchar();
    }
    return Head;
}
void LAppend(M_Node* H,M_Type v)
{
    for(M_Node* p = H ; p->Next != NULL ; p = p->Next);
    M_Node nd = new M_Node;
    p->Next = &nd;
    nd.Prev = p;
    nd.Value = v;
}

void LInsert(M_Node* H,M_Type v,int pos)
{
    int cnt=0;
    M_Node* p,q;
    for(p = H ; (++cnt<pos)&&(p != NULL) ; p = p->Next);
    if(p-Next == NULL){printf("Failed.\n");break;};
    if(cnt==pos)
    {
        q = p->Next;
        M_Node nd = new M_Node;
        nd.Value = v;
        M_Node* r = &nd;

        //INSERT
        r->Prev = p; r->Next = q;
        p->Next = r;
        q->Prev = r;
    };
    printf("Done.\n");
}

void LDelete(M_Node* H,M_Type v,int pos)
{
    int cnt=0;
    M_Node* p,q,r;
    for(p = H ; (++cnt<pos)&&(p != NULL) ; p = p->Next);
    if(p-Next == NULL){printf("Failed.\n");break;};
    if(cnt==pos)
    {
        q = p->Next;
        r = p->Prev;
        free(p);

        //DELETE
        r->Next = q
        q->Prev = r;
    };
    printf("Done.\n");
}
void LClear(M_Node* H)
{
    M_Node* p = H;
    do{
        M_Node*q = p->Next;
        free(p);
        p = q;
    }while(p!=NULL)
    printf("Done.\n");
}
