#include <stdio.h>
#include <cs50.h>
#include <math.h>

    int main (void) {


        long card = get_long("CARD ID: ");
        long valueOfCard = card;
        long cardValue = card;
        long visa = card;
        long count = 0;

                while(valueOfCard != 0){
                valueOfCard /= 10;
                count++;
            }
        cardValue = cardValue / (pow  (10, (count - 2)));
        visa = visa / (pow  (10, (count - 1)));
        long fullValidation = 0;
            for(int i = count; i > 0; i = i - 1){
                if(i % 2 == 0)  {
                    fullValidation = fullValidation + (card % 10);
                    card /= 10;
                } else {
                    if(2*((card % 10)) < 10) {
                    fullValidation = fullValidation + 2*((card % 10));
                    card /= 10;
                    } else {
                    fullValidation = fullValidation + ((2*((card % 10))) % 10) + 1;
                    card /= 10;
                    }
                }
            }
            if (fullValidation % 2 == 0 && (count == 13 || count == 15 || count == 16)) {
                printf("CARD STATUS: VALID\n");
                if(count == 15 && (cardValue == 34 || cardValue == 37)){
                printf("TYPE OF CARD: AMEX\n");
                }
                else if (count == 16 &&
                (cardValue == 51 || cardValue == 52 ||
                cardValue == 53 || cardValue == 54 ||
                cardValue == 55)){
                printf("TYPE OF CARD: MASTERCARD\n");
                } else if (visa == 4 && (count == 13 || count == 16)){
                printf("TYPE OF CARD: VISA\n");
                } else {
                printf("SOMETHING WENT WRONG!\n");
                }
            }else {
                printf("CARD STATUS: INVALID\n");
            }
    }
