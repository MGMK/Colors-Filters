// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"

using namespace std;

unsigned char image_1[SIZE][SIZE][3];
unsigned char image_2[SIZE][SIZE][3];


void loadImage_Bonus();
void loadImage_Bonus_2();
void saveImage_Bonus();

// Abd El Hamed Functios
void Filter_1_bonus();
void Filter_4_bonus();
void Filter_7_bonus();


// Mohamed Hamdy Functions
void Filter_2_bonus();
void Filter_5_bonus();
void Filter_8_bonus();

// Mohamed Ali Functions
void Filter_3_bonus();
void Filter_6_bonus();
void Filter_9_bonus();


int main ()
{
    while ( true )
    {
        while ( true)
        {
            cout << "Ahlan ya user ya habibi ?\n";
            loadImage_Bonus();
            string x ;
            cout << "\n1- Black and White Image .\n2- Invert Filter\n3- Merge Images .\n4- Flip Image .\n5- Rotate Image .\n6- Darken and Lighten Image ."
                 << "\n7- Detect Image Edges .\n8- Enlarge Image .\n9- Shrink Image .\ns- Save the image to a file .\n0- To End .";
            while ( true)
            {
                cout << "\n\nEnter Your Choose Please :";
                cin >> x ;
                if (x == "1")
                {
                    Filter_1_bonus();
                    cout <<"Successful process";
                }
                else if ( x == "2")
                {
                    Filter_2_bonus();
                    cout <<"Successful process";
                }
                else if ( x == "3")
                {
                    loadImage_Bonus_2();
                    Filter_3_bonus();
                    cout <<"Successful process";
                }
                else if ( x == "4")
                {
                    Filter_4_bonus();
                    cout <<"Successful process";
                }
                else if (x == "5")
                {
                    Filter_5_bonus();
                    cout <<"Successful process";
                }
                else if (x == "6")
                {
                    Filter_6_bonus();
                    cout <<"Successful process";
                }
                else if (x == "7")
                {
                    Filter_7_bonus();
                    cout <<"Successful process";
                }
                else if (x == "8")
                {
                    Filter_8_bonus();
                    cout <<"Successful process";
                }
                else if (x == "9")
                {
                    Filter_9_bonus();
                    cout <<"Successful process";
                }
                else if (x == "s")
                {
                    saveImage_Bonus();
                    cout <<"Successful process\n";
                    loadImage_Bonus();
                }        else
                    continue;
            }
        }
}
}

void loadImage_Bonus()
{
    char filename[100];
    cout << "Enter the image name :";
    cin >> filename;
    strcat (filename, ".bmp");
    readRGBBMP(filename,  image_1);

}
void loadImage_Bonus_2()
{
    char filename[100];
    cout << "\nEnter the second image name :";
    cin >> filename;
    strcat (filename, ".bmp");
    readRGBBMP(filename,  image_2);

}

void saveImage_Bonus()
{
    char filename_1[100];
    cout << "\nEnter the target image file name:";
    cin >> filename_1;
    strcat (filename_1, ".bmp");
    writeRGBBMP(filename_1, image_2);

}


void Filter_1_bonus()
{
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            if ((image_1[i][j][0]+image_1[i][j][1]+image_1[i][j][2])/ 3 >= 127)
            {
                image_1[i][j][0]=255;
                image_1[i][j][1]=255;
                image_1[i][j][2]=255;
            }
            else
            {
                image_1[i][j][0]=0;
                image_1[i][j][1]=0;
                image_1[i][j][2]=0;
            }
        }
    }

    for ( int i = 0 ; i < SIZE ; i++)
    {
        for ( int j = 0 ; j < SIZE ; j++)
        {
            image_2[i][j][0] = image_1[i][j][0];
            image_2[i][j][1] = image_1[i][j][1];
            image_2[i][j][2] = image_1[i][j][2];
        }
    }

}
void Filter_2_bonus()
{
    for(int i=0 ; i < SIZE ; i++)
    {
        for(int j=0 ; j < SIZE ; j++)
        {
            image_1[i][j][0] = 255 - image_1[i][j][0];
            image_1[i][j][1] = 255 - image_1[i][j][1];
            image_1[i][j][2] = 255 - image_1[i][j][2];
        }
    }

    for ( int i = 0 ; i < SIZE ; i++)
    {
        for ( int j = 0 ; j < SIZE ; j++)
        {
            image_2[i][j][0] = image_1[i][j][0];
            image_2[i][j][1] = image_1[i][j][1];
            image_2[i][j][2] = image_1[i][j][2];
        }
    }

}
void Filter_3_bonus()
{
    for(int i=0 ; i < SIZE ; i++)
    {
        for(int j=0 ; j < SIZE ; j++)
        {
            image_1[i][j][0] = (image_1[i][j][0] + image_2[i][j][0])/2;
            image_1[i][j][1] = (image_1[i][j][1] + image_2[i][j][1])/2;
            image_1[i][j][2] = (image_1[i][j][2] + image_2[i][j][2])/2;
        }
    }
    for ( int i = 0 ; i < SIZE ; i++)
    {
        for ( int j = 0 ; j < SIZE ; j++)
        {
            image_2[i][j][0] = image_1[i][j][0];
            image_2[i][j][1] = image_1[i][j][1];
            image_2[i][j][2] = image_1[i][j][2];
        }
    }
}

