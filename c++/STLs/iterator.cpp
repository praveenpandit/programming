// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename T>
class linkedList
{
    class Node
    {
        T data;
        Node *pNext;
        friend class linkedList;
    };
    Node *getNode(T data)
    {
        Node *pNewNode = new Node;
        pNewNode->data = data;
        pNewNode->pNext = nullptr;
        return pNewNode;
    }
    Node *&getRootNode()
    {
        return m_spRoot;
    }
    static Node *m_spRoot;

public:
    linkedList<T>() noexcept
    {
        m_spRoot = nullptr;
    }
    void push(T data)
    {
        Node *pTemp = getNode(data);
        if (!getRootNode())
            getRootNode() = pTemp;
        else
        {
            Node *curr = getRootNode();
            while (curr->pNext)
                curr = curr->pNext;
            curr->pNext = pTemp;
        }
    }
    void traverse()
    {
        Node *curr = getRootNode();
        while (curr)
        {
            cout << curr->data << "->";
            curr = curr->pNext;
        }
        cout << "EOL" << endl;
    }
    class iterator
    {
        const Node *m_pCurrent;

    public:
        iterator() noexcept : m_pCurrent(m_spRoot) {}
        iterator(const Node *pNode) noexcept : m_pCurrent(pNode) {}
        iterator &operator=(Node *pNode)
        {
            this->m_pCurrent = pNode;
            return *this;
        }
        iterator &operator++()
        {
            if (m_pCurrent)
                m_pCurrent = m_pCurrent->pNext;
            return *this;
        }
        iterator operator++(int)
        {
            iterator itr = *this;
            ++*this;
            return itr;
        }
        bool operator!=(const iterator itr)
        {
            return m_pCurrent != itr.m_pCurrent;
        }
        T operator*()
        {
            return m_pCurrent->data;
        }
    };
    iterator begin() { return iterator(m_spRoot); }
    iterator end() { return iterator(nullptr); }
};
template <typename T>
typename linkedList<T>::Node *linkedList<T>::m_spRoot = nullptr;
int main()
{
    linkedList<int> listInt;
    listInt.push(1);
    listInt.push(2);
    cout << "Traversing LinkedList through method" << endl;
    listInt.traverse();
    cout << "Traversing LinkedList through Iterator" << endl;
    linkedList<int>::iterator itr;
    for (itr = listInt.begin(); itr != listInt.end(); itr++)
        cout << *itr << " ";
    return 0;
}