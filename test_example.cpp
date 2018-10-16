#include "acutest.h"
#include "LinkedList.h"

void create_linked_list()
{
    auto linkedList = new LinkedList();
    TEST_CHECK(linkedList != nullptr);
    delete linkedList;
}

void created_linked_list_is_empty()
{
    auto linkedList = new LinkedList();
    TEST_CHECK(linkedList->length == 0);
    delete linkedList;
}

void push_one_item()
{
    auto linkedList = new LinkedList();
    linkedList->pushTail("a", 1);
    TEST_CHECK(linkedList->head->name == "a");
    TEST_CHECK(linkedList->head->amount == 1);
    TEST_CHECK(linkedList->tail == linkedList->head);
    delete linkedList;
}

void push_two_items() {
    auto linkedList = new LinkedList();
    linkedList->pushTail("a", 1);
    linkedList->pushTail("b", 2);
    auto first = linkedList->head;
    auto second = first->next;

    TEST_CHECK(first->name == "a");
    TEST_CHECK(first->amount == 1);
    TEST_CHECK(second->name == "b");
    TEST_CHECK(second->amount == 2);
    TEST_CHECK(linkedList->tail == second);
    delete linkedList;
}

void push_three_items() {
    auto linkedList = new LinkedList();
    linkedList->pushTail("a", 1);
    linkedList->pushTail("b", 2);
    linkedList->pushTail("c", 3);
    auto first = linkedList->head;
    auto second = first->next;
    auto third = second->next;

    TEST_CHECK(first->name == "a");
    TEST_CHECK(first->amount == 1);
    TEST_CHECK(second->name == "b");
    TEST_CHECK(second->amount == 2);
    TEST_CHECK(third->name == "c");
    TEST_CHECK(third->amount == 3);
    TEST_CHECK(linkedList->tail == third);
    delete linkedList;
}

void update_node_in_empty_list_does_nothing() {
    auto linkedList = new LinkedList();
    linkedList->updateNode("a", 1);

    delete linkedList;
}

void updates_node_in_one_node() {
    auto linkedList = new LinkedList();
    linkedList->pushTail("a", 1);
    linkedList->updateNode("a", 2);

    TEST_CHECK(linkedList->head->name == "a");
    TEST_CHECK(linkedList->head->amount == 2);

    delete linkedList;
}

void updates_second_node() {
    auto linkedList = new LinkedList();
    linkedList->pushTail("a", 1);
    linkedList->pushTail("b", 1);
    linkedList->updateNode("b", 2);

    TEST_CHECK(linkedList->head->next->name == "b");
    TEST_CHECK(linkedList->head->next->amount == 2);

    delete linkedList;
}

void destroying_empty_list() {
    auto linkedList = new LinkedList();
    delete linkedList;
}

void copy_operator_works() {
    LinkedList first;
    first.pushTail("a", 1);
    LinkedList second(first);
    // first still exists
    TEST_CHECK(first.head->name == "a");
    TEST_CHECK(first.head->amount == 1);
    TEST_CHECK(first.tail->name == "a");
    TEST_CHECK(first.tail->amount == 1);
    // not same address
    TEST_CHECK(&first != &second);

}

void copy_operator_works_empty_list() {
    LinkedList first;
    LinkedList second(first);
    // first still exists
    TEST_CHECK(first.head == nullptr);
    TEST_CHECK(first.tail == nullptr);
    TEST_CHECK(first.length == 0);
}

void length_works_push() {
    LinkedList list;
    TEST_CHECK(list.length == 0);
    list.pushTail("a", 1);
    TEST_CHECK(list.length == 1);
    list.pushTail("b", 1);
    TEST_CHECK(list.length == 2);
}

void length_works_copy()  {
    LinkedList second;
    second.pushTail("e", 1);
    LinkedList third(second);
    TEST_CHECK(third.length == second.length);
}

TEST_LIST = {
        { "Can create empty LinkedList", create_linked_list },
        { "Empty LinkedList has length == 0 ", created_linked_list_is_empty},
        { "LinkedList with one item (a,1) verifies that property", push_one_item},
        { "Pushes two items", push_two_items},
        { "Pushes three items", push_three_items},
        { "Updating node of empty list does not throw", update_node_in_empty_list_does_nothing},
        { "LinkedList gets its only node updated", updates_node_in_one_node},
        { "Updates second node", updates_second_node},
        { "Destroying empty list", destroying_empty_list},
        { "Copy operator works", copy_operator_works},
        { "Copy operator works on empty list", copy_operator_works_empty_list},
        { "Length reflects true length of list by push", length_works_push},
        { "Length reflects true length of list by copy", length_works_copy},
        { 0 }
};
