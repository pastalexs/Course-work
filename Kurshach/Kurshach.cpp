#include "stdafx.h"
#include <opencv2\opencv.hpp>  
#include <opencv2\core\cuda.hpp>
#include <opencv2\stitching.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include "opencv2/xfeatures2d.hpp"


using namespace cv;
using namespace std;

void main()
{
	vector< Mat > vImg;

	Mat rImg;

	vImg.push_back(imread("./stitching_img/S1.jpg", IMREAD_UNCHANGED));
	vImg.push_back(imread("./stitching_img/S2.jpg", IMREAD_UNCHANGED));
	vImg.push_back(imread("./stitching_img/S3.jpg", IMREAD_UNCHANGED));
	vImg.push_back(imread("./stitching_img/S4.jpg", IMREAD_UNCHANGED));
	vImg.push_back(imread("./stitching_img/S5.jpg", IMREAD_UNCHANGED));
	vImg.push_back(imread("./stitching_img/S6.jpg", IMREAD_UNCHANGED));

	Stitcher stitcher = Stitcher::createDefault();

	unsigned long AAtime = 0, BBtime = 0;
	AAtime = getTickCount();

	Stitcher::Status status = stitcher.stitch(vImg, rImg);

	BBtime = getTickCount();
	printf("ProcessingTime %.2lf sec \n", (BBtime - AAtime) / getTickFrequency());

	if (Stitcher::OK == status)
		imshow("Stitching Result", rImg);
	else
		printf("Stitching fail.");

	waitKey(0);
	imwrite("output.jpg", rImg);
}
