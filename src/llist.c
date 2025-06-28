/* (c) Alex Gaetano Padula
** apache v2.0
*/
#include "llist.h"


int linked_list_new(struct linked_list **ll)
{
    *ll = malloc(sizeof(struct linked_list));
    if (*ll == NULL) return -1;

    (*ll)->head = NULL;
    (*ll)->tail = NULL;

    return 0;
}

int linked_list_delete(struct linked_list **ll)
{
    if (*ll == NULL) return -1;

    struct node *current = (*ll)->head;

    if (current == NULL)
    {
        free(*ll);
        *ll = NULL;
        return 0;
    }

    while (1)
    {
        struct node *next = current->next;

        free(current);

        current = next;

        if (current == NULL) break;
    }

    (*ll)->head = NULL;
    (*ll)->tail = NULL;


    free(*ll);
    *ll = NULL;

    return 0;
}

int linked_list_push(struct linked_list *ll, void *data)
{

    if (ll->head == NULL)
    {
        ll->head = malloc(sizeof(struct node));
        if (ll->head == NULL) return -1;

        ll->head->data = data;
        ll->head->next = NULL;
    }
    else
    {
        ll->tail = malloc(sizeof(struct node));
        if (ll->tail == NULL) return -1;

        ll->tail->data = data;
        ll->tail->next = NULL;

        struct node *current = ll->head;

        while (1)
        {
            if (current->next == NULL)
            {
                current->next = ll->tail;
                break;
            }
            current = current->next;

        }
    }

    return 0;
}

void *linked_list_pop(struct linked_list *ll)
{

    struct node *current = ll->head;

    if (ll->tail == NULL || current == NULL)
    {
        return NULL;
    }

    if (current->next == NULL)
    {
        char *data = malloc(strlen(current->data) +1);
        if (data == NULL) return NULL;

        strcpy(data, current->data);
        free(current);

        ll->head = NULL;
        ll->tail = NULL;
        return data;
    }

    while (1)
    {
        if (current->next == ll->tail)
        {
            char *data = malloc(strlen(ll->tail->data) + 1);
            if (data == NULL) return NULL;

            strcpy(data, ll->tail->data);
            free(ll->tail);
            current->next = NULL;
            ll->tail = current;

            return data;
        }

        current = current->next;

    }

}

void linked_list_foreach(const struct linked_list *ll, void (*callback)(void *data))
{
    if (ll == NULL) return;

    struct node *current = ll->head;

    if (current == NULL) return;

    while (1)
    {
        callback(current->data);
        current = current->next;

        if (current == NULL) break;
    }
}