#ifndef __PLATE_CPP__
#define __PLATE_CPP__

#include<iostream>
#include"Plate.hpp"

int LineCheck(int x1,int x2,int y)   //横向特征检测
{
	int overlap_num=0,white_count=0,black_count=0;   //交点数，白点数，黑点数

	//特征点检测，由左至右检查当前点颜色
	for(int i=x1;i<=x2;i++)
	{
		if(white_count==0)   //未遇到白点
		{
			if(Plate[i][y]==White)
			{
				white_count++;
			}
		}
		else if(black_count==0)   //遇到白点而未遇到黑点
		{
			if(Plate[i][y]==White)
			{
				white_count++;
			}
			else
			{
				black_count++;
			}
		}
		else   //已经过一段白色，一段黑色
		{
			if(Plate[i][y]==Black)
			{
				black_count++;
			}
			else   //再次遇到白点说明黑色未满足黑色阈值，则忽略前面黑色点
			{
				black_count=0;
				white_count++;
			}
		}

		//计数阈值检测
		if(white_count>=ThW&&(black_count>=ThB||i==x2))   //白点数到达阈值，且超出的黑点数也到达阈值，或者计数以达到边界，算作一个特征点
		{
			overlap_num++;
			white_count=0;
			black_count=0;
		}
		else if(white_count<ThW&&black_count>=ThB)   //只有黑点数到达阈值，看作噪点，清零等待下一次计数
		{
			white_count=0;
			black_count=0;
		}
	}

	//
	return overlap_num;
}

int ColumnCheck(int y1,int y2,int x)   //纵向特征点检测，与上面算法一致，仅xy坐标交换
{
	int overlap_num=0,white_count=0,black_count=0;

	//
	for(int i=y1;i<=y2;i++)
	{
		if(white_count==0)
		{
			if(Plate[x][i]==White)
			{
				white_count++;
			}
		}
		else if(black_count==0)
		{
			if(Plate[x][i]==White)
			{
				white_count++;
			}
			else
			{
				black_count++;
			}
		}
		else
		{
			if(Plate[x][i]==Black)
			{
				black_count++;
			}
			else
			{
				black_count=0;
				white_count++;
			}
		}

		//
		if(white_count>=ThW&&(black_count>=ThB||i==y2))
		{
			overlap_num++;
			white_count=0;
			black_count=0;
		}
		else if(white_count<ThW&&black_count>=ThB)
		{
			white_count=0;
			black_count=0;
		}
	}

	//返回交点数
	return overlap_num;
}

void Cut(void)   //字符切割算法还有个问题没想好，暂时没放上来
{
}

void Recognition(int position)   //单个字符识别
{
	using namespace std;

	//通过字符位置计算检测线位置
	int left=Position[position][0];
	int right=Position[position][1];
	int up=Position[position][2];
	int down=Position[position][3];
	int middle=(right+left)/2;
	int line1=up+(down-up)/4;
	int line2=up+(down-up)/3;
	int line3=down-(down-up)/3;
	int line4=line3;
	int column=middle;

	//特征检测
	Feature[0]=LineCheck(middle,right,line1);
	Feature[1]=LineCheck(left,right,line2);
	Feature[2]=LineCheck(left,right,line3);
	Feature[3]=LineCheck(left,middle,line4);
	Feature[4]=ColumnCheck(up,down,column);

	//特征对照，字符识别
	for(int i=0;i<sizeof(StandardFeature)/sizeof(StandardFeature[0]);i++)
	{
		bool match=1;
		for(int j=0;j<sizeof(Feature)/sizeof(int);j++)
		{
			if(Feature[j]!=StandardFeature[i][j])
			{
				match=0;
			}
		}
		if(match==1)
		{
			cout<<i<<"   ";
		}
	}
	cout<<endl;
}

#endif

