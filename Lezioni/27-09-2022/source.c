//
// Created by Gabriele Scannagatti on 27/09/22.
//
#include<stdio.h>
#include<stdlib.h

struct n {
    int value;
    strcut n * next;
};

typedef struct n Node;

int main(void) {
    Node * head = NULL;
    Node el;
    el.value = 10;
    el.next = NULL;
    head = &el;
    Node el1;
    el1.value = 2;
    el1.next = NULL;
    el.next = &el1;

    Node* l = head;
    while(l!=NULL){
        printf("%d\n", l->value);
        l = l->next;
    }
    return 0;
}