int main()
{
    NAdress root = NULL;
    karyawan x, y, z;
    x = createData("udin", 10);

    y.id = 20;
    y.name = "idin";

    z.id = 5;
    z.name = "edan";

    root = insert(root, x);
    insert(root, y);
    insert(root, z);

    printPreorder(root);
    printf("\nPreorder traversal of binary tree is \n");
    delete (root, 20);
    printPreorder(root);

    getchar();
    system("cls");
    return 0;
}
