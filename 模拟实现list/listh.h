#pragma once
#include<iostream>
namespace bite
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
            :_pPre(nullptr)
            ,_pNext(nullptr)
            ,_val(val)
        {}
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };
    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        {}
        ListIterator(const Self& l)
            :_pNode(l._pNode)
        {}
        T& operator*()
        {
            return _pNode->_val;
        }
        T* operator->()
        {
            return &_pNode->_val;
        }
        Self &operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }
        Self operator++(int)
        {
            Self temp(_pNode);
            _pNode = _pNode->_pNext;
            return temp;
        }
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }
        Self& operator--(int)
        {
            Self temp(_pNode);
            _pNode = _pNode->_pPre;
            return temp;
        }
        bool operator!=(const Self& l)
        {
            return _pNode != l._pNode;
        }
        bool operator==(const Self& l)
        {
            return _pNode == l._pNode;
        }
        PNode _pNode;
    };

    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
        {
            CreateHead();
        }
        list(int n, const T& value = T())
        {
            CreateHead();
            for (int i = 0; i < n; ++i) {
                push_back(value);
            }
        }
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            while (first != last) {
                push_back(*first);
                ++first;
            }
        }
        list(const list<T>& l)
        {
            CreateHead();
            list<T>temp(l.begin(), l.end());
            swap(temp);
        }
        list<T>& operator=(const list<T> l)
        {
            swap(l);
            return *this;
        }
        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
        }
        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return iterator(_pHead->_pNext);
        }
        iterator end()
        {
            return iterator(_pHead);
        }
        const_iterator begin() const
        {
            return iterator(_pHead->_pNext);
        }
        const_iterator end() const
        {
            return iterator(_pHead);
        }
        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            size_t size = 0;
            ListNode* p = _pHead->_pNext;
            while (p != _pHead) {
                size++;
                p = p->_pNext;
            }
            return size;
        }
        bool empty()const
        {
            return size() == 0;
        }
        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return _pHead;
        }
        const T& front()const
        {
            return _pHead;
        }
        T& back()
        {
            return _pHead->_pPre;
        }
        const T& back()const
        {
            return _pHead->_pPre;
        }
        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) { insert(begin(), val); }
        void pop_back() { erase(--end()); }
        void push_front(const T& val) { insert(begin(), val); }
        void pop_front() { erase(begin()); }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            PNode newNode = new Node(val);
            PNode cur = pos._pNode;
            newNode->_pPre = cur->_pPre;
            newNode->_pNext = cur;
            newNode->_pPre->_pNext = newNode;
            cur->_pPre = newNode;
            return iterator(cur);
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {    
            PNode Pnode = pos._pNode;
            PNode next = Pnode->_pNext;
            next->_pPre = Pnode->_pPre;
            Pnode->_pPre->_pNext = next;
            delete Pnode;
            Pnode = nullptr;
            return iterator(next);
        }
        void clear()
        {
            iterator it = begin();
            while (it != end()) {
                it = erase(it);
                ++it;
            }
        }
        void swap(list<T>& l)
        {
            swap(l._pHead);
        }
    private:
        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
        }
        PNode _pHead;
    };
};