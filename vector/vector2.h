#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace bit
{
    template<class T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
        typedef T* iterator;
        typedef const T* const_iterator;
        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
         const_iterator cbegin() const
        {
            return _start;
        }
         const_iterator cend() const
        {
            return _finish;
        }
            // construct and destroy
        vector()
            : _start(nullptr)
            , _finish(nullptr)
            , _endOfStorage(nullptr)
        {};
        vector(int n, const T& value = T())
            : _start(nullptr)
            , _finish(nullptr)
            , _endOfStorage(nullptr)
        {
            reserve(n);
            while (n--) {
                push_back(value);
            }
        }
        template<class InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            reserve(last - first);
            while (first != last) {
                push_back(*first);
                ++first;
            }
        }
        vector(const vector<T>& v)
            :_start(nullptr)
            , _finish(nullptr)
            , _endOfStorage(nullptr)
        {
            reserve(v.capacity);
            iterator it = begin();
            const_iterator cit = cbegin();
            while (cit != cend()) {
                *it = *cit;
                it++;
                cit++;
            }
        };
        vector<T>& operator= (vector<T> v) 
        {
            swap(v);
            return *this;
        }
        ~vector()
        {
            delete[]_start;
            _start = _finish = _endOfStorage = nullptr;
        }
            // capacity
        size_t size() const
        {
            return _finish - _start;
        }
        size_t capacity() const
        {
            return _endOfStorage - _finish;
        }
        void reserve(size_t n)
        {
            if (n > capacity()) {
                size_t oldsize = size();
                T* tmp = new T[n];
                if (_start) {
                    for (size_t i = 0; i < oldsize; i++) {
                        tmp[i] = _start[i];
                    }
                }
                delete[]_start;
                _start = tmp;
                _finish = _start+ oldsize;
                _endOfStorage = _start + n;
            }
        }
        void resize(size_t n, const T& value = T())
        {
            if (n > capacity()) {
                reserve(n);
                iterator it = _finish;
                _finish = _start + n;
                while (it != _finish) {
                    *it = value;
                    ++it;
                }
            }
            if (n <= size()) {
                _finish = _start + n;
                return;
            }

        }
            ///////////////access///////////////////////////////
        T& operator[](size_t pos)
        {
            assert(pos <= end());
            return *(_start + pos);
        }
        const T& operator[](size_t pos)const
        {
            assert(pos <= end());
            return *(_start + pos);
        }
            ///////////////modify/////////////////////////////
        void push_back(const T& x)
        {
            if (_finish == _endOfStorage) {
                size_t newcapcity = capacity() == 0 ? 1 : capacity() * 2;
                reserve(newcapcity);
            }
            *_finish = x;
            _finish++;
        }
        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endOfStorage, v._endOfStorage);
        }
        iterator insert(iterator pos, const T& x)
        {
            assert(pos <= end());
            if (_finish == _endOfStorage) {
                size_t newcapcity = (0 == capacity()) ? 1 : (capacity() * 2);
                reserve(newcapcity);
                pos = _start + size();
            }
            iterator end = _finish - 1;
            while (end >= pos) {
                *(end + 1) = *end;  
                end--;
            }
            *pos = x;
            ++_finish;
            return pos;
        }
        iterator erase(iterator pos)
        {
            assert(pos <= end());
            iterator begin = pos + 1;
            while (begin < _finish);
            {
                *(begin - 1) = *begin;
                ++begin;
            }
            --_finish;
            return pos;
        }
    private:
        iterator _start; // 指向数据块的开始
        iterator _finish; // 指向有效数据的尾
        iterator _endOfStorage; // 指向存储容量的尾
    };
}