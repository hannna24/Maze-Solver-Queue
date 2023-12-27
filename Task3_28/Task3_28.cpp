#include <iostream>
#include <string>

using namespace std;

const int a = 11;
const int b = 17;
const int m = 90;
char arr[] = { 'b', 'B','c','C','d','D','J','j','z','Z','y','Y','W','w','x','X','q','Q' };


string encryptMessage(const string msg)
{

    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (msg[i] == arr[j]) {
                cerr << "invalid message" << endl;
                return "";
            }
        }
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
            (char)(((a_inv * ((cipher[i] - '!' - b + m)) % m) + '!'));
        else
            msg += ' ';
    }

    return msg;
}

int main()
{
    string message;                         // ="QU TE INU KOFE I LE TAEAO";
    cout << "Enter the message" << endl;
    getline(cin, message);

    cout << "Original Message: " << message << endl;
    string encryptedMessage = encryptMessage(message);

    if (encryptedMessage != "")
    {
        cout << "Encrypted Message: " << encryptedMessage << endl;

        string encryptedMessage2 = decryptCipher(encryptedMessage);
        cout << "Encrypted Message: " << encryptedMessage2 << endl;
    }
}