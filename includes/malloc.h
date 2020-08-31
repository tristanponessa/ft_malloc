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

t_box *l; //global


#endif //MALLOC_MALLOC_H
