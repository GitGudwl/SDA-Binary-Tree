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
    insert(tree.root, createData("Fikri Syabantika", 88));
    insert(tree.root, createData("Christa Dayanti", 73));
    insert(tree.root, createData("Haris Anjani", 58));
    insert(tree.root, createData("Aprian Amalina", 47));
    insert(tree.root, createData("Doni Assodiqin", 62));
    insert(tree.root, createData("Marvel Tilanusari", 59));
    insert(tree.root, createData("Hilman Ardiansyah", 64));
    insert(tree.root, createData("Izhar Subekti", 11));
    insert(tree.root, createData("Mustofah Sabri", 41));

    
    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(tree.root);
    printPreorder(tree.root);
    SearchUtility(tree.root, 41);

    getchar();
    system("cls");
    return 0;
}
