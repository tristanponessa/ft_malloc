//
// Created by Tristan PONESSA on 8/31/20.
//

#include <includes/malloc.h>

typedef struct      s_box {
    void            *madr;
    size_t          len;
    int             available;
    struct s_box    *next;
}                   t_box;



void                show_alloc_ex_mem() {

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

    fprintf(STDERR, msg);
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

//void *realloc(void *ptr, size_t size);
