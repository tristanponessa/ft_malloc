//
// Created by Tristan PONESSA on 8/31/20.
//

#ifndef MALLOC_MALLOC_H
#define MALLOC_MALLOC_H

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

#define TINY_HEAP_ALLOCATION_SIZE (4 * getpagesize())
#define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)
#define SMALL_HEAP_ALLOCATION_SIZE (16 * getpagesize())
#define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)

typedef struct s_heap {
    struct s_heap	*prev;
    struct s_heap	*next;
    t_heap_group	group;
    size_t		total_size;
    size_t		free_size;
    size_t		block_count;
} t_heap;

typedef struct s_block {
    struct s_block	*prev;
    struct s_block	*next;
    size_t		data_size;
    bool		freed;
} t_block;


#endif //MALLOC_MALLOC_H
