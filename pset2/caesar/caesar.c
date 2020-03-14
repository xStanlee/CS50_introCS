#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>



int main (int argc, char *argv[]){

    if (argc != 2)
    {
        printf("Usage: ./Caesar [ENCRYPT]\n");
        return 1;
    }

    string plaintext = get_string("Put text to encrypt: ");
    int n = strlen(plaintext);
    int crypt = atoi(argv[1]);
    char realCiphertext[n + 1];
    int ciphertext[n];

    for (int i = 0; i < n; i++) {
        ciphertext[i] = (int) plaintext[i];
        if(ciphertext[i] != 44){
        ciphertext[i] += crypt;
        } else {
        ciphertext[i] = (int) plaintext[i];
        }
        realCiphertext[i] = (char)ciphertext[i];
    }
        realCiphertext[n + 1] = '\0';

    printf("Output encrypted text: %s\n", realCiphertext);
}
