#include "SurveyClass.h"

float _round(const float& x) {
    return ((int) (x * 100.0f)) / 100.0f;
}

SurveyClass::SurveyClass() {
    this->members = new LinkedList;
}

SurveyClass::SurveyClass(const SurveyClass &other) {
    this->members = new LinkedList((*other.members));
}

SurveyClass &SurveyClass::operator=(const SurveyClass &list) {
    if (this == &list) return *this;
    
    // delete if existing already
    delete this->members;
    this->members = new LinkedList((*list.members));
    
    return *this;
}

SurveyClass::SurveyClass(SurveyClass &&other) {
    std::swap(other.members, this->members);
}

SurveyClass &SurveyClass::operator=(SurveyClass &&list) {
    std::swap(list.members, this->members);
    return *this;
}

SurveyClass::~SurveyClass() {
    delete members;
}

void SurveyClass::handleNewRecord(string _name, float _amount) {
    members->updateNode(std::move(_name), _amount);
}

float SurveyClass::calculateMinimumExpense() {
    if (members->length == 0) return 0.0f;
    float min = members->head->amount;
    Node *head = members->head;
    while (head != nullptr) {
        min = min > head->amount ? head->amount : min;
        head = head->next;
    }
    min = _round(min);
    return min;
}


float SurveyClass::calculateMaximumExpense() {
    if (members->length == 0) return 0.0f;
    float max = members->head->amount;
    Node *head = members->head;
    while (head != nullptr) {
        max = max < head->amount ? head->amount : max;
        head = head->next;
    }
    max = _round(max);
    return max;
}

float SurveyClass::calculateAverageExpense() {
    if (members->length == 0) return 0.0f;

    float sum = 0.0f;
    Node *head = members->head;
    while (head != nullptr) {
        sum += head->amount;
        head = head->next;
    }
    sum /= (float) members->length;
    sum = _round(sum);
    return sum;
}
