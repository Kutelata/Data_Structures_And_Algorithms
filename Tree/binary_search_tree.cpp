#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree()
    {
        this->root = nullptr;
    }

    // create new node
    tNode *newNode(int data)
    {
        tNode *node = new tNode;
        if (node == NULL)
        { // cannot allocate memory
            exit(1);
        }
        else
        {
            node->data = data;
            node->pLeft = NULL;
            node->pRight = NULL;
        }
        return node;
    }

    // insert new Node into tree
    tNode *insertNode(tNode *node, int value)
    {
        if (node != NULL)
        {
            if (node->data == value)
            {
                return node;
            }
            else if (node->data > value)
            {
                node->pLeft = insertNode(node->pLeft, value);
            }
            else
            {
                node->pRight = insertNode(node->pRight, value);
            }
        }
        else
        {
            node = newNode(value);
        }
        return node;
    }

    void NLR(tNode *root)
    {
        if (root != NULL)
        {
            if (root != NULL)
            {
                cout << root->data << " ";
            }
            NLR(root->pLeft);
            NLR(root->pRight);
        }
    }

    tNode *searchNodeByRecursion(tNode *root, int x)
    {
        if (root != NULL)
        {
            if (root->data == x)
            {
                return root;
            }
            if (root->data > x)
            {
                return searchNodeByRecursion(root->pLeft, x);
            }
            else
            {
                return searchNodeByRecursion(root->pRight, x);
            }
        }
        return NULL;
    }

    tNode *searchNodeWithoutRecursion(tNode *root, int x)
    {
        tNode *p = root;
        while (p != NULL)
        {
            if (p->data == x)
            {
                return p;
            }
            else if (p->data > x)
            {
                p = p->pLeft;
            }
            else
            {
                p = p->pRight;
            }
        }
        return NULL;
    }

    tNode *minValueNode(tNode *node)
    {
        tNode *current = node;
        while (current && current->pLeft != NULL)
        {
            current = current->pLeft;
        }
        return current;
    }

    tNode *deleteNode(tNode *root, int x)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->data > x)
        {
            root->pLeft = deleteNode(root->pLeft, x);
        }
        else if (root->data < x)
        {
            root->pRight = deleteNode(root->pRight, x);
        }
        else
        {
            tNode *p = root;
            if (root->pLeft == NULL)
            {
                root = root->pRight;
                delete p;
            }
            else if (root->pRight == NULL)
            {
                root = root->pLeft;
                delete p;
            }
            else
            {
                tNode *temp = minValueNode(root->pRight);
                root->data = temp->data;
                root->pRight = deleteNode(root->pRight, temp->data);
            }
        }
        return root;
    }
};

int main()
{
    // create binary search tree
    createEmptyTree();
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 10);
    root = insertNode(root, 14);
    root = insertNode(root, 4);
    cout << "traverse tree with NLR:";
    NLR(root);
    tNode *temp = searchNodeWithoutRecursion(root, 10);
    if (temp != NULL)
    {
        cout << endl
             << "Found x=10";
    }
    else
    {
        cout << endl
             << "Cannot found x=10";
    }
    root = deleteNode(root, 3);
    cout << endl
         << "traverse tree with NLR after delete node:";
    NLR(root);
    system("pause");
}