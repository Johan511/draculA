#include "../0_headers/test_server/testing.h"
#include <iostream>
__UINT16_TYPE__ Testing::getAckNum()
{
    return this->initial_acknowledgement_number;
}

__UINT16_TYPE__ Testing::getSeqNum()
{
    return this->initial_sequence_number;
}

Testing::Testing(std::string message)
{
    this->message = message;
}

Testing::Testing(__UINT16_TYPE__ inital_acknowledgement_number, __UINT16_TYPE__ initial_sequence_number, std::string message, int number_of_times)
{
    // std::cout << inital_acknowledgement_number << std::endl;
    this->initial_acknowledgement_number = inital_acknowledgement_number;
    this->initial_sequence_number = initial_sequence_number;
    this->message = message;
    this->number_of_times = number_of_times;
}

Testing::~Testing()
{
}

std::string Testing::getmessage()
{
    return message;
}

bool Testing::generate_message(char *buffer, __U16_TYPE acknowledgement_number, __U16_TYPE sequence_number)
{
    std::string acknowledgement_double_char = int16toDoubleChar(acknowledgement_number);
    std::string sequence_double_char = int16toDoubleChar(sequence_number);
    buffer[0] = acknowledgement_double_char[0];
    buffer[1] = acknowledgement_double_char[1];
    buffer[2] = sequence_double_char[0];
    buffer[3] = sequence_double_char[1];

    int i = 0;
    for (; i < message.size(); i++)
    {
        buffer[i + 4] = message[i];
    }
    buffer[i + 4] = '\0';
    return true;
}

std::string Testing::int16toDoubleChar(__U16_TYPE number)
{
    std::string doubleChar;
    doubleChar = doubleChar + (char)(number >> 8);
    doubleChar = doubleChar + (char)((number << 8) >> 8);
    std::cout << number << std::endl;
    return doubleChar;
}