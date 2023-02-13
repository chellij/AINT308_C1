//James Rogers Jan 2022 (c) Plymouth University
//Edited by Rachel Ireland-Jones Feb 2023 :)
#include <iostream>

#include<opencv2/opencv.hpp>
#include<opencv2/opencv_modules.hpp>

using namespace std;
using namespace cv;

int main(){

    //Path of image folder
    string PathToFolder = "../Task1/Car Images/";

    //Loop through the 30 car images
    for(int n=0; n<30; ++n){

        //generate the image file using n and the folder path
        string PathToImage = PathToFolder+to_string(n)+".png";

        //print path to image
        //cout<<PathToImage<<endl;

        //Load car image at the file paths location
        Mat Car=imread(PathToImage);

        int w = Car.cols;
        int h = Car.rows;

        //overall photo rgb values;
        int R = 0;
        int G = 0;
        int B = 0;

        //  loop through image, reading values
        for (int hh = 0; hh < h; hh++){
            for(int ww = 0; ww < w; ww++){

                //read pixel RGB values into Vector [blue green red]
                Vec3b PixelValue = Car.at<Vec3b>(hh,ww);

                int b = PixelValue[0];
                int g = PixelValue[1];
                int r = PixelValue[2];

                //compare values and increase the overall value
                //if pixel is predominantly one colour
                if(r > g + b){
                    R++;
                }
                else if(g > b + r){
                    G++;
                }
                else if(b > g + r){
                    B++;
                }
            }
        }
        string colour;
        if(R > B && R > G){
            colour = "red";
        }
        else if(G > B && G > R){
            colour = "green";
        }
        else if(B > G && B > R){
            colour = "blue";
        }
        cout << "Car " << n << " Analysed: " << colour << endl;

        while(waitKey(10)!= 'x'){
            imshow("Car", Car);
        }
    }
}
