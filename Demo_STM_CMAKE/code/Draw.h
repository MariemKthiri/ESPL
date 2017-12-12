/*
 * Draw.h
 *
 *  Created on: Dec 1, 2017
 *      Author: lab_espl_stud06
 */

#ifndef CODE_DRAW_H_
#define CODE_DRAW_H_
#include "includes.h"
#include "math.h"


uint8_t carSize=20;
static const uint16_t displaySizeX = 320, displaySizeY = 240;
#define 	Teal   HTML2COLOR(0x008080)
font_t font; // Load font for ugfx

double posCar=0;
double y=0;
double increment=0;
int i=0;

void DrawInfo(int CourseNum);
void DrawTrack1(int a,int b,double increment);
void DrawTrack2(int a,int b,double increment);


void DrawStartMenu(){


	font_t font1; // Load font for ugfx
	font1 = gdispOpenFont("DejaVuSansBold80*");
	char str[100];
	sprintf( str, "Formula 1 Race Game");
	gdispDrawString(80, 85, str, font1, Black);
	//gdispDrawStringBox (displaySizeX/4,displaySizeY/4,200,80,str,font1,Blue,justifyCenter);
	int i = 0;
	while( i<30){
		gdispFillArea(i*displaySizeX/30,40,10,10, Black);
		gdispFillArea((i+1)*displaySizeX/30,40,10,10, White);
		i = i+2;
	}
	i = 0;
	while( i<30){
		gdispFillArea(i*displaySizeX/30,50,10,10, White);
		gdispFillArea((i+1)*displaySizeX/30,50,10,10, Black);
		i = i+2;
	}
	i = 0;
	while( i<30){
		gdispFillArea(i*displaySizeX/30,60,10,10, Black);
		gdispFillArea((i+1)*displaySizeX/30,60,10,10, White);
		i = i+2;
	}

	i = 0;
	while( i<30){
		gdispFillArea(i*displaySizeX/30,120,10,10, Black);
		gdispFillArea((i+1)*displaySizeX/30,120,10,10, White);
		i = i+2;
	}
	i = 0;
	while( i<30){
		gdispFillArea(i*displaySizeX/30,130,10,10, White);
		gdispFillArea((i+1)*displaySizeX/30,130,10,10, Black);
		i = i+2;
	}
	i = 0;
	while( i<30){
		gdispFillArea(i*displaySizeX/30,140,10,10, Black);
		gdispFillArea((i+1)*displaySizeX/30,140,10,10, White);
		i = i+2;
	}
	color_t color1 = Cyan, color2 = Cyan;

	gdispFillArea(30,160,110,40,color1);
	gdispDrawBox(30,160,110,40,Black);
	gdispDrawBox(35,165,100,30,Black);
	sprintf( str, "One Player Mode");
	gdispDrawString(40, 170, str, font1, Blue);
	gdispFillArea(180,160,115,40,color2);
	gdispDrawBox(180,160,115,40,Black);
	gdispDrawBox(185,165,105,30,Black);
	sprintf( str, "Two Player Mode");
	gdispDrawString(190, 170, str, font1, Blue);
	sprintf( str, "Press Button D");
	gdispDrawString(40, 210, str, font1, Black);
	sprintf( str, "Press Button B");
	gdispDrawString(190, 210, str, font1, Black);

};
void DrawPauseMenu(){};
void DrawEndMenu(){};
void DrawCourse1(){};





void DrawCourseMenu(){
	font = gdispOpenFont("DejaVuSans24*");
	char str[100];
	char strA[100];
	char strB[100];
	char strC[100];


	increment=increment+1;
	gdispFillArea(30,30,displaySizeX-60,displaySizeY-60, Teal);
	gdispFillArea(35,35,displaySizeX-60,displaySizeY-60, SkyBlue);
	gdispFillArea(70,50,displaySizeX-140,20, Blue);
	sprintf( str, "Choose one course");
	sprintf( strA, "Press A");
	sprintf( strB, "Press B");
	sprintf( strC, "Press C");
	gdispDrawString(120, 52, str, font, Yellow);
	gdispDrawString(60, displaySizeY-150, strA, font, Yellow);
	gdispDrawString(190, displaySizeY-150, strB, font, Yellow);
	DrawTrack1(20,-85,increment*1000); //Task can be used
	DrawTrack2(160,-85,increment*1000);

};

