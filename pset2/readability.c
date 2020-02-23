#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main (void) {

    string input = get_string("Type in a article: ");
    int n = strlen(input);
    int letters = 0;
    int words = 1;
    int sentence = 0;

    float index = 0;


    int a = 32;
    int b = 33;
    int c = 44;
    int d = 46;
    int e = 63;

    printf("%s\n", input);
    for (int i = 0; i < n; i++){

    if  ( (input[i] !=  a)  &&
          (input[i] !=  b)  &&
          (input[i] !=  c)  &&
          (input[i] !=  d)  &&
          (input[i] !=  e) ) {

                letters++;
    } else {
                if( (input[i] ==  b) ||
                    (input[i] ==  d) ||
                    (input[i] ==  e) ){
                        sentence++;
         } else if(input[i] ==  a){
                        words++;
        } else {
                sentence+=0;
                words+=0;
                    }
                letters+=0;
    }
}

    printf("Letters: %d\n", letters);
    printf("Words: %d\n", words);
    printf("Sentences: %d\n", sentence);

    float lettersF = (float) letters;
    float wordsF = (float) words;
    float sentenceF = (float) sentence;

    float hundredValue = 100/wordsF;

    index = (0.0588 * letters * hundredValue) - (0.296 * sentence * hundredValue) - 15.8;

    float roundf(float index);

    if(index < 1) {
    printf("Before Grade 1\n");
    }else if (index > 16){
    printf("Grade 16+\n");
    }else {
    printf("Grade: %.0f\n", index);
    }
}
