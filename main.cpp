#include <iostream>
#include <cctype>
#include "ciphertext.h"


using namespace std;
int main() {
    string message, passcode, cipher, command;

    cout << "Welcome to the SMU Encryption Engine!" << endl;
    cout << endl;
    cout << "Do you want to ENCRYPT, DECRYPT, OR QUIT " << endl;

    while (command != "QUIT" || command != "quit")                               //Looping until quit is entered
    {
        cout << "Please Enter a command: ";
        getline(cin, command);
        cout << endl;

        if (command == "ENCRYPT" || command == "encrypt") {                     //Function 1
            //Encryption of the text, by using pass by value.
            cout << "Enter the message to be encrypted: ";
            getline(cin, message);

            cout << endl;
            cout << "Enter passcode ";
            getline(cin, passcode);

            cout << endl;
            cout << "Encrypting your message ........ " << endl;
            cout << endl;
            cipher = encrypt_text(message, passcode);            //Function call
            cout
                    << endl;                                                       //Just extra empty lines to make the output look readable
        } else if (command == "DECRYPT" || command == "decrypt") {                //Function 2
            // Decryption of the text, bvy using pass by reference
            cout << "Enter the cipher to be decrypted: ";
            getline(cin, cipher);

            cout << endl;

            cout << "Enter passcode ";
            getline(cin, passcode);

            cout << "Decrypting your message..." << endl;
            cout << endl;

            message = "";                                                       //Assigning message an empty string
            decrypt_text(message, cipher, passcode);                           //Function call

            cout << endl;
        } else if (command == "QUIT" || command == "quit") {                      //Function 3
            goodBye();                                                          //Function call
            break;
        } else {

            cout << command << " is not a valid input!"
                 << endl;                  //If the command is none of the three, then it is invalid
            cout << "Please enter ENCRYPT / DECRYPT / QUIT." << endl;
            cout << endl;
        }
    }

    return 0;
}
