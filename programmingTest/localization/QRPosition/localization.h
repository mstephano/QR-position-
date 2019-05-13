#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

struct PostionInfo
{
	int xPosition;
	int yPosition;
	int depth;
	int theataX;
	int theataY;
	int theataZ;
};

class QRLocation
{
public:
	QRLocation(){
		
		CODELENGTH = 39.2;
		ANGLE_DATA = 0.0546;
		fx = 951.8508;
		fy = 951.9705;
		u0 = 650.7842;
		v0 = 536.4463;
		
		/*fx = 735.922;
		fy = 736.0184;
		u0 = 631.3601;
		v0 = 519.8215;*/
		
		outftxt=NULL;
		isSent = false;
		
		};
	~QRLocation(){};
	string inputCode;
	vector<string> codeInfo;
	vector<Point> zbarScan(Mat& input, int centerPos[]);

	// ��ĳ���
	float CODELENGTH;

	//�궨����
	float ANGLE_DATA ;
	float fx;
	float fy;
	float u0;
	float v0;

	//��ӡ��λ��Ϣ���ĵ���
	ofstream* outftxt;
	
	// �Ƿ��Ͷ�λ��Ϣ
	bool isSent;

	// ��λ���
	PostionInfo results;
	
	// �Ƿ񱨴�
	
	int isError;

	// ֻ�����е�fx��ͨ��cos��x,yͨ����ֱ���ظ�����������������
	//void localizeXYZ(vector<Point>& QR, Mat& img);
	//void localizeXYZCenter(vector<Point>& QR, Mat& img);

	// ͨ���궨��Ľ�����任�������������굽�������ı任��x y����ͨ��z�ı任�������
	//void localizeXYZCalibXY(vector<Point>& QR, Mat& img);

	//�벻����ʱ�򣬼�����ֱ��������ظ�ʽ
	//vector<float> getVerticalPixelsNumbers(vector<Point>& QR);

	// ����������ֱ������������б��
	//void getAngleByPixelsNumbers(vector<Point>& QR, ofstream& imageInformation, \
		Mat& img, vector<float>& PixelsNumbers);

	// ����ͷ�ص�����������localization����
	//void* callLocalizationFunction(void* pImg, ofstream* outf, float resizePara);
	bool callLocalizationByRmatrix(void* pImg, float resizePara, \
									float codeLength, float upCenterX, \
									float lowerCenterY, bool isUp, int codeNumbers, int& isError);
	//bool callLocalizeXYZCenter(void* pImg, float resizePara);

	// ����ά�����򵥶���ȡ����
	Rect getQRRegionRectangle(vector<Point>& AllQR, int& imgWidth, int& imgHeight, float resizePara);

	// �궨��������̣��õ��ڲξ���������ת�����ƽ������
	//void localizationByRmatrix(vector<vector<Point2f> >& image_points_seq,
		//float matrix[][3], float distortion[5]);
		
	void localizationByRmatrix(vector<vector<Point2f> >&image_points_seq, vector<vector<Point3f> >&object_points);
};