#include "BasicDataBase.h"

string BasicDataBase::operatorBrandName(const string &id) {
    unordered_map<string, string> BRAND_NAME_MAP = {
            {"NULL",  "NULL"},
            {"42500", "Cellcom"},
            {"42501", "Partner"},
            {"42502", "Rami levi"},
            {"42503", "pelephone"},
            {"42504", "012"}
    };
    return BRAND_NAME_MAP[id];
}