#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, char const *argv[])
{
    int p[][2] = {{6,6}, {5,5}, {4,4}, {3,3}, {2,2}, {1,1}, {0,0}};
    node_st *head = create_list();
    int rows = sizeof(p) / sizeof(p[0]); // 计算行数
    for (int i = 0; i < rows; i++)
    {
        add_node(head, p[i][0], p[i][1]);
    }
    print_list(head);
    free_list(head);

    return 0;
}
