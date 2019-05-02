#include<stdio.h>

typedef struct
{
	unsigned short FileType;   //文件类型，为BM
	unsigned FileSize;   //文件大小（Byte）
	unsigned short Reserved1;   //BMP保留字1，为0
	unsigned short Reserved2;   //BMP保留字2，为0
	unsigned BitmapOffset;   //文件头长度/BMP首地址偏移量（Byte）
}BitmapFileHeader;

typedef struct
{
	unsigned BitmapInfoSize;   //
	unsigned Width;   //
	unsigned Height;   //
	unsigned short Planes;   //
	unsigned short BitCount;   //
	unsigned Compression;   //
	unsigned BitmapSize;   //
	unsigned xPPM;   //
	unsigned yPPM;   //
	unsigned ColorUsed;   //
	unsigned ImportantColor;   //
}BitmapInfoHeader;
int main()
{
	int a;

	/*printf("long long: %d\n",sizeof(long long));
	printf("long: %d\n",sizeof(long));
	printf("int: %d\n",sizeof(int));
	printf("short: %d\n",sizeof(short));*/
	return 0;
}
