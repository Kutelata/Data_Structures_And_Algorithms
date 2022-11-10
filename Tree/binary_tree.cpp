#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree(Node *root)
    {
        this->root = root;
    }

    void InsertNode(Node *nodeInTree, int value)
    {
        Node *newNode = new Node(value);
        if (nodeInTree->left == nullptr)
        {
            nodeInTree->left = newNode;
        }
        else if (nodeInTree->right == nullptr)
        {
            nodeInTree->right = newNode;
        }
        else
        {
            newNode->left = nodeInTree->left;
            nodeInTree->left = newNode;
        }
    }

    void InsertNewRoot(int value)
    {
        Node *newNode = new Node(value);
        newNode->left = this->root;
        this->root = newNode;
    }

    void NLR()
    {
        Node *newNode = this->root;
        if (newNode != nullptr)
        {
            if (newNode != nullptr)
            {
                cout << newNode->data << " ";
            }
            this->root = newNode->left;
            NLR();
            this->root = newNode->right;
            NLR();
        }
    }

    void LNR()
    {
        Node *newNode = this->root;
        if (newNode != nullptr)
        {
            this->root = newNode->left;
            LNR();
            if (newNode != nullptr)
            {
                cout << newNode->data << " ";
            }
            this->root = newNode->right;
            LNR();
        }
    }

    void LRN()
    {
        Node *newNode = this->root;
        if (newNode != nullptr)
        {
            this->root = newNode->left;
            LRN();
            this->root = newNode->right;
            LRN();
            if (newNode != nullptr)
            {
                cout << newNode->data << " ";
            }
        }
    }
};

int main()
{
    Node *root = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    BinaryTree Btree = BinaryTree(root);

    Btree.InsertNewRoot(12);
    Btree.InsertNode(node7, 13);
    Btree.NLR();
}