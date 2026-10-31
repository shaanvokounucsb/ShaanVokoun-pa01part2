#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// ============================================================================
// CS32 P01 Part 2: a singly linked list
//
// This class already works: it is correct and does not leak. But much of it
// does the same job as code in your Vector, and now in Sequence. Your job is to
// make LinkedList<T> derive from Sequence<T> and delete everything that
// Sequence now provides. Do not change how the list stores its nodes.
// ============================================================================

#include "Sequence.h"
#include <initializer_list>
#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
class LinkedList : public Sequence<T> {
public:
    LinkedList();
    LinkedList(std::initializer_list<T> il);
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);
    ~LinkedList() override;

    std::size_t size() const override;
    T& at(std::size_t i) override;
    const T& at(std::size_t i) const override;
    void insert(std::size_t index, const T& value) override;
    void erase(std::size_t index) override;

    void push_back(const T& value) override;

private:
    struct Node {
        T value;
        Node* next;
    };

    Node* head_;
    std::size_t size_;

    Node* node_at(std::size_t i) const;
    void append_all(const LinkedList& other);
    void free_all();
};

#include "LinkedList.cpp"

#endif
