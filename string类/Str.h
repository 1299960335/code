#pragma once
#include<iostream>
#include<assert.h>
#pragma warning(disable:4996)
using namespace std;
namespace bit
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const bit::string& s)
        {
            for (size_t i = 0; i < s.size(); i++) {
                _cout << s[i];
            }
            return _cout;
        }
        friend istream& operator>>(istream& _cin, bit::string& s)
        {
            char ch;
            while(1){

                    _cin.get(ch);
                    _cin >> ch;
                if (ch == ' ' || ch == '\n') {
                     break;
                }
                 else {
                     s += ch;
                 }
            }
            return _cin;
        }
    public:
        typedef char* iterator;
    public:
        string(const char* str = "")
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        string(const string& s)
            :_str(nullptr)
            , _capacity(0)
            , _size(0)
        {
            string tmp(s._str);
            swap(tmp);
        };
        string& operator=(string& s)
        {
            swap(s);
            return *this;
        }
        ~string()
        {
            delete[] _str;
            _capacity = 0;
            _size = 0;
            _str = nullptr;
        }
        //////////////////////////////////////////////////////////////

        // iterator
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str+_size;
        }
        /////////////////////////////////////////////////////////////

        // modify
        void PushBack(char c)
        {
            if (_size == _capacity) {
                _capacity *= 2;
                reserve(_capacity);
            }
            _str += c;
            _size++;
            _str[_size] = '\0';
        }
        string& operator+=(char c)
        {
            PushBack(c);
            return *this;
        }
        void Append(const char* str)
        {
            size_t len = strlen(str);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            strcpy(_str + _size, str);
            _size += len;
        }
        string& operator+=(const char* str)
        {
            Append(str);
            return *this;
        }
        void swap(string& s)
        {
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }
        const char* c_str()const
        {
            return _str;
        }
        /////////////////////////////////////////////////////////////
        // capacity

        size_t size()const
        {
            return _size;
        }
        size_t capacity()const
        {
            return _capacity;
        }
        void resize(size_t newSize, char c = '\0')
        {
            if (newSize > _capacity) {
                reserve(newSize);
            }
            if (newSize < _capacity) {
                _str[newSize] = '\0';
                _size = newSize;
            }
            for (size_t i = _size; i < newSize; i++) {
                _str[i] = c;
            }
            _str[newSize] = '\0';
            _size = newSize;
        }
        void reserve(size_t newCapacity)
        {
            if (newCapacity > _capacity) {
                char* tmp = new char[newCapacity + 1];
                strcpy(tmp, _str);
                delete[]_str;
                _str = tmp;
            }
        }
        /////////////////////////////////////////////////////////////
        // access
        char& operator[](size_t index)
        {
            assert(index < _size);
            return _str[index];
        }
        const char& operator[](size_t index)const
        {
            assert(index < _size);
            return _str[index];
        }
        /////////////////////////////////////////////////////////////
        //relational operators
      /*  bool operator<(const string& s1, const string& s2)
        {
            size_t i1 = 0, i2 = 0;
            while (i1 < s1.size() && i2 < s2.size()) {
                if (s1[i1] > s2[i2]) {
                    return false;
                }
                else if (s1[i1] < s2[i2]) {
                    return true;
                }
                else {
                    i1++;
                    i2++;
                }
            }
            if (i2 < s2.size()) {
                return true;
            }
            else {
                return false;
            }
        }
        bool operator>(const string& s1, const string& s2)
        {
            size_t i1 = 0, i2 = 0;
            while (i1 < s1.size() && i2 < s2.size()) {
                if (s1[i1] > s2[i2]) {
                    return true;
                }
                else if (s1[i1] < s2[i2]) {
                    return false;
                }
                else{
                    i1++;
                    i2++;
                }
            }
            if (i1 < s1.size()) {
                return true;
            }
            else {
                return false;
            }
        }
        bool operator==(const string& s1, const string& s2)
        {
            size_t i1 = 0, i2 = 0;
            while (i1 < s1.size() && i2 < s2.size()) {
                if (s1[i1] > s2[i2]) {
                    return false;
                }
                else if (s1[i1] < s2[i2]) {
                    return false;
                }
                else {
                    i1++;
                    i2++;
                }
            }
            if (i1 == s1.size()&&i2==s2.size()) {
                return true;
            }
            else {
                return false;
            }
        }
        bool operator!=(const string& s1, const string& s2)
        {
            size_t i1 = 0, i2 = 0;
            while (i1 < s1.size() && i2 < s2.size()) {
                if (s1[i1] > s2[i2]) {
                    return true;
                }
                else if (s1[i1] < s2[i2]) {
                    return true;
                }
                else {
                    i1++;
                    i2++;
                }
            }
            if (i1 == s1.size() && i2 == s2.size()) {
                return false;
            }
            else {
                return true;
            }

        }*/
        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const
        {
            for (size_t i = pos; i < _size; i++) {
                if (_str[i] == c) {
                    return i;
                }
            }
            return npos;
        }
        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const
        {
            const char* ret = strstr(_str + pos, s);
            if (ret == nullptr) {
                return npos;
            }
            else {
                return ret - _str;
            }
        }
        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c)
        {
            if (_size == _capacity) {
                reserve(2 * _capacity);
            }
            size_t end = _size + 1;
            while (end >= pos) {
                _str[end] = _str[end - 1];
                --end;
            }
            _str[pos] = c;
            _size++;
        }
        string& insert(size_t pos, const char* str)
        {
            assert(pos <= _size);
            size_t len = strlen(str);
            if (_size + len >= _capacity) {
                reserve(_capacity + len);
            }
            size_t end = _size + len + 1;
            while (end > pos + len - 1) {
                _str[end] = _str[end - len];
                --end;
            }
            strncpy(_str + pos, str, len);
            _size += len;
        }
        // 删除pos位置上的元素，并返回该元素的下一个位置
        string& erase(size_t pos, size_t len)
        {
            assert(pos < _size);
            if (len == npos || pos + len >= _size) {
                _str[pos] = '\0';
                _size = pos;
            }
            else {
                strcpy(_str + pos, _str + pos + len);
                _size -= len;
            }
        }
    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    public:
        static const size_t npos;
    };
    const size_t string::npos = -1;
}