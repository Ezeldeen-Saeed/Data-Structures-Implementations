#include <iostream>
#include "BinaryTree.cpp"

using namespace std;

int main() {
    BinaryTree<int> tree;
    tree.insert(2);
    tree.insert(4);
    tree.insert(5);
    tree.insert(7);
    tree.insert(1);
    tree.insert(9);



    tree.levelOrder();
    cout << "Last node: " << tree.findLastNode(tree.getRoot()) << endl;
    cout << "Height of tree: " << tree.height() << endl;
    cout << "2 Node: " << tree.find(2) << endl;
    cout << "Parent node: " << tree.findParent(tree.getRoot(), 4) << endl;

    tree.deleteNode(4);

    tree.levelOrder();


    return 0;
}
