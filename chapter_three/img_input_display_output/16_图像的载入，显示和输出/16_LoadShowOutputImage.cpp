//--------------------------------------【程序说明】-------------------------------------------
//		程序说明：《OpenCV3编程入门》OpenCV3版书本配套示例程序16
//		程序描述：图像的载入、显示和输出示例
//		开发测试所用操作系统： Windows 7 64bit
//		开发测试所用IDE版本：Visual Studio 2010
//		开发测试所用OpenCV版本：	3.0 beta
//		2014年11月 Created by @浅墨_毛星云
//		2014年12月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;


int main( )
{
	//-----------------------------------【一、图像的载入和显示】---------------------------------
	//	描述：以下三行代码用于完成图像的载入和显示
	//--------------------------------------------------------------------------------------------------

	Mat girl=imread("girl.jpg"); //载入图像到Mat
	namedWindow("【1】动漫图",WINDOW_GUI_NORMAL); //创建一个名为 "【1】动漫图"的窗口  
	imshow("【1】动漫图",girl);//显示名为 "【1】动漫图"的窗口  

	//-----------------------------------【二、初级图像混合】--------------------------------------
	//	描述：二、初级图像混合
	//--------------------------------------------------------------------------------------------------
	//载入图片
	Mat image= imread("dota.jpg",1);//1为199时出错，图片会被压缩，导致接下来的Rect函数出错。
	Mat logo= imread("dota_logo.jpg");

	//载入后先显示
	namedWindow("【2】原画图");
	imshow("【2】原画图",image);

	namedWindow("【3】logo图");
	imshow("【3】logo图",logo);

	// 定义一个Mat类型，用于存放，图像的ROI
	Mat imageROI;
	//imageROI = image;
	//方法一
	//指定image中和logo一样大小的区域进行操作，imageROI的数据与源图像image共享存储区，所以此后在imageROI上的操作也会作用在源图像image上  
	//rect是一个方法，参数1，2为坐标，3.4为宽高
	imageROI = image(Rect(500, 200, logo.cols, logo.rows));
	/*try
	{
		imageROI = image(Rect(800, 350, logo.cols, logo.rows));
	}
	catch(Exception)
	{
		printf("wrong");
	}*/
	//方法二，效果和方法一一样
	//imageROI= image(Range(350,350+logo.rows),Range(800,800+logo.cols));

	// 将logo加到原图上
	//数组相加函数，imageROI为原数组，0.8为该数组权值，logo为另一个原数组，
	//0.2为该数组权重，0为添加常数项，imageROI为输出目标数组，函数输出结果为：imageROI=imageROI*0.8+logo*0.2+0 
	addWeighted(imageROI,0.5,logo,0.3,0.,imageROI);

	//显示结果
	namedWindow("【4】原画+logo图");
	imshow("【4】原画+logo图",image);

	//-----------------------------------【三、图像的输出】--------------------------------------
	//	描述：将一个Mat图像输出到图像文件
	//-----------------------------------------------------------------------------------------------
	//输出一张jpg图片到工程目录下
	imwrite("由imwrite生成的图片.jpg",image);

	waitKey();

	return 0;
}
