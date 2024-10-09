#include <iostream>
#include "VigenerCipher.h"

using namespace std;

void vigenerCipherRealization()
{
    string key, value;
    cout << "Введите ключ: ";
    cin >> key;
    VigenerCipher vigenerCipher(key);
    cout << "Введите строку или \"exit\", если хотите закончить программу: ";
    cin >> value;
    while (value != "exit")
    {
        cout << endl << "Зашифровка: " << vigenerCipher.decode(value) << endl;
        cout << "Введите строку или \"exit\", если хотите закончить программу: ";
        cin >> value;
    }
}


//int main()
//{
//    setlocale(LC_ALL, "Rus");
//    //vigenerCipherRealization();
//}
//
