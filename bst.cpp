#include <iostream>
#include <queue>
#include <vector>
#include "bst.h"

//TODO: MAKE SURE WE EMPTY TRAVQUEUE BEFORE USING AGAIN

bst::bst()
{
    root = nullptr;
}

Node* bst::createNode(int val)
{
    Node* newNode = new Node();
    newNode->val = val;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    return newNode;
}

Node* bst::insertnode(int val, Node* node)
{
    if (node == nullptr)
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

std::vector<int> printlist(Node* node)
{
    std::queue<Node*> travQueue;
    std::vector<int> result;

    travQueue.push(node);

    while (!travQueue.empty())
    {
        if (node->prev != nullptr)
        {
            travQueue.push(node->prev);
        }
        if (node->next != nullptr)
        {
            travQueue.push(node->next);
        }
        result.push_back(node->val);
        travQueue.pop();
        node = travQueue.front();
    }
}