#include <iostream>
#include <string>

using namespace std;

const int a = 7;
const int b = 13;
const int m = 90;


string encryptMessage(const string msg)
{

    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] == ' ')
        {
            cipher = cipher + '0';

        }
        else
        {
            cipher = cipher +
                (char)((((a * (msg[i] - '!')) + b) % m) + '!');
        }
    }
    return cipher;
}

string decryptCipher(string cipher)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;


    for (int i = 0; i < m; i++)
    {
        flag = (a * i) % m;


        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if (cipher[i] != '0')

            msg = msg +
            (char)(((a_inv * (cipher[i] - '!' - b + m) % m) + '!'));
        else
            msg += ' ';
    }

    return msg;
}

int main()
{
    do
    {
        string message;
        cout << "Enter the message: ";
        getline(cin, message);
        cout << endl;

        cout << "Original Message: " << message << endl;
        string encryptedMessage = encryptMessage(message);

        if (encryptedMessage != "")
        {
            cout << "Encrypted Message: " << encryptedMessage << endl;

            string encryptedMessage2 = decryptCipher(encryptedMessage);
            cout << "Encrypted Message: " << encryptedMessage2 << endl;
        }
        char x;
        cout << " if you want to exit press q " << endl;
        cin >> x;
        if (x == 'q')
            break;
        else
            continue;
    } while (true);

    /*
    int option;
    string message;
    string encryptedMessage;
    do
    {
        cout << "------------------------------------------------------" << endl;
        cout << "what operation do you want to perform? " << endl << "select option number.Enter 0 to exit" << endl;
        cout << "1. Enter new message" << endl;
        cout << "2. Encrypt()" << endl;
        cout << "3. Decrypt()" << endl;
        cout << "------------------------------------------------------" << endl;
        cin >> option;


        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the message: ";
            getline(cin, message);
            cout << endl;
            break;
        case 2:
            cout << "Original Message: " << message << endl;
            encryptedMessage = encryptMessage(message);
            if (encryptedMessage != "")
            {
                cout << "Encrypted Message: " << encryptedMessage << endl;
            }
            break;
        case 3:
            cout << "Original Message: " << message << endl;
            if (encryptedMessage != "")
            {
                cout << "Encrypted Message: " << encryptedMessage << endl;
                string encryptedMessage2 = decryptCipher(encryptedMessage);
                cout << "Encrypted Message: " << encryptedMessage2 << endl;
            }
            break;
        }

    } while (option != 0);*/
}