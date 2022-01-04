#pragma once
struct ServicesTypes {
    unsigned int voiceCall{};
    unsigned int message{};
};

struct Services {
    ServicesTypes incoming;
    ServicesTypes outgoing;
};