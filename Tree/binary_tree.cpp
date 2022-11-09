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

    // void LNR(Node *root)
    // {
    //     if (root != NULL)
    //     {
    //         LNR(root->pLeft);
    //         if (root != NULL)
    //         {
    //             cout << root->data << " ";
    //         }
    //         LNR(root->pRight);
    //     }
    // }

    // void LRN(Node *root)
    // {
    //     if (root != NULL)
    //     {
    //         LRN(root->pLeft);
    //         LRN(root->pRight);
    //         if (root != NULL)
    //         {
    //             cout << root->data << " ";
    //         }
    //     }
    // }
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

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node5->left = node6;
    node5->right = node7;

    BinaryTree Btree = BinaryTree(root);

    Btree.NLR();

    // // traverse binary tree with NLR
    // cout << "traverse tree with NLR:";
    // NLR(root);
    // // traverse tree LNR
    // cout << "\ntraverse tree with LNR:";
    // LNR(root);
    // // traverse tree LRN
    // cout << "\ntraverse tree with LRN:";
    // LRN(root);
    // // insert new Node into tree
    // insertNode(node2, 9);
    // // traverse binary tree with NLR after insert new Node
    // cout << "\ntraverse tree with NLR:";
    // NLR(root);
    // system("pause");
}