void Filter_4_bonus()
{
    char z ;
    cout << "\n1- To Get Right Inverse Image . \n2- To Get Rotate Image (180 Degree).\n>>>";
    cin >> z ;
    if (z == '1')
    {
        for(int i=0 ; i < SIZE ; i++)
        {
            for(int j=0 ; j < SIZE ; j++)
            {
                image_2[i][j][0] = image_1[i][SIZE - j][0];
                image_2[i][j][1] = image_1[i][SIZE - j][1] ;
                image_2[i][j][2] = image_1[i][SIZE - j][2] ;
            }
        }

    }
    else if ( z == '2')
    {
        int x = 0 ;
        for(int i=0 ; i < SIZE ; i++)
        {
            for(int j=0 ; j < SIZE ; j++)
            {
                image_2[i][j][0] = image_1[SIZE - x][j][0];
                image_2[i][j][1] = image_1[SIZE - x][j][1] ;
                image_2[i][j][2] = image_1[SIZE - x][j][2] ;
            }
            x++;
        }
    }

}

void Filter_5_bonus()
{
    char z ;
    cout << "\n 1- To Rotate image 90 degree .\n 2- To Rotate image 180 degree .\n 3- To Rotate image 270 degree .\n>>>";
    cin >> z ;
    if ( z == '1')
    {
        for(int i=0 ; i < SIZE ; i++)
        {
            for(int j=0 ; j < SIZE ; j++)
            {
                image_2[j][SIZE - i][0] = image_1[i][j][0];
                image_2[j][SIZE - i][1] = image_1[i][j][1];
                image_2[j][SIZE - i][2] = image_1[i][j][2];
            }
        }
    }
    else if ( z == '2')
    {
        int x = 0 ;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image_2[i][j][0]=image_1[SIZE - x][SIZE - j][0];
                image_2[i][j][1]=image_1[SIZE - x][SIZE - j][1];
                image_2[i][j][2]=image_1[SIZE - x][SIZE - j][2];
            }
            x++;
        }
    }

    else if ( z == '3')
    {
        int x = 0;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image_2[SIZE - j][i][0]=image_1[i][j][0];
                image_2[SIZE - j][i][1]=image_1[i][j][1];
                image_2[SIZE - j][i][2]=image_1[i][j][2];
            }
        }

    }


}

