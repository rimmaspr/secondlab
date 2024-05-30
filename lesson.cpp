#include <iostream>
#include "DynamicArray.h"
#include "DynamicArray_tests.h"
#include "LinkedList.h"
#include "LinkedList_tests.h"
#include "Sequence.h"
#include "Sequence_tests.h"
#include <cstdio>


using namespace std;

int getint() {
    int value{};
    int scanf_value{};
    scanf_value = scanf_s("%d", &value);

    if (!scanf_value) {
        cout << "Invalid input. Try again: ";
        scanf_s("%*[^\n]");
        return getint();
    }
    return value;
}

int getchoice(int minval, int maxval) {
    int choice{};
    choice = getint();
    if (choice < minval or choice > maxval) {
        cout << "Invalid input. Enter number from " << minval << " to " << maxval << ": ";
        return getchoice(minval, maxval);
    }
    return choice;
}


int main() {

    cout << "Tests  for all classes: ";

    menuDA();
    menuLinkedList();
    menuSequence();

        
    // Тестирование DynamicArray
    cout << "\nTesting DynamicArray:\n";
    int sizea;
    cout << "Enter the size: ";
    sizea = getint();

    DynamicArray<int> myArray(sizea);

    cout << "Enter " << sizea << " elements: ";
    for (int i = 0; i < sizea; ++i) {
        int element;
        element = getint();
        myArray.append(element);
    }

    cout << "Array: ";
    myArray.printArray();

    cout << "Length: " << myArray.getSize() << endl;

    int indexa;
    cout << "Enter the index of the element you want to set: ";
    indexa = getint();
    if (indexa < 0 or indexa >= myArray.getSize()) {
        cerr << "Error: Index out of bounds" << endl;
    }
    else {
        int value;
        cout << "Enter the element: ";
        cin >> value;
        myArray.set_element(indexa, value);
        cout << "The array after setting the element is: ";
        myArray.printArray();
    }

    cout << "Enter the index of the element you want to get: ";
    indexa = getint();
    try {
        int element = myArray.get_element(indexa);
        cout << "Element at index " << indexa << ": " << element << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }


    // Тестирование LinkedList
    cout << "\nTesting LinkedList:" << endl;
    LinkedList<int> list;

    int sizel;
    cout << "Enter the size: ";
    sizel = getint();
    cout << "Enter " << sizel << " elements: ";
    for (int i = 0; i < sizel; ++i) {
        int element;
        cin >> element;
        list.Append(element);
    }

    cout << "List: ";
    for (int i = 0; i < sizel; ++i) {
        cout << list.Get(i) << " ";
    }
    cout << endl;

    cout << "First element: " << list.GetFirst() << endl;
    cout << "Last element: " << list.GetLast() << endl;
    cout << "Length: " << list.GetLength() << endl;

    try {
        int in1, in2;
        cout << "Enter start index for sublist: ";
        cin >> in1;
        cout << "Enter start index for sublist: ";
        cin >> in2;
        LinkedList<int>* sublist = list.GetSubList(in1, in2);
        cout << "Sublist: ";
        for (int i = 0; i < sublist->GetLength(); ++i) {
            cout << sublist->Get(i) << " ";
        }
        cout << endl;
        delete sublist;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    int indexl;
    cout << "Enter the index of the element you want to get: ";
    cin >> indexl;
    try {
        int element = list.Get(indexl);
        cout << element << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    int elems, elemd;
    cout << "Enter the element you want insart at start of list: ";
    cin >> elems;
    list.Prepend(elems);
    cout << "Enter the element you want insart at end of list: ";
    cin >> elemd;
    list.Append(elemd);
    
    cout << "The LinkedList is: ";
    for (int i = 0; i < list.GetLength(); ++i) {
        cout << list.Get(i) << " ";
    }
    cout << endl;


    // Тестирование АrraySequence
    cout << "\nTesting ArraySequence:" << endl;
    ArraySequence<int> arraySeq;

    int sizeas;
    cout << "Enter the size: ";
    cin >> sizeas;
    cout << "Enter elements: ";
    for (int i = 0; i < sizeas; ++i) {
        int element;
        cin >> element;
        arraySeq.Append(element);
    }

    cout << "ArraySequence: ";
    for (int i = 0; i < arraySeq.GetLength(); ++i) {
        cout << arraySeq.Get(i) << " ";
    }
    cout << endl;

    cout << "First element: " << arraySeq.GetFirst() << endl;
    cout << "Last element: " << arraySeq.GetLast() << endl;
    cout << "Length: " << arraySeq.GetLength();

    int indexas;
    cout << "\nEnter the position of the element you want to set: ";
    cin >> indexas;
    if (indexas < 0 or indexas >= arraySeq.GetLength()) {
        cerr << "Error: Index out of bounds" << std::endl;
    }
    else {
        int value;
        cout << "Enter the element: ";
        cin >> value;
        arraySeq.InsertAt(value, indexas);
        cout << "The array after setting the element is: ";
        cout << "The LinkedList is: ";
        for (int i = 0; i < arraySeq.GetLength(); ++i) {
            cout << arraySeq.Get(i) << " ";
        }
        cout << endl;
    }
    
    int indexstartas, indexendtas;
    cout << "Enter start index for subsequence: ";
    cin >> indexstartas;
    cout << "Enter end index for subsequence: ";
    cin >> indexendtas;

    try {
        Sequence<int>* subsequence = arraySeq.GetSubsequence(indexstartas, indexendtas);
        cout << "Subsequence: ";
        for (int i = 0; i < subsequence->GetLength(); ++i) {
            cout << subsequence->Get(i) << " ";
        }
        cout << endl;
        delete subsequence;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    int elemstartas, elemendas;
    cout << "Enter the element you want set at start: ";
    cin >> elemstartas;
    arraySeq.Prepend(elemstartas);
    cout << "Enter the element you want set at end: ";
    cin >> elemendas;
    arraySeq.Append(elemendas);

    cout << "ArraySequence: ";
    for (int i = 0; i < arraySeq.GetLength(); ++i) {
        cout << arraySeq.Get(i) << " ";
    }
    cout << endl;


    // Тестирование LinkedListSequence
    cout << "\nTesting LinkedListSequence:" << endl;
    LinkedListSequence<int> linkedListSeq;
    
    int sizels;
    cout << "Enter the size: ";
    cin >> sizels;
        
    cout << "Enter " << sizels << " elements: ";
    for (int i = 0; i < sizels; ++i) {
        int element;
        cin >> element;
        linkedListSeq.Append(element);
    }

    cout << "List: ";
    for (int i = 0; i < linkedListSeq.GetLength(); ++i) {
        cout << linkedListSeq.Get(i) << " ";
    }
    cout << endl;

    cout << "First element: " << linkedListSeq.GetFirst() << endl;
    cout << "Last element: " << linkedListSeq.GetLast() << endl;
    cout << "Length: " << linkedListSeq.GetLength() << endl;
    
    int indexlls;
    cout << "Enter the index of element you want get: ";
    cin >> indexlls;
    try {
        int element = linkedListSeq.Get(indexlls);
        cout << "Element: " << element << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    int elemstartlls, elemendllls;
    cout << "Enter the element you want set at start: ";
    cin >> elemstartlls;
    linkedListSeq.Prepend(elemstartlls);
    cout << "Enter the element you want set at end: ";
    cin >> elemendllls;
    linkedListSeq.Append(elemendllls);

    cout << "List: ";
    for (int i = 0; i < linkedListSeq.GetLength(); ++i) {
        cout << linkedListSeq.Get(i) << " ";
    }
    cout << endl;

    int indexstartllls, indexendllls;
    cout << "Enter start index for subsequence: ";
    cin >> indexstartllls;
    cout << "Enter end index for subsequence: ";
    cin >> indexendllls;

    try {
        Sequence<int>* subsequence = linkedListSeq.GetSubsequence(indexstartllls, indexendllls);
        cout << "Subsequence: ";
        for (int i = 0; i < subsequence->GetLength(); ++i) {
            cout << subsequence->Get(i) << " ";
        }
        cout << endl;
        delete subsequence;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    } 

    return 0;
}