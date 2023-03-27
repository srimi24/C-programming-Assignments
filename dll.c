#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
    node_t *new_node;
    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next=NULL;

    if(list->head == NULL && list->tail == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->size++;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
    node_t *new_node;
    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next=NULL;

    if(list->tail == NULL && list->head == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
    list->size++;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
    node_t *temp;
    temp = list->head;
    while(temp->data != prev && temp !=NULL)
    {
        temp = temp->next;
    }
    if(temp->next != NULL)
    {
        node_t *new_node;
        new_node = (node_t*)malloc(sizeof(node_t));
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next=NULL;

       /* new_node->next = temp->next;
        temp->next->prev = new_node;
        new_node->prev = temp;*/
        temp->next->prev = new_node;
		new_node->next = temp->next;
				
		new_node->prev = temp;
		temp->next = new_node;
    }
    else
    {
        node_t *new_node;
        new_node = (node_t*)malloc(sizeof(node_t));
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next=NULL;

        temp->next = new_node;
        new_node->prev = temp;

        list->tail = new_node;
    }
    
    list->size++;
    
    
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
    

    if(list->head != NULL)
    {
        node_t *temp;
        temp = list->head;
        
        list->head = list->head->next;
        list->head->prev = NULL;
        free(temp);
        temp = NULL;
    }
    list->size--;  
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
    
    if(list->tail != NULL)
    {
        node_t *temp;
        temp = list->tail;
        
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(temp);
        temp = NULL;
    }
    list->size--; 
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
    node_t *temp;
    temp = list->head;
    

    while(temp->data != data && temp != NULL)
    {
        temp = temp->next;
    }

    if(temp->prev == NULL)
    {
        list->head = list->head->next;
        list->head->prev = NULL;
        free(temp);
        temp = NULL;
    }

    else if(temp->next == NULL)
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(temp);
        temp = NULL;
    }
    
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        temp=NULL;
    }
    
    list->size--; 
    
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{	
    node_t *temp;
    temp = list->head;

    while(temp!=NULL)
        {
            if(temp->data == data)
                
                return temp;
            temp = temp->next;
        }
    return NULL;
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

