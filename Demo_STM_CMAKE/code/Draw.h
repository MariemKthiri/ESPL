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


int carSize=10;
static const uint16_t displaySizeX = 320, displaySizeY = 240;


double posCar=0;
double y=0;
int i=0;

void DrawStartMenu(){};
void DrawCourseMenu();
void DrawCourse1(){};
void DrawCourse2(){};
void DrawCourse3(){};




void DrawInfo(CourseNum){
	char str[100];
	font_t font1; // Load font for ugfx
	font1 = gdispOpenFont("DejaVuSans24*");
	if(CourseNum==1){
		double positionTrack1[26][2]={{35,displaySizeY-50},{46,displaySizeY-50},{50,displaySizeY-50},{60,displaySizeY-50},{70,displaySizeY-50},{80,displaySizeY-50},{90,displaySizeY-50},
					{98,displaySizeY-48},{101,displaySizeY-40},{98,displaySizeY-32},{90,displaySizeY-29},{80,displaySizeY-29},{70,displaySizeY-29},{60,displaySizeY-29},{50,displaySizeY-29},
					{46,displaySizeY-18},{38,displaySizeY-10},{35,displaySizeY-26},{24,displaySizeY-10},{25,displaySizeY-18},{25,displaySizeY-29},{25,displaySizeY-39},{27,displaySizeY-47},{27,displaySizeY-50}
			};





			gdispFillArea(0,0,displaySizeX,displaySizeY/6, White);
			gdispFillArea(0,3*displaySizeY/4,displaySizeX,displaySizeY, White);


			//Draw course on the screen
			gdispDrawThickArc(90,displaySizeY-40,9,11,-90,90,Red );
			gdispDrawThickArc(35,displaySizeY-24+5,9,11,180,360,Red );
			gdispDrawThickLine(35,displaySizeY-50,90,displaySizeY-50,Red,3,1 );
			gdispDrawThickLine(57,displaySizeY-29,90,displaySizeY-29,Red,3,1 );
			gdispDrawThickLine(25,displaySizeY-39,25,displaySizeY-19,Red,3,1 );
			gdispDrawThickArc(35,displaySizeY-39,9,11,90,180,Red );
			gdispDrawThickArc(57,displaySizeY-18,9,11,90,180,Red );

			//for (int i=0; i<26;i++){
			int posTrack= (int) posCar/10000;
			gdispFillCircle (positionTrack1[posTrack][0],positionTrack1[posTrack][1],5,Black);
			//}

	}
	if(CourseNum==2){
	double positionTrack2[26][2]={{20,3*displaySizeY/4+10},{40,3*displaySizeY/4+10},{60,3*displaySizeY/4+10},{100,3*displaySizeY/4+10},
	{115,3*displaySizeY/4+20},{115,3*displaySizeY/4+40},{100,3*displaySizeY/4+50},{85,3*displaySizeY/4+50},{70,3*displaySizeY/4+50},
	{65,225},{70,220},{85,220},{87.5,215},{85,210},{60,210},{30,210},{25,215},{30,220},{50,220},{55,225},{50,230},{30,230},
	{20,230},{10,220},{10,200}
	};


	gdispFillArea(0,0,displaySizeX,displaySizeY/6, White);
	gdispFillArea(0,3*displaySizeY/4,displaySizeX,displaySizeY, White);

	//Draw Course
	gdispDrawThickLine(22,3*displaySizeY/4+9,100,3*displaySizeY/4+9,Black,3,1);
	gdispDrawThickArc(22,3*displaySizeY/4+30,20,22,90,270,Black);
	gdispDrawThickArc(100,3*displaySizeY/4+30,20,22,-90,90,Black);
	gdispDrawThickLine(22,3*displaySizeY/4+51,50,3*displaySizeY/4+51,Black,3,1);
	gdispDrawThickLine(70,3*displaySizeY/4+51,100,3*displaySizeY/4+51,Black,3,1);
	gdispDrawThickArc(50,3*displaySizeY/4+45,5,7,-90,90,Black);
	gdispDrawThickArc(70,3*displaySizeY/4+45,5,7,90,270,Black);
	gdispDrawThickLine(30,3*displaySizeY/4+39,50,3*displaySizeY/4+39,Black,3,1);
	gdispDrawThickLine(70,3*displaySizeY/4+39,90,3*displaySizeY/4+39,Black,3,1);
	gdispDrawThickArc(30,3*displaySizeY/4+34,5,7,90,270,Black);
	gdispDrawThickArc(90,3*displaySizeY/4+34,5,7,-90,90,Black);
	gdispDrawThickLine(30,3*displaySizeY/4+28,90,3*displaySizeY/4+28,Black,3,1);
	//Draw position on track

	int posTrack = (int) posCar/10000;
	gdispDrawCircle(positionTrack2[posTrack][0],positionTrack2[posTrack][1],2,Red);
	gdispFillCircle(positionTrack2[posTrack][0],positionTrack2[posTrack][1],2,Red);
	}

}

void DrawWay(uint8_t joystickPositionY) {

	int i=0;

	double v=(200-joystickPositionY)/60; //velocity's factor
	if (v>0){
	        y=y+1+v; //Add with acceleration and deceleration
	        }
    else
	    {
	    if (joystickPositionY<250)
	    y=y+1-0,5*v;
	    }

   int j=-20;
   double posXmin=-255-3*carSize;

   posCar=posCar+y;
   if (y>3*displaySizeY/4)
	   y=0;
   double k=0;
	while (i<20) { //


		gdispFillArea(0,y+i*(displaySizeY/20),displaySizeX,displaySizeY/20, Black);
		gdispFillArea(0,y+(i+1)*(displaySizeY/20),displaySizeX,displaySizeY/20, White);


		gdispFillArea(0,y+j*(displaySizeY/20),displaySizeX,displaySizeY/20, Black);
		gdispFillArea(0,y+(j+1)*(displaySizeY/20),displaySizeX,displaySizeY/20, White);


        k=k+1;
		i=i+2;
		j=j+2;

	    }

}
void DrawWayStraight(uint8_t joystickPositionX,uint8_t joystickPositionY){
    //Draw the rode lines
	double factor=128/(displaySizeX/6); //Stabilization factor
    double posX=(128-joystickPositionX)/factor+2*carSize;
    double BorderRight[100];
	double BorderLeft[100];
    int i=0;

    for (int k=0; k<80; k++) {
    	BorderLeft[k]=-3*carSize+posX+displaySizeX/3;
    	BorderRight[k]=posX+2*displaySizeX/3;
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
	double factor=128/(displaySizeX/6); //Stabilization factor
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
	double factor=128/(displaySizeX/6); //Stabilization factor
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
 //-----------------------------------Draw static car------------------------------------------
char CarOption='a';
void DrawCar(CarOption) {
	if (CarOption=='a'){
	gdispFillArea(displaySizeX/2, 3*displaySizeY/4-carSize, carSize, carSize,Red);
	}
}


#endif /* CODE_DRAW_H_ */
