#include "acutest.h"
#include "SurveyClass.h"

void constructs_without_crashing() {
    SurveyClass surveyClass;
    TEST_CHECK(surveyClass.members != nullptr);
    TEST_CHECK(surveyClass.members->length == 0);
}

void add_one_record() {
    SurveyClass surveyClass;
    surveyClass.handleNewRecord("a", 1.0f);
    Node *first = surveyClass.members->head;

    TEST_CHECK(first->name == "a");
    TEST_CHECK(first->amount == 1.0f);
    TEST_CHECK(surveyClass.members->length == 1);
}

void add_two_records() {
    SurveyClass surveyClass;
    surveyClass.handleNewRecord("a", 1.0f);
    surveyClass.handleNewRecord("b", 2.0f);
    Node *first = surveyClass.members->head;
    Node *second = first->next;

    TEST_CHECK(first->name == "a");
    TEST_CHECK(first->amount == 1.0f);
    TEST_CHECK(second->name == "b");
    TEST_CHECK(second->amount == 2.0f);
    TEST_CHECK(surveyClass.members->length == 2);
}

void min_1_2_equals_1() {
    SurveyClass surveyClass;
    surveyClass.handleNewRecord("a", 1.0f);
    surveyClass.handleNewRecord("b", 2.0f);
    TEST_CHECK(surveyClass.calculateMinimumExpense() == 1.0f);
}

void min_1_2_equals_2() {
    SurveyClass surveyClass;
    surveyClass.handleNewRecord("a", 1.0f);
    surveyClass.handleNewRecord("b", 2.0f);
    TEST_CHECK(surveyClass.calculateMaximumExpense() == 2.0f);
}

void min_empty_0() {
    SurveyClass surveyClass;
    TEST_CHECK(surveyClass.calculateMinimumExpense() == 0.0f);
}

void max_empty_0() {
    SurveyClass surveyClass;
    TEST_CHECK(surveyClass.calculateMaximumExpense() == 0.0f);
}

void avg_empty_0() {
    SurveyClass surveyClass;
    TEST_CHECK(surveyClass.calculateAverageExpense() == 0.0f);
}

void avg_correct() {
    float vals[] = {1.2f, 6.5f, 700.2, 800.3};
    float expectedAvg = (1.2f + 6.5f + 700.2f + 800.3f) / 4.0f;
    SurveyClass surveyClass;
    surveyClass.handleNewRecord("a", vals[0]);
    surveyClass.handleNewRecord("b", vals[1]);
    surveyClass.handleNewRecord("c", vals[2]);
    surveyClass.handleNewRecord("d", vals[3]);
    TEST_CHECK(surveyClass.calculateAverageExpense() == expectedAvg);
}

void copy_empty() {
    SurveyClass first;
    SurveyClass second = first;
    TEST_CHECK(first.members != second.members); // check deep copy
    TEST_CHECK(first.members->length == second.members->length); // check deep copy
}

void copy_one_item() {
    SurveyClass first;
    first.handleNewRecord("a", 1);
    SurveyClass second = first;
    TEST_CHECK(first.members != second.members); // check deep copy
    TEST_CHECK(first.members->length == second.members->length); // check deep copy
    TEST_CHECK(first.members->head->name == second.members->head->name); // check deep copy
    TEST_CHECK(first.members->head->amount == second.members->head->amount); // check deep copy
}

void move_empty() {
    SurveyClass first;
    SurveyClass second = std::move(first);
    TEST_CHECK(first.members == nullptr);
    TEST_CHECK(second.members != nullptr);
    TEST_CHECK(second.members->length == 0);
}

void move_one_item() {
    SurveyClass first;
    first.handleNewRecord("a", 1);
    auto oldMembers = first.members;
    SurveyClass second = std::move(first);
    TEST_CHECK(first.members == nullptr);
    TEST_CHECK(second.members == oldMembers);
    TEST_CHECK(second.members->head == oldMembers->head);
    TEST_CHECK(second.members->head->name == oldMembers->head->name);
    TEST_CHECK(second.members->head->amount == oldMembers->head->amount);
}
TEST_LIST = {
        {"Constructs without crashing",  constructs_without_crashing},
        // copy
        {"Copies empty survey class", copy_empty},
        {"Copies survey class with one item", copy_one_item},
        // move
        {"Moves empty survey class", move_empty},


        {"Can add record (a, 1)",        add_one_record},
        {"Can add record (a, 1) (b, 2)", add_two_records},
        {"Avg of empty is 0",            avg_empty_0},
        {"Avg is correct",            avg_correct},
        {"Min of empty is 0",            min_empty_0},
        {"Max of empty is 0",            max_empty_0},
        {"Min of 1 and 2 is 1",          min_1_2_equals_1},
        {"Max of 1 and 2 is 2",          min_1_2_equals_2},
        {0}
};
