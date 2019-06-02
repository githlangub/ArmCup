#include<iostream>
#include"Plate.hpp"

int LineCheck(int x1,int x2,int y)
{
	int overlap_num=0,white_count=0,black_count=0;

	//
	for(int i=x1;i<=x2;i++)
	{
		if(white_count==0)
		{
			if(Plate[i][y]==White)
			{
				white_count++;
			}
		}
		else if(black_count==0)
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
		else
		{
			if(Plate[i][y]==Black)
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
		if(white_count>=ThW&&(black_count>=ThB||i==x2))
		{
			overlap_num++;
			white_count=0;
			black_count=0;
		}
		else if(white_count>=ThW&&black_count>=ThB)
		{
			white_count=0;
			black_count=0;
		}
	}

	//
	return overlap_num;
}

int ColumnCheck(int y1,int y2,int x)
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

	//
	return overlap_num;
}

int PointCheck(int x1,int x2,int line1,int line2)
{
}

void Recognition(int position)
{
	using namespace std;

	//
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

	//
	Feature[0]=LineCheck(middle,right,line1);
	Feature[1]=LineCheck(left,right,line2);
	Feature[2]=LineCheck(left,right,line3);
	Feature[3]=LineCheck(left,middle,line4);
	Feature[4]=ColumnCheck(up,down,column);

	//
	for(int i=0;i<sizeof(StandardFeature)/sizeof(int);i++)
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
		else
		{
			cout<<"?";
		}
	}
	cout<<endl;
}
