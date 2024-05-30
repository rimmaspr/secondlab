#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    LinkedList(T* items, int count) : LinkedList() {
        for (int i = 0; i < count; ++i) {
            Append(items[i]);
        }
    }
    LinkedList(const LinkedList& other) : LinkedList() {
        Node* current = other.head;
        while (current != nullptr) {
            Append(current->data);
            current = current->next;
        }
    }

    T GetFirst() const {
        if (head == nullptr) {
            throw std::out_of_range("Index out of bounds: the list is empty");
        }
        return head->data;
    }

    T GetLast() const {
        if (tail == nullptr) {
            throw std::out_of_range("Index out of bounds: the list is empty");
        }
        return tail->data;
    }

    T Get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex) const {
        if (startIndex < 0 or endIndex >= size || startIndex > endIndex) {
            throw std::out_of_range("Index out of bounds");
        }
        LinkedList<T>* sublist = new LinkedList<T>();
        Node* current = head;
        for (int i = 0; i < startIndex; ++i) {
            current = current->next;
        }
        for (int i = startIndex; i <= endIndex; ++i) {
            sublist->Append(current->data);
            current = current->next;
        }
        return sublist;
    }

    int GetLength() const {
        return size;
    }

    void Append(T item) {
        Node* newNode = new Node{ item, nullptr };
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void Prepend(T item) {
        Node* newNode = new Node{ item, head };
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
        size++;
    }

    void InsertAt(T item, int index) {
        if (index < 0 or index > size) {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0) {
            Prepend(item);
            return;
        }
        if (index == size) {
            Append(item);
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* newNode = new Node{ item, current->next };
        current->next = newNode;
        size++;
    }

    LinkedList<T>* Concat(LinkedList<T>* list) {
        LinkedList<T>* result = new LinkedList<T>(*this);
        Node* current = list->head;
        while (current != nullptr) {
            result->Append(current->data);
            current = current->next;
        }
        return result;
    }

    void Clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    ~LinkedList() {
        Clear();
    }
};
