#ifndef MAIN_CPP_CIPHERTEXT_H
#define MAIN_CPP_CIPHERTEXT_H
#include <iostream>

using namespace std;

string encrypt_text(string message,string passcode);
void decrypt_text(string& message, string cipher, string passcode);
void goodBye();
#endif //MAIN_CPP_CIPHERTEXT_H