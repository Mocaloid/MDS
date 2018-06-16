#ifndef MSORT_H_INCLUDED
#define MSORT_H_INCLUDED


#endif // MSORT_H_INCLUDED

#include "MDSGeneral.h"
void Swap(Type&a,Type&b);
Status BubbleSort(Type*A,int n)
{
    for(int i=0;i<n-1;++i)
    {
        for(int j=i+1;j>0 && A[j]<A[j-1];--j)
        {
            Swap(A[j],A[j-1]);
        }
    }
    return Success;
}//o(n^2)

Status InsertSort(Type*A,int n)
{
    for(int i=1;i<n;++i)
    {
        if(A[i] < A[i-1])
        {
            Type q = A[i];
            int j=i-1;
            for(1;j>0 && A[j]>A[i];--j)A[j]=A[j-1];//
            A[j+1]=A[i];
        }
    }
    return Success;
}//o(n^2)?

void HeapAdjust(Type*H,int s,int m);
Status HeapSort(Type*A,int n)
{
    for(int i=n;i>0;--i)A[i]=A[i-1];//Heap begin from 1 but Array not
    //InitHeap
    /** Root is A[1]
      * A[i]'s lchild is A[i*2]
      * A[i]'s rchild is A[i*2+1]
      * A[i]'s parent is A[i/2],whatever i is odd or even
    ***/
    for(int i=n/2;i>0;--i)HeapAdjust(A,i,n);//Build a heap from the bottom

    //HeapSort
    for(int i=n;i>0;--i)
    {
        Swap(A[1],A[i]);
        HeapAdjust(A,1,i-1);
    }
    for(int i=0;i<n;++i)A[i]=A[i+1];//Ignore it.
    return Success;
}//o(nlogn)








/*######################################
            other function
########################################*/
void Swap(Type&a,Type&b)
{
    //a^=b;b^=a;a^=b;
    Type c=a;a=b;b=c;

}
void HeapAdjust(Type*H,int s,int m)// m:Max capacity of heap   s:top node position
{
    Type rc = H[s];
    for(int j=2*s;j<=m;j*=2)    //find a child
    {
        if(j<m && (H[j]<H[j+1]))j++;     //find a GREATER child
        if(rc>H[j])break;       //if rc's at a right place,then we don't need to do anth
        H[s] = H[j];    s = j;  //if not,Swap
    }
    H[s] = rc;
}





