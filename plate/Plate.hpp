#ifndef __PLATE_HPP__
#define __PLATE_HPP__

#define WIDTH 577
#define HEIGHT 184

unsigned char Plate[WIDTH][HEIGHT];   //车牌数据
unsigned char AllPlate[10][WIDTH][HEIGHT];

const unsigned char White=1,Black=0;   //白为0,黑为1

const int ThW=10,ThB=10;   //白色阈值，黑色阈值（可以被认为是数字/空位的最小长度，可调）

const int StandardFeature[10][5]={	{1,2,2,1,2},
					{0,1,1,0,1},
					{1,1,1,1,3},
					{1,1,1,0,3},
					{1,1,2,1,2},
					{0,1,1,0,3},
					{0,1,2,1,3},
					{1,1,1,0,2},
					{1,2,2,1,3},
					{1,2,1,0,3}};   //标准车牌数字特征（10个数字，x1、x2、x3、x4、y检测线）

int Position[7][4]={	{23,85,26,154},
			{95,157,26,154},
			{207,267,26,154},
			{280,340,26,154},
			{353,413,26,154},
			{427,486,26,154},
			{500,560,26,154}};   //车牌字符位置参考值，建议由切割算法生成(7个字符，左、右、上、下边界坐标)

int Feature[5]={0};   //被测车牌数字特征

const double TH_nor_H=10.00/WIDTH;
const double TH_nor_V=10.00/HEIGHT;
const double TH_noi_X=5.00/WIDTH;
const double TH_noi_Y=5.00/HEIGHT;

int Vertical_Cut[10][2]={0};
int Horizontal_Cut[10][2]={0};
int Vertical[577]={0};
int Horizontal[184]={0};

double District_Count[10][9]={0.00};

#endif

