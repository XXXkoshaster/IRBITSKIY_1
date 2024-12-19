#pragma once

#include <iostream>

class Vector final
{
private:
    double* _data;
    size_t _size;
    size_t _capacity;

public:
    class Iterator
    {
    private:
    double* _curr;
    
    public:
        Iterator(double* curr) : _curr(curr) {}

        Iterator& operator=(const Iterator& other) 
        {
            if (this != &other)
                _curr = other._curr;

            return *this;
        }

        Iterator& operator+=(const size_t& other)
        {
            _curr += other;

            return *this;
        }

        Iterator& operator-=(const size_t& other)
        {
            _curr -= other;
            return *this;
        }

        Iterator operator-(const size_t& other) const 
        {
            return Iterator(_curr - other);
        }
        
        size_t operator-(const Iterator& other) const 
        {
            return _curr - other._curr;
        }

        Iterator operator+(const size_t& other) const 
        {
            return Iterator(_curr + other);
        }

        Iterator& operator++()
        {
            _curr++;

            return *this;
        }

        Iterator operator++(int)
        {
            Iterator copy{*this};
            _curr++;

            return copy;
        }

        Iterator& operator--()
        {
            _curr--;

            return *this;
        }
        
        Iterator operator--(int)
        {
            Iterator copy{*this};
            _curr--;

            return copy;
        }

        bool operator>(const Iterator& other) const 
        {
            return _curr > other._curr;
        }

        bool operator<(const Iterator& other) const 
        {
            return _curr < other._curr;
        }

        bool operator>=(const Iterator& other) const 
        {
            return _curr >= other._curr;
        }

        bool operator<=(const Iterator& other) const 
        {
            return _curr <= other._curr;
        }

        bool operator==(const Iterator& other) const 
        {
            return _curr == other._curr;
        }

        bool operator!=(const Iterator& other) const 
        {
            return _curr != other._curr;
        }
        
        double& operator*() const
        {
            return *_curr;
        }

        double* operator->() const
        {
            return _curr;
        }
    };

    Vector() : _data(nullptr), _size(0), _capacity(0) {}

    Vector(size_t size)
    {
        _size = size;
        _capacity = size;
        _data = new double[size]();
    }

    template <typename InputIterator>
    Vector(InputIterator first, InputIterator last)
    {
        _size = std::distance(first, last);
        _capacity = _size;
        _data = new double[_size];
        std::copy(first, last, _data);
    }

    Vector(std::initializer_list<double> init_list)
    {
        _size = init_list.size();
        _capacity = _size;
        _data = new double[_size];
        std::copy(init_list.begin(), init_list.end(), _data);
    }

    Vector(const Vector& other)
    {
        _size = other._size;
        _capacity = other._capacity;
        _data = new double[_capacity];
        std::copy(other._data, other._data + _size, _data);

    }

    Vector& operator=(const Vector& other)
    {
        if (this != &other)
            delete[] _data;

        _size = other._size;
        _capacity = other._capacity;
        _data = new double[_capacity];
        std::copy(other._data, other._data + _size, _data);
    }

    double& at(size_t index) const
    {
        return _data[index];
    }

    double& front() const
    {
        return _data[0];
    }

    double& back() const
    {
        return _data[_size - 1];
    }

    bool empty() const
    {
        return (_size == 0);
    }

    size_t size() const
    {
        return _size;
    }

    void reserve(size_t new_capacity)
    {   
        if (new_capacity <= _capacity)
            return;

        double* new_data = new double[new_capacity];

        for (size_t i = 0; i < _size; i++)
            new_data[i] = std::move(_data[i]);

        delete[] _data;

        _data = new_data;
        _capacity = new_capacity;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    void shrink_to_fit()
    {
        if (_capacity > _size)
        {
            double* new_data = new double[_size];

            for (size_t i = 0; i < _size; ++i)
                new_data[i] = std::move(_data[i]);

            delete [] _data;

            _data = new_data;
            _capacity = _size;
        }
    }

    void clear()
    {
        delete[] _data;
        _size = 0;
        _capacity = 0;
        _data = nullptr;
    }

    void insert(size_t index, const double elem)
    {
        if (_size == _capacity)
            reserve(_capacity > 0 ? _capacity * 2 : 1);

        for (size_t i = _size; i > index; i--)
            _data[i] = std::move(_data[i - 1]);
        
        _data[index] = elem;

        _size++;
    }

    void erase(size_t index)
    {
        for (size_t i = index; i < _size - 1; i++)
            _data[i] = std::move(_data[i + 1]);

        _size--;
    }

    void push_back(const double& elem)
    {
        if (_size == _capacity)
            reserve(_capacity > 0 ? _capacity * 2 : 1);
        
        _data[_size] = elem;
        _size++;
    }  

    void pop_back()
    {
        _size--;
    }

    void resize(size_t size, const double& elem)
    {
        if (size == _size)
            return;
        
        if (size < _size) {
            size--;
            
            _size = size;
        } else {
            if (_capacity < size)
                reserve(size);

            for (size_t i = _size; i < size; i++)
                _data[i] = elem;

            _size = size;
        }
    }


    std::partial_ordering operator<=>(const Vector& other) const
    {
        size_t min_size = std::min(this->_size, other._size);

        for (size_t i = 0; i < min_size; i++) {
            if (auto cmp = this->at(i) <=> other.at(i); cmp != 0)
                return cmp;
        }

        return this->_size <=> other._size;
    }


    bool operator==(const Vector& other) const
    {
        if (this->size() != other.size())
            return false;

        for (size_t i = 0; i < this->size(); i++) {
            if (this->at(i) != other.at(i))
                return false;
        }

        return true;
    }

    Iterator begin() const
    {
        return Iterator(_data);
    }

     Iterator end() const
    {
        return Iterator(_data + _size);
    }

    ~Vector()
    {
        clear();
    };

};

