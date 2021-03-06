#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int i,j,t,p;

void displayimage(Mat image, String windowname){
    
    imshow(windowname, image);
}


Mat readimage(String filename)
{
    return imread(filename);
}




int main(int argc, char** argv){
       
    Mat img=imread(argv[1],CV_LOAD_IMAGE_COLOR);
    Mat img1(img.rows,img.cols,CV_8UC3);
    imshow("ima",img);

    int r=0,g=0,b=0,t=0,i,j,a[3];
    
    namedWindow("Color",WINDOW_NORMAL);
    createTrackbar("R","Color",&r,255);
    createTrackbar("G","Color",&g,255);
    createTrackbar("B","Color",&b,255);
    createTrackbar("T","Color",&t,255);

    while(1)
      {
	for(i=0;i<img.rows;i++)
	  {
	    for(j=0;j<img.cols;j++)
	      {
		a[0]=img.at<Vec3b>(i,j)[0];
		a[1]=img.at<Vec3b>(i,j)[1]; 
		a[2]=img.at<Vec3b>(i,j)[2];
		if((a[0]>=b-t && a[0]<=b+t)&&(a[1]>=g-t && a[1]<=g+t)&&(a[2]>=r-t&&a[2]<=r+t))
		  {
		    img1.at<Vec3b>(i,j)[0]=a[0];
		    img1.at<Vec3b>(i,j)[1]=a[1];
		    img1.at<Vec3b>(i,j)[2]=a[2];
		  }
		else
		  {
		    img1.at<Vec3b>(i,j)[0]=0;
		    img1.at<Vec3b>(i,j)[1]=0;
		    img1.at<Vec3b>(i,j)[2]=0;
		  }
	      }
	  }
	imshow("Color",img1);
	waitKey(10);
      }
    
    return 0;
}

