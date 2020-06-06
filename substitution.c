#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // If no command line arguments entered
    if (argc != 2)
    {
        // Print usage instructions to user
        printf("Usage: ./substition KEY\n");
        return 1;
    }

    // Get key from command line arguments
    string key = argv[1];

    // Calculate key length as reused several times
    int key_length = strlen(key);

    // Key Validation - Key must contain 26 characters
    if (key_length != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // Key Validation - Key must only contain alphabetic charaters
    for (int i = 0; i < key_length; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain alphabetic charaters\n");
            return 1;
        }
    }

    // Key Validation - Key must not contain repeated characteres
    int char_count[26] = {0};
    for (int i = 0; i < key_length; i++)
    {
        if (char_count[tolower(key[i]) - 97] > 0)
        {
            printf("Key must not contain repeated characters\n");
            return 1;
        }
        else
        {
            char_count[tolower(key[i]) - 97]++;
        }
    }

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");
    int text_length = strlen(plaintext);

    // Encipher plain text
    char ciphertext[text_length + 1];
    for (int i = 0; i < text_length; i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(key[plaintext[i] - 65]);
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(key[plaintext[i] - 97]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // Add null char to end of ciphertext
    ciphertext[text_length] = '\0';

    // Print ciphertext
    printf("ciphertext: %s\n", ciphertext);
}