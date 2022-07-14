#include "ciphertext.h"

// FUNCTION 1
string encrypt_text(string message,string passcode) {
    string cipher= "";                                                                                  // Declaring and assigning an empty string to cipher.
    int spaces = 0;                                                                                     // Initializing the space to be zero, counts the spaces in the text.
    for (int i = 0; i < message.length(); i++) {                                                        // Starting a for loop to check the length of the message.
        int passcode_index = (i - spaces) % passcode.length();                                          // Subtracting the spaces from the counter(i) and modding it by n so that we can find the index of the passcode.
        char passcode_letter = toupper(passcode[passcode_index]);                                       // Capitalizing the letters of the passcode (since each alphabet has a different ascii value).
        int offset_value = passcode_letter - 65;                                                        // We want the passcode to rotate it back to the initial letter.
        char curr_letter = toupper(message[i]);                                                         // Capitalizing the letters of the text entered (since each alphabet has a different ascii value).
        int curr_ascii_value = curr_letter + offset_value;                                              // Checking the ASCII value, if it is under 95 or over, so we could loop it further.

        if (!isalpha(curr_letter)) {                                                                    // Checking if there are any characters other than alphabets.
            spaces++;
            cipher += curr_letter;                                                                      // If it is not a character just add it to the cipher without changing the value.
        } else {
            if (curr_ascii_value >= 91) {                                                               // If the letters go over 'Z' we need it to go back to 'A' and start from there.
                curr_ascii_value = curr_ascii_value % 91 + 65;                                          // 95 is the ASCII value of 'Z' and 65 is ASCII value of 'A'.
            }
            char curr_encrypted_letter = char(curr_ascii_value);
            cipher += curr_encrypted_letter;                                                            // Storing and adding each letter into cipher.
        }

    }
    cout << "The encrypted message is : " << cipher;
    cout<< endl;
    return cipher;                                                                                      // Returning the value of Cipher.

}


// FUNCTION 2
void decrypt_text(string &message, string cipher, string passcode) {

    int spaces = 0;
    for (int i = 0; i < cipher.length(); i++) {
        int passcode_index = (i - spaces) % passcode.length();
        char passcode_letter = toupper(passcode[passcode_index]);
        int offset_value = passcode_letter - 65;
        char curr_letter = toupper(cipher[i]);
        int curr_ascii_value = curr_letter - offset_value;


        if (!isalpha(curr_letter)) {
            spaces++;
            message += curr_letter;
        }
        else {
            if (curr_ascii_value < 65) {                                                                // We check if the char is less than 'A' we want it to loop it back to 'Z'.
                curr_ascii_value += 26;
            }
            char curr_encrypted_letter = char(curr_ascii_value);                                        // Converting ASCII to char.
            message += curr_encrypted_letter;                                                           // Storing it into message
        }

    }
    cout << "Decrypted message: " << message;
    cout << endl;

}


//FUNCTION 3
void goodBye() {
    cout << "Good Bye!" << endl;
}
