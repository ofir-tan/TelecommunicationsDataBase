#include "CustomerBilling.h"

void CustomerBilling::update(const Record &data) {
    switch (data.callType) {
        case MOC: // outgoing voice call.
            if (data.sameOperator())
                withinMobileOperator.outgoing.voiceCall += data.duration;
            else
                outsideMobileOperator.outgoing.voiceCall += data.duration;
            break;
        case MTC: // incoming voice call.
            if (data.sameOperator())
                withinMobileOperator.incoming.voiceCall += data.duration;
            else
                outsideMobileOperator.incoming.voiceCall += data.duration;
            break;
        case SMS_MO: // outgoing message.
            if (data.sameOperator())
                withinMobileOperator.outgoing.message += 1;
            else
                outsideMobileOperator.outgoing.message += 1;
            break;
        case SMS_MT: // incoming message.
            if (data.sameOperator())
                withinMobileOperator.incoming.message += 1;
            else
                outsideMobileOperator.incoming.message += 1;
            break;
        case GPRS: // internet.
            dataUsed.uploaded += data.upload;
            dataUsed.downloaded += data.download;
            break;
    }
}

ostream &operator<<(ostream &os, const CustomerBilling &billing) {
    os << "Customer ID: " << billing.customerID << " ("
       << CustomerBilling::operatorBrandName(billing.operatorID) << ")" << endl;
    //
    os << "\t* Services within the mobile operator *" << endl;
    os << "\tIncoming voice call durations: "
       << billing.withinMobileOperator.incoming.voiceCall << endl;
    os << "\tOutgoing voice call durations: "
       << billing.withinMobileOperator.outgoing.voiceCall << endl;
    os << "\tIncoming SMS messages: "
       << billing.withinMobileOperator.incoming.message << endl;
    os << "\tOutgoing SMS messages: "
       << billing.withinMobileOperator.outgoing.message << endl;
    //
    os << "\t* Services outside the mobile operator *" << endl;
    os << "\tIncoming voice call durations: "
       << billing.outsideMobileOperator.incoming.voiceCall << endl;
    os << "\tOutgoing voice call durations: "
       << billing.outsideMobileOperator.outgoing.voiceCall << endl;
    os << "\tIncoming SMS messages: "
       << billing.outsideMobileOperator.incoming.message << endl;
    os << "\tOutgoing SMS messages: "
       << billing.outsideMobileOperator.outgoing.message << endl;
    //
    os << "\t* Internet use *" << endl;
    os << "\tMB downloaded: "
       << billing.dataUsed.downloaded << " | ";
    os << "MB uploaded: "
       << billing.dataUsed.uploaded << endl;
    return os;
}

