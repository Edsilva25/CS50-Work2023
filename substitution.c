#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Function to validate the substitution key
bool validate_key(const char *key)
{
    int freq[26] = {0};
    int len = strlen(key);

    // Key must be of length 26
    if (len != 26)
    {
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        // Key must contain only alphabetic characters
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = tolower(key[i]) - 'a';
        // Each letter in the key must be unique
        if (freq[index] > 0)
        {
            return false;
        }

        freq[index]++;
    }

    return true;
}

// Function to encrypt a character using the substitution key
char encrypt(char ch, const char *key)
{
    if (isalpha(ch))
    {
        bool is_uppercase = isupper(ch);
        int index = tolower(ch) - 'a';
        char encrypted_ch = tolower(key[index]);
        return is_uppercase ? toupper(encrypted_ch) : encrypted_ch;
    }
    return ch;
}

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    char *key = argv[1];

    // Validate the key
    if (!validate_key(key))
    {
        printf("Invalid key\n");
        return 1;
    }

    printf("plaintext: ");
    char plaintext[100];
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++)
    {
        char encrypted_ch = encrypt(plaintext[i], key);
        printf("%c", encrypted_ch);
    }
    printf("\n");

    return 0;
}
