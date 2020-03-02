#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height - 1; i++){
        for(int j = 0; j < width; j++){
            int greyScale = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3);
            image[i][j].rgbtRed = greyScale;
            image[i][j].rgbtGreen = greyScale;
            image[i][j].rgbtBlue = greyScale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sRR,sRB,sRG;
    float sGR,sGB,sGG;
    float sBR,sBB,sBG;

    sRR = 0.393;
    sRB = 0.189;
    sRG = 0.769;

    sGR = 0.349;
    sGB = 0.168;
    sGG = 0.686;

    sBR = 0.272;
    sBB = 0.168;
    sBG = 0.534;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
                float sepiaRed = (sRR * image[i][j].rgbtRed/3) + (sRG * image[i][j].rgbtGreen/3) + (sRB * image[i][j].rgbtBlue/3);
                float sepiaBlue = (sBR * image[i][j].rgbtRed/3) + (sBG * image[i][j].rgbtGreen/3) + (sBB * image[i][j].rgbtBlue/3);
                float sepiaGreen = (sGR * image[i][j].rgbtRed/3) + (sGG * image[i][j].rgbtGreen/3) + (sGB * image[i][j].rgbtBlue/3);

                sepiaRed = round(sepiaRed);
                sepiaBlue = round(sepiaBlue);
                sepiaGreen = round(sepiaGreen);

                int sepiaR = sepiaRed;
                int sepiaB = sepiaBlue;
                int sepiaG = sepiaGreen;

                image[i][j].rgbtRed = sepiaR;
                image[i][j].rgbtBlue = sepiaB;
                image[i][j].rgbtGreen = sepiaG;

            if(sepiaR > 255){
                image[i][j].rgbtRed = 255;
            }
            if(sepiaB > 255){
                image[i][j].rgbtBlue = 255;
            }
            if(sepiaG > 255){
                image[i][j].rgbtGreen = 255;
            }
        }
}
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int fromStart = 0;
    RGBTRIPLE temporary;
    int fromEnd = width;
    for(int i = 0; i < height - 1; i++){
    while(fromEnd > fromStart){
            temporary = image[i][fromStart];
            image[i][fromStart] = image[i][fromEnd];
            image[i][fromEnd] = temporary;
            fromStart++;
            fromEnd--;
        }
        fromStart = 0;
        fromEnd = width;
    }
    //int halfWidth = width/2;
   /* for(int i = 0; i < height - 1; i++){
        for(int j = 0; j <= width - j; j++){
                int k = width - j;
                image[i][j] = image[i][k];
            }
        } */
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
    {
        int up, down, left, right, upperRed, middleRed, lowerRed, upperBlue, middleBlue, lowerBlue, upperGreen, middleGreen, lowerGreen;

        for(int i = 0; i <= height; i++){
            if(i>0){
            up = i - 1;
            }else{
            up = i;
            }
            down = i + 1;

            for(int j = 0; j < width - 1; j++){

            if(j>0){
            left = j - 1;
            }else {
            left = 0;
            }
            right = j + 1;

            upperRed = (image[up][left].rgbtRed + image[up][j].rgbtRed + image[up][right].rgbtRed);
            middleRed =  (image[i][left].rgbtRed + image[i][j].rgbtRed + image[i][right].rgbtRed);
            lowerRed = (image[down][left].rgbtRed + image[down][j].rgbtRed + image[down][right].rgbtRed);

            upperBlue = (image[up][left].rgbtBlue + image[up][j].rgbtBlue + image[up][right].rgbtBlue);
            middleBlue = (image[i][left].rgbtBlue + image[i][j].rgbtBlue + image[i][right].rgbtBlue);
            lowerBlue =  (image[down][left].rgbtBlue + image[down][j].rgbtBlue + image[down][right].rgbtBlue);

            upperGreen = (image[up][left].rgbtGreen + image[up][j].rgbtGreen + image[up][right].rgbtGreen);
            middleGreen = (image[i][left].rgbtGreen + image[i][j].rgbtGreen + image[i][right].rgbtGreen);
            lowerGreen = (image[down][left].rgbtGreen + image[down][j].rgbtGreen + image[down][right].rgbtGreen);

                                    // INNER PIXEL SQUARE

                if((up >= 0) && (left >= 0)) {   //(down >= 0) && (right <= width) &&

                image[i][j].rgbtRed = (upperRed + middleRed + lowerRed)/9;

                image[i][j].rgbtBlue = (upperBlue + middleBlue + lowerBlue)/9;

                image[i][j].rgbtGreen = (upperGreen + middleGreen + lowerGreen)/9;

                    if(up == 0){

                        image[i][j].rgbtRed = (middleRed + lowerRed)/6;

                        image[i][j].rgbtBlue = (middleBlue + lowerBlue)/6;

                        image[i][j].rgbtGreen = (middleGreen + lowerGreen)/6;

                        if(left == 0){

                            image[i][j].rgbtRed = ((middleRed - image[i][left].rgbtRed) + (lowerRed - image[down][left].rgbtRed))/4;

                            image[i][j].rgbtBlue =  ((middleBlue - image[i][left].rgbtBlue) + (lowerBlue - image[down][left].rgbtBlue))/4;

                            image[i][j].rgbtGreen = ((middleRed - image[i][left].rgbtGreen) + (lowerBlue - image[down][left].rgbtGreen))/4;
                        }
                        if(j == width){

                            image[i][j].rgbtRed = ((middleRed - image[i][right].rgbtRed) + (lowerRed - image[down][right].rgbtRed))/4;

                            image[i][j].rgbtBlue =  ((middleBlue - image[i][right].rgbtBlue) + (lowerBlue - image[down][right].rgbtBlue))/4;

                            image[i][j].rgbtGreen = ((middleRed - image[i][right].rgbtGreen) + (lowerBlue - image[down][right].rgbtGreen))/4;
                        }

                    }

                    if(i == height) {

                        image[i][j].rgbtRed = (upperRed + middleRed)/6;

                        image[i][j].rgbtBlue = (upperBlue + middleBlue)/6;

                        image[i][j].rgbtGreen = (upperGreen + middleGreen)/6;

                        if(left == 0){

                            image[i][j].rgbtRed = ((upperRed - image[up][left].rgbtRed) + (middleRed - image[i][left].rgbtRed))/4;

                            image[i][j].rgbtBlue =  ((upperBlue - image[up][left].rgbtBlue) + (middleBlue - image[i][left].rgbtBlue))/4;

                            image[i][j].rgbtGreen =  ((upperGreen - image[up][left].rgbtGreen) + (middleBlue - image[i][left].rgbtGreen))/4;
                        }
                        if(j == width){

                            image[i][j].rgbtRed = ((upperRed - image[up][right].rgbtRed) + (middleRed - image[i][right].rgbtRed))/4;

                            image[i][j].rgbtBlue =  ((upperBlue - image[up][right].rgbtBlue) + (middleBlue - image[i][right].rgbtBlue))/4;

                            image[i][j].rgbtGreen =  ((upperGreen - image[up][right].rgbtGreen) + (middleBlue - image[i][right].rgbtGreen))/4;
                        }
                    }

                    if(j == 0) {

                        image[i][j].rgbtRed = ((upperRed - image[up][left].rgbtRed)  + (middleRed - image[i][left].rgbtRed) + (lowerRed - image[down][left].rgbtRed))/6;

                        image[i][j].rgbtBlue = ((upperBlue - image[up][left].rgbtBlue)  + (middleBlue - image[i][left].rgbtBlue) + (lowerBlue - image[down][left].rgbtBlue))/6;

                        image[i][j].rgbtGreen = ((upperGreen - image[up][left].rgbtGreen)  + (middleGreen - image[i][left].rgbtGreen) + (lowerGreen - image[down][left].rgbtGreen))/6;
                    }

                    if(j == width){

                        image[i][j].rgbtRed = ((upperRed - image[up][right].rgbtRed)  + (middleRed - image[i][right].rgbtRed) + (lowerRed - image[down][right].rgbtRed))/6;

                        image[i][j].rgbtBlue = ((upperBlue - image[up][right].rgbtBlue)  + (middleBlue - image[i][right].rgbtBlue) + (lowerBlue - image[down][right].rgbtBlue))/6;

                        image[i][j].rgbtGreen = ((upperGreen - image[up][right].rgbtGreen)  + (middleGreen - image[i][right].rgbtGreen) + (lowerGreen - image[down][right].rgbtGreen))/6;
                    }


            }   else {

                image[i][j].rgbtRed = image[i][j].rgbtRed;

                image[i][j].rgbtBlue = image[i][j].rgbtBlue;

                image[i][j].rgbtGreen = image[i][j].rgbtGreen;
            }
        }
    }
     return;
}

