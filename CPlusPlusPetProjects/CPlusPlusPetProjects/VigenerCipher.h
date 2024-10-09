#pragma once

#include <iostream>
#include <string>

using namespace std;

class VigenerCipher
{
public:
    VigenerCipher();
    VigenerCipher(string key);

    void setKey(string value);
    char getDecodingChar(char value);
    string decode(string value);

private:
    string key = "a";
    int keyIndex = 0;

    int getAlphabetsLength();
    char getNextKeyChar();
    int toIndexInAlphabet(char value);
    char toLowerAscii(int value);
    char toUpperAscii(int value);
};
