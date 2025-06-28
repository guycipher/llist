#include "../src/llist.h"
#include <assert.h>

/* callback method for foreach testing*/
void callback(void *data)
{
    char *cStr = data;
    printf("%s\n", cStr);
}

void test_new_llist(void)
{
    struct linked_list *ll;
    assert(linked_list_new(&ll) == 0);
    assert(linked_list_delete(&ll) == 0);
}

void test_llist_print_empty(void)
{
    struct linked_list *ll;
    assert(linked_list_new(&ll) == 0);



    (void)linked_list_foreach(ll, callback);

    assert(linked_list_delete(&ll) == 0);

}

void test_push_pop(void)
{
    struct linked_list *ll;
    assert(linked_list_new(&ll) == 0);

    assert(linked_list_push(ll, "Hello") == 0);
    assert(linked_list_push(ll, "World") == 0);
    assert(linked_list_push(ll, "I") == 0);
    assert(linked_list_push(ll, "Am") == 0);
    assert(linked_list_push(ll, "Alex") == 0);

    linked_list_foreach(ll, callback);

    char *dat = linked_list_pop(ll);
    assert(strcmp(dat,"Alex") == 0);
    free(dat);

    dat = linked_list_pop(ll);
    assert(strcmp(dat,"Am") == 0);
    free(dat);

    dat = linked_list_pop(ll);
    assert(strcmp(dat,"I") == 0);
    free(dat);

    dat = linked_list_pop(ll);
    assert(strcmp(dat,"World") == 0);
    free(dat);

    dat = linked_list_pop(ll);
    assert(strcmp(dat,"Hello") == 0);
    free(dat);


    assert(linked_list_delete(&ll) == 0);
}

int main(void)
{
    test_new_llist();
    test_llist_print_empty();
    test_push_pop();
}