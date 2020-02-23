#include <stdio.h>
#include <cs50.h>
#include <string.h>



int main (int key, string argc[]){

    //int key = get_int("Key to encode: ");
    string plaintext = get_string("Put text to encrypt: ");
    int n = strlen(plaintext);

    char realCiphertext[n + 1];
    int ciphertext[n];

    for (int i = 0; i < n; i++) {
        ciphertext[i] = (int) plaintext[i];
        if(ciphertext[i] != 44){
        ciphertext[i] += key;
        } else {
        ciphertext[i] = (int) plaintext[i];
        }
        //ciphertext[i] = ciphertext[i] % 26;
        realCiphertext[i] = (char)ciphertext[i];
    }
        realCiphertext[n + 1] = '\0';

    //printf("%d\n", plaintext[0]);
    printf("%s\n", realCiphertext);
    printf("%d\n", key);
}
