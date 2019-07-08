#include<iostream>
#include<fstream>
#include"Plate.hpp"
//#include"Plate.cpp"
#include"Cut.cpp"
using namespace std;

int main(int argc,char* argv[])
{
	//读取车牌图片文件存入Plate[577][184]
	for(int i=1;i<=10;i++)
	{
		fstream pic;
		char* filepath=argv[i];
		pic.open(filepath,ios::binary|ios::in);
		pic.read((char*)Plate,577*184);
		pic.close();
		for(int j=0;j<577;j++)
		{
			for(int k=0;k<184;k++)
			{
				AllPlate[i-1][j][k]=Plate[j][k];
			}
		}
	}
	int number=(int)(argv[argc-1][0]-0x30);
	for(int i=0;i<577;i++)
	{
		for(int j=0;j<184;j++)
		{
			Plate[i][j]=AllPlate[number][i][j];
		}
	}

	//识别车牌2～6号字符
	/*for(int j=2;j<=6;j++)
	{
		Recognition(j);
	}
	cout<<endl;*/
	
	//
	Projection();
	cout<<"==========Vertical Projection=========="<<endl;
	int min=184;
	int min_point=0;
	for(int i=0;i<577;i++)
	{
		//cout<<"V"<<i<<": "<<Vertical[i]<<endl;
		/*if(Vertical[i]>20&&Vertical[i]<=min)
		{
			min=Vertical[i];
			min_point=i;
		}*/
	}
	//cout<<"Minimum "<<min<<" at "<<"V"<<min_point<<endl;
	min=184;
	min_point=0;
	cout<<"==========Horizontal Projection=========="<<endl;
	for(int i=0;i<184;i++)
	{
		//cout<<"H"<<i<<": "<<Horizontal[i]<<endl;
		/*if(Horizontal[i]>20&&Horizontal[i]<=min)
		{
			min=Horizontal[i];
			min_point=i;
		}*/
	}
	//cout<<"Minimum "<<min<<" at "<<"H"<<min_point<<endl;
	for(int i=3;i<10;i++)
	{
		if(Vertical_Cut[i][0]!=0||Vertical_Cut[i][1]!=0)
		{
			cout<<"Charecter "<<i<<" Cut at ";
			cout<<"X"<<Vertical_Cut[i][0]<<" to "<<"X"<<Vertical_Cut[i][1];
			cout<<endl;
		}
	}
	for(int i=0;i<10;i++)
	{
		if(Horizontal_Cut[i][0]!=0||Horizontal_Cut[i][1]!=0)
		{
			cout<<"Charecter "<<i<<" Cut at ";
			cout<<"Y"<<Horizontal_Cut[i][0]<<" to "<<"Y"<<Horizontal_Cut[i][1];
			cout<<endl;
		}
	}
	
	return 0;
}

