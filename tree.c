#include <stdio.h>
#include <stdlib.h>
#include "bool.h"
#include "tree.h"

void createTree(Tree *t)
{
    t->root = NULL;
}

karyawan createData(char *s, int id)
{
    karyawan temp;
    temp.name = s;
    temp.id = id;
    return temp;
}

NAdress newNode(karyawan data)
{
    NAdress node = (NAdress)malloc(sizeof(treenode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

NAdress Getroot(Tree t)
{
    return t.root;
}

char *GetName(treenode *P)
{
    return P->data.name;
}

int GetId(treenode *P)
{
    return P->data.id;
}

void printPostorder(NAdress node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    printf("iD\t : %d\n", GetId(node));
    printf("Nama\t :%s\n", GetName(node));
}

void printInorder(NAdress node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    printf("iD\t : %d\n", GetId(node));
    printf("Nama\t :%s\n", GetName(node));

    /* now recur on right child */
    printInorder(node->right);
}

void printPreorder(NAdress node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    printf("iD\t : %d\n", GetId(node));
    printf("Nama\t :%s\n", GetName(node));

    /* then recur on left subtree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

NAdress searchelement(NAdress node, int id)
{
    if (node == NULL)
        return NULL;

    if (id == node->data.id)
    {
        return node;
    }
    NAdress result = searchelement(node->left, id);
    if (result)
        return result;
    return searchelement(node->right, id);
}

NAdress minvaluenode(NAdress node)
{
    NAdress current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

NAdress insert(NAdress node, karyawan data)
{

    if (node == NULL)
        return newNode(data);
    else if (node->data.id == data.id)
    {
        printf("ID yang dimasukan sudah ada\n");
        return node;
    }

    /* Otherwise, recur down the tree */
    if (data.id < node->data.id)
        node->left = insert(node->left, data);
    else if (data.id > node->data.id)
        node->right = insert(node->right, data);

    /* return the (unchanged) node pointer */
    return node;
}

NAdress delete (NAdress node, int id)
{
    if (node == NULL)
        return node;
    if (id < GetId(node))
        node->left = delete (node->left, id);
    else if (id > GetId(node))
        node->right = delete (node->right, id);
    else
    {
        if (node->left == NULL)
        {
            NAdress temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            NAdress temp = node->left;
            free(node);
            return temp;
        }
        NAdress temp = minvaluenode(node->right);
        node->data = temp->data;
        node->right = delete (node->right, GetId(temp));
    }
}

void SearchUtility(NAdress node, int id)
{
    if (searchelement(node, id) == NULL)
    {
        printf("\nData Tersebut tidak tidak tersedia\n");
    }
    else
    {
        printf("Alamat\t :%p\n", searchelement(node, id));
        printf("Nama\t :%s\n", searchelement(node, id)->data.name);
    }
}

void menu()
{
    printf("1.Masukan data ke dalam tree\n");
    printf("2.hapus data dalam tree\n");
    printf("3.Print tree\n");
    printf("4.Cari data di dalam tree\n");
}
