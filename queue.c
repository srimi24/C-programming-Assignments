#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue_t* create_queue()   // return a newly created empty queue
{
	// DO NOT MODIFY!!!
	queue_t* Q = (queue_t*) malloc(sizeof(queue_t));
	Q->list = create_list();
	Q->front = Q->list->head;
	Q->rear = Q->list->tail;
	Q->size = Q->list->size;
	return Q;
}

void enqueue(queue_t* q, int data) // TODO: insert data at the end of a queue
{
    node_t *new_node;
    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next=NULL;

    if(q->front==NULL)
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
   
    q->size ++;

}

int dequeue(queue_t* q) 	// TODO: return the data at the front of a queue and remove it. Return -1 if queue is empty
{
    if(q->front == NULL)
        return -1;
    else
    {
        node_t *temp;
        int data = q->front->data;

        temp = q->front;
        q->front = q->front->next;
        free(temp);
        temp = NULL;
        return data;

    }
    q->size--;

}

int front(queue_t* q) // TODO: return the data at the front of a queue. Return -1 if queue is empty
{
    if(q->front == NULL)
        return -1;
    int data = q->front->data;
    return data;

    
}

int empty(queue_t* q) // return if the queue is empty
{
	// DO NOT MODIFY!!!
	return is_empty(q->list);
}

int queue_size(queue_t* q) // returns the number of elements in the queue
{
	// DO NOT MODIFY!!!
	return q->size;
}

void delete_queue(queue_t* q) // empty the contents of the queue
{
	// DO NOT MODIFY!!!
	delete_list(q->list);
	free(q);
}

void display(queue_t *q)
{
    
    if(q->front == NULL)
        printf("Queue Underflow\n");
    else
    {
        node_t *temp;
        temp = q->front;
        while(temp != q->rear)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}


