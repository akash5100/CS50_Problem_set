#include "helpers.h"
#include <math.h>
#include<stdlib.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    
    float avg;
    
    for ( int i = 0; i < height; i++)
    {
        for ( int j = 0; j < width; j++)
        {                 
            avg=round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.00);                              
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;          
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp[3];
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width/2 ; i++)
        {
            tmp[0] = image[j][i].rgbtBlue;
            tmp[1] = image[j][i].rgbtGreen;
            tmp[2] = image[j][i].rgbtRed;

            // swap pixels with the ones on the opposite side of the picture and viceversa
            image[j][i].rgbtBlue  = image[j][width-i-1].rgbtBlue;
            image[j][i].rgbtGreen = image[j][width-i-1].rgbtGreen;
            image[j][i].rgbtRed   = image[j][width-i-1].rgbtRed;

            image[j][width-i-1].rgbtBlue  = tmp[0];
            image[j][width-i-1].rgbtGreen = tmp[1];
            image[j][width-i-1].rgbtRed   = tmp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            // sums values of the pixel and 8 neighboring ones, skips iteration if it goes outside the pic
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[j + k][i + h].rgbtBlue;
                    sumGreen += image[j + k][i + h].rgbtGreen;
                    sumRed += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            // averages the sum to make picture look blurrier
            temp[j][i].rgbtBlue = round(sumBlue / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtRed = round(sumRed / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
    
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    float GxRed, GxBlue, GxGreen;
    float GyRed, GyBlue, GyGreen;
    float X,Y;
    //create a temporary image 2d array to not change calculation after every loop
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            
            GyBlue = 0.0;
            GyGreen = 0.0;
            GyRed = 0.0;
            GxBlue = 0.0;
            GxGreen = 0.0;
            GxRed = 0.0;

            // sums values of the pixel and 8 neighboring ones after applying a modifier, skips iteration if it goes outside the pic
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    // calculates modifiers for vertical and horizantal borders
                    X = (k + 1 * k - k * abs(h));
                    Y = (h + 1 * h - h * abs(k));

                    GxBlue += image[j + k][i + h].rgbtBlue * X;
                    GxGreen += image[j + k][i + h].rgbtGreen * X;
                    GxRed += image[j + k][i + h].rgbtRed * X;

                    GyBlue += image[j + k][i + h].rgbtBlue * Y;
                    GyGreen += image[j + k][i + h].rgbtGreen * Y;
                    GyRed += image[j + k][i + h].rgbtRed * Y;
                }
            }

            // obtains the final values of the pixels combining X and Y calculations
            temp[j][i].rgbtBlue = check(round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue)));
            temp[j][i].rgbtGreen = check(round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen)));
            temp[j][i].rgbtRed = check(round(sqrt(GxRed * GxRed + GyRed * GyRed)));
        }
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
    return;
}

int check(int a)
{
    if (a>255)
    {
        return a=255;
    }
    else
    {
        return a;
    }
}

