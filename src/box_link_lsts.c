
#include <includes/malloc.h>
#include <sys/mman.h>
#include <unistd.h>

//in bytes
#define TINY_MIN 0
#define TINY_MAX (size_t)(getpagesize() * 1)
#define SMALL_MIN 9
#define SMALL_MAX 32
#define LARGE_MIN 33
#define NB_ALLOCS 1000

size_t mem_page_size = (size_t)getpagesize();

typedef struct      s_box {
    void            *madr;
    size_t          len;
    unsigned        available:1;
    struct s_box    *next;
}                   t_box;

typedef struct      s_alloc_manager {
    //if no room room , continue with last elen next ptr to linked list
    t_box tiny[NB_ALLOCS];
    t_box small[NB_ALLOCS];
    t_box used[NB_ALLOCS];

}                   t_alloc_manager;

t_alloc_manager   new_alloc_manager()
{
    t_alloc_manager x;
    size_t          i;

    i = 0;
    while (i < NB_ALLOCS)
    {
        x.tiny[i] = new_tbox();
        ++i;
    }
    i = 0;
    while (i < NB_ALLOCS)
    {
        x.small[i] = new_tbox();
        ++i;
    }
    i = 0;
    while (i < NB_ALLOCS)
    {
        x.used[i] = new_tbox();
        ++i;
    }

    return x;
}


t_box   new_tbox()
{
    t_box x;

    x.madr = NULL;
    x.len = 0;
    x.available = 1;
    x.next = NULL;
    return x;
}

t_box   init_tbox()
{
    t_box x;

    x.madr = NULL;
    x.len = 0;
    x.available = 1;
    x.next = NULL;
    return x;
}


void *ft_mmap(size_t length) {

    void *zone;

    zone = (t_box *)mmap(NULL, length, PROT_READ | PROT_EXEC | PROT_WRITE, MAP_SHARED, -1 ,0);
    if (zone == MAP_FAILED)//(void *) -1
        return NULL;
    return zone;
}


t_box *ft_create_elem() {

    t_box *elem;

    elem = (t_box *)ft_mmap(madr, sizeof(t_box), PROT_READ | PROT_EXEC | PROT_WRITE, MAP_SHARED, -1 ,0);
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


//
// Created by Tristan PONESSA on 8/31/20.
//

#include <includes/malloc.h>




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
