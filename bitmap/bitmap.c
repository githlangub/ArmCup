#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	short a;char b;   //文件类型，为BM
	unsigned FileSize;   //文件大小（Byte）
	unsigned short Reserved1;   //BMP保留字1，为0
	unsigned short Reserved2;   //BMP保留字2，为0
	unsigned BitmapOffset;   //文件头长度/BMP首地址偏移量（Byte）
}tag_BitmapFileHeader;

typedef struct
{
	unsigned BitmapInfoSize;   //位图信息长度（Byte）
	int Width;   //宽度（Pixel）
	unsigned Height;   //高度（Pixel）
	unsigned short Planes;   //目标设备类型，为1
	unsigned short BitCount;   //单像素点大小（1,4,8,24,32 bit）
	unsigned Compression;   //压缩类型，为0
	unsigned BitmapSize;   //4B对齐位图数据大小（Byte）
	unsigned xPPM;   //水平分辨率（Pixel per Meter）
	unsigned yPPM;   //垂直分辨率（Pixel per Meter）
	unsigned ColorUsed;   //所用的颜色？
	unsigned ImportantColor;   //重要的颜色？
}tag_BitmapInformation;

typedef struct
{
	tag_BitmapFileHeader BitmapFileHeader;
	tag_BitmapInformation BitmapInformation;
}tag_BitmapHeader,* p_BitmapHeader;

typedef struct
{
	unsigned char Blue;
	unsigned char Green;
	unsigned char Red;
	unsigned char Reserved;
}BitmapRGBQuad;

int main()
{
	FILE* fp1=fopen("../tp1.bmp","rb");
	p_BitmapHeader bmp1=(p_BitmapHeader)malloc(sizeof(tag_BitmapHeader));
	int n=fread(bmp1,sizeof(tag_BitmapHeader),1,fp1);
	printf("%x\n",bmp1->BitmapFileHeader.BitmapOffset);
	//printf("%x\n",*((unsigned*)((unsigned char*)bmp1+2)));
	int ret=fclose(fp1);

	return 0;
}
