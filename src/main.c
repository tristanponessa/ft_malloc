#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <sys/mman.h>

#define TINY_MIN 1
#define TINY_MAX 8
#define SMALL_MIN 9
#define SMALL_MAX 32
#define LARGE_MIN 33

#define NB_ALLOCS 100


void *mmap(void *addr, size_t length, int prot, int flags,
           int fd, off_t offset);
int munmap(void *addr, size_t length);


PROT_READ  Pages may be read.
PROT_EXEC  Pages may be executed.
PROT_WRITE Pages may be written.
//flag
MAP_SHARED


typedef struct s_list {
    struct s_list *next;
    void *data;
}              t_list;

typedef struct s_box {
    void *ptr;
    size_t len;
    int available;
}              t_box;

//************************************************************************************
t_list *ft_create_elem(void *data) {

    t_list *elem;

    elem = (t_list *)malloc(sizeof(t_list));
    elem->next = NULL;
    elem->data = data;
    return elem;
}

t_list *ft_list_last(t_list *blst) {

    while (blst->next != NULL)
        blst = blst->next;
    return blst;
}

void ft_list_push_back(t_list **begin_lst, void *data) {

    t_list *blst = *begin_lst;
    t_list *head = blst;
    while (blst->next != NULL)
        blst = blst->next;
    blst->next = ft_create_elem(data);
    *begin_lst = head;
}

void ft_clear_lst(t_list **l) {

    t_list *blst = *l;
    t_list *nxt;
    while (1) {
        if (blst->next == NULL)
            break;
        nxt = blst->next;
        free(blst);
        blst = nxt;
    }
    free(blst);
    *l = NULL;
}

void print_lst(t_list *l) {

    void *data;
    if (!l)
        return ;
    while (1) {
        data = l->data;
        printf("data %s\n", (char *)data);
        if (l->next == NULL)
            break;
        l = l->next;
    }
}


void show_alloc_ex_mem();

void free(void *ptr)
{
    t_box *ibox = (t_box*)ptr;
    munmap(ibox->ptr, ibox->len);
}

void *malloc(size_t size)
{
    t_box *ibox;

    if (size == 0)
        return NULL;
    if (size > TINY_MIN && size <= SMALL_MAX)
    {

    }
    //if (size >= SMALL_MIN && size <= SMALL_MAX)
    //{

    //}
    if (size >= TINY_MIN)
    {

    }




}


void *realloc(void *ptr, size_t size);
//



int main() {

    t_list *tiny_allocs;
    t_list *small_allocs;
    t_list *large_allocs;








}

