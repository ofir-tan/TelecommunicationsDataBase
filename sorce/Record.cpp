#include "Record.h"

Record::Record(const vector<string> &cdrRecord) {
    if(cdrRecord.empty()) return;
    unordered_map<string, CallType> toEnum{{"MOC",    MOC},
                                           {"MTC",    MTC},
                                           {"SMS-MO", SMS_MO},
                                           {"SMS-MT", SMS_MT},
                                           {"GPRS",   GPRS}};
    id = cdrRecord[0];
    operatorBrand = cdrRecord[1];
    operatorID = cdrRecord[2];
    callType = toEnum[cdrRecord[3]];
    duration = stoi(cdrRecord[4]);
    download = stoi(cdrRecord[5]);
    upload = stoi(cdrRecord[6]);
    otherID = cdrRecord[7];
    otherOperatorID = cdrRecord[8];
}