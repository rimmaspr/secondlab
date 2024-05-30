#pragma once
#include <stdexcept>
using namespace std;

template <class T>
class Sequence {
public:
    virtual T& Get(int index) = 0;
    virtual int GetLength() = 0;
    virtual void Append(const T& item) = 0;
    virtual void Prepend(const T& item) = 0;
    virtual void InsertAt(const T& item, int index) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
    virtual T& GetFirst() = 0;
    virtual T& GetLast() = 0;

    virtual ~Sequence() {}
};

template <class T>
class ArraySequence : public Sequence<T> {
private:
    T* items;
    int size;
public:
    ArraySequence() : items(nullptr), size(0) {}

    ArraySequence(T* items, int count) : size(count) {
        this->items = new T[count];
        for (int i = 0; i < count; ++i) {
            this->items[i] = items[i];
        }
    }

    ArraySequence(const ArraySequence& other) : size(other.size) {
        this->items = new T[size];
        for (int i = 0; i < size; ++i) {
            this->items[i] = other.items[i];
        }
    }

    ~ArraySequence() {
        delete[] items;
    }

    ArraySequence& operator=(const ArraySequence& other) {
        if (this != &other) {
            delete[] items;
            size = other.size;
            items = new T[size];
            for (int i = 0; i < size; ++i) {
                items[i] = other.items[i];
            }
        }
        return *this;
    }

    T& Get(int index) override {
        if (index < 0 or index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return items[index];
    }

    int GetLength() override {
        return size;
    }

    void Append(const T& item) override {
        T* newItems = new T[size + 1];
        for (int i = 0; i < size; ++i) {
            newItems[i] = items[i];
        }
        newItems[size] = item;
        delete[] items;
        items = newItems;
        ++size;
    }

    void Prepend(const T& item) override {
        T* newItems = new T[size + 1];
        newItems[0] = item;
        for (int i = 0; i < size; ++i) {
            newItems[i + 1] = items[i];
        }
        delete[] items;
        items = newItems;
        ++size;
    }

    void InsertAt(const T& item, int index) override {
        if (index < 0 or index > size) {
            throw std::out_of_range("Index out of bounds");
        }
        ++size;
        T* newItems = new T[size];
        for (int i = 0; i < index; ++i) {
            newItems[i] = items[i];
        }
        newItems[index] = item;
        for (int i = index + 1; i < size; ++i) {
            newItems[i] = items[i - 1];
        }
        delete[] items;
        items = newItems;
    }


    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {
        if (startIndex < 0 or startIndex > endIndex or endIndex >= size) {
            throw std::out_of_range("Invalid subsequence bounds");
        }
        int subsequenceSize = endIndex - startIndex + 1;
        T* subsequenceItems = new T[subsequenceSize];
        for (int i = startIndex; i <= endIndex; ++i) {
            subsequenceItems[i - startIndex] = items[i];
        }
        return new ArraySequence<T>(subsequenceItems, subsequenceSize);
    }

    Sequence<T>* Concat(Sequence<T>* list) override {
        int newSize = size + list->GetLength();
        T* newItems = new T[newSize];
        for (int i = 0; i < size; ++i) {
            newItems[i] = items[i];
        }
        for (int i = 0; i < list->GetLength(); ++i) {
            newItems[size + i] = list->Get(i);
        }
        return new ArraySequence<T>(newItems, newSize);
    }

    T& GetFirst() override {
        if (size == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return items[0];
    }

    T& GetLast() override {
        if (size == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        return items[size - 1];
    }
};

template <class T>
class LinkedListSequence : public Sequence<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;
    int size;
public:
    LinkedListSequence() : head(nullptr), size(0) {}

    LinkedListSequence(const LinkedListSequence& other) : size(other.size) {
        if (other.head == nullptr) {
            head = nullptr;
        }
        else {
            head = new Node(other.head->data);
            Node* current = head;
            Node* otherCurrent = other.head->next;
            while (otherCurrent != nullptr) {
                current->next = new Node(otherCurrent->data);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }

    ~LinkedListSequence() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    T& Get(int index) override {
        if (index < 0 or index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    int GetLength() override {
        return size;
    }

    void Append(const T& item) override {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++size;
    }

    void Prepend(const T& item) override {
        Node* newNode = new Node(item, head);
        head = newNode;
        ++size;
    }

    void InsertAt(const T& item, int index) override {
        if (index < 0 or index > size) {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0) {
            Prepend(item);
        }
        else {
            Node* newNode = new Node(item);
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            ++size;
        }
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {
        if (startIndex < 0 || startIndex > endIndex || endIndex >= size) {
            throw std::out_of_range("Invalid subsequence bounds");
        }
        LinkedListSequence<T>* subsequence = new LinkedListSequence<T>();
        Node* current = head;
        for (int i = 0; i < startIndex; ++i) {
            current = current->next;
        }
        for (int i = startIndex; i <= endIndex; ++i) {
            subsequence->Append(current->data);
            current = current->next;
        }
        return subsequence;
    }

    Sequence<T>* Concat(Sequence<T>* list) override {
        LinkedListSequence<T>* concatenated = new LinkedListSequence<T>(*this);
        for (int i = 0; i < list->GetLength(); ++i) {
            concatenated->Append(list->Get(i));
        }
        return concatenated;
    }

    T& GetFirst() override {
        if (head == nullptr) {
            throw std::out_of_range("Sequence is empty");
        }
        return head->data;
    }

    T& GetLast() override {
        if (head == nullptr) {
            throw std::out_of_range("Sequence is empty");
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->data;
    }

};
