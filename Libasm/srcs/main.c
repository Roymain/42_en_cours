#include <stdlib.h>
#include <stdio.h>

typedef struct    s_list
{
    void*            data;
    struct s_list*    next;
}                t_list;

void    ft_list_push_front(t_list **begin_list, void *data);
int        ft_list_size(t_list *begin_list);
void    ft_list_sort(t_list **begin_list, int (*cmp)());
void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

int        ft_atoi_base(char *str, char *base);

int cmp (void *c1, void* c2) {
    if (*(char*)c1 == *(char*)c2)
        return 0;
    return 1;
}

void del(void *c) {
    *(char*)c = '0';
}

int main()
{
    char c1 = 'a';
    char c2 = 'b';
    char c3 = 'c';
    char c4 = 'd';
    char c5 = 'e';
    char c6 = 'j';
    printf("%c %c %c %c %c\n", c1, c2, c3, c4, c5);
    t_list*    lst = NULL;
    ft_list_push_front(&lst, &c5);
    ft_list_push_front(&lst, &c4);
    ft_list_push_front(&lst, &c3);
    ft_list_push_front(&lst, &c2);
    ft_list_push_front(&lst, &c1);
    //ft_list_remove_if(&lst, &c5, &cmp, &del);
    //				ft_list_remove_if(&lst, &c6, &cmp, &del);
    //ft_list_remove_if(&lst, &c1, &cmp, &del);
    ft_list_remove_if(&lst, &c2, &cmp, &del);
    //ft_list_remove_if(&lst, &c3, &cmp, &del);
    //ft_list_remove_if(&lst, &c4, &cmp, &del);
    printf("%c %c %c %c %c\n", c1, c2, c3, c4, c5);
    t_list*    test = lst;
	while (test){
		dprintf(2, "%c ", *(char*)test->data);
		test = test->next;
	}
	dprintf(2, "\n");
    return 0;
}
