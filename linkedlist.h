class linkedlist
{
    struct Node
    {
        int val;
        Node* next;
    };

    public:
        linkedlist();
        void insertnode_sorted(int val);
        void insertnode_unsorted(int val);
        void printlist();
        void deletenode(int val);
        void emptylist();
        int size;
        Node* head;
    private:
        //cursor node for traversing list, for operations such as insertion, deletion, printing, etc.
        Node* cursor; 
};