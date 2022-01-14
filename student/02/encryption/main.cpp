#include <iostream>
#include <cctype>

using namespace std;

static string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

bool key_tester(string key) // Tests the encryption key
{

    static int ALPHABET_SIZE = 26;
    string::size_type length = ALPHABET_SIZE;

    if ( key.length() != length )
    {
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return false;
    }

    for ( int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if ( isupper(key.at(i)) )
        {
            cout << "Error! The encryption key must only contain " <<
                    "lower case characters." << endl;
            return false;
        }
    }



    for ( int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if ( key.find(ALPHABET.at(i)) == string::npos )
        {
            cout << "Error! The encryption key must contain all alphabets a-z." <<
                    endl;
            return false;
        }
    }


    return true;

}

bool text_tester(string text)
{
    for ( string::size_type i = 0; i < text.length(); ++i )
    {
        if ( isupper(text.at(i)) )
        {
            cout << "Error! The text to be encrypted must only contain " <<
                    "lower case characters." << endl;
            return false;
        }
    }
    return true;
}

char encrypt_char(char character, string key)
{
    int i = ALPHABET.find(character);
    return key.at(i);
}

string encrypt_str(string text, string key)
{
    string encrypted_text = text;

    for ( string::size_type i = 0; i < text.length(); ++i)
    {
        encrypted_text.at(i) = encrypt_char(text.at(i), key);
    }

    return encrypted_text;
}

int main()
{
    cout << "Enter the encryption key: ";
    string enc_key = "abcdefghijklmnopqrstuvwxyz";
    cin >> enc_key;

    if ( !key_tester(enc_key) )
        return EXIT_FAILURE;

    cout << "Enter the text to be encrypted: ";
    string text = "abc";
    cin >> text;

    if ( !text_tester(text) )
        return EXIT_FAILURE;

    cout << "Encrypted text: " << encrypt_str(text, enc_key) << endl;


    return EXIT_SUCCESS;
}