void DrawTrack1(int a,int b,double increment){
	//variables a and b are the offset of the position of the track
	double positionTrack1[26][2]={{35,displaySizeY-50},{46,displaySizeY-50},{50,displaySizeY-50},{60,displaySizeY-50},{70,displaySizeY-50},{80,displaySizeY-50},{90,displaySizeY-50},
				{98,displaySizeY-48},{101,displaySizeY-40},{98,displaySizeY-32},{90,displaySizeY-29},{80,displaySizeY-29},{70,displaySizeY-29},{60,displaySizeY-29},{50,displaySizeY-29},
				{46,displaySizeY-18},{38,displaySizeY-10},{35,displaySizeY-26},{24,displaySizeY-10},{25,displaySizeY-18},{25,displaySizeY-29},{25,displaySizeY-39},{27,displaySizeY-47},{27,displaySizeY-50}
		};




		//Draw course on the screen
		gdispDrawThickArc(90+a,displaySizeY-40+b,9,11,-90,90,Red );
		gdispDrawThickArc(35+a,displaySizeY-24+5+b,9,11,180,360,Red );
		gdispDrawThickLine(35+a,displaySizeY-50+b,90+a,displaySizeY-50+b,Red,3,1 );
		gdispDrawThickLine(57+a,displaySizeY-29+b,90+a,displaySizeY-29+b,Red,3,1 );
		gdispDrawThickLine(25+a,displaySizeY-39+b,25+a,displaySizeY-19+b,Red,3,1 );
		gdispDrawThickArc(35+a,displaySizeY-39+b,9,11,90,180,Red );
		gdispDrawThickArc(57+a,displaySizeY-18+b,9,11,90,180,Red );

		//for (int i=0; i<26;i++){
		int posTrack= (int) increment/10000;
		gdispFillCircle (positionTrack1[posTrack][0]+a,positionTrack1[posTrack][1]+b,3,Black);
		//}
}


void DrawTrack2(int a,int b,double increment){
	double positionTrack2[26][2]={{20,3*displaySizeY/4+10},{40,3*displaySizeY/4+10},{60,3*displaySizeY/4+10},{100,3*displaySizeY/4+10},
	{115,3*displaySizeY/4+20},{115,3*displaySizeY/4+40},{100,3*displaySizeY/4+50},{85,3*displaySizeY/4+50},{70,3*displaySizeY/4+50},
	{65,225},{70,220},{90,220},{95,215},{90,210},{60,210},{30,210},{25,215},{30,220},{50,220},{55,225},{50,230},{30,230},
	{20,230},{5,220},{5,200}
	};


	//Draw Course
	gdispDrawThickLine(22+a,3*displaySizeY/4+9+b,100+a,3*displaySizeY/4+9+b,Black,3,1);
	gdispDrawThickArc(22+a,3*displaySizeY/4+30+b,20,22,90,270,Black);
	gdispDrawThickArc(100+a,3*displaySizeY/4+30+b,20,22,-90,90,Black);
	gdispDrawThickLine(22+a,3*displaySizeY/4+51+b,50+a,3*displaySizeY/4+51+b,Black,3,1);
	gdispDrawThickLine(70+a,3*displaySizeY/4+51+b,100+a,3*displaySizeY/4+51+b,Black,3,1);
	gdispDrawThickArc(50+a,3*displaySizeY/4+45+b,5,7,-90,90,Black);
	gdispDrawThickArc(70+a,3*displaySizeY/4+45+b,5,7,90,270,Black);
	gdispDrawThickLine(30+a,3*displaySizeY/4+39+b,50+a,3*displaySizeY/4+39+b,Black,3,1);
	gdispDrawThickLine(70+a,3*displaySizeY/4+39+b,90+a,3*displaySizeY/4+39+b,Black,3,1);
	gdispDrawThickArc(30+a,3*displaySizeY/4+34+b,5,7,90,270,Black);
	gdispDrawThickArc(90+a,3*displaySizeY/4+34+b,5,7,-90,90,Black);
	gdispDrawThickLine(30+a,3*displaySizeY/4+28+b,90+a,3*displaySizeY/4+28+b,Black,3,1);
	//Draw position on track

	int posTrack = (int) increment/10000;
	gdispDrawCircle(positionTrack2[posTrack][0]+a,positionTrack2[posTrack][1]+b,2,Red);
	gdispFillCircle(positionTrack2[posTrack][0]+a,positionTrack2[posTrack][1]+b,2,Red);
	}

