#ifndef tree_H
#define tree_H
#include "bool.h"

typedef struct data
{
    int id;
    char *name;
} karyawan;

typedef struct node *NAdress;

typedef struct node
{
    karyawan data;
    NAdress left;
    NAdress right;
} treenode;

typedef struct
{
    NAdress root;
} Tree;

void createTree(Tree *t);

karyawan createData(char *s, int id);

NAdress newNode(karyawan data);

NAdress Getroot(Tree t);

char *GetName(treenode *P);

int GetId(treenode *P);

void printPostorder(NAdress node);

void printInorder(NAdress node);

void printPreorder(NAdress node);

NAdress searchelement(NAdress node, int id);

NAdress minvaluenode(NAdress node);

NAdress insert(NAdress node, karyawan data);

NAdress delete (NAdress node, int id);

boolean notdone();

#endif