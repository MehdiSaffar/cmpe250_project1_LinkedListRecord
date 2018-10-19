#include "LinkedList.h"

LinkedList::LinkedList() {
    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::LinkedList(const LinkedList &list) {
    this->length = list.length;
    if (list.length == 0) {
        // do nothing
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }

    this->head = new Node(*(list.head));

    auto lastNode = &(this->head);
    while ((*lastNode)->next != nullptr) {
        lastNode = &((*lastNode)->next);
    }

    this->tail = (*lastNode);
}

LinkedList &LinkedList::operator=(const LinkedList &list) {
    if(this == &list) return *this;

    this->length = list.length;
    if (list.length == 0) {
        // do nothing
        this->head = nullptr;
        this->tail = nullptr;
        return *this;
    }

    this->head = new Node((*list.head));

    auto lastNode = &(this->head);
    while ((*lastNode) != nullptr) {
        lastNode = &((*lastNode)->next);
    }

    this->tail = (*lastNode);
    return *this;
}

LinkedList::LinkedList(LinkedList &&list) {
    std::swap(this->length, list.length);
    std::swap(this->head, list.head);
    std::swap(this->tail, list.tail);
}

LinkedList &LinkedList::operator=(LinkedList &&list) {
    std::swap(this->length, list.length);
    std::swap(this->head, list.head);
    std::swap(this->tail, list.tail);
    return *this;
}

void LinkedList::pushTail(string _name, float _amount) {
    this->length++;
    if (this->head == nullptr) {
        this->tail = this->head = new Node(_name, _amount);
        return;
    }

    this->tail->next = new Node(_name, _amount);
    this->tail = this->tail->next;
}

void LinkedList::updateNode(string _name, float _amount) {
    // do nothing if empty list
    if (this->head == nullptr) {
        pushTail(_name, _amount);
        return;
    }

    auto node = &(this->head);
    while ((*node) != nullptr && (*node)->name != _name) {
        node = &((*node)->next);
    }

    if ((*node) == nullptr) {
        pushTail(_name, _amount);
    } else {
        (*node)->amount = _amount;
    }

}


LinkedList::~LinkedList() {
    // it is enough to delete this->head as that will
    // call the destructor of the Node in this->head
    // which will itself call the destructor of its next node
    // until the end of the linked llist
    delete this->head;
}
