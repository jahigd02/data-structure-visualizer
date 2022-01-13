#include <iostream>
#include <string>

struct Node
{
    int val;
    Node* next;
};

class linkedlist
{
    public:
        linkedlist();
        void insertnode(int val);
        void printlist();
        void deletenode(int val);
    private:
        Node* head;
        //cursor node for traversing list, for operations such as insertion, deletion, printing, etc.
        Node* cursor; 
};

linkedlist::linkedlist()
{
    head = NULL;
    cursor = head;
}

void linkedlist::insertnode(int val)
{
    //create a new Node and initialize its value to be the value passed to the insertnode function.
    Node* newNode = new Node();
    newNode->val = val;

    cursor = head;

    //edge case: list is empty. thus, set head node to point to the new node, and set new node's next to be NULL.
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    } 
    //edge case: desired number to insert is less than current node, and the list has one member. so, we'll just set newNode->next to the cursor's pointed-to
    //node, and set the head to point to the newNode.
    else if(val <= cursor->val)
    {
        newNode->next = cursor;
        head = newNode;
    }
    //most general case for insertion: the desired value is larger than the current value pointed to by the cursor. the first if statement 
    //covers the special case where the list has one member, and thus we set head->next to be the newNode (and don't have to re-assign the head node.) 
    //in most cases though, the while loop will iterate through the list, stopping when the next cursor->val is greater. Then, we carefully assign a temporary
    //pointer to a node to be cursor->next, let the current cursor->next point to newNode, and let newNode->next point to that (what would have been overwritten
    //if not for our temporary node) cursor->next. This process can be imagined as "wedging a node between two existing nodes."
    else if (val > cursor->val)
    {
        if (head->next == NULL)
        {
            head->next = newNode;
        } 
        else
        {
            while (cursor->next != NULL && val > cursor->next->val)
            {
                cursor = cursor->next;
            }
            Node* temp = new Node();
            temp = cursor->next;
            cursor->next = newNode;                 
            newNode->next = temp;
        }
        
    }
}

void linkedlist::deletenode(int val)
{
    cursor = head;
    //edge case: list is empty. do nothing (but tell user "list is empty; nothing to delete.").
    if (head == NULL)
    {
        std::cout << "List is empty; nothing to delete.\n";
        return;
    }
    //edge case: list has one member. delete that member, and set head to NULL.
    else if (head->next == NULL)
    {
        if (head->val == val)
        {
            delete(cursor);
            std::cout << "[" << val << "] removed from list successfully.\n";
            head = NULL;
            return;
        }
    } 
    else if (head->val == val)
    {
        Node* temp = head->next;
        delete(head);
        head = temp;
        std::cout << "[" << val << "] removed from list successfully.\n";
        return;
    }
    else
    {
        while (cursor->next->val != val && cursor->next->next != NULL)
        {
            cursor = cursor->next;
        }
        if (cursor->next->val == val)
        {
            if (cursor->next->next != NULL)
            {
                Node* temp = cursor->next->next;
                delete(cursor->next);
                cursor->next = temp;
            } else if (cursor->next->next == NULL)
            {
                delete(cursor->next);
                cursor->next = NULL;
            }
            std::cout << "[" << val << "] removed from list successfully.\n";
            return;
        }
    }
    std::cout << "[" << val << "] not in list.\n";
    return;
}

void linkedlist::printlist()
{
    cursor = head;
    //edge case: list is empty. print result that "list is empty."
    if (head == NULL)
    {
        std::cout << "List is empty.\n";
    } else
    {
        while (cursor != NULL)
        {
            std::cout << "[" << cursor->val << "]";
            if (cursor->next != NULL)
            {
                std::cout << "->";
            }
            cursor = cursor->next;
        }
        std::cout << "\n";
    }
}

