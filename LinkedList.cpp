#include "LinkedList.h"
#include <assert.h>


LinkedList::LinkedList() {
    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::LinkedList(const LinkedList &list) {
//    cerr << "Copy called" << endl;
    this->length = list.length;
    if(list.length == 0) {
        // do nothing
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }

    this->head = new Node(*(list.head));

    auto lastNode = &(this->head);
    while((*lastNode)->next != nullptr) {
        lastNode = &((*lastNode)->next);
    }

    this->tail = (*lastNode);
}

LinkedList &LinkedList::operator=(const LinkedList &list) {
//    cerr << "Copy (=) called" << endl;
    this->length = list.length;
    if(list.length == 0) {
        // do nothing
        this->head = nullptr;
        this->tail = nullptr;
        return *this;
    }

    this->head = new Node((*list.head));

    auto lastNode = &(this->head);
    while((*lastNode) != nullptr) {
        lastNode = &((*lastNode)->next);
    }

    this->tail = (*lastNode);
    return *this;
}

LinkedList::LinkedList(LinkedList &&list) {
//    cerr << "Move called" << endl;

}

LinkedList &LinkedList::operator=(LinkedList &&list) {
    return *(new LinkedList());
}

void LinkedList::pushTail(string _name, float _amount) {
    this->length++;
    if(this->head == nullptr) {
        this->tail = this->head = new Node(_name, _amount);
        return;
    }

    auto lastNode = &(this->head);
    while((*lastNode) != nullptr) {
        lastNode = &((*lastNode)->next);
    }
    (*lastNode) = new Node(_name, _amount);
    this->tail = *lastNode;
}

void LinkedList::updateNode(string _name, float _amount) {
    // do nothing if empty list
    if(this->head == nullptr)  {
//        std::cerr << "List is empty" << std::endl;
        return;
    }

    auto node = &(this->head);
    while((*node) != nullptr && (*node)->name != _name) {
        node = &((*node)->next);
    }

    if((*node) == nullptr) {
//        std::cerr << "Could not find node of name " << _name << std::endl;
        return;
    }

    (*node)->amount = _amount;

}


LinkedList::~LinkedList() {
    // it is enough to delete this->head as that will
    // call the destructor of the Node in this->head
    // which will itself call the destructor of its next node
    // until the end of the linked llist
    delete this->head;
}
