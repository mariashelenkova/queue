#pragma once

#include <iostream>
#include <vector>

template<class T>
class Queue
{
    std::vector<T> data;
    size_t head; // Указывает на начало очереди
    size_t tail; // Указывает на конец очереди
    size_t count; // Количество элементов в очереди
    size_t capacity; // Размер буфера

public:
    Queue(int n = 0, T value = T()) : head(0), tail(0), count(0), capacity(n)
    {
        if (n < 0)
        {
            throw "Error";
        }

        data = std::vector<T>(capacity, value);
    }

    void push(const T& val)
    {
        if (count == capacity)
        {
            throw "Error";
        }

        data[tail] = val;
        tail = (tail + 1) % capacity;
        count++;
    }

    void pop()
    {
        if (empty())
        {
            throw "Error";
        }

        head = (head + 1) % capacity;
        count--;
    }

    T& top()
    {
        if (empty())
        {
            throw "Error";
        }

        return data[head];
    }

    bool empty() const noexcept
    {
        return count == 0;
    }

    size_t size() const noexcept
    {
        return count;
    }

    void clear() noexcept
    {
        head = 0;
        tail = 0;
        count = 0;
    }
};