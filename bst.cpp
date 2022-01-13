#include <iostream>

class bst
{
    struct Node
    {
        int val;
        Node* prev;
        Node* next;
    };

    public:
        bst();
        Node* insertnode(int val, Node* node);
        Node* createNode(int val);
        Node* root;
        
};

bst::bst()
{
    root = NULL;
}

bst::Node* bst::createNode(int val)
{
    Node* newNode = new Node();
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

bst::Node* bst::insertnode(int val, bst::Node* node)
{
    if (node == NULL)
    {
        return createNode(val);
    } 
    if (val > node->val)
    {
        node->next = insertnode(val, node->next);
    } 
    else
    {
        node->prev = insertnode(val, node->prev);
    }

    return node;
}
