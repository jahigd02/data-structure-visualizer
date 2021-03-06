#include <iostream>
#include <queue>
#include <math.h>
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
        std::vector<int> bfs(Node* node);
        void printlist(Node* node);
        int treeheight(Node* node);
};

class treePrinter
{
    public:
        void tile();
        void node(int val);
        void empty();
        void brk();
};

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

int bst::treeheight(Node* node)
{
    if (node == nullptr)
    {
        return -1;   
    } 
    else
    {
        int leftTreeHeight = treeheight(node->prev);
        int rightTreeHeight = treeheight(node->next);

        return std::max(leftTreeHeight, rightTreeHeight) + 1;
    }
}

std::vector<int> bst::bfs(Node* node)
{
    std::queue<Node*> travQueue;
    std::vector<int> result;

    int h = treeheight(root) + 1;
   
    travQueue.push(node);

    /* while (!travQueue.empty()) */
    for (int i = 0; i < pow(2, h) - 1; i++)
    {   
        node = travQueue.front();
        if (node != nullptr)
        {
            if (node->prev != nullptr)
            {
                travQueue.push(node->prev);
            } else
            {
                travQueue.push(nullptr);
            }
            if (node->next != nullptr)
            {
                travQueue.push(node->next);
            } else
            {
                travQueue.push(nullptr);
            }
        } else
        {
            travQueue.push(nullptr);
            travQueue.push(nullptr);
        }
        if (node != nullptr)
        {
            result.push_back(node->val);
        } else
        {
            result.push_back(-1);
        }
        travQueue.pop();
    }
    return result;
}

void bst::printlist(Node* node)
{   
    std::vector<int> result = bfs(root);
    int level = 0;
    for (int i = 0; i < result.size(); i++)
    {
        if (i+1 == pow(2, level))
        {
            std::cout<<"\n";
            level++;
        }
        std::cout << result[i] << " ";
    }
    std::cout << "\n\n";
}