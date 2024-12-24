#pragma once

#include <iostream>
#include <vector>

template<class T>
class Queue
{
private:
    void resize(size_t new_capacity)
    {
        std::vector<T> new_data(new_capacity);
        for (size_t i = 0; i < count; ++i)
        {
            new_data[i] = data[(head + i) % capacity];
        }

        data = std::move(new_data);
        head = 0;
        tail = count;
        capacity = new_capacity;
    }

    std::vector<T> data;
    size_t head; // Указывает на начало очереди
    size_t tail; // Указывает на конец очереди
    size_t count; // Количество элементов в очереди
    size_t capacity; // Размер буфера

public:
    Queue(int n = 4, T value = T()) : head(0), tail(0), count(0), capacity(n)
    {
        if (n <= 0)
        {
            throw "Capacity must be greater than zero";
        }

        data = std::vector<T>(capacity, value);
    }

    void push(const T& val)
    {
        if (count == capacity)
        {
            resize(capacity * 2);
        }

        data[tail] = val;
        tail = (tail + 1) % capacity;
        count++;
    }

    void pop()
    {
        if (empty())
        {
            throw "Queue is empty";
        }

        head = (head + 1) % capacity;
        count--;
    }

    T& top()
    {
        if (empty())
        {
            throw "Queue is empty";
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