void DrawTrack3(int a,int b,double increment){
	double positionTrack2[26][2]={{20,3*displaySizeY/4+10},{40,3*displaySizeY/4+10},{60,3*displaySizeY/4+10},{100,3*displaySizeY/4+10},
	{115,3*displaySizeY/4+20},{115,3*displaySizeY/4+40},{100,3*displaySizeY/4+50},{85,3*displaySizeY/4+50},{70,3*displaySizeY/4+50},
	{65,225},{70,220},{90,220},{95,215},{90,210},{60,210},{30,210},{25,215},{30,220},{50,220},{55,225},{50,230},{30,230},
	{20,230},{5,220},{5,200}
	};


	//Draw Course
	gdispDrawThickLine(22+a,3*displaySizeY/4+9+b,100+a,3*displaySizeY/4+9+b,Black,3,1);
	gdispDrawThickArc(22+a,3*displaySizeY/4+30+b,20,22,90,270,Black);
	gdispDrawThickArc(100+a,3*displaySizeY/4+30+b,20,22,-90,90,Black);
	gdispDrawThickLine(22+a,3*displaySizeY/4+51+b,50+a,3*displaySizeY/4+51+b,Black,3,1);
	gdispDrawThickLine(70+a,3*displaySizeY/4+51+b,100+a,3*displaySizeY/4+51+b,Black,3,1);
	gdispDrawThickArc(50+a,3*displaySizeY/4+45+b,5,7,-90,90,Black);
	gdispDrawThickArc(70+a,3*displaySizeY/4+45+b,5,7,90,270,Black);
	gdispDrawThickLine(30+a,3*displaySizeY/4+39+b,50+a,3*displaySizeY/4+39+b,Black,3,1);
	gdispDrawThickLine(70+a,3*displaySizeY/4+39+b,90+a,3*displaySizeY/4+39+b,Black,3,1);
	gdispDrawThickArc(30+a,3*displaySizeY/4+34+b,5,7,90,270,Black);
	gdispDrawThickArc(90+a,3*displaySizeY/4+34+b,5,7,-90,90,Black);
	gdispDrawThickLine(30+a,3*displaySizeY/4+28+b,90+a,3*displaySizeY/4+28+b,Black,3,1);
	//Draw position on track

	int posTrack = (int) increment/10000;
	gdispDrawCircle(positionTrack2[posTrack][0]+a,positionTrack2[posTrack][1]+b,2,Red);
	gdispFillCircle(positionTrack2[posTrack][0]+a,positionTrack2[posTrack][1]+b,2,Red);
	}



void DrawInfo(int CourseNum){

	font = gdispOpenFont("DejaVuSans24*");
	char str[50];
	gdispFillArea(0,0,displaySizeX,displaySizeY/6, White);
	gdispFillArea(0,3*displaySizeY/4,displaySizeX,displaySizeY, White);
	sprintf( str, "%d",posCar);
	gdispDrawString(3*displaySizeX/4, 3*displaySizeY/4+30, str, font, Black);

	if(CourseNum==1){
			     //Draw Track for course 1 on the screen
			     DrawTrack1(0,0,posCar);
	}
	if(CourseNum==2){
		           //Draw Track for course 2 on the screen
		           DrawTrack2(0,0,posCar);
	}
	}

