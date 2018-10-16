#include "SurveyClass.h"
#include <limits>

SurveyClass::SurveyClass() {
    members = new LinkedList;
}

SurveyClass::SurveyClass(const SurveyClass &other) {

}

SurveyClass &SurveyClass::operator=(const SurveyClass &list) {
    return *this;
}

SurveyClass::SurveyClass(SurveyClass &&other) {

}

SurveyClass &SurveyClass::operator=(SurveyClass &&list) {
    return *this;
}

SurveyClass::~SurveyClass() {
    delete members;
}

void SurveyClass::handleNewRecord(string _name, float _amount) {
    members->pushTail(_name, _amount);
}

float SurveyClass::calculateMinimumExpense() {
    if(members->length == 0) return 0.0f;
    float min = numeric_limits<float>::max();
    Node* head = members->head;
    while(head != nullptr){
        min = min > head->amount ? head->amount : min;
        head = head->next;
    }
    return min;
}

float SurveyClass::calculateMaximumExpense() {
    if(members->length == 0) return 0.0f;
    float max = -numeric_limits<float>::max();
    Node* head = members->head;
    while(head != nullptr){
        max = max < head->amount ? head->amount : max;
        head = head->next;
    }
    return max;
}

float SurveyClass::calculateAverageExpense() {
    if(members->length == 0) return 0.0f;

    float sum = 0.0f;
    Node* head = members->head;
    while(head != nullptr) {
        sum += head->amount;
        head = head->next;
    }
    sum /= (float) members->length;
    return sum;
}
