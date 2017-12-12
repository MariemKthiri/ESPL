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


//---------------------------------------Declare Timers----------------------------
TimerHandle_t xTimers; //Define the de-bouncing timer
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
int ButtonA=0;
int ButtonB=0;
int ButtonC=0;
int ButtonD=0;
int ButtonE=0;
int debounce = 0; //Restricts the execution of the Buttons

//----------------Semaphores && Notifications---------------------


//----------------Start the main---------------------

int main() {

	// Initialize Board functions and graphics
	ESPL_SystemInit();

	timer_Init();
	// Initializes Draw Queue with 100 lines buffer
	JoystickQueue = xQueueCreate(100, 2 * sizeof(char));

	// Initializes Tasks with their respective priority

	xTaskCreate(SystemState, "SystemState", 1000, NULL, 1, NULL);
	xTaskCreate(drawTask, "drawTask", 1000, NULL, 2, NULL);
	xTaskCreate(checkJoystick, "checkJoystick", 1000, NULL, 5, NULL); //comment if the board is Receiver

	// Start FreeRTOS Scheduler
	vTaskStartScheduler();

}


void ButtonA_Pressed(void)//Button A debounce task
{

	xTimerReset(xTimers, 0); //Resets the debouncing timer
	if(debounce == 0)
	 {

			if (GPIO_ReadInputDataBit(ESPL_Register_Button_A, ESPL_Pin_Button_A)==0)
			{
				ButtonA = 1;
				debounce = 1; //The function is executed
				//wait until the timer of the  debouncing expires
			}

	}

}


void ButtonB_Pressed(void)//Button B debounce task
{

	xTimerReset(xTimers, 0); //Resets the debouncing timer
	if(debounce == 0)
	 {

			if (GPIO_ReadInputDataBit(ESPL_Register_Button_B, ESPL_Pin_Button_B)==0)
			{
				ButtonB = 1;
				debounce = 1; //The function is executed
				//wait until the timer of the  debouncing expires
			}

	}

}

void ButtonC_Pressed(void)//Button C debounce task
{

	xTimerReset(xTimers, 0); //Resets the debouncing timer
	if(debounce == 0)
	 {

			if (GPIO_ReadInputDataBit(ESPL_Register_Button_C, ESPL_Pin_Button_C)==0)
			{
				ButtonC = 1;
				debounce = 1; //The function is executed
				//wait until the timer of the  debouncing expires
			}

	}

}

void ButtonD_Pressed(void)//ButtonDB debounce task
{

	xTimerReset(xTimers, 0); //Resets the debouncing timer
	if(debounce == 0)
	 {

			if (GPIO_ReadInputDataBit(ESPL_Register_Button_D, ESPL_Pin_Button_D)==0)
			{
				ButtonD = 1;
				debounce = 1; //The function is executed
				//wait until the timer of the  debouncing expires
			}

	}

}

void ButtonE_Pressed(void)//Button E debounce task
{

	xTimerReset(xTimers, 0); //Resets the debouncing timer
	if(debounce == 0)
	 {

			if (GPIO_ReadInputDataBit(ESPL_Register_Button_E, ESPL_Pin_Button_E)==0)
			{
				ButtonE = 1;
				debounce = 1; //The function is executed
				//wait until the timer of the  debouncing expires
			}

	}

}

//Function executed when the debouncing timer expires ---->  Resets the debounce variable and stops the timer

void vTimerCallback(TimerHandle_t pxTimer){
	//Allow the next button interruption
	debounce = 0;

	//Stop the timer
	xTimerStop(pxTimer, 0);
}


// Create the debouncing timer
void timer_Init(){
	//Software timer to debounce the button
	//xTimers = xTimerCreate("timer", 205 / portTICK_PERIOD_MS, pdTRUE, (void *)0, vTimerCallback);
	xTimers = xTimerCreate("timer",pdMS_TO_TICKS(200), pdTRUE, (void *)0, vTimerCallback);
	xTimerStart(xTimers, 0);
	xTimerStop(xTimers, 0);

}

void SystemState()
{
	while(1)
	{
		switch(CurrentState)
		{
		case StartMenu:
			ButtonB_Pressed();
			ButtonD_Pressed();

			if (ButtonD){
				CurrentMode=OnePlayerMode;
			    CurrentState=CoursesMenu;
				ButtonD = 0;
				vTaskDelay(300);
			}
			if (ButtonB)
			{
	            vTaskDelay(300);
				CurrentMode=TwoPlayerMode;
	            CurrentState=CoursesMenu;
	            ButtonB = 0;

			}

		break;
		case CoursesMenu:
			ButtonB_Pressed();

			if (ButtonA)
			{
				CourseNum=1;
				CurrentState=Game;
				ButtonA = 0;
				vTaskDelay(300);

			}
			if (ButtonB)
			{
				vTaskDelay(300);
				CourseNum=2;
				CurrentState=Game;
				ButtonB = 0;

			}
			if (ButtonC)
			{
				CourseNum=3;
				CurrentState=Game;
				ButtonC = 0;
				vTaskDelay(300);
			}

		break;
		case Game:
			ButtonE_Pressed();

			if (ButtonE)
			CurrentState=PauseMenu;

		break;
		case PauseMenu:
			ButtonB_Pressed();

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
		sprintf( str, "%s",CurrentState);
		gdispDrawString(displaySizeX/2, displaySizeY/2, str, font1, Black);



		switch(CurrentState)
				{

				case StartMenu:
					DrawStartMenu();
					ButtonB = 0;
					//vTaskDelay(500);
				break;


				case CoursesMenu:
						DrawCourseMenu();

						//vTaskDelay(500);
				break;
				case Game:
					DrawWay(joystickPosition.y);
					if (CourseNum==1)
				    DrawCourse1();
					if (CourseNum==2)
				    DrawCourse2(joystickPosition.x,joystickPosition.y);
					if (CourseNum==3)
				    DrawCourse3();
					DrawCar('a');
					DrawInfo(CourseNum);
					//vTaskDelay(500);
				break;
				case PauseMenu:
				    DrawPauseMenu();
				    //vTaskDelay(500);
				break;
				case EndMenu:
				    DrawEndMenu();
				    //vTaskDelay(500);
				break;
				}

		//SystemState();

		//DrawWay(joystickPosition.y);
		//DrawWayRight(joystickPosition.x,joystickPosition.y,20,10);

		//DrawCar(CarOption);
		//DrawInfo(CourseNum);
		//DrawCourseMenu();
		//SystemState();
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
