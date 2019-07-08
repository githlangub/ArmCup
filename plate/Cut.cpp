 #include<iostream>
 #include"Plate.hpp"
using namespace std;
 
 void Projection(void)
 {
 	//投影 
 	for(int i=0;i<HEIGHT;i++)
 	{
 		for(int j=0;j<WIDTH;j++)
 		{
 			if(Plate[j][i]==1)
 			{
 				Vertical[j]++;
 				Horizontal[i]++;
			 }
		 }
	 }
	
	//归一化 
	for(int i=0;i<WIDTH;i++)
	{
			Vertical[i]=(Vertical[i]/(double)HEIGHT)>TH_nor_V?1:0;
	}
	for(int i=0;i<HEIGHT;i++)
	{
			Horizontal[i]=(Horizontal[i]/(double)WIDTH)>TH_nor_H?1:0;
	}
	
	//降噪
	bool up=0,down=0;
	int up_point=0,down_point=0;
	int char_count=0;
	for(int i=1;i<WIDTH;i++) 
	{
		if(Vertical[i]==1&&Vertical[i-1]==0)
		{
			up=1;
			up_point=i;
		}
		if(Vertical[i]==0&&Vertical[i-1]==1)
		{
			down=1;
			down_point=i;
		}
		if(up&&down)
		{
			up=down=0;
			if((double)(down_point-up_point)/WIDTH>TH_noi_X)
			{
				char_count++;
				Vertical_Cut[char_count][0]=up_point;
				Vertical_Cut[char_count][1]=down_point;
				up_point=down_point=0;
			}
		}
	}
	up=down=0;
	up_point=down_point=0;
	char_count=0;
	for(int i=1;i<WIDTH;i++) 
	{
		if(Horizontal[i]==1&&Horizontal[i-1]==0)
		{
			up=1;
			up_point=i;
		}
		if(Horizontal[i]==0&&Horizontal[i-1]==1)
		{
			down=1;
			down_point=i;
		}
		if(up&&down)
		{
			up=down=0;
			if((double)(down_point-up_point)/HEIGHT>TH_noi_Y)
			{
				char_count++;
				Horizontal_Cut[char_count][0]=up_point;
				Horizontal_Cut[char_count][1]=down_point;
				up_point=down_point=0;
			}
		}
	}
 }
 


double District_Count(int left,int right,int up,int down)
{
	int count=0;
	for(int i=up;i<=down;i++)
	{
		for(int j=left;j<=right;j++)
		{
			if(Plate[j][i]==1)
			{
				count++;
			}
		}
	}
	return count/(double)((right-left)*(down-up));
}



void Cal(void)
{
}
