#include <unistd.h>
#include <stdio.h>

int main()
{
    int mem_page_size = getpagesize();
    printf("%d", mem_page_size);
}