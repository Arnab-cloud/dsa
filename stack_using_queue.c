#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue
{
    int cap, front, rear;
    int *arr;
}typedef queue;

struct stack_using_queue
{
    queue* Q1;
    queue* Q2;
}typedef stack;

queue* createQueue()
{
    queue* new = (queue*)malloc(sizeof(queue));
    new->cap = 1;
    new->front = new->rear = -1;
    new->arr = (int*)malloc(sizeof(int)*100);
    return new;
}

int isEmpty(queue* q)
{
    return q->front > q->rear || (q->front == -1) && (q->front == -1);
}

void enQueue(queue* q, int val)
{
    q->arr[++(q->rear)] = val;
    if(q->front == -1)
        (q->front)++;
}

int deQueue(queue* q)
{
    if(isEmpty(q))
        return NULL;
    return q->arr[(q->front)++];
}

int topQueue(queue* q)
{
    if(isEmpty(q))
        return NULL;
    return q->arr[q->rear];
}

void freeQueue(queue* q)
{
    free(q->arr);
    free(q);
}

stack* createStack()
{
    stack *s = (stack*)malloc(sizeof(stack));
    s->Q1 = createQueue();
    s->Q2 = createQueue();
    return s;
}

int isEmptyStack(stack *s)
{
    return isEmpty(s->Q1) && isEmpty(s->Q2); 
}

void push(stack *s, int val)
{
    if(isEmpty(s->Q1))
        enQueue(s->Q2,val);
    else
        enQueue(s->Q1,val);
}

int pop(stack* s)
{
    int size;
    if(isEmptyStack(s))
        return NULL;
    printf("ok ");
    if(!isEmpty(s->Q1))
    {
        size = s->Q1->cap;
        for(int i=1; i<size; i++)
            enQueue(s->Q2,deQueue(s->Q1));
        return deQueue(s->Q1);
    }
    size = s->Q2->cap;
    for(int i=1; i<size; i++)
        enQueue(s->Q1,deQueue(s->Q2));
    return deQueue(s->Q2);
}

int top(stack* s)
{
    if(isEmptyStack(s))
        return false;
    if(!isEmpty(s->Q1))
        return topQueue(s->Q1);
    return topQueue(s->Q2);
}

void freeStack(stack* s)
{
    freeQueue(s->Q1);
    freeQueue(s->Q2);
    free(s);
}

int main()
{
    stack *s = createStack();
    push(s,1);
    push(s,2); 
    push(s,3); 
    push(s,4);
    while(!isEmptyStack(s))
        printf("%d \n", pop(s)); 
    freeStack(s);
    return 0;
}
