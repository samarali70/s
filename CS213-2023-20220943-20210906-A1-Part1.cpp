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
#include <regex>

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
int num;

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
void blur();
void mirror();
void shuffle();
void crop();
void skew(); 


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
    cout<<"10-Blur image"<<endl;
    cout<<"11-Mirror"<<endl;
    cout<<"12-Shuffle"<<endl;
    cout<<"13-Crop"<<endl;
    cout<<"14-Skew"<<endl;
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
else if (num==10){
    blur() ;
}
else if (num==11){
    mirror() ;
}
else if (num==12){
    shuffle() ;
}
else if (num==13){
    crop() ;
}
else if (num==14){
    skew() ;
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
    for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
            image2[i][j]=image[i][j];
            image[i][j]=255;
        }
    }
    if(s==1){
    int k =0;
    int z =0;
   for(int i=0; i< 128; i++){
   for(int j=0; j<128; j++){
        image[i][j]=(image2[k][z]+image2[k+1][z]+image2[k][z+1]+image2[k+1][z+1])/4;
        z+=2;

   }k+=2;
   z=0;
   }}
    if(s==2){
    int k =0;
    int z =0;
   for(int i=0; i< 128; i++){
   for(int j=0; j<64; j++){
        image[i][j]=(image2[k][z]+image2[k+1][z]+image2[k][z+1]+image2[k+1][z+1]+image2[k][z+2]+image2[k+1][z+2]+image2[k][z+3]+image2[k+1][z+3])/8;
        z+=4;

   }k+=2;
   z=0;
   }}
    else if(s==3){
    int k =0;
    int z =0;
   for(int i=0; i< 64; i++){
   for(int j=0; j<64; j++){
        image[i][j]=(image2[k][z]+image2[k+1][z]+image2[k+2][z]+image2[k+3][z]+image2[k][z+1]+image2[k+1][z+1]+image2[k+2][z+1]+image2[k+3][z+1]+image2[k][z+2]+image2[k+1][z+2]+image2[k+2][z+2]+image2[k+3][z+2]+image2[k][z+3]+image2[k+1][z+3]+image2[k+2][z+3]+image2[k+3][z+3])/16;
        z+=4;

   }k+=4;
   z=0;
   }}}

    void mirror(){
        int m;
        cout<<"Choose number to mirror half 1-Left, 2-Right, 3-Upper, 4-Lower: ";
        cin>> m;
 
         if(m==1){
    //Left
    for (int i = 0; i < SIZE; i++) {
    for (int j = 128; j< SIZE; j++) {
        image[i][j]=image[i][abs(j-255)];}}}

         else if(m==2){
    //Right
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< 128; j++) {
        image[i][j]=image[i][abs(j-255)];}}}

         else if(m==3){
    //Upper
    for (int i = 127; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j]=image[abs(i-255)][j];}}}

         else if(m==4){
    //Lower
    for (int i = 0; i < 128; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j]=image[abs(i-255)][j];}}}}

    void blur() {
    string radius_;
    cout << "Please enter the radius you want to blur your image with:\n";
    // Taking radius input from user
    cin >> radius_;
    regex validChoice("0*[1-9][0-9]*");
    while (!regex_match(radius_, validChoice)) {
        cout << "Please enter a valid radius:\n";
        cin >> radius_;
    }

    int radius = stoi(radius_);

    for (int i = radius; i < SIZE -
                             radius; i++) { // loop for every possible row that has the needed radius around (without going out of boundaries)
        for (int j = radius; j < SIZE -
                                 radius; j++) { // loop for every possible column that has the needed radius around (without going out of boundaries)

            // ave variable to calculate the color of the blurred pixel by getting the average color of a group of pixels
            int ave = 0;

            // adding the color of these group of pixels then diving by the number of them
            for (int k = i - radius; k <= i + radius; k++) {
                for (int l = j - radius; l <= j + radius; l++) {
                    ave += image[k][l];
                }
            }
            ave /= (2 * radius + 1) * (2 * radius + 1);

            // filling the correspondent pixels with the blurred average in the new image
            for (int k = i - radius; k <= i + radius; k++) {
                for (int l = j - radius; l <= j + radius; l++) {
                    image2[k][l] = ave;
                }
            }

        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image2[i][j];
        }
    }
}


void crop(){
int l;
cout<<"Enter the square length i\n pixels you want to crop the rest: ";
cin>>l;
int k=(256-l)/2;
    for (int i = 0; i <SIZE ; i++) {
    for (int j = 0; j<k; j++) {
        image[i][j]=255;}}
    for (int i = 0; i <SIZE ; i++) {
    for (int j = l+k; j<SIZE; j++){
        image[i][j]=255;}}
    for (int j =0; j<SIZE; j++) {
    for (int i = 0; i <k; i++) {
        image[i][j]=255;}}
    for (int j = 0; j<SIZE; j++){
    for (int i =l+k; i <SIZE; i++) {
        image[i][j]=255;}}
}

void flip() {
    cout << "Flip (h)orizontally or (v)ertically ?"
            "\n>>";
    char choice;
    cin >> choice;
    if (tolower(choice) == 'v') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[255 - i][j];
            }
        }
    } else if (tolower(choice) == 'h') {

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[i][255 - j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
    saved = false;
}

void horizontal() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

    }
  }
}


