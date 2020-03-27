// BST-AVL-Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{
    avl<int> avlTree;
    string input = "";
    (srand(time(NULL)));
    while (true) {
        cout << "[R]andom  [I]nsert  [C]clear  [S]earch [E]rase  e[X]it: ";
        cin >> input;
        if (input == "r" || input == "R") {
            int num = (rand() % 100) + 1;
            cout << "-- Inserting " << num << "\nTree_node tree: item: " << num << endl;
            avlTree.insert(num);
            cout << avlTree << "\n\n=========================\n";
        } else if (input == "i" || input == "I") {
            int num = 0;
            cout << "? ";
            cin >> num;
            cout << "-- Inserting " << num << "\nTree_node tree: item: " << num << endl;
            avlTree.insert(num);
            cout << avlTree << "\n\n=========================\n";
        } else if (input == "s" || input == "S") {
            int num = 0;
            cout << "? ";
            cin >> num;
            tree_node<int>* foundPtr = NULL;
            if (avlTree.search(num, foundPtr)) {
                cout << "item is found. |" << foundPtr->_item << "|\n";
            } else {
                cout << "Item not found.\n";
            }
            cout << avlTree << "\n\n=========================\n";
        } else if (input == "c" || input == "C") {
            avlTree.clear();
            cout << avlTree << "\n\n=========================\n";
        } else if (input == "x" || input == "X") {
            break;
        } else if (input == "e" || input == "E") {
            int num = 0;
            cout << "? ";
            cin >> num;
            if (avlTree.erase(num)) {
                cout << "erased |" << num << "|\n" << avlTree;
               
            } else {
                cout << num << " was not found" << endl << avlTree;
            }

        }
    }
    cout << "\n\n=========================\n";


    return 0;
}

