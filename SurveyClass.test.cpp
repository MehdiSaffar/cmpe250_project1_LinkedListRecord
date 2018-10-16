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

TEST_LIST = {
        {"Constructs without crashing",  constructs_without_crashing},
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