//Skews the image to the desired size
void skew(){
    double radius ; 
    cin >> radius ;
    radius = ( radius * 22 ) / ( 180 * 7 ) ;
    double mov = tan(radius) * 256 ;
    double step = mov / SIZE ; // Steps to take for the image to move.
    unsigned char img[SIZE][SIZE+(int)mov]  ;
    for ( int i = 0 ; i < SIZE ; i++ )
        for ( int j = 0 ; j < SIZE ; j++ )
            img[i][j] = 255 ;
    for ( int i = 0 ; i < SIZE ; i++ ){
        for ( int j = 0 ; j < SIZE ; j++ ){
            img[i][j+(int)mov] = image[i][j] ;
        }
        mov -= step ;
    }
    for ( int i = 0 ; i < SIZE ; i++ ){
        for ( int j = 0 ; j < SIZE; j++ ){
            image[i][j] = img[i][j] ;
        }
    }
}
void shuffle () {
      string order;
      unsigned char Quarter_1[SIZE][SIZE];
      unsigned char Quarter_2[SIZE][SIZE];
      unsigned char Quarter_3[SIZE][SIZE];
      unsigned char Quarter_4[SIZE][SIZE];
      cout << "Enter the order of quarters you want the image to be ordered by :" << endl;
      getline(cin >> ws, order, '\n');
      for (int i = 0; i < order.length(); i++) {
          if (order[i] == ' ') {
              order.erase(i, 1);
              i--;
          }
      }
      while(true) {
          bool is_valid = true;
          if (order.length() == 4) {
              for (int i = 0; i < 4; i++) {
                  if (order[i] < '1' || order[i] > '4') {
                      is_valid = false;
                  }
              }
              if (is_valid) {
                  break;
              }
          }
          cout << "Please enter a valid order :";
          getline(cin >> ws, order, '\n');
          for (int i = 0; i < order.length(); i++) {
              if (order[i] == ' ') {
                order.erase(i, 1);
                i--;
              }
          }
      }
      for (int i = 0; i < 128; i++) {
          for (int j = 0; j < 128; j++) {
            Quarter_1[i][j] = image[i][j];
          }
      }
      for (int i = 0; i < 128; i++) {
          for (int j = 128; j < 256; j++) {
            Quarter_2[i][j] = image[i][j];
          }
      }
      for (int i = 128; i < 256; i++) {
          for (int j = 0; j < 128; j++) {
            Quarter_3[i][j] = image[i][j];

          }
      }
      for (int i = 128; i < 256; i++) {
          for (int j = 128; j < 256; j++) {
            Quarter_4[i][j] = image[i][j];
          }
      }
      for (int k = 0; k < 4; k++) {
          if (k == 0) {
              for (int i = 0; i < 128; i++) {
                  for (int j = 0; j < 128; j++) {
                      if (order[0] == '1') {
                          image2[i][j] = Quarter_1[i][j];
                      } else if (order[0] == '2') {
                          image2[i][j] = Quarter_2[i][128 + j];
                      } else if (order[0] == '3') {
                          image2[i][j] = Quarter_3[128 + i][j];
                      } else if (order[0] == '4') {
                          image2[i][j] = Quarter_4[128 + i][128 + j];
                      }
                  }
              }
          } else if (k == 1) {
              for (int i = 0; i < 128; i++) {
                  for (int j = 128; j < 256; j++) {
                      if (order[1] == '1') {
                          image2[i][j] = Quarter_1[i][j - 128];
                      } else if (order[1] == '2') {
                          image2[i][j] = Quarter_2[i][j];
                      } else if (order[1] == '3') {
                          image2[i][j] = Quarter_3[128 + i][j - 128];
                      } else if (order[1] == '4') {
                          image2[i][j] = Quarter_4[128 + i][j];
                      }
                  }
              }
          } else if (k == 2) {
              for (int i = 128; i < 256; i++) {
                  for (int j = 0; j < 128; j++) {
                      if (order[2] == '1') {
                          image2[i][j] = Quarter_1[i - 128][j];
                      } else if (order[2] == '2') {
                          image2[i][j] = Quarter_2[i - 128][128 + j];
                      } else if (order[2] == '3') {
                          image2[i][j] = Quarter_3[i][j];
                      } else if (order[2] == '4') {
                          image2[i][j] = Quarter_4[i][128 + j];
                      }
                  }
              }
          } else if (k == 3) {
              for (int i = 128; i < 256; i++) {
                  for (int j = 128; j < 256; j++) {
                      if (order[3] == '1') {
                          image2[i][j] = Quarter_1[i - 128][j - 128];
                      } else if (order[3] == '2') {
image2[i][j] = Quarter_2[i - 128][j];
                      } else if (order[3] == '3') {
                          image2[i][j] = Quarter_3[i][j - 128];
                      } else if (order[3] == '4') {
                          image2[i][j] = Quarter_4[i][j];
                      }
                  }
              }
          }
      }
      for (int i = 0; i < SIZE; i++) {
          for (int j = 0; j < SIZE; j++) {
              image[i][j] = image2[i][j];
          }
      }

  }











