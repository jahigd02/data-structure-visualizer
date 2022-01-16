#include <iostream>
#include <string>

#include "linkedlist.cpp"
#include "bst.cpp"

//TODO:
//CONSIDER -- DO WE WANT DATA STRUCTURES TO SAVE WHEN WE RETURN TO MAIN MENU?                           -- DONE
    //IF NOT, RIGHT A PSEUDO-DESTRUCTOR FOR EACH DATA STRUCTURE (CALLED UPON RETURN TO MAIN_MENU)       -- DONE
    //NEEDS TO FREE (delete()) ALL POINTERS, SO WE NEED TO KEEP UP A LIST OF ALL THE POINTERS           -- DONE
//WRITE EXIT PROGRAM FUNCTIONALITY
//FINISH BST IMPLEMENTATION
    //WRITE LINKED LIST INITIALIZATION -- AKA, WE NEED A WAY TO DELETE THE WHOLE THING!
        //WRITE DELETION (WE NEED POST ORDER)
        //WRITE BALANCE FUNCTIONALITY?
        //WRITE GETHEIGHT FUNCTION
//POSSIBLY UPGRADE OR ADD DOUBLY LINKED + CIRCULAR FUNCTIONALITY TO LINKED LIST
//IMPLEMENT STACK
//IMPLEMENT QUEUE
//IMPLEMENT HASH TABLE
//IMPLEMENT PRIORITY QUEUE

void main_menu();
void linkedlist_menu();
void bst_menu();
void linkedlist_insertnode_sorted_shell(int val);
void linkedlist_insertnode_unsorted_shell(int val);
void linkedlist_deletenode_shell(int val);
void linkedlist_printlist_shell();
void linkedlist_emptylist_shell();
void linkedlist_initialization();

linkedlist myList;
bst myBst;

int main(int argc, char* argv[])
{
    std::cout<<"debug";
    main_menu();
}

void main_menu()
{
    int dataStructureChoice = 0;
    std::cout << "Select a data structure to operate:\n1.Linked List\n2.Binary Search Tree\n"; 
    std::cin >> dataStructureChoice;
    std::cout << "\n";

    switch(dataStructureChoice)
    {
        case 1:
            linkedlist_initialization();
            linkedlist_menu();
            break;
        case 2:
            bst_menu();
            break;
        default:
            main_menu();
    }
}

void linkedlist_menu()
{   
    int linkedListOperationChoice = 0;
    std::cout << "Select operation:\n1.Add Item (Sorted)\n2.Add Item (Unsorted, to end of List)\n3.Delete Item\n4.Print List\n9.Return to Data Structure Select\n";
    std::cin >> linkedListOperationChoice;
    std::cout << "\n";

    switch(linkedListOperationChoice)
    {
        int item; 
        case 1:
            std::cout << "Item to add:\n"; 
            std::cin >> item;
            linkedlist_insertnode_sorted_shell(item);
            std::cout << "\n";
            break;
        case 2:
            std::cout << "Item to add:\n";
            std::cin >> item;
            linkedlist_insertnode_unsorted_shell(item);
            std::cout << "\n";
            break;
        case 3:
            std::cout << "Item to delete:\n";
            std::cin >> item; std::cout << "\n";
            linkedlist_deletenode_shell(item);
            std::cout << "\n";
            break;
        case 4:
            linkedlist_printlist_shell();
            std::cout << "\n";
            break;
        case 9:
            linkedlist_emptylist_shell();
            main_menu();
            break;
        deafult:
            break;
    }

    linkedlist_menu();
}

void bst_menu()
{
    std::cout << "Select operation:\n1.Add Item\n2.Print List\n";
    int bstMenuChoice = 0;
    std::cin >> bstMenuChoice;

    int item = 0;

    switch(bstMenuChoice)
    {
        case 1:
            std::cout << "Item to add:\n";
            std::cin >> item;
            myBst.root = myBst.insertnode(item, myBst.root);
            break;
            
        case 2:
            myBst.printlist(myBst.root);
            //std::cout << myBst.treeheight(myBst.root);
            break;
    }
    bst_menu();
}

void linkedlist_initialization()
{
    myList.head = nullptr;
    myList.size = 0;
}

void linkedlist_insertnode_sorted_shell(int val)
{
    myList.insertnode_sorted(val);
}

void linkedlist_insertnode_unsorted_shell(int val)
{
    myList.insertnode_unsorted(val);
}

void linkedlist_deletenode_shell(int val)
{
    myList.deletenode(val);
}

void linkedlist_printlist_shell()
{
    myList.printlist();
}

void linkedlist_emptylist_shell()
{
    myList.emptylist();
}
