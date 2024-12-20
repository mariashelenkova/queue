#pragma once

#include <iostream>
#include <vector>

template<class T>
class Queue
{
    std::vector<T> data;
    size_t head; 
    size_t a;

public:
    Queue(int n = 0, T value = T()) : head(0), a(0)
    {
        if (n < 0)
        {
            throw "Error";
        }

        data = std::vector<T>(n, value);
    }

    void push(const T& val) noexcept
    {
        data.push_back(val);
        a++;
    }

    void pop()
    {
        if (empty())
        {
            throw "Error";
        }

        head++;
    }

    T& top()
    {
        if (empty())
        {
            throw "Error";
        }

        return data[head];
    }

    bool empty() noexcept
    {
        return head == a; 
    }

    size_t size()
    {
        return a - head; 
    }

    void clear() noexcept
    {
        head = 0; 
        a = 0;
        data.resize(0);
    }
};