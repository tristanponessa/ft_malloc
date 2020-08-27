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

t_box *l; //global

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





t_box *ft_create_elem() {

    t_box *elem;

    elem = (t_box *)ft_mmap(madr, sizeof(t_box), PROT_READ | PROT_EXEC | PROT_WRITE, MAP_SHARED, 3 ,0);
    if elem {
        elem->madr = NULL;
        elem->size = -1;
        elem->available = -1;
        elem->next = NULL;
    }
    return elem;
}

void ft_box_push_back(size_t len) {

    t_box *blst;
    t_box *head;

    if !l{
        l = ft_create_elem();
        return ;
    }
    blst = l;
    head = l;
    while (blst->next != NULL)
        blst = blst->next;
    blst->next = ft_create_elem(data);
    l = head;
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

void show_alloc_ex_mem() {
    
    if (!l)
        return ;
    while (1) {
        printf("adr %p ", l->madr);
        printf("size %z\n", l->len);
        if (l->next == NULL)
            break;
        l = l->next;
    }
}

void fatal(char *msg) {

    ft_put_fd(STDERR, msg);
    //free all
    exit(0);
}

void *ft_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {

    void *zone;

    zone = (t_box *)mmap(addr, length, prot, flags, fd, offset);
    if (zone == MAP_FAILED)//(void *) -1
        return NULL;
    return zone;
}

void free(void *ptr)
{
    int r;

    if !ptr
        return ;
    t_box *ibox = (t_box*)ptr;
    r = munmap(ibox->ptr, ibox->len);
    if (r == -1)
        fatal("munmap failed with -1");
}


void *malloc(size_t size)
{

    t_box *i;
    int res = 0;

    i = lst;
    while (1) {


        //didnt find anything in tiny or small
        if (!blst || blst->next == NULL)
            res = add_small_tiny(&lst);
            if (res == -1)

            return i;
        if (len >= LARGE_MIN)
            //create zone
            res = ft_box_push_back(&lst, len);
            //go to end of list
            if (res == -1)
                return NULL;
            return i;//go to end of list change i
        if (len >= TINY_MIN && len <= TINY_MAX && i->madr) || (len >= TINY_MIN && len <= TINY_MAX && i->madr)
            res = 1;

        if res == -1
            return NULL;
        if res == 1
            return i;

        i = i->next;
    }
}

int add_bunch() {

}

t_box *get_available_tbox(t_size len) {

}
//adds 100 tiny small to cur lst
int add_small_tiny(t_box **l) {

    int i = 0;
    int res = 0;
    //t_box* l = ft_create_elem(&i);
    while i < NB_ALLOCS * 2 {
        if (i <= NB_ALLOCS)
            res = ft_list_push_back(&l, TINY);
        else
            res = ft_list_push_back(&l, SMALL);
        ++i;
    }
    return res;
}

void add_large(t_box **l ,size_t len) {

    ft_list_push_back(&l, len);
}

void *realloc(void *ptr, size_t size);
//



int main() {




}

