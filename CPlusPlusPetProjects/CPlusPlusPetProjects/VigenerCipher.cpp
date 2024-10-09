#include "VigenerCipher.h"


VigenerCipher::VigenerCipher() {}

VigenerCipher::VigenerCipher(string key) 
{
    setKey(key);
}

void VigenerCipher::setKey(string value)
{
    key = "";
    for (char i : value)
        if ('a' <= i && i <= 'z' || 'A' <= i && i <= 'Z')
            key += tolower(i);
    keyIndex = 0;
}

char VigenerCipher::getDecodingChar(char value)
{
    if ('a' <= value && value <= 'z')
        return toLowerAscii((toIndexInAlphabet(getNextKeyChar()) + toIndexInAlphabet(value)) % getAlphabetsLength());
    if ('A' <= value && value <= 'Z')
        return toUpperAscii((toIndexInAlphabet(getNextKeyChar()) + toIndexInAlphabet(value)) % getAlphabetsLength());
    return value;
}

string VigenerCipher::decode(string value)
{
    if (key == "")
        key = "a";
    string result;
    for (int i = 0; i < value.length(); i++)
        result += getDecodingChar(value[i]);
    return result;
}

int VigenerCipher::getAlphabetsLength()
{
    return 'z' - 'a' + 1;
}

char VigenerCipher::getNextKeyChar()
{
    int value = key[keyIndex];
    keyIndex = ++keyIndex % key.size();
    return value;
}

int VigenerCipher::toIndexInAlphabet(char value)
{   
    return tolower(value) - 'a';
}

char VigenerCipher::toLowerAscii(int value)
{
    return value + 'a';
}

char VigenerCipher::toUpperAscii(int value)
{
    return value + 'A';
}