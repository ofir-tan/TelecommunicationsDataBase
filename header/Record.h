#pragma once
#include "string"
#include "vector"
#include "unordered_map"
#include "CallType.h"

using namespace std;

struct Record {
    // constructor:
    explicit Record(const vector<string> &cdrRecord);

    // members:
    string id;
    string operatorBrand;
    string operatorID;
    enum CallType callType;
    unsigned int duration;
    unsigned int download;
    unsigned int upload;

    // corresponding third party in this call:
    string otherID;
    string otherOperatorID;

    // methods:
    [[nodiscard]] bool empty() const { return id.empty(); }
    [[nodiscard]] bool sameOperator() const { return operatorID == otherOperatorID; };
};