#include "opencv3_learn.h"

using namespace cv;
using namespace std;

void chapter1_test()
{
	// ��̽opencv
	Mat src_img = imread("tan.jpg");
	//Mat src_img = imread(argv[1],1);

	Mat edge, gray_img;
	Mat element = getStructuringElement(MORPH_RECT, Size(30, 30));
	Mat dst_img;
	
	int i=1;

	printf("\t%d\n\t%d\r%d\n\r%d",i,i,i,i);

	//ͼ����
	if (i < 4)
	{
		namedWindow("ԭͼ", 0);
		imshow("ԭͼ", src_img);
	}

	switch (i)
	{
	//��ʴ
	case 1:		
		erode(src_img, dst_img, element);
		namedWindow("��ʴЧ��ͼ", 0);
		imshow("��ʴЧ��ͼ", dst_img);
		// �ȴ�20s�󴰿��Զ��ر�
		waitKey(200000);
		break;

	//��Ե���
	case 2:
		cvtColor(src_img, gray_img, CV_BGR2GRAY);
		blur(gray_img, edge, Size(3, 3));
		Canny(edge, edge, 3, 9, 3);
		namedWindow("��ԵЧ��ͼ", 0);
		imshow("��ԵЧ��ͼ", edge);
		// �ȴ�20s�󴰿��Զ��ر�
		waitKey(20000);
		break;

	//ͼ��ģ��
	case 3:
		//���о�ֵ�˲�
		blur(src_img, dst_img, Size(50, 50));

		namedWindow("ģ��Ч��ͼ", 0);
		imshow("ģ��Ч��ͼ", dst_img);
		// �ȴ�20s�󴰿��Զ��ر�
		waitKey(20000);
		break;

	case 4:
		while (1)
		{
			//VideoCapture capture;
			//capture.open("1.mp4");
			VideoCapture capture("1.mp4");
			Mat frame;
			capture >> frame;

			if (frame.empty())
			{
				break;
			}

			namedWindow("��ȡ��Ƶ", 0);
			imshow("��ȡ��Ƶ", frame);
			// �ȴ�6000 ms�󴰿��Զ��ر�
			waitKey(30);
		}

		break;

	case 5:
		while (1)
		{
			VideoCapture capture(0);
			Mat frame;
			capture >> frame;

			if (frame.empty())
			{
				break;
			}

			namedWindow("��ȡ����ͷ��Ƶ", 0);
			imshow("��ȡ����ͷ��Ƶ", frame);
			// �ȴ�6000 ms�󴰿��Զ��ر�
			waitKey(30);
		}

		break;

	case 6:
		while (1)
		{
			//��ȡ����ͷ
			VideoCapture capture(0);
			Mat frame;
			Mat video_edge;
			capture >> frame;

			if (frame.empty())
			{
				break;
			}

			//��Ե���
			cvtColor(frame, video_edge, CV_BGR2GRAY);
			blur(video_edge, video_edge, Size(7, 7));
			Canny(video_edge, video_edge, 0, 30, 3);

			namedWindow("�������Ƶ", 0);
			imshow("�������Ƶ", video_edge);

			// �ȴ�����30ms����ѭ��
			if (waitKey(30) >= 0)
			{
				break;
			}
		}

		break;

	default:
		// �ȴ�2s�󴰿��Զ��ر�
		waitKey(2000);
		break;
	}
}

