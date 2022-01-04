#pragma once
// Call type: call type one of:
//    - MOC: outgoing voice call.
//    - MTC: incoming voice call.
//    - SMS-MO: outgoing message.
//    - SMS-MT: incoming
enum CallType {
    MOC, MTC, SMS_MO, SMS_MT, GPRS
};