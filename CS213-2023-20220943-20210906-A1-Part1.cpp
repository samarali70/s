// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:	team.cpp
// Last Modification Date:	10/10/2023
// Author1 and ID and Group:	Tibian Tarig 20220943
// Author2 and ID and Group:	Samar Abaker 20210906
// Teacher:		Dr. Mohammad El-Ramly
// Purpose: Learning more about coding in the c++ language

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
int num;
int x;
void loadImage ();
void loadImage2 ();
void menuDisplay ();
void saveImage ();
void BW();
void invert();
void mergeImage();
void flip();
void rot();
void dorl();
void edge();
void enlarge();
void shrink();
void shuffle();

int main(){
  loadImage();
  menuDisplay();
  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void loadImage2 () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the second source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image2);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];
   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
   // y to exit code and n to start again
   char exit;
   cout<<"Enter y to exit or n to begin again: ";
   cin>>exit;
   if(exit=='n'){
    main();
   }
}

//_________________________________________
void menuDisplay() {
    cout<<"Select a fliter to apply or 0 to exit: "<<endl;
    cout<<"1- Black & White Filter"<<endl;
    cout<<"2- Invert Filter"<<endl;
    cout<<"3- Merge Filter"<<endl;
    cout<<"4- Flip Image"<<endl;
    cout<<"5- Rotate Image"<<endl;
    cout<<"6- Darken and Lighten Image"<<endl;
    cout<<"7- Find Image Edges"<<endl;
    cout<<"8- Enlarge Image"<<endl;
    cout<<"9- Shrink Image"<<endl;

    cin>>num;
if (num==1){
    BW();
}
else if(num==2){
    invert();
}
else if(num==3){
    mergeImage();
}
else if (num==4){
    flip();
    }
else if (num==5){
    rot();
}
else if (num==6){
    dorl();
}
else if (num==7){
    edge();
}
else if (num==8){
    enlarge() ;
}
else if (num==9){
    shrink() ;
}
else if(num==0){
    exit(0) ;
}
}
//_________________________________________
//Filtters
//_________________________________________
void BW() {
    //Black and White Filter
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
    //Turn all pixels [0-127] to Black[0]
      if (image[i][j] <= 127)
            image[i][j] = 0;
    //Turn all pixels [128-255] to White[255]
        else
            image[i][j] = 255;

    }
  }
}
//_________________________________________
void invert() {
       for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
        //Invert colours
        image[i][j]=abs(image[i][j]-255);
        }
        }
}
//_________________________________________
void mergeImage(){
        loadImage2();
       for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
                image1[i][j]= image[i][j];
        image[i][j]= (image1[i][j]+image2[i][j])/2;
        }
}}
//_________________________________________
void flip(){
    char flip;
    cout<<"Flip (h)orizontally or (v)ertically ? ";
    cin>>flip;
    if(flip=='v'){
    //Flip vertically
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image1[i][j]=image[i][j];}}
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
         image[i][j]= image1[abs(i-255)][j];

}
}}
else if(flip=='h'){
    //Flip horizontally
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image1[i][j]=image[i][j];}}
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
         image[i][j]= image1[i][abs(j-255)];

}
}}}
//_________________________________________
void rot (){
    //rotate
int deg;
cout<<"Rotate (90), (180) or (270) degrees clockwise ?";
cin>> deg;
switch(deg)
{
case 90:
    //Transpose Image
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image1[i][j]=image[i][j];}}
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
         image[i][j]= image1[j][i];
}
}
    //Flip Image horizontally
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image1[i][j]=image[i][j];}}
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
         image[i][j]= image1[i][abs(j-255)];

}}
case 180:
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image1[i][j]=image[i][j];}}
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
         image[i][j]= image1[abs(i-255)][abs(j-255)];

}
}
case 270:
    //Transpose Image
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image1[i][j]=image[i][j];}}
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
         image[i][j]= image1[j][i];
}
}
    //Flip Image vertically
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image1[i][j]=image[i][j];}}
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
         image[i][j]= image1[abs(i-255)][j];

}
}

}
}
//_________________________________________
void dorl(){

    //darken or lighten
char r;
cout<<"Do you want to (d)arken or (l)ighten image ?";
cin>>r;
//if the user chose to darken
if(r=='d'){
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
    if(image[i][j]>=50){
        image[i][j]-=50;}
    else{
        image[i][j]=0;
    }
    }}}
//if the user chose to lighten
else{
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
    if(image[i][j]<=205){
        image[i][j]+=50;}
    else{
        image[i][j]=255;
    }
    }}}
}

void edge(){
   for(int i=0; i< SIZE; i++){
   for(int j=0; j<SIZE; j++){
    if(abs(image[i][j]-image[i+1][j])>100){
        image[i][j]=0;
        image[i+1][j]=255;}
    else{
        image[i][j]=255;
    }
    }
    }
   }


void enlarge()
{  int part;
    cout<<"Enter the number you want to enlarge: 1, 2, 3, 4? "<<endl;
    cin>> part;
    if(part==1){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            image2[i][j]=image[i][j];
            image[i][j]=0;

        }
    }
    int k =0;
    int z =0;
   for(int i=0; i< 128; i++){
   for(int j=0; j<128; j++){
        image[k][z]=image2[i][j];
        image[k+1][z]=image2[i][j];
        image[k][z+1]=image2[i][j];
        image[k+1][z+1]=image2[i][j];
        z+=2;

   }k+=2;
   z=0;
   }}
    else if(part==2){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            image2[i][j]=image[i][j];
            image[i][j]=0;

        }
    }
    int k =0;
    int z =0;
   for(int i=0; i< 128; i++){
   for(int j=128; j<256; j++){
        image[k][z]=image2[i][j];
        image[k+1][z]=image2[i][j];
        image[k][z+1]=image2[i][j];
        image[k+1][z+1]=image2[i][j];
        z+=2;

   }k+=2;
   z=0;
   }}
       if(part==3){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            image2[i][j]=image[i][j];
            image[i][j]=0;

        }
    }
    int k =0;
    int z =0;
   for(int i=128; i< 256; i++){
   for(int j=0; j<128; j++){
        image[k][z]=image2[i][j];
        image[k+1][z]=image2[i][j];
        image[k][z+1]=image2[i][j];
        image[k+1][z+1]=image2[i][j];
        z+=2;

   }k+=2;
   z=0;
   }}
    if(part==4){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            image2[i][j]=image[i][j];
            image[i][j]=0;

        }
    }
    int k =0;
    int z =0;
   for(int i=128; i< 256; i++){
   for(int j=128; j<256; j++){
        image[k][z]=image2[i][j];
        image[k+1][z]=image2[i][j];
        image[k][z+1]=image2[i][j];
        image[k+1][z+1]=image2[i][j];
        z+=2;

   }k+=2;
   z=0;
   }}

   }

void shrink(){
    int s;
    cout<<"Shrink 1-Half, 2-Quarter, 3-Third (Choose a number): "<<endl;
    cin>>s;
    if(s==1){
        for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            image2[i][j]=image[i][j];
            image[i][j]=255;
        }
    }
    int k =0;
    int z =0;
   for(int i=0; i< 128; i++){
   for(int j=0; j<128; j++){
        image[i][j]=(image2[k][z]+image2[k+1][z]+image2[k][z+1]+image2[k+1][z+1])/4;
        z+=2;

   }k+=2;
   z=0;
   }}
   else if(s==2){
        for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            image2[i][j]=image[i][j];
            image[i][j]=255;
        }
    }
    int g =0;
    int h =0;
    int sum=0;
    for(int i=0; i< SIZE; i+=3){
    for(int j=0; j<SIZE; j+=3){
    for(int k=0; k<4; k++){
    for(int z=0; z<4; z++){
        sum+= image2[i+k][j+z];
        }
        }
        image[g][h]=sum/16;
        h++;
        }
        g++;
        h=0;
   }
   }

    }










