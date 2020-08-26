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


typedef struct s_box {
    void *madr;
    size_t len;
    int available;
    struct s_box *next;
}              t_box;

//************************************************************************************

/*
void *ft_mmap() {

    void *zone;

    zone = (t_box *)mmap(madr, len, )
    if (zone == NULL)
        return NULL;
}
*/

t_box *ft_create_elem(void *madr, size_t len) {

    t_box *elem;

    elem = (t_box *)mmap(madr, sizeof(t_box), PROT_READ | PROT_EXEC | PROT_WRITE, MAP_SHARED, 3 ,0);

    elem->madr = data;




    elem->size = len;
    elem->available = 1;
    elem->next = NULL;

    return elem;
}

t_box *ft_box_last(t_box *blst) {

    while (blst->next != NULL)
        blst = blst->next;
    return blst;
}

void ft_box_push_back(t_box **begin_lst, void *data) {

    t_box *blst = *begin_lst;
    t_box *head = blst;
    while (blst->next != NULL)
        blst = blst->next;
    blst->next = ft_create_elem(data);
    *begin_lst = head;
}

void ft_clear_lst(t_box **l) {

    t_box *blst = *l;
    t_box *nxt;
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

void print_lst(t_box *l) {

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

    t_box *tiny_allocs;
    t_box *small_allocs;
    t_box *large_allocs;

    t_box *allocs;


}

