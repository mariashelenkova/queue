#pragma once

#include <iostream>
#include <vector>

template<class T>
class Queue
{
    std::vector<T> data;

public:
    Queue(int n = 0, T value = T())
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
    }

    void pop()
    {
        if (empty())
        {
            throw "Error";
        }

        data.erase(data.begin());
    }

    T& top()
    {
        if (empty())
        {
            throw "Error";
        }

        return data.back();
    }

    bool empty() noexcept
    {
        return data.empty();
    }

    size_t size()
    {
        return data.size();
    }
};
