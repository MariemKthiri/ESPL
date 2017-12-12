/**
 * This is the main file of the ESPLaboratory Demo project.
 * It implements simple sample functions for the usage of UART,
 * writing to the display and processing user inputs.
 *
 * @author: Jonathan Müller-Boruttau,
 * 			Tobias Fuchs tobias.fuchs@tum.de
 * 			Nadja Peters nadja.peters@tum.de (RCS, TUM)
 *
 */
#include "includes.h"
#include "math.h"
#include "timers.h"
#include "StaticAllocation.h"
#include "Draw.h"

#define PIXMAP_WIDTH	100
#define PIXMAP_HEIGHT	100
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
// start and stop bytes for the UART protocol
static const uint8_t startByte = 0xAA, stopByte = 0x55;

//static const uint16_t displaySizeX = 320, displaySizeY = 240;

QueueHandle_t ESPL_RxQueue; // Already defined in ESPL_Functions.h
SemaphoreHandle_t ESPL_DisplayReady;

// Stores lines to be drawn
QueueHandle_t JoystickQueue;

struct coord joystickPosition = { 0, 0 };
char connect_uart = 0;



//---------------------Declare tasks---------------


//---------------------Declare globals-----------------------

StaticTask_t xTaskBuffer;
StackType_t xStack[1000];
uint8_t joystickPositionX,joystickPositionY;


//Declare the Game states type
typedef enum
{StartMenu,CoursesMenu,Game,PauseMenu,EndMenu } State;
static State CurrentState=StartMenu;

//Declare the Mode type
typedef enum
{OnePlayerMode,TwoPlayerMode} Mode;
Mode CurrentMode=OnePlayerMode;

//Declare course number
int CourseNum=1;

//Declare Button variables (Bool)
int ButtonE=0;
int ButtonF=0;
int ButtonA=0;
int ButtonB=0;
int ButtonC=0;

//----------------Semaphores && Notifications---------------------


//----------------Start the main---------------------

int main() {

	// Initialize Board functions and graphics
	ESPL_SystemInit();

	// Initializes Draw Queue with 100 lines buffer
	JoystickQueue = xQueueCreate(100, 2 * sizeof(char));

	// Initializes Tasks with their respective priority

	xTaskCreate(drawTask, "drawTask", 1000, NULL, 1, NULL);
	xTaskCreate(checkJoystick, "checkJoystick", 1000, NULL, 5, NULL); //comment if the board is Receiver

	// Start FreeRTOS Scheduler
	vTaskStartScheduler();

}


static void SystemState()
{
	while(1)
	{
		switch(CurrentState)
		{
		case StartMenu:
			if (ButtonF){
				CurrentMode=OnePlayerMode;
			    CurrentState=CoursesMenu;
			}
			if (ButtonE)
			{
				CurrentMode=TwoPlayerMode;
	            CurrentState=CoursesMenu;
			}
		break;
		case CoursesMenu:
			if (ButtonA)
			{
				CourseNum=1;
				CurrentState=Game;
			}
			if (ButtonB)
			{
				CourseNum=2;
				CurrentState=Game;
			}
			if (ButtonC)
			{
				CourseNum=3;
				CurrentState=Game;
			}

		break;
		case Game:

			if (ButtonE)
			CurrentState=PauseMenu;

		break;
		case PauseMenu:

			if (ButtonA)
			CurrentState=Game;
			if (ButtonB)
			CurrentState=StartMenu;
		break;
		case EndMenu:
			if (ButtonB)
			CurrentState=StartMenu;
		break;
		}
	}
}

//---------------------------------------NEW FUNCTION WAY 1-----------------------------------------------------


//Example task which draws to the display.

void drawTask() {


	struct coord joystickPosition; // joystick queue input buffer


	while (TRUE) {

		while (xQueueReceive(JoystickQueue, &joystickPosition, 0) == pdTRUE);
		// Clear background
		gdispClear(White);
		font_t font1; // Load font for ugfx
		font1 = gdispOpenFont("DejaVuSans24*");
		char str[100];
		sprintf( str, "position  %d",joystickPosition.y);
		gdispDrawString(displaySizeX/2, displaySizeY/2, str, font1, Black);

	/*	switch(CurrentState)
				{
				case StartMenu:
				DrawStartMenu();
				break;
				case CoursesMenu:
				DrawCourseMenu();
				break;
				case Game:
					DrawWay(joystickPosition.y);
					if (CourseNum==1)
				    DrawCourse1();
					if (CourseNum==2)
				    DrawCourse2();
					if (CourseNum==3)
				    DrawCourse3();
					DrawCar('a');
					DrawInfo(CourseNum);
				break;
				case PauseMenu:
				    DrawPauseMenu();

				break;
				case EndMenu:
				    DrawEndMenu();
				break;
				}
				*/
		DrawWay(joystickPosition.y);
		DrawWayRight(joystickPosition.x,joystickPosition.y,20,10);

		DrawCar(CarOption);
		DrawInfo(CourseNum);

		// Wait for display to stop writing
		xSemaphoreTake(ESPL_DisplayReady, portMAX_DELAY);



		// swap buffers
		ESPL_DrawLayer();





	}

}

//This task polls the joystick value every 20 ticks

void checkJoystick() {
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
//struct coord joystickPosition = {0, 0};
	const TickType_t tickFramerate = 1;

	while (TRUE) {
		// Remember last joystick values
		joystickPosition.x = (uint8_t) (ADC_GetConversionValue(
				ESPL_ADC_Joystick_2) >> 4);
		joystickPosition.y = (uint8_t) 255
				- (ADC_GetConversionValue(ESPL_ADC_Joystick_1) >> 4);

		if (!connect_uart)
			xQueueSend(JoystickQueue, &joystickPosition, 100);

		// Execute every 20 Ticks
		vTaskDelayUntil(&xLastWakeTime, tickFramerate);
	}
}