//openc3��4��ѧϰ
void chapter4_test()
{	
	int option;
	option = 4;
	switch (option)
	{
	case 1:   //mat���ʼ������
	{		
		//int size[3] = { 2,2,2 };
		Mat m1(2, 2, CV_8UC3, Scalar(1, 0, 255)), m3, m4, m5, m6, m7, m8, m9;
		Mat m2(2, 2, CV_8UC3, Scalar::all(0));
		m3.create(3, 4, CV_8UC(3));
		m4 = Mat::eye(4, 4, CV_8UC3);
		m5 = Mat::ones(4, 4, CV_8UC3);
		m6 = Mat::zeros(4, 4, CV_8UC3);
		m7 = (Mat_<double>(2, 2) << 1, 2, 3, 4);
		m8 = m7.col(1).clone();
		m7.row(1).copyTo(m9);
		cout << "m1=" << endl << "" << m1 << endl << endl;
		cout << "m2=" << endl << "" << m2 << endl << endl;
		cout << "m3=" << endl << "" << m3 << endl << endl;
		cout << "m4=" << endl << "" << m4 << endl << endl;
		cout << "m5=" << endl << "" << m5 << endl << endl;
		cout << "m6=" << endl << "" << m6 << endl << endl;
		cout << "m7=" << endl << "" << m7 << endl << endl;
		cout << "m8=" << endl << "" << m8 << endl << endl;
		cout << "m9=" << endl << "" << m9 << endl << endl;
		waitKey(0);
		break;
	}

	case 2:  //��ʽ�����
	{		
		Mat r(10, 3, CV_8UC3);
		randu(r, Scalar::all(0), Scalar::all(255));

		cout << "<Ĭ�Ϸ��> r=" << endl << "" << r << endl << endl;
		cout << "<pythoon���> r=" << endl << "" << format(r, Formatter::FMT_PYTHON) << endl << endl;
		cout << "<���ŷ��> r=" << endl << "" << format(r, Formatter::FMT_CSV) << endl << endl;
		cout << "<c���> r=" << endl << "" << format(r, Formatter::FMT_C) << endl << endl;
		cout << "<Ĭ�Ϸ��> r=" << endl << "" << format(r, Formatter::FMT_DEFAULT) << endl << endl;
		cout << "<matlab���> r=" << endl << "" << format(r, Formatter::FMT_MATLAB) << endl << endl;
		cout << "<numpy���> r=" << endl << "" << format(r, Formatter::FMT_NUMPY) << endl << endl;
		waitKey(0);
		break;
	}

	case 3:  //��������������ݽṹ
	{
		Point2f p2f(6, 5); //��ά��
		Point3f p3f(6, 5, 6);  //��ά��

		vector<float> v;
		v.push_back(6);
		v.push_back(4);
		v.push_back(7);

		vector<Point2f> points(20);
		for (size_t i = 0; i < points.size(); i++)
		{
			points[i] = Point2f(i * 5, i);
		}

		cout << "p2f=" << endl << "" << p2f << endl << endl;
		cout << "p3f=" << endl << "" << p3f << endl << endl;
		cout << "v=" << endl << "" << Mat(v) << endl << endl;
		cout << "points=" << endl << "" << points << endl << endl;

		waitKey(0);
		break;

	}

	case 4:
	{
		Mat src = imread("tan.jpg"),pro_src;
		cvtColor(src, pro_src, COLOR_BGR2GRAY);
		namedWindow("�����ͼ", 0);
		imshow("�����ͼ", pro_src);
		waitKey();
	}

	default:
		break;
	}
}

void chapter5_test()
{
	Mat src_img = imread("me.jpg");  //jpg��JPG�����ִ�Сд
	Mat logo_img = imread("dota_logo.jpg");
	if (!src_img.data || !logo_img.data)
	{
		printf("��ȡ����");
	}

	else
	{
		//����һ
		Mat img_roi = src_img(Rect(src_img.cols/2, src_img.rows/2, logo_img.cols, logo_img.rows));

		//������,ע��range�����к���
		//Mat img_roi = src_img(Range(src_img.rows/ 2, src_img.rows / 2 + logo_img.rows),\
			Range(src_img.cols / 2, src_img.cols / 2 + logo_img.cols));

		//������Ĥ����Ĥ�����ǻҶ�ͼ
		Mat mask = imread("dota_logo.jpg", 0);

		//ע������ʽ�е����
		logo_img.copyTo(img_roi, mask);

		namedWindow("ROI��ʾ", 0);
		imshow("ROI��ʾ", src_img);

		waitKey(0);

	}


}