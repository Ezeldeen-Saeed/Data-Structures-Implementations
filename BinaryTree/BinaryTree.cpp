#include <queue>
using namespace std;

template <typename Tdata>
class TreeNode {
public:
    Tdata data;
    TreeNode<Tdata>* left;
    TreeNode<Tdata>* right;

    TreeNode(Tdata _data) {
        this->data = _data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename Tdata>
class BinaryTree {
private:
    TreeNode<Tdata>* root;

public:
    BinaryTree() { root = nullptr; }

    ~BinaryTree() { clear(root); }

    void insert(Tdata _data) {
        TreeNode<Tdata>* newNode = new TreeNode<Tdata>(_data);
        if (root == nullptr) {
            root = newNode;
            cout << "Inserted root: " << newNode->data << endl;
            return;
        }

        queue<TreeNode<Tdata>*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode<Tdata>* currentNode = q.front();
            q.pop();

            // Check left child
            if (currentNode->left == nullptr) {
                currentNode->left = newNode;
                cout << "Inserted " << newNode->data << " to the left of " << currentNode->data << endl;
                return;
            } else {
                q.push(currentNode->left);
            }

            // Check right child
            if (currentNode->right == nullptr) {
                currentNode->right = newNode;
                cout << "Inserted " << newNode->data << " to the right of " << currentNode->data << endl;
                return;
            } else {
                q.push(currentNode->right);
            }
        }
    }

    void levelOrder() {
        if (root == nullptr) {
            cout << "The tree is empty." << endl;
            return;
        }

        queue<TreeNode<Tdata>*> q;
        q.push(root);

        cout << "Tree elements (level-order): ";
        while (!q.empty()) {
            TreeNode<Tdata>* currentNode = q.front();
            q.pop();
            cout << currentNode->data << " ";

            if (currentNode->left != nullptr)
                q.push(currentNode->left);
            if (currentNode->right != nullptr)
                q.push(currentNode->right);
        }
        cout << endl;
    }

    int height() {
        return internalHeight(this->root);
    }

    int internalHeight(TreeNode<Tdata> *node) {
        if (node == nullptr) return 0;
        return 1 + max(internalHeight(node->left), internalHeight(node->right));
    }

    void preOrder() {
        internalPreOrder(this->root);
        cout << endl;
    }

    void internalPreOrder(TreeNode<Tdata> *node) {
        if (node == nullptr) return;
        cout << node->data << " -> ";
        internalPreOrder(node->left);
        internalPreOrder(node->right);
    }

    TreeNode<Tdata>* getRoot() {
        return this->root;
    }

    TreeNode<Tdata>* findLastNode(TreeNode<Tdata> *node) {
        if (height() == 1) {
            delete[] node;
            return nullptr;
        }  
        if (node->right == nullptr) {
            return node;
        } else {
            node = node->right;
            return findLastNode(node);
        } 
    }

    TreeNode<Tdata>* find(Tdata data) {
        return internalFind(this->root, data);
    }

    TreeNode<Tdata>* internalFind(TreeNode<Tdata>* currentNode, Tdata data) {
        if (currentNode == nullptr) {
            return nullptr;
        }

        if (currentNode->data == data) {
            return currentNode;
        }

        TreeNode<Tdata>* leftResult = internalFind(currentNode->left, data);
        if (leftResult != nullptr) {
            return leftResult;
        }

        return internalFind(currentNode->right, data);
    }

    TreeNode<Tdata>* findParent(TreeNode<Tdata>* currentNode, Tdata data) {
        if (currentNode == nullptr) {
            return nullptr;
        }

        if ((currentNode->left != nullptr && currentNode->left->data == data) || (currentNode->right != nullptr && currentNode->right->data == data)) {
            return currentNode;
        }

        TreeNode<Tdata>* leftResult = findParent(currentNode->left, data);
        if (leftResult != nullptr) {
            return leftResult;
        }
        
        return findParent(currentNode->right, data);
    }


    // Without clear method.
/*    void deleteNode(Tdata data) {

        TreeNode<Tdata> *currentNode = find(data);
        if (currentNode == nullptr) { cout << "Node not found." << endl; }
        TreeNode<Tdata> *lastNode = findLastNode(this->root);
        TreeNode<Tdata> *parentLastNode = findParent(this->root, lastNode->data);

        if (currentNode == this->root && currentNode == lastNode) {
            delete root;
            root = nullptr;
            return;
        }

        currentNode->data = lastNode->data;

        if (parentLastNode != nullptr) {
            if (parentLastNode->left == lastNode) {
                parentLastNode->left = nullptr;
            } else if (parentLastNode->right == lastNode) {
                parentLastNode->right = nullptr;
            }
        } 

        delete lastNode;
    } */

    // Using clear method.
    void deleteNode(Tdata data) {
        TreeNode<Tdata>* currentNode = find(data);
        if (currentNode == nullptr) {
            cout << "Node not found." << endl;
            return;
        }

        if (currentNode == root && root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
            return;
        }

        TreeNode<Tdata>* lastNode = findLastNode(root);
        TreeNode<Tdata>* parentLastNode = findParent(root, lastNode->data);

        currentNode->data = lastNode->data;

        if (parentLastNode != nullptr) {
            if (parentLastNode->left == lastNode) {
                parentLastNode->left = nullptr;
            } else if (parentLastNode->right == lastNode) {
                parentLastNode->right = nullptr;
            }
        } else {
            root = nullptr;
        }

        clear(lastNode);
    }


private:
    void clear(TreeNode<Tdata>* node) {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }
};
