#include <iostream>
#include "Sequence.h"

using namespace std;

void testAppends(Sequence<int>* seq) {
    cout << "\nTesting append" << endl;

    seq->Append(1);
    seq->Append(2);
    seq->Append(3);

    cout << "Expected result: 1 2 3" << endl;
    cout << "Actual result:   ";
    for (int i = 0; i < seq->GetLength(); ++i) {
        cout << seq->Get(i) << " ";
    }
    cout << endl;
}

void testPrepends(Sequence<int>* seq) {
    cout << "\nTesting prepend" << endl;

    seq->Prepend(3);
    seq->Prepend(2);
    seq->Prepend(1);

    cout << "Expected result: 1 2 3" << endl;
    cout << "Actual result:   ";
    for (int i = 0; i < seq->GetLength(); ++i) {
        cout << seq->Get(i) << " ";
    }
    cout << endl;
}

void testGetFirsts(Sequence<int>* seq) {
    cout << "\nTesting getFirst" << endl;

    seq->Append(1);
    seq->Append(2);
    seq->Append(3);

    cout << "Expected result: 1" << endl;
    cout << "Actual result:   " << seq->GetFirst() << endl;
}

void testGetLasts(Sequence<int>* seq) {
    cout << "\nTesting getLast" << endl;

    seq->Append(1);
    seq->Append(2);
    seq->Append(3);

    cout << "Expected result: 3" << endl;
    cout << "Actual result:   " << seq->GetLast() << endl;
}

void testGets(Sequence<int>* seq) {
    cout << "\nTesting get" << endl;

    seq->Append(1);
    seq->Append(2);
    seq->Append(3);

    cout << "Expected result at index 1: 2" << endl;
    cout << "Actual result at index 1:   " << seq->Get(1) << endl;
}

void testGetSubsequences(Sequence<int>* seq) {
    cout << "\nTesting getSubsequence" << endl;

    seq->Append(1);
    seq->Append(2);
    seq->Append(3);

    Sequence<int>* subsequence = seq->GetSubsequence(1, 2);

    cout << "Expected result: 2 3" << endl;
    cout << "Actual result:   ";
    for (int i = 0; i < subsequence->GetLength(); ++i) {
        cout << subsequence->Get(i) << " ";
    }
    cout << endl;

    delete subsequence;
}

void testInsertAts(Sequence<int>* seq) {
    cout << "\nTesting insertAt" << endl;

    seq->Append(1);
    seq->Append(3);

    seq->InsertAt(2, 1);

    cout << "Expected result: 1 2 3" << endl;
    cout << "Actual result:   ";
    for (int i = 0; i < seq->GetLength(); ++i) {
        cout << seq->Get(i) << " ";
    }
    cout << endl;
}

void testConcats(Sequence<int>* seq1, Sequence<int>* seq2) {
    cout << "\nTesting concat" << endl;

    seq1->Append(1);
    seq1->Append(2);
    seq1->Append(3);

    Sequence<int>* result = seq1->Concat(seq2);

    cout << "Expected result: 1 2 3 4 5 6" << endl;
    cout << "Actual result:   ";
    for (int i = 0; i < result->GetLength(); ++i) {
        cout << result->Get(i) << " ";
    }
    cout << endl;

    delete result;
}

void menuSequence() {
    char choice;
    char type;

    cout << "Choose the type of sequence to test:" << endl;
    cout << "1. ArraySequence" << endl;
    cout << "2. LinkedListSequence" << endl;
    cout << "Enter your choice: ";
    cin >> type;

    Sequence<int>* seq1;
    Sequence<int>* seq2;

    if (type == '1') {
        seq1 = new ArraySequence<int>();
        seq2 = new ArraySequence<int>();
        seq2->Append(4);
        seq2->Append(5);
        seq2->Append(6);
    }
    else if (type == '2') {
        seq1 = new LinkedListSequence<int>();
        seq2 = new LinkedListSequence<int>();
        seq2->Append(4);
        seq2->Append(5);
        seq2->Append(6);
    }
    else {
        cout << "Invalid choice. Exiting." << endl;
        return;
    }

    do {
        cout << "\nChoose a test to run:" << endl;
        cout << "1. Test appends" << endl;
        cout << "2. Test prepends" << endl;
        cout << "3. Test getFirsts" << endl;
        cout << "4. Test getLasts" << endl;
        cout << "5. Test gets" << endl;
        cout << "6. Test getSubsequences" << endl;
        cout << "7. Test insertAts" << endl;
        cout << "8. Test concats" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            testAppends(seq1);
            break;
        case '2':
            testPrepends(seq1);
            break;
        case '3':
            testGetFirsts(seq1);
            break;
        case '4':
            testGetLasts(seq1);
            break;
        case '5':
            testGets(seq1);
            break;
        case '6':
            testGetSubsequences(seq1);
            break;
        case '7':
            testInsertAts(seq1);
            break;
        case '8':
            testConcats(seq1, seq2);
            break;
        case '0':
            cout << "Exiting test menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != '0');

    delete seq1;
    delete seq2;
}
