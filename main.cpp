#include <iostream>
#include <string>
#include "linkedlist.cpp"
#include "bst.cpp"

//TODO:
//WRITE FUNTION TO FREE LINKED LIST MEMORY UPON RETURNING TO MAIN MENU OR EXIT
//WRITE EXIT PROGRAM FUNCTIONALITY
//FINISH BST IMPLEMENTATION
//POSSIBLY UPGRADE OR ADD DOUBLY LINKED + CIRCULAR FUNCTIONALITY TO LINKED LIST
//IMPLEMENT STACK
//IMPLEMENT QUEUE
//IMPLEMENT HASH TABLE
//IMPLEMENT TRIE(?)
//IMPLEMENT PRIORITY QUEUE

void linkedlist_menu();
void linkedlist_insertnode_shell(int val);
void linkedlist_deletenode_shell(int val);
void linkedlist_printlist_shell();

linkedlist myList;
bst myBst;


int main(int argc, char* argv[])
{
    linkedlist_menu();

}

int main_menu()
{

}

void linkedlist_menu()
{
    int choice = 0;
    std::cout << "Select operation:\n1.Add Item\n2.Delete Item\n3.Print List\n9.Return to Data Structure Select\n";
    std::cin >> choice;
    std::cout << "\n";

    switch(choice)
    {
        int item; 
        case 1:
            std::cout << "Item to add:\n"; 
            std::cin >> item;
            linkedlist_insertnode_shell(item);
            std::cout << "\n";
            break;
        case 2:
            std::cout << "Item to delete:\n";
            std::cin >> item; std::cout << "\n";
            linkedlist_deletenode_shell(item);
            std::cout << "\n";
            break;
        case 3:
            linkedlist_printlist_shell();
            std::cout << "\n";
            break;
        case 9:
            main(); //replace this with the main menu function when it's completed.
	    break;
        deafult:
            linkedlist_printlist_shell();
    }

    linkedlist_menu();
}

void linkedlist_insertnode_shell(int val)
{
    myList.insertnode(val);
}

void linkedlist_deletenode_shell(int val)
{
    myList.deletenode(val);
}

void linkedlist_printlist_shell()
{
    myList.printlist();
}