void Filter_6_bonus()
{
    int num;
    cout <<"1-Darken Image.\n"
         <<"2-Lighten Image.\n"
         <<">>> ";
    cin >> num;
    if (num==1)
    {
        for (int i = 0 ; i < SIZE ; i++)
        {
            for (int j = 0 ; j < SIZE ; j++)
            {
                image_1[i][j][0]/=2;
                image_1[i][j][1]/=2;
                image_1[i][j][2]/=2;
            }
        }
    }
    else if (num==2)
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for (int j = 0 ; j < SIZE ; j++)
            {
                int Index_Red=image_1[i][j][0] + 0.5*image_1[i][j][0];
                int Index_Green=image_1[i][j][1] + 0.5*image_1[i][j][1];
                int Index_Blue=image_1[i][j][2] + 0.5*image_1[i][j][2];
                if ( Index_Red > 255)
                {
                    Index_Red=255;
                }
                if ( Index_Green > 255)
                {
                    Index_Green=255;
                }
                if ( Index_Blue > 255)
                {
                    Index_Blue=255;
                }
                image_1[i][j][0] = Index_Red ;
                image_1[i][j][1] = Index_Green ;
                image_1[i][j][2] = Index_Blue ;
            }
        }
    }
    for ( int i =  0 ; i < SIZE ; i++)
    {
		for (int j = 0 ; j < SIZE ; j++)
		{
			image_2[i][j][0] = image_1[i][j][0];
			image_2[i][j][1] = image_1[i][j][1];
			image_2[i][j][2] = image_1[i][j][2];
		} 
	}
}
void Filter_7_bonus()
{
    for ( int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ;  j++)
        {
                image_2[i][j][0] = 255;
                image_2[i][j][1] = 255;
                image_2[i][j][2] = 255;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if (
					(image_1[i][j][0] > (image_1[i+1][j][0] + 45 ) || image_1[i][j][0] > (image_1[i][j+1][0] + 45 ) || image_1[i][j][0] > (image_1[i+1][j+1][0] + 45 ) ||  image_1[i][j][0] > (image_1[i-1][j-1][0] + 45 )  )&&
                    (image_1[i][j][1] >  (image_1[i+1][j][1] + 45 ) || image_1[i][j][1] >  (image_1[i][j+1][1] + 45 ) ||  image_1[i][j][1] > (image_1[i+1][j+1][1] + 45 ) || image_1[i][j][1] > (image_1[i-1][j-1][1] + 45 ) )&&
                    (image_1[i][j][2] >  (image_1[i+1][j][2] + 45 ) || image_1[i][j][2] >  (image_1[i][j+1][2] + 45 ) ||  image_1[i][j][2] > (image_1[i+1][j+1][2] + 45 ) || image_1[i][j][2] > (image_1[i-1][j-1][2] + 45 ) )
				)
                    
				{
					  image_2[i][j][0]=0;
                      image_2[i][j][1]=0;
                      image_2[i][j][2]=0;
                }
        }
    }
}
void Filter_8_bonus()
{
    char x ;
    cout << "1- if you want quarters one .\n2- if you want quarters two .\n3- if you want quarters three .\n4- if you want quarters four .";
    cout << "\n>>>";
    cin >> x ;
    if ( x == '1')
    {
        int rows = 0, cols = 0 ;
        for ( int i = 0 ; i <SIZE ; i+=2)
        {
            for ( int j = 0 ; j< SIZE ; j+=2)
            {
                image_2[i][j][0] =image_1[rows][cols][0];
                image_2[i+1][j][0] =image_1[rows][cols][0];
                image_2[i][j+1][0] =image_1[rows][cols][0];
                image_2[i+1][j+1][0] =image_1[rows][cols][0];



                image_2[i][j][1] =image_1[rows][cols][1];
                image_2[i+1][j][1] =image_1[rows][cols][1];
                image_2[i][j+1][1] =image_1[rows][cols][1];
                image_2[i+1][j+1][1] =image_1[rows][cols][1];


                image_2[i][j][2] =image_1[rows][cols][2];
                image_2[i+1][j][2] =image_1[rows][cols][2];
                image_2[i][j+1][2] =image_1[rows][cols][2];
                image_2[i+1][j+1][2] =image_1[rows][cols][2];

                cols++;
            }
            rows++;
            cols=0;
        }
    }
    else if (x == '2')
    {
        int rows = 0, cols = SIZE/2 ;
        for ( int i = 0 ; i <SIZE ; i+=2)
        {
            for ( int j = 0 ; j< SIZE ; j+=2)
            {
                image_2[i][j][0] =image_1[rows][cols][0];
                image_2[i+1][j][0] =image_1[rows][cols][0];
                image_2[i][j+1][0] =image_1[rows][cols][0];
                image_2[i+1][j+1][0] =image_1[rows][cols][0];



                image_2[i][j][1] =image_1[rows][cols][1];
                image_2[i+1][j][1] =image_1[rows][cols][1];
                image_2[i][j+1][1] =image_1[rows][cols][1];
                image_2[i+1][j+1][1] =image_1[rows][cols][1];


                image_2[i][j][2] =image_1[rows][cols][2];
                image_2[i+1][j][2] =image_1[rows][cols][2];
                image_2[i][j+1][2] =image_1[rows][cols][2];
                image_2[i+1][j+1][2] =image_1[rows][cols][2];

                cols++;
            }
            rows++;
            cols=SIZE/2;
        }
    }
    else if(x == '3')
    {
        int rows = SIZE/2, cols = 0 ;
        for ( int i = 0 ; i <SIZE ; i+=2)
        {
            for ( int j = 0 ; j< SIZE ; j+=2)
            {
                image_2[i][j][0] =image_1[rows][cols][0];
                image_2[i+1][j][0] =image_1[rows][cols][0];
                image_2[i][j+1][0] =image_1[rows][cols][0];
                image_2[i+1][j+1][0] =image_1[rows][cols][0];



                image_2[i][j][1] =image_1[rows][cols][1];
                image_2[i+1][j][1] =image_1[rows][cols][1];
                image_2[i][j+1][1] =image_1[rows][cols][1];
                image_2[i+1][j+1][1] =image_1[rows][cols][1];


                image_2[i][j][2] =image_1[rows][cols][2];
                image_2[i+1][j][2] =image_1[rows][cols][2];
                image_2[i][j+1][2] =image_1[rows][cols][2];
                image_2[i+1][j+1][2] =image_1[rows][cols][2];

                cols++;
            }
            rows++;
            cols=0;
        }
    }
    else if (x == '4')
    {
        int rows = SIZE/2, cols = SIZE/2 ;
        for ( int i = 0 ; i <SIZE ; i+=2)
        {
            for ( int j = 0 ; j< SIZE ; j+=2)
            {
                image_2[i][j][0] =image_1[rows][cols][0];
                image_2[i+1][j][0] =image_1[rows][cols][0];
                image_2[i][j+1][0] =image_1[rows][cols][0];
                image_2[i+1][j+1][0] =image_1[rows][cols][0];



                image_2[i][j][1] =image_1[rows][cols][1];
                image_2[i+1][j][1] =image_1[rows][cols][1];
                image_2[i][j+1][1] =image_1[rows][cols][1];
                image_2[i+1][j+1][1] =image_1[rows][cols][1];


                image_2[i][j][2] =image_1[rows][cols][2];
                image_2[i+1][j][2] =image_1[rows][cols][2];
                image_2[i][j+1][2] =image_1[rows][cols][2];
                image_2[i+1][j+1][2] =image_1[rows][cols][2];

                cols++;
            }
            rows++;
            cols=SIZE/2;
        }
    }
}

