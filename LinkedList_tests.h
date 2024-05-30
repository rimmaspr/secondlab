#pragma once
#include <iostream>
#include "LinkedList.h"

using namespace std;

void testAppendll() {
    cout << "\nTesting append" << endl;

    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);

    cout << "Expected result: 1 2 3" << endl;
    cout << "Actual result:   ";
    for (int i = 0; i < list.GetLength(); ++i) {
        cout << list.Get(i) << " ";
    }
    cout << endl;
}

void testPrependll() {
    cout << "\nTesting prepend" << endl;

    LinkedList<int> list;
    list.Prepend(3);
    list.Prepend(2);
    list.Prepend(1);

    cout << "Expected result: 1 2 3" << endl;
    cout << "Actual result:   ";
    for (int i = 0; i < list.GetLength(); ++i) {
        cout << list.Get(i) << " ";
    }
    cout << endl;
}

void testGetFirstll() {
    cout << "\nTesting getFirst" << endl;

    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);

    cout << "Expected result: 1" << endl;
    cout << "Actual result:   " << list.GetFirst() << endl;
}

void testGetLastll() {
    cout << "\nTesting getLast" << endl;

    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);

    cout << "Expected result: 3" << endl;
    cout << "Actual result:   " << list.GetLast() << endl;
}

void testGetll() {
    cout << "\nTesting get" << endl;

    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);

    cout << "Expected result at index 1: 2" << endl;
    cout << "Actual result at index 1:   " << list.Get(1) << endl;
}

void testGetSubListll() {
    cout << "\nTesting getSubList" << endl;

    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);
    list.Append(4);
    list.Append(5);

    LinkedList<int>* sublist = list.GetSubList(1, 3);

    cout << "Expected result: 2 3 4" << endl;
    cout << "Actual result:   ";
    for (int i = 0; i < sublist->GetLength(); ++i) {
        cout << sublist->Get(i) << " ";
    }
    cout << endl;

    delete sublist;
}

void testInsertAtll() {
    cout << "\nTesting insertAt" << endl;

    LinkedList<int> list;
    list.Append(1);
    list.Append(3);

    list.InsertAt(2, 1);

    cout << "Expected result: 1 2 3" << endl;
    cout << "Actual result:   ";
    for (int i = 0; i < list.GetLength(); ++i) {
        cout << list.Get(i) << " ";
    }
    cout << endl;
}

void testConcatll() {
    cout << "\nTesting concat" << endl;

    LinkedList<int> list1;
    list1.Append(1);
    list1.Append(2);

    LinkedList<int> list2;
    list2.Append(3);
    list2.Append(4);

    LinkedList<int>* result = list1.Concat(&list2);

    cout << "Expected result: 1 2 3 4" << endl;
    cout << "Actual result:   ";
    for (int i = 0; i < result->GetLength(); ++i) {
        cout << result->Get(i) << " ";
    }
    cout << endl;

    delete result;
}

void menuLinkedList() {
    char choice;

    do {
        cout << "\nChoose a test to run:" << endl;
        cout << "1. Test append" << endl;
        cout << "2. Test prepend" << endl;
        cout << "3. Test getFirst" << endl;
        cout << "4. Test getLast" << endl;
        cout << "5. Test get" << endl;
        cout << "6. Test getSubList" << endl;
        cout << "7. Test insertAt" << endl;
        cout << "8. Test concat" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            testAppendll();
            break;
        case '2':
            testPrependll();
            break;
        case '3':
            testGetFirstll();
            break;
        case '4':
            testGetLastll ();
            break;
        case '5':
            testGetll();
            break;
        case '6':
            testGetSubListll();
            break;
        case '7':
            testInsertAtll();
            break;
        case '8':
            testConcatll();
            break;
        case '0':
            cout << "Exiting test menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != '0');
}