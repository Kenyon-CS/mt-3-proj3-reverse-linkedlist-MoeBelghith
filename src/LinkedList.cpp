#include "LinkedList.hpp"
#include <sstream>

LinkedList::LinkedList() : head_(nullptr) {}
LinkedList::~LinkedList() {
    Node* p = head_;
    while (p) {
        Node* n = p->next;
        delete p;
        p = n;
    }
}
void LinkedList::push_front(int v) {
    head_ = new Node(v, head_);
}
void LinkedList::reverse() {
    Node* p = head_;
    LinkedList newList;  
    while (p) 
    {
        newList.push_front(p->value);
        p = p->next;
    }

    p = head_;
    while (p) 
    {
        Node* n = p->next;
        delete p;
        p = n;
    }
    head_ = newList.head_;
    newList.head_ = nullptr;
}


std::string LinkedList::to_string() const {
    std::ostringstream oss;
    oss << "[";
    Node* p = head_;
    bool first = true;
    while (p) {
        if (!first) oss << ", ";
        first = false;
        oss << p->value;
        p = p->next;
    }
    oss << "]";
    return oss.str();
}
