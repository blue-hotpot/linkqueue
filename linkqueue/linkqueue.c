#include<stdio.h>
#include<stdlib.h>
#include"linkqueue.h"

//finish
linkqueue *linkqueue_creat()
{
    linkqueue *lq=NULL;
    while(lq==NULL)
    {
        lq=(linkqueue *)malloc(sizeof(linkqueue));
        printf("1");
    }
    lq->front=lq->rear=NULL;
    while((lq->front)==NULL)
    {
        lq->front=lq->rear=(nodepoint)malloc(sizeof(node));
        printf("2");
    }
    lq->front->data=-1;
    lq->front->next=NULL;
    return lq;
}

//finish
int linkqueue_free(linkqueue *lq)
{
    if(lq==NULL||lq->rear==NULL)
    {
        printf("the linkqueue is null\n");
        return -1;
    }
    //队尾进去，队头出
    //队头   队尾
    printf("free:\n");
    while(lq->front!=lq->rear)
    {
        nodepoint ret=lq->front;
        lq->front=lq->front->next;
        printf("%d\t",ret->data);
        free(ret);
    }
    printf("%d\n",lq->front->data);
    free(lq->front);
    free(lq);
    return 1;
}

//finish
int linkqueue_in(linkqueue *lq,datatype data)
{
    if(lq==NULL||lq->rear==NULL)
    {
        printf("the linkqueue is null\n");
        return -1;
    }
    lq->rear->data=data;
    while(lq->rear->next==NULL)
    {
        lq->rear->next=(nodepoint)malloc(sizeof(node));
        printf("3");
    }
    lq->rear=lq->rear->next;
    lq->rear->data=-1;
    lq->rear->next=NULL;
    return 1;
}

//fnish
datatype linkqueue_out(linkqueue *lq)
{
    if(lq==NULL||lq->rear==NULL)
    {
        printf("the linkqueue is null\n");
        return -1;
    }
    datatype ret=lq->front->data;
    nodepoint brief=lq->front;
    lq->front=lq->front->next;
    free(brief);
    return ret;
}

//finish
int linkqueue_clear(linkqueue *lq)
{
    if(lq==NULL||lq->rear==NULL)
    {
        printf("the linkqueue is null\n");
        return -1;
    }
    //队尾进去，队头出
    //队头   队尾
    while(lq->front!=lq->rear)
    {
        nodepoint ret=lq->front;
        lq->front=lq->front->next;
        free(ret);
    }
    return 1;
}

//finish
int linkqueue_empty(linkqueue *lq)
{
    return (lq->front==lq->rear?1:0);
}

//finish
int linkqueue_show(linkqueue *lq)
{
    nodepoint point=lq->front;
    printf("the queue is:\n");
    while (point!=lq->rear)
    {
        printf("%d\t",point->data);
        point=point->next;
    }
    printf("%d",point->data);
    printf("\n");
}