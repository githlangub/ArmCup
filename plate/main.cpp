#include<iostream>
#include<fstream>
#include"Plate.hpp"
#include"Plate.cpp"
using namespace std;

int main(int argc,char* argv[])
{
	//读取车牌图片文件存入Plate[577][184]
	fstream pic;
	char* filepath=argv[1];
	pic.open(filepath,ios::binary|ios::in);
	pic.read((char*)Plate,577*184);
	pic.close();

	//识别车牌2～6号字符
	for(int j=2;j<=6;j++)
	{
		Recognition(j);
	}
	cout<<endl;
	return 0;
}
