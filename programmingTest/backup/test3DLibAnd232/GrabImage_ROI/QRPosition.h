#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "zbar.h"
#include <math.h>

#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;
using namespace zbar;

typedef struct PostionInfo
{
	float xPosition;
	float yPosition;
	float depth;
	float slopeAngle;
};

class QRLocation
{
public:
	QRLocation(){};
	~QRLocation(){};
	string inputCode;
	vector<Point> zbarScan(Mat& input, string &codeInfo);
	vector<string> getStringMunber(string& codeInfo);

	// ��ĳ���
	float CODELENGTH = 40;

	//�궨����
	float ANGLE_DATA = 0.0724;
	float fx = 760.8522;
	float fy = 760.9905;
	float u0 = 462.3623;
	float v0 = 329.8684;

	// ֻ�����е�fx��ͨ��cos��x,yͨ����ֱ���ظ�����������������
	PostionInfo localizeXYZ(vector<Point>& QR, Mat& img);

	// ͨ���궨��Ľ�����任�������������굽�������ı任��x y����ͨ��z�ı任�������
	PostionInfo localizeXYZCalibXY(vector<Point>& QR, Mat& img);

	//�벻����ʱ�򣬼�����ֱ��������ظ�ʽ
	vector<float> getVerticalPixelsNumbers(vector<Point>& QR);

	// ����������ֱ������������б��
	void getAngleByPixelsNumbers(vector<Point>& QR, ofstream& imageInformation, \
		Mat& img, vector<float>& PixelsNumbers);

	// ����ͷ�ص�����������localization����
	void* callLocalizationFunction(void* pImg);

	// ����ά�����򵥶���ȡ����
	Rect getQRRegionRectangle(vector<Point>& AllQR, int& imgWidth, int& imgHeight);

	// �궨��������̣��õ��ڲξ���������ת�����ƽ������
	void localizationByRmatrix(vector<vector<Point2f> >& image_points_seq,
		float matrix[][3], float distortion[5]);
};
