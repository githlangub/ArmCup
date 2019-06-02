#ifndef __PLATE_HPP__
#define __PLATE_HPP__

unsigned char Plate[577][184];

const unsigned char White=1,Black=0;

const int ThW=10,ThB=10;

//const int StandardFeature[10][3]={{},
				//	};
int StandardFeature[10][5]={	{1,2,2,1,2},
				{0,1,1,0,1},
				{1,1,1,1,3},
				{1,1,1,0,3},
				{1,1,2,1,2},
				{0,1,1,0,3},
				{0,1,2,1,3},
				{1,1,1,0,2},
				{1,2,2,1,3},
				{1,2,1,0,3}};

int Position[7][4]={	{23,85,26,154},
			{95,157,26,154},
			{207,267,26,154},
			{280,340,26,154},
			{353,413,26,154},
			{427,486,26,154},
			{500,560,26,154}};

int Feature[5]={0};

#endif

