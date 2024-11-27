#include <queue>
using namespace std;

template <typename Tdata>
class TreeNode {
public:
    Tdata data;
    TreeNode<Tdata>* left;
    TreeNode<Tdata>* right;
    int counter;

    TreeNode(Tdata _data) {
        this->data = _data;
        this->left = nullptr;
        this->right = nullptr;
        this->counter = 1;
    }
};

template <typename T> class NodeAndParent {
public:
    TreeNode<T> *node;
    TreeNode<T> *parent;
    bool isLeft;
};

template <typename Tdata>
class BinaryTree {
private:
    TreeNode<Tdata>* root;

public:
    BinaryTree() { root = nullptr; }

    ~BinaryTree() { clear(root); }

    void BSInsert(Tdata _data) {
        // If you want to no allowing duplication.
        //if (this->find(_data)) return;

        if (this->find(_data)) {
            this->find(_data)->counter++;
            cout << endl << "Adding " << _data << " for " << find(_data)->counter << " times." << endl;
            return;
        }

        TreeNode<Tdata>* newNode = new TreeNode<Tdata>(_data);
        if (root == nullptr) {
            root = newNode;
            cout << "Inserted root: " << newNode->data << endl;
            return;
        }
        TreeNode<Tdata>* currentNode = this->root;

        while (currentNode != nullptr) {
            if (_data < currentNode->data) {
                if (currentNode->left == nullptr) {
                    currentNode->left = newNode; 
                    break;
                } else {
                    currentNode = currentNode->left;
                }
            } else {
                if (currentNode->right == nullptr) {
                    currentNode->right = newNode;
                    break;
                } else {
                    currentNode = currentNode->right;
                }
            }
        }
    }


    void balance() {
        vector<Tdata> nodes;
        inOrderToArray(this->root, nodes);
        this->root = recursiveBalance(0, nodes.size() - 1, nodes);
    }

    void inOrderToArray(TreeNode<Tdata> *node, vector<Tdata> &nodes) {
        if (node == nullptr)
          return;
        inOrderToArray(node->left, nodes);
        nodes.push_back(node->data);
        inOrderToArray(node->right, nodes);
    }

    TreeNode<Tdata> *recursiveBalance(int start, int end, vector<Tdata> &nodes) {
        if (start > end)
          return nullptr;
        int mid = (start + end) / 2;
        TreeNode<Tdata> *newNode = new TreeNode(nodes[mid]);
        newNode->left = recursiveBalance(start, mid - 1, nodes);
        newNode->right = recursiveBalance(mid + 1, end, nodes);
        return newNode;
    }

    bool isExist(Tdata _data) {
        return (BSFind(_data) == nullptr);
    }

    void BSDelete(Tdata _data) {
        NodeAndParent<Tdata> *nodeAndParentInfo = this->findNodeAndParent(_data);
        if (nodeAndParentInfo->node == nullptr) return;

        if (nodeAndParentInfo->node->left != nullptr && nodeAndParentInfo->node->right != nullptr) {
            BSDelete_has_childs(nodeAndParentInfo->node);
        } else if (nodeAndParentInfo->node->left != nullptr ^ nodeAndParentInfo->node->right != nullptr) {
            BSDelete_has_child(nodeAndParentInfo->node);
        } else if (nodeAndParentInfo->node->left == nullptr && nodeAndParentInfo->node->right == nullptr) {
            BSDelete_leaf(nodeAndParentInfo);
        } else {
            cout << "Something worng!!";
            return;
        }
    }

    void BSDelete_has_childs(TreeNode<Tdata> *nodeToDelete) {
        TreeNode<Tdata> *currentNode = nodeToDelete->right;
        TreeNode<Tdata> *parent = nullptr;

        while (currentNode->left != nullptr) {
            parent = currentNode;
            currentNode = currentNode->left;
        }

        if (parent == nullptr) {
            nodeToDelete->right = currentNode->right;
        } else {
            nodeToDelete->right = currentNode->right;
        }

        nodeToDelete->data = currentNode->data;
        delete currentNode;
    }

    void BSDelete_has_child(TreeNode<Tdata> *nodeToDelete) {
        TreeNode<Tdata> *nodeToReplace;
        nodeToDelete->left != nullptr ? nodeToReplace = nodeToDelete->left : nodeToReplace = nodeToDelete->right;

        nodeToDelete->left = nodeToReplace->left;
        nodeToDelete->right = nodeToReplace->right;
        nodeToDelete->data = nodeToReplace->data;

        delete nodeToReplace;
    }

    void BSDelete_leaf(NodeAndParent<Tdata> *nodeAndParentInfo) {
        if (nodeAndParentInfo->parent == nullptr) {
            delete this->root;
        } else {
            if (nodeAndParentInfo->isLeft) {
                nodeAndParentInfo->parent->left = nullptr;
            } else {
                nodeAndParentInfo->parent->right = nullptr;
            }
        }
        delete nodeAndParentInfo->node;
    }

    NodeAndParent<Tdata> *findNodeAndParent(Tdata _data) {
        TreeNode<Tdata> *currentNode = this->root;
        TreeNode<Tdata> *parent = nullptr;
        NodeAndParent<Tdata> *nodeAndParentInfo = nullptr;
        bool left = false;
        while (currentNode != nullptr) {
          if (currentNode->data == _data) {
            nodeAndParentInfo = new NodeAndParent<Tdata>();
            nodeAndParentInfo->node = currentNode;
            nodeAndParentInfo->parent = parent;
            nodeAndParentInfo->isLeft = left;
            break;
          } else if (currentNode->data > _data) {
            parent = currentNode;
            left = true;
            currentNode = currentNode->left;
          } else {
            parent = currentNode;
            left = false;
            currentNode = currentNode->right;
          }
        }
        return nodeAndParentInfo;
    }

    TreeNode<Tdata>* BSFind(Tdata _data) {
        TreeNode<Tdata>* currentNode = this->root;
        while (currentNode != nullptr) {
            if (currentNode->data == _data) {
                return currentNode;
            } else if (currentNode->data < _data) {
                currentNode = currentNode->left;
            } else if (currentNode->data > _data) {
                currentNode = currentNode->right;
            }
        }
        return nullptr;
    }

    void insert(Tdata _data) {
        if (this->find(_data)) return;
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
