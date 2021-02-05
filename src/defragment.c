


void defragment_array_elem(t_box* pre_alloc_adr, t_box *user_mem_adr)
{
    size_t i;

    i = 0;
    while (user_mem_adr[i])
        ++i;

        user_mem_adr[i] = *pre_alloc_adr;

    }
}

/*
#go threw whole list
defragment_array(t_box* pre_alloc_arr, t_box *user_mem_arr)
{



}

defragment_linked_lst()
{


}
*/