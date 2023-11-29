#include<stdio.h>
#include"linkqueue.h"
int main()
{
    linkqueue *lq;
    lq=linkqueue_creat();
    linkqueue_in(lq,1);
    linkqueue_in(lq,2);
    linkqueue_in(lq,3);
    printf("\n");
    linkqueue_show(lq);
    printf("%d\n",linkqueue_out(lq));
    linkqueue_show(lq);
    if(linkqueue_empty(lq))
        printf("empty1\n");
    linkqueue_clear(lq);
    if(linkqueue_empty(lq))
        printf("empty2\n");
    linkqueue_free(lq);
    return 0;
}