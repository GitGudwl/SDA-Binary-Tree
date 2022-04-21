#include "tree.h"
#include "tree.c"
#include <stdlib.h>

int main()
{
    Tree tree;
    createTree(&tree);

    tree.root = insert(tree.root, createData("Dhika Putra", 45));
    insert(tree.root, createData("Dhika Putra", 45));
    insert(tree.root, createData("Chandra Diva", 87));
    insert(tree.root, createData("Abdullah Anugrah", 65));
    insert(tree.root, createData("Bayu Virani", 39));
    insert(tree.root, createData("Chaerul Ardina", 92));
    insert(tree.root, createData("Abdullah Anugrah", 65));




    printPreorder(tree.root);
    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(tree.root);
    printf("Alamat\t :%p\n", searchelement(tree.root, 50));
    printf("Nama\t :%s\n", searchelement(tree.root, 50)->data.name);

    getchar();
    system("cls");
    return 0;
}
