#include "OperatorSettlement.h"

void OperatorSettlement::update(const Record &data) {
    switch (data.callType) {
        case MOC: // outgoing voice call.
            services.outgoing.voiceCall += data.duration;
            break;
        case MTC: // incoming voice call.
            services.incoming.voiceCall += data.duration;
            break;
        case SMS_MO: // outgoing message.
            services.outgoing.message += 1;
            break;
        case SMS_MT: // incoming message.
            services.incoming.message += 1;
            break;
        case GPRS: // internet.
            dataUsed.uploaded += data.upload;
            dataUsed.downloaded += data.download;
            break;
    }
}

ostream &operator<<(ostream &os, const OperatorSettlement &settlement) {
    os << "Operator Brand: "
       << OperatorSettlement::operatorBrandName(settlement.operatorID) << " ("
       << settlement.operatorID << ")" << endl;
    os << "\tIncoming voice call durations: "
       << settlement.services.incoming.voiceCall << endl;
    os << "\tOutgoing voice call durations: "
       << settlement.services.outgoing.voiceCall << endl;
    os << "\tIncoming SMS messages: "
       << settlement.services.incoming.message << endl;
    os << "\tOutgoing SMS messages: "
       << settlement.services.outgoing.message << endl;
    os << "\tMB downloaded: "
       << settlement.dataUsed.downloaded << " | ";
    os << "MB uploaded: "
       << settlement.dataUsed.uploaded << endl;
    return os;
}

