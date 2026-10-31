#ifndef VECTOR_H
#define VECTOR_H

// ============================================================================
// CS32 P01 Part 2: your Vector, now part of a class hierarchy
//
// This is the same Vector.h as Part 1, but in Part 2 it is YOUR file: you edit
// it and submit it. Make Vector<T> derive from Sequence<T>, add the const
// version of at(), and delete every declaration that Sequence now provides.
// Bring over your Vector.cpp from Part 1 next to this file.
//
// Rules (same as Part 1):
//   - Allocate the buffer with new T[...] and release it with delete[].
//   - Do not use std::vector, std::deque, std::list, or smart pointers.
//   - Whenever capacity() is 0, no buffer is allocated and data() == nullptr.
// ============================================================================

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include "Sequence.h"

template <typename T>
class Vector : public Sequence<T> {
public:
    static double growth_factor;

    Vector();
    explicit Vector(std::size_t n);
    Vector(std::size_t n, const T& value);
    Vector(std::initializer_list<T> il);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector() override;

    T& operator[](std::size_t i);
    const T& at(std::size_t index) const override;
    const T& operator[](std::size_t i) const;
    T& at(std::size_t i) override;
    T* data();

    T* begin();
    const T* begin() const;
    T* end();
    const T* end() const;

    std::size_t size() const override;
    std::size_t capacity() const;
    void reserve(std::size_t n);
    void shrink_to_fit();

    void push_back(const T& value) override;
    void clear();
    void resize(std::size_t n);
    void insert(std::size_t index, const T& value) override;
    void erase(std::size_t index) override;

private:
    void reallocate(std::size_t new_cap);

    T* begin_;
    T* end_;
    T* end_cap_;
};

#include "Vector.cpp"

#endif
