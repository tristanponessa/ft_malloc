#include <stdio.h>
#include <ctype.h>

void  print_group(const char *conversion, const char *mem_zone, const char* default_, size_t from_pos, size_t max_len)
{
    size_t i;

    i = 0;
    while (i < 16)
    {
        if (from_pos < max_len && isprint(mem_zone[from_pos]))
            printf(conversion, mem_zone[from_pos]);
        else
            printf("%s ", default_);
        ++i;
        ++from_pos;
    }
}

void print_hexdump(const char *mem_zone, const size_t len)
{
    size_t i;

    i = 0;
    while (i < len)
    {
        printf("%04zx  ", i); /* mem group */
        print_group("%02x " ,mem_zone,"XX" ,i , len); /* hex group */
        printf("  ");
        print_group("%c " ,mem_zone,"." ,i , len); /* ascii group */
        printf("\n");
        i += 16;
    }
}



void stackoverflow_hexDump (const char * desc, const void * addr, const int len) {
    int i;
    char buff[17];
    const char * pc = (const char *)addr;

    // Output description if given.
    // Process every byte in the data.

    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).

        if ((i % 16) == 0) {
            // Don't print ASCII buffer for the "zeroth" line.
            if (i != 0)
                printf ("  %s\n", buff);
            // Output the offset.
            printf ("  %04x ", i);
        }

        // Now the hex code for the specific character.
        printf (" %02x", pc[i]);
        // And buffer a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e)) // isprint() may be better.
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }
    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        printf ("   ");
        i++;
    }
    // And print the final ASCII buffer.
    printf ("  %s\n", buff);
}

int main()
{
    char *str = "my name is Natsirt!";


    //DumpHex(&str[0], sizeof(str));

    char my_str[] = "a char string greater than 16 chars";
    stackoverflow_hexDump ("my_str", &my_str, sizeof (my_str));
    printf("\n");
    print_hexdump(&my_str[0], sizeof(my_str));
    return 0;
}