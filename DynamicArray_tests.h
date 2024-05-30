#pragma once
#include "DynamicArray.h"

using namespace std;

void testAppend() {
    cout << "\nTesting append" << endl;

    DynamicArray<int> arr(5);

    arr.append(1);
    arr.append(2);
    arr.append(3);

    cout << "Expected result: 1 2 3" << endl;
    cout << "Actual result:   ";
    arr.printArray();
}

void testResize() {
    cout << "\nTesting resize" << endl;

    DynamicArray<int> arr(2);

    arr.append(1);
    arr.append(2);
    arr.append(3);

    cout << "Expected result: 1 2 3" << endl;
    cout << "Actual result:   ";
    arr.printArray();
}

void testGetSize() {
    cout << "\nTesting getSize" << endl;

    DynamicArray<int> arr(3);

    cout << "Expected result: 0" << endl;
    cout << "Actual result:   " << arr.getSize() << endl;

    arr.append(1);
    arr.append(2);
    arr.append(3);

    cout << "Expected result: 3" << endl;
    cout << "Actual result:   " << arr.getSize() << endl;
}

void testGetElement() {
    cout << "\nTesting get_element" << endl;

    DynamicArray<int> arr(3);

    arr.append(1);
    arr.append(2);
    arr.append(3);

    cout << "Expected result: 2" << endl;
    cout << "Actual result:   " << arr.get_element(1) << endl;
}

void testSetElement() {
    cout << "\nTesting set_element" << endl;

    DynamicArray<int> arr(3);

    arr.append(1);
    arr.append(2);
    arr.append(3);

    arr.set_element(1, 5);

    cout << "Expected result: 1 5 3" << endl;
    cout << "Actual result:   ";
    arr.printArray();
}

void menuDA() {
    char choice;

    do {
        cout << "\nChoose a test to run:" << endl;
        cout << "1. Test append" << endl;
        cout << "2. Test resize" << endl;
        cout << "3. Test getSize" << endl;
        cout << "4. Test get_element" << endl;
        cout << "5. Test set_element" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            testAppend();
            break;
        case '2':
            testResize();
            break;
        case '3':
            testGetSize();
            break;
        case '4':
            testGetElement();
            break;
        case '5':
            testSetElement();
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