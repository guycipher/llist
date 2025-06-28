/* (c) Alex Gaetano Padula
 ** apache v2.0
*/
#ifndef LLIST_H
#define LLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* simple linked list in c w/ linear time O(n) written as a c11
 * library.
 */

struct node
{
    void *data;
    struct node *next;
};

struct linked_list
{
    struct node *head;
    struct node *tail;
};

int linked_list_new(struct linked_list **ll);
int linked_list_delete(struct linked_list **ll);
int linked_list_push(struct linked_list *ll, void *data);
void *linked_list_pop(struct linked_list *ll);
void linked_list_foreach(const struct linked_list *ll, void (*callback)(void *data));

#endif /* LLIST_H */