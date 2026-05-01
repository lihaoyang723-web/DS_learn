#include <iostream>

#include "binarytree.h"

int main()
{
    using Tree = binaryTree<char>;

    Tree tree;

    std::cout << "binaryTree interactive test\n";
    std::cout << "Use '#' to represent an empty node when building the tree.\n";

    char flag = '#';
    bool running = true;

    while (running)
    {
        std::cout << "\nMenu:\n"
                  << "1. create tree\n"
                  << "2. show root\n"
                  << "3. preorder\n"
                  << "4. midorder\n"
                  << "5. postorder\n"
                  << "6. levelorder\n"
                  << "7. query left child\n"
                  << "8. query right child\n"
                  << "9. delete left subtree\n"
                  << "10. delete right subtree\n"
                  << "11. clear tree\n"
                  << "12. is empty\n"
                  << "0. exit\n"
                  << "choose: ";

        int choice = -1;
        if (!(std::cin >> choice))
        {
            break;
        }

        char x = 0;
        switch (choice)
        {
            case 1:
                tree.createTree(flag);
                break;
            case 2:
                std::cout << "root = " << tree.root(flag) << '\n';
                break;
            case 3:
                tree.preorder();
                std::cout << '\n';
                break;
            case 4:
                tree.midorder();
                std::cout << '\n';
                break;
            case 5:
                tree.postorder();
                std::cout << '\n';
                break;
            case 6:
                tree.levelorder();
                std::cout << '\n';
                break;
            case 7:
                std::cout << "node: ";
                std::cin >> x;
                std::cout << "left child = " << tree.lchild(x, flag) << '\n';
                break;
            case 8:
                std::cout << "node: ";
                std::cin >> x;
                std::cout << "right child = " << tree.rchild(x, flag) << '\n';
                break;
            case 9:
                std::cout << "delete left subtree of: ";
                std::cin >> x;
                tree.deleft(x);
                break;
            case 10:
                std::cout << "delete right subtree of: ";
                std::cin >> x;
                tree.deright(x);
                break;
            case 11:
                tree.clear();
                std::cout << "tree cleared\n";
                break;
            case 12:
                std::cout << (tree.isempty() ? "true\n" : "false\n");
                break;
            case 0:
                running = false;
                break;
            default:
                std::cout << "invalid choice\n";
                break;
        }
    }

    return 0;
}