void DrawWay(uint8_t joystickPositionY) {

	//int i=0;

	double v=(200-joystickPositionY)/60; //velocity's factor
	if (v>0){
	        y=y+1+v; //Add with acceleration and deceleration
	        }
    else
	    {
	    if (joystickPositionY<250)
	    y=y+1-0,5*v;
	    }

   int j=-10;
   //double posXmin=-255-3*carSize;

   posCar=posCar+y;
   if ((2*y)>3*displaySizeY/4)
	   y=0;
   double k=0;

 //if (i>3*displaySizeY/4)
	// i=0;


        gdispFillArea(0,y,displaySizeX,(displaySizeY/20), Black);
        gdispFillArea(0,y+displaySizeY/10,displaySizeX,(displaySizeY/20)+10, Black);
        gdispFillArea(0,y+displaySizeY/5,displaySizeX,(displaySizeY/20)+20, Black);
		gdispFillArea(0,y+(3*displaySizeY/10),displaySizeX,(displaySizeY/20)+30, Black);
		gdispFillArea(0,y+(4*displaySizeY/10),displaySizeX,(displaySizeY/20)+50, Black);



/*	while (i<10) { //


		gdispFillArea(0,y+i*7.5,displaySizeX,7.5+i, Black);
		gdispFillArea(0,y+(i+1)*7.5+i,displaySizeX,7.5+i, White);


		gdispFillArea(0,y+j*7.5,displaySizeX,7.5+j, Black);
		gdispFillArea(0,y+(j+1)*7.5+j,displaySizeX,7.5+j, White);


        k=k+1;
		i=i+2;
		j=j+2;

	    }
*/
}
void DrawWayStraight(uint8_t joystickPositionX,uint8_t joystickPositionY){
    //Draw the rode lines
	double factor=128/(displaySizeX/6); //Stabilization factor
    double posX=(128-joystickPositionX)/factor+2*carSize;
    double BorderRight[100];
	double BorderLeft[100];
    int i=0;

    for (int k=0; k<80; k++) {
    	BorderLeft[k]=-3*carSize+posX+displaySizeX/3-k+39;
    	BorderRight[k]=posX+2*displaySizeX/3+k-39;
    }
	while (i<40) { //

	    if (BorderLeft[40]>displaySizeX/2)
	    	BorderLeft[i]=(displaySizeX)/2;
	    if (BorderRight[40]<displaySizeX/2)
	    	BorderRight[i]=(displaySizeX)/2+carSize;


		gdispFillArea(BorderLeft[i],i*(displaySizeY/40),BorderRight[i]-BorderLeft[i],displaySizeY/40, Green);

		i=i+1;


	    }

	//DrawWay(BorderLeft, BorderRight,joystickPositionY);

    }


void DrawWayRight(uint8_t joystickPositionX,uint8_t joystickPositionY, double translationOffset, double deviation){
    //Draw the road lines
	//double factor=128/(displaySizeX/6); //Stabilization factor
    double posX=(128-joystickPositionX)/1.5+2*carSize;
    double BorderRight[100];
	double BorderLeft[100];
    int i=0;

    for (int k=0; k<80; k++) {
    	BorderLeft[k]=-3*carSize+posX+displaySizeX/3+(39-k)*(39-k)/deviation-k+39+translationOffset;
    	BorderRight[k]=posX+2*displaySizeX/3+(39-k)*(39-k)/deviation+k-39+translationOffset;
    }
	while (i<40) { //

	    if (BorderLeft[30]>displaySizeX/2){
	    	//BorderLeft[i]=(displaySizeX)/2;
	    	BorderRight[i]=BorderRight[i]-(BorderLeft[30]-displaySizeX/2);
	    	BorderLeft[i]= BorderLeft[i]-(BorderLeft[30]-displaySizeX/2);

	    }
	    if (BorderRight[30]<displaySizeX/2+carSize){
	    	//BorderRight[i]=(displaySizeX)/2+carSize;
	    	BorderLeft[i]= BorderLeft[i]-(BorderRight[30]-displaySizeX/2-carSize);
	    	BorderRight[i]= BorderRight[i]-(BorderRight[30]-displaySizeX/2-carSize);
	    }

		gdispFillArea(BorderLeft[i],i*(displaySizeY/40),BorderRight[i]-BorderLeft[i],displaySizeY/40, Green);

		i=i+1;


	    }

    }



