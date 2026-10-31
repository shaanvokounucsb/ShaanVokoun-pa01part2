// ============================================================================
// CS32 P01 Part 2: LinkedList implementation
//
// This file is #included at the bottom of LinkedList.h rather than compiled on
// its own (templates must be visible wherever they are used).
// ============================================================================

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "LinkedList.h"



#include <stdexcept>
#include <initializer_list>

// ---- Constructors and the Big 3 ---
template <typename T>
LinkedList<T>::LinkedList() : head_(nullptr), size_(0) {}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> il) : head_(nullptr), size_(0) {
    for (const T& val : il) {
        push_back(val);
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) : head_(nullptr), size_(0) {
    append_all(other);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) {
        free_all();
        append_all(other);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    free_all();
}
// ---- Everything else ----
template <typename T>
std::size_t LinkedList<T>::size() const {
    return size_;
}

template <typename T>
T& LinkedList<T>::at(std::size_t i) {
    if (i >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return node_at(i)->value;
}

template <typename T>
const T& LinkedList<T>::at(std::size_t i) const {
    if (i >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return node_at(i)->value;
}

template <typename T>
void LinkedList<T>::insert(std::size_t index, const T& value) {
    if (index > size_) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        head_ = new Node{value, head_};
    } else {
        Node* prev = node_at(index - 1);
        prev->next = new Node{value, prev->next};
    }
    ++size_;
}

template <typename T>
void LinkedList<T>::erase(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    Node* target;
    if (index == 0) {
        target = head_;
        head_ = head_->next;
    } else {
        Node* prev = node_at(index - 1);
        target = prev->next;
        prev->next = target->next;
    }
    delete target;
    --size_;
}

template <typename T>
void LinkedList<T>::push_back(const T& value) {
    insert(size_, value);
}

// --- Private Helper Functions ---

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::node_at(std::size_t i) const {
    Node* current = head_;
    for (std::size_t step = 0; step < i; ++step) {
        current = current->next;
    }
    return current;
}

template <typename T>
void LinkedList<T>::append_all(const LinkedList& other) {
    for (std::size_t i = 0; i < other.size_; ++i) {
        push_back(other.at(i));
    }
}

template <typename T>
void LinkedList<T>::free_all() {
    Node* current = head_;
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
    head_ = nullptr;
    size_ = 0;
}

#endif
