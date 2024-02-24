#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstdint>
#include <cstddef>
#include <memory>

template<class T>
struct ListElement
{
public:
    ListElement(): next(nullptr){};

    ListElement<T>* next;
    T data;
};

template<class T>
class LinkedList
{
public:

    // Constructor
    LinkedList(): m_head(nullptr), m_list_lenght(0){};

    // save val to List
    uint32_t save(T value);

    // get the first element of list
    T getFront();

    // get current list length
    size_t getLen();

    // remove item from list, return uint32_t
    uint32_t remove(uint64_t value);

protected:
    ListElement<T>* m_head;
    size_t m_list_lenght;
};

template<class T>
uint32_t LinkedList<T>::save(T value)
{
    // get the adress of our new memory 
    ListElement<T> *p_mem_elem = (new ListElement<T>);
    if (p_mem_elem == nullptr)
    {
        return 0x00;
    }
    
    p_mem_elem -> data = value;

    // insert first element
    if (m_head == nullptr)
    {
        m_head = p_mem_elem;
        this -> m_list_lenght++;
        return 0x00;
    }

    // start at the m_head
    ListElement<T>* p_tmp_head = m_head;

    // go through the list until we reach the null
    while (p_tmp_head != nullptr)
    {
        if (p_tmp_head -> next == nullptr)
        {
            p_tmp_head -> next = p_mem_elem;
            this -> m_list_lenght++;
            return 0x00;
        }
        p_tmp_head = p_tmp_head -> next;
    }

    return 0x01;
}

template<class T>
T LinkedList<T>::getFront()
{
    if (m_head != nullptr)
    {
        T ret = m_head -> data;
        ListElement<T>* del_id = m_head;

        m_head = m_head -> next;
        this -> m_list_lenght--;
        return ret;
    }
}

template<class T>
size_t LinkedList<T>::getLen()
{
    return this -> m_list_lenght;
}

template<class T>
uint32_t LinkedList<T>::remove(uint64_t id)
{
    // get the id of the value     
    
    ListElement<T>* p_tmp_curr = m_head;
    ListElement<T>* p_tmp_prev = m_head;
    while (p_tmp_curr != nullptr)
    {
        uint64_t elem_id = *((uint64_t*)(&(p_tmp_curr -> data)));
        if (elem_id == id)
        {
            // rearrange list
            p_tmp_prev -> next  = p_tmp_curr -> next;
            this -> m_list_lenght--;
            return 0x00;
        }

        p_tmp_prev = p_tmp_curr;
        p_tmp_curr = p_tmp_curr->next;
    }
    return 0;
}

#endif