void DrawWayLeft(uint8_t joystickPositionX,uint8_t joystickPositionY, double translationOffset, double deviation){
    //Draw the road lines
	//double factor=128/(displaySizeX/6); //Stabilization factor
    double posX=(128-joystickPositionX)/1.5+2*carSize;
    double BorderRight[100];
	double BorderLeft[100];
    int i=0;

    for (int k=0; k<80; k++) {
    	BorderLeft[k]=-3*carSize+posX+displaySizeX/3-(39-k)*(39-k)/deviation-k+39-translationOffset;
    	BorderRight[k]=posX+2*displaySizeX/3-(39-k)*(39-k)/deviation+k-39-translationOffset;
    }
	while (i<40) { //

	    if (BorderLeft[30]>displaySizeX/2){
	    	//BorderLeft[i]=(displaySizeX)/2;
	    	BorderRight[i]=BorderRight[i]-(BorderLeft[30]-displaySizeX/2);
	    	BorderLeft[i]= BorderLeft[i]-(BorderLeft[30]-displaySizeX/2);

	    }
	    if (BorderRight[30]<displaySizeX/2+carSize){
	    	//BorderRight[i]=(displaySizeX)/2+carSize;
	    	BorderLeft[i]= BorderLeft[i]-(BorderRight[30]-displaySizeX/2-carSize);
	    	BorderRight[i]= BorderRight[i]-(BorderRight[30]-displaySizeX/2-carSize);
	    }

		gdispFillArea(BorderLeft[i],i*(displaySizeY/40),BorderRight[i]-BorderLeft[i],displaySizeY/40, Black);

		i=i+1;


	    }

    }

//-----------------------------------Draw Course 2--------------------------------------------
void DrawCourse2(uint8_t joystickPositionX,uint8_t joystickPositionY){
	if((posCar>=0)&&(posCar<50000)){
		DrawWayStraight(joystickPositionX,joystickPositionY);
		}
	if((posCar>=50000)&&(posCar<75000)){
		DrawWayRight(joystickPositionX,joystickPositionY,20,20);
		}
	if((posCar>=75000)&&(posCar<100000)){
			DrawWayRight(joystickPositionX,joystickPositionY,40,10);
		}
	if((posCar>=100000)&&(posCar<125000)){
			DrawWayRight(joystickPositionX,joystickPositionY,20,20);
		}
	if((posCar>=125000)&&(posCar<150000)){
			DrawWayStraight(joystickPositionX,joystickPositionY);
		}
	if((posCar>=150000)&&(posCar<160000)){
			DrawWayRight(joystickPositionX,joystickPositionY,20,20);
		}
	if((posCar>=160000)&&(posCar<170000)){
			DrawWayRight(joystickPositionX,joystickPositionY,40,10);
		}
	if((posCar>=170000)&&(posCar<180000)){
			DrawWayRight(joystickPositionX,joystickPositionY,20,20);
		}
	if((posCar>=180000)&&(posCar<200000)){
				DrawWayStraight(joystickPositionX,joystickPositionY);
		}
	if((posCar>=200000)&&(posCar<210000)){
			DrawWayLeft(joystickPositionX,joystickPositionY,20,20);
		}
	if((posCar>=210000)&&(posCar<220000)){
			DrawWayLeft(joystickPositionX,joystickPositionY,40,10);
		}
	if((posCar>=220000)&&(posCar<230000)){
			DrawWayRight(joystickPositionX,joystickPositionY,20,20);
		}
	if((posCar>=230000)&&(posCar<270000)){
				DrawWayStraight(joystickPositionX,joystickPositionY);
		}
};


//-----------------------------------Draw Course 3--------------------------------------------
void DrawCourse3(){

};


//-----------------------------------Draw static car------------------------------------------
char CarOption='a';
void DrawCar(char CarOption) {
	if (CarOption=='a'){
	gdispFillArea(displaySizeX/2, 3*displaySizeY/4-carSize, carSize, carSize,Red);
	gdispFillArea(displaySizeX/2-5, 3*displaySizeY/4-5, 5, 5,Black);
	gdispFillArea(displaySizeX/2+carSize, 3*displaySizeY/4-5, 5, 5,Black);
	}
}


#endif /* CODE_DRAW_H_ */
