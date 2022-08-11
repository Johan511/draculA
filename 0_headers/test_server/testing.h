#pragma once
#include <stdint.h>
#include <string>
class Testing
{
private:
    __UINT16_TYPE__ initial_acknowledgement_number;
    __UINT16_TYPE__ initial_sequence_number;
    std::string message;

public:
    int number_of_times;

    __UINT16_TYPE__ getAckNum();
    __UINT16_TYPE__ getSeqNum();
    std::string getmessage();
    Testing(__UINT16_TYPE__ inital_acknowledgement_number, __UINT16_TYPE__ initial_sequence_number, std::string message, int number_of_times);
    Testing(std::string message);

    ~Testing();

    bool send();
    int spam();

    bool generate_message(char *buffer, __U16_TYPE acknowledgement_number, __U16_TYPE sequence_number);
    static std::string int16toDoubleChar(__U16_TYPE number);

protected:
};