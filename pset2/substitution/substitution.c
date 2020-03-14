// small letters

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void) {

        string key = get_string("Put the key on: ");
        int n = strlen(key);

            while(n != 26) {
            printf("KEY IS INVALID! IT HAS TO HAVE 26 LENGTH OF LETTERS\n");
            key = get_string("Try again! :");
            n = strlen(key);
        }

            for (int i = 0; i < n; i++){
                while(!isalpha(key[i])) {
                printf("KEY IS INVALID! SHOULD BE BUILD ONLY BY LETTERS\n");
                key = get_string("Try again! :");
            }
        }
            for(int i = n; i >= 0; i--){
                for(int j = i-1; j >= 0; j--){
                while(!(key[i] != key[j])){
                    printf("KEY IS INVALID! YOU DUPLICATE LETTER SOMEWHERE\n");
                    key = get_string("Try again! :");
                }
                }
            }

            for (int i = 0; i < n; i++){
                key[i] = tolower(key[i]);
            }

            string transformFrom = "abcdefghijklmnopqrstuvwxyz";
            int tFF = strlen(transformFrom);
            string plaintext = get_string("Put the text to encrypt: ");
            int plainL = strlen(plaintext);
            char signs[5] = {' ', ',', '.', '!', '?'};

            char temporary[plainL];
            for (int i = 0 ; i < plainL; i++){
                for(int j = 0; j < tFF; j++){

                    if(plaintext[i] == transformFrom[j]){
                        temporary[i] = key[j];
                    }
                    else
                    {
                        for(int k = 0 ; k < 5;  k++)
                        {
                            if(plaintext[i] == signs[k])
                            {
                                temporary[i] = signs[k];
                            }


                    }
              }
      } 

}


printf("Encrypted text: %s\n", temporary);
}