void Filter_9_bonus()
{
    char x ;
    cout << "1- if you want 1/2 from original image .\n2- if you want 1/3 from original image .\n3- if you want 1/4 from original image .";
    cout <<"\n>>>";
    cin >> x ;
    if ( x == '1')
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for ( int j = 0 ; j < SIZE ; j++)
            {
                image_2[i/2][j/2][0]=((image_1[i][j][0]+ image_1[i+1][j][0]+ image_1[i][j+1][0]+ image_1[i+1][j+1][0])/4);
                image_2[i/2][j/2][1]=((image_1[i][j][1]+ image_1[i+1][j][1]+ image_1[i][j+1][1]+ image_1[i+1][j+1][1])/4);
                image_2[i/2][j/2][2]=((image_1[i][j][2]+ image_1[i+1][j][2]+ image_1[i][j+1][2]+ image_1[i+1][j+1][2])/4);
                image_2[i][j][0]=255;
                image_2[i][j][1]=255;
                image_2[i][j][1]=255;
            }
        }
    }
    else if ( x == '2' )
    {
        for ( int i = 0 ; i < SIZE  ; i++)
        {
            for ( int j = 0 ; j < SIZE ; j++)
            {
                image_2[i/3][j/3][0]=((image_1[i][j][0]+ image_1[i+1][j][0]+ image_1[i][j+1][0]+ image_1[i+1][j+1][0])/4);
                image_2[i/3][j/3][1]=((image_1[i][j][1]+ image_1[i+1][j][1]+ image_1[i][j+1][1]+ image_1[i+1][j+1][1])/4);
                image_2[i/3][j/3][2]=((image_1[i][j][2]+ image_1[i+1][j][2]+ image_1[i][j+1][2]+ image_1[i+1][j+1][2])/4);
                image_2[i][j][0]=255;
                image_2[i][j][1]=255;
                image_2[i][j][1]=255;
            }
        }
    }
    else if ( x == '3' )
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for ( int j = 0 ; j < SIZE ; j++)
            {
                image_2[i/4][j/4][0]=((image_1[i][j][0]+ image_1[i+1][j][0]+ image_1[i][j+1][0]+ image_1[i+1][j+1][0])/4);
                image_2[i/4][j/4][1]=((image_1[i][j][1]+ image_1[i+1][j][1]+ image_1[i][j+1][1]+ image_1[i+1][j+1][1])/4);
                image_2[i/4][j/4][2]=((image_1[i][j][2]+ image_1[i+1][j][2]+ image_1[i][j+1][2]+ image_1[i+1][j+1][2])/4);
                image_2[i][j][0]=255;
                image_2[i][j][1]=255;
                image_2[i][j][1]=255;
            }
        }
    }
}
