#include <vector>
#include "linkedlist.h"

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
        linkedlist travList;
        bst();
        Node* createNode(int val);
        Node* insertnode(int val, Node* node);
        std::vector<int> printlist(Node* node); 

        
};