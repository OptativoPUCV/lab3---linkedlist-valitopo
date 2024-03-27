#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
   
  List * new = (List *)malloc(sizeof(List));

  return new;
}

void * firstList(List * list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->head == NULL) {
        return NULL;
    }
    list->current = list->head;
    return list->head->data;
  
}

void * nextList(List * list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->current == NULL)
    {
        return NULL;
    }
    if (list->current->next == NULL)
    {
        return NULL;
    }
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {

    if (list == NULL) {
        return NULL;
    }
    if (list->tail == NULL) {
        return NULL;
    }
    list->current = list->tail;
    return list->tail->data;
}

void * prevList(List * list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->current == NULL)
    {
        return NULL;
    }
    if (list->current->prev == NULL)
    {
        return NULL;
    }
    list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
    if (list == NULL) {
        return;
    }
    Node * new = createNode(data);
    if (list->head == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        new->next = list->head;
        list->head->prev = new;
        list->head = new;
    }
  
}
    


void pushBack(List * list, void * data) {
    if (list == NULL) {
        return;
    }
    Node * new = createNode(data);
    if (list->tail == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        new->prev = list->tail;
      
    }
    list->current = list->tail;
    list->tail = new;
  
    pushCurrent(list,data);
    
}

void pushCurrent(List * list, void * data) {
    if (list == NULL) {
        return;
    }
    Node * new = createNode(data);
    if (list->current == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        new->next = list->current->next;
        new->prev = list->current;
        list->current->next = new;
        if (new->next != NULL)
        {
            new->next->prev = new;
        }
    }
    list->current = new;
    
  
}

void * popFront(List * list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->head == NULL) {
        return NULL;
    }
    Node * aux = list->head;
    list->head = list->head->next;
    if (list->head != NULL)
    {
        list->head->prev = NULL;
    }
    else
    {
        list->tail = NULL;
    }
    list->current = list->head;  
    return aux->data;

}

void * popBack(List * list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->tail == NULL) {
        return NULL;
    }
    Node * aux = list->tail;
    list->tail = list->tail->prev;
    if (list->tail != NULL)
    {
        list->tail->next = NULL;
    }
    else
    {
        list->head = NULL;
    }
    list->current = list->tail;
    return aux->data;
}

void * popCurrent(List * list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->current == NULL) {
        return NULL;
    }
    Node * aux = list->current;
    if (list->current->prev != NULL)
    {
        list->current->prev->next = list->current->next;
    }
    else
    {
        list->head = list->current->next;
    }
    if (list->current->next != NULL)
    {
        list->current->next->prev = list->current->prev;
    }
    else
    {
        list->tail = list->current->prev;
    }
    list->current = list->current->next;
    return aux->data;
  
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}