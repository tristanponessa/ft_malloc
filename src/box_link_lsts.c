//
// Created by Tristan PONESSA on 8/31/20.
//

#include <includes/malloc.h>

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
