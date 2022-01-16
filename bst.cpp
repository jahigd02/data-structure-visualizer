#include <iostream>
#include <queue>
#include <vector>

struct Node
    {
        int val;
        Node* prev;
        Node* next;
    };

class bst
{
    public:
        Node* root;
        bst();
        Node* createNode(int val);
        Node* insertnode(int val, Node* node);
        void printlist(Node* node);
};

bst::bst()
{
    root = NULL;
}

Node* bst::createNode(int val)
{
    Node* newNode = new Node();
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

Node* bst::insertnode(int val, Node* node)
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

void bst::printlist(Node* node)
{
    std::queue<Node*> travQueue;
    std::vector<int> result;

    travQueue.push(node);

    while (!travQueue.empty())
    {
        result.push_back(node->val);
        if (node->prev != NULL)
        {
            travQueue.push(node->prev);
        } else if (node->prev == NULL)
        {
            result.push_back(-1);
        }
        if (node->next != NULL)
        {
            travQueue.push(node->next);
        } else if (node->next == NULL)
        {
            result.push_back(-1);
        }
        travQueue.pop();
        node = travQueue.front();
    }

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
}