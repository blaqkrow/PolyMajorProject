/*
 * Algo.c
 *
 *  Created on: Jul 8, 2013
 *      Author: blaqkrow
 */

#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <termios.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

//declartions for GPIO
#include "Algo.h"
#include "forFatah.h"
#include "Pump_Parameters.h"
#include "Regimen.h"

#include "DB_Api.h"
#include "sqlite3.h"
#include "client.h"


#define MAXBUF 100

//End

static int key_CheckAvailable = 0;
static unsigned char key_Value = 0;

time_t time1; //the current time

int lastPressedTime; //the last pcea bolus triggered time*** IN SECONDS!!!
int previousPressedTime; //the previous pcea bolus trig time
int lastStepDownTime;
int lastRegimeTime;
int timeBuffer[10]; //First in Last Out buffer to check if infusion /hr > 20 ml
int startTime;
char* time_string;

unsigned char start = 0; // start flag/ button ***NEED API FOR THIS
unsigned char patientFlag = 0; // ***NEED API FOR THIS
unsigned char first = 1;

int stage = 0; // select the current stage
unsigned char isStageSteppingUp = 1; //flag for stepping up and down of stages

unsigned char startTimeFlag = 0;

float totalInfused = 0; //total amount infused

unsigned char r1Once = 1; // Special flags for stage 1
unsigned char showOnce = 1;

//messageFlag = 0 : successful pcea bolus

//stageFlag = 0; regime has steped up


double doubleStartTime;
double doublePreviousTime = 0;
double doubleTime;
int theTime;
int infuseFlag = 0;
int pumpStopTimeFlag = 0;
int isInfusing = 0;
int count = 0;

int seconds = 0;
int minutes = 0;

int i, messageFlag, stageFlag;
int fd;
struct termios config;

int bolusCount = 0;
int PBolus = 0;
int UPBolus = 0;
int ABolus = 0;
int PBFlag = 0;

char cmd[100];

//initialise buttons
int inval = 1;
int lastinval;
int outval = 0;
int outval2 = 0;
int fd_button;
int fd_led;
int fd_led2;
char dev_button[64];
char dev_led[64];
char dev_led2[64];

//button end
//JIAN RONG VARIABLE
int Soundflag = 0;



void algoMain(void) //initialise things here
{

	int res;

	pthread_t buttonThread;
	pthread_t algoThread;
	pthread_t Thread1;



	printf("Welcome!");

	const char *device = "/dev/ttymxc1";

	//START CONFIGURING STUFF HERE!!!!

	//load drivers here
	sprintf(cmd,"modprobe gpio");
	system(cmd);
	sprintf(cmd,"cd /dev/gpio");
	system(cmd);
	sprintf(cmd,"mknod 1 c 240 1");
	system(cmd);
	sprintf(cmd,"mknod 9 c 240 9");
	system(cmd);
	sprintf(cmd,"mknod 106 c 240 106");
	system(cmd);
	sprintf(cmd,"mknod 107 c 240 107");
	system(cmd);
	sprintf(cmd,"mknod 108 c 240 108");
	system(cmd);
	sprintf(cmd,"mknod 109 c 240 109");
	system(cmd);
	sprintf(cmd,"mknod 174 c 240 174");
    system(cmd);
    sprintf(cmd,"mknod 175 c 240 175");
    system(cmd);
    sprintf(cmd,"mknod 176 c 240 176");
    system(cmd);
    sprintf(cmd,"mknod 198 c 240 198");
    system(cmd);

	snprintf(dev_button, sizeof(dev_button) - 1, "/dev/gpio/175"); //was pin 1 (175)
	fd_button = open(dev_button, O_RDWR);

	/* LED */
	snprintf(dev_led, sizeof(dev_led) - 1, "/dev/gpio/198");
	fd_led = open(dev_led, O_RDWR);

	snprintf(dev_led2, sizeof(dev_led2) - 1, "/dev/gpio/176");
	fd_led2 = open(dev_led2, O_RDWR);

	/* Configure button as input */
	ioctl(fd_button, GPIO_CONFIG_AS_INP);

	/* Configure LED as output */
	ioctl(fd_led, GPIO_CONFIG_AS_OUT);
	ioctl(fd_led2, GPIO_CONFIG_AS_OUT);

	//config com port
		fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY); //Open Port
			config.c_cflag = B19200| CS8 | CLOCAL | CREAD;	 //Port Settings

			cfsetispeed(&config, B19200);					 //Port Input Baud Rate

			tcsetattr(fd,TCSANOW,&config);
			//Save Settings to the Port

			printf("fd = %d \n", fd);						 //Error Checking for Port

	// DONE CONFIGURING STUFF!!!!!!!

		res = pthread_create(&buttonThread, NULL, buttonPressed, NULL);

		if(res !=0)
		{
			printf("error creating button thread \n");
		}

		 res = pthread_create(&algoThread, NULL, algo, NULL);

		 if(res !=0)
		{
			//printf("error creating algo thread \n");
		}

		pthread_create(&Thread1, NULL, keypad_Thread, NULL);
//		SoundthreadDeclare();


			//if(pthread_join(buttonThread, NULL))
			//{
				//printf("error joining thread \n");
			//}
			//if(pthread_join(algoThread, NULL))
			//{
				//printf("error joining thread \n");
			//}


//		 setRate();
//		 setDirection();
}

void *algo()
{
	while(1)
	{
		time1 = time(NULL);
		time_string = ctime(&time1);
		//do pcea here
		if(start == 1) //have you started the application?
		{
			doubleTime = difftime(time1,startTime);

			theTime = doubleTime;

			minutes = theTime / 60;
			seconds = theTime % 60;

			if(startTimeFlag == 0)
			{
				startTimeFlag = 1; //set to true, set to false when infusion is over/stopped
				startTime =  time1;
				doubleTime = difftime(time1,startTime);
				printf("Infusion started! The start time is %.2lf \n",doubleTime);

			}
			if(doubleTime - doublePreviousTime == 1) //do this every 1 second
			{
				doublePreviousTime = doubleTime;
				if(infuseFlag == 1)
				{

					if(count < 180){

					totalInfused = totalInfused + (5./180.); //only int can work

					////int x = totalInfused;
					//if(x % 5 == 0)
					//{
					//	totalInfused = x;
					//}

					}
					else
					{

						count = 0;
						infuseFlag = 0;
					}
					count++;

				}

			}

			if(patientFlag == 1)
			{
			patientFlag = 0;

				if((doubleTime - lastRegimeTime > 600) && (doubleTime - lastPressedTime > 600)) //must be 10 miin after last AB and PB
				{
					if((doubleTime - timeBuffer[3] >3600) || ((doubleTime <= 3600) && (bolusCount < 4))) //if the 4th bolus was more than an hour past
					{
						previousPressedTime = lastPressedTime;

						//*** LOG IN THE SAVE TIME INTO DATABASE ***//

						lastPressedTime = doubleTime; // last pressed time becomes current time
						lastStepDownTime = lastPressedTime; //save it to step down time

						pumpStopTimeFlag = doubleTime;

						updateBuffer();
						bolusCount++;
						PBolus++;
						infuseFlag = 1;
						PBFlag = 1;
						PumpStart();

						//*** LOG/SAVE/DISPLAY INFUSED VOLUME (???) ***//

						//DISPLAY SUCCESSFUL PCEA BOLUS
						 messageFlag = 0; // successful pcea bolus
						 //printf("Time: %s", time_string);
						 //printf("The time is %.2lf",doubleTime);
						 printf("The time is %d", minutes);
						 printf(":%d", seconds);
						 printf(" Successful PCEA Bolus. \n\r");

						if(stage <4)
						{
							stage++;
							isStageSteppingUp = 1;
							printf("Stage has stepped up! Stage number: %d \n", stage);
							//printf(+stage+"\n");

						//DISPLAY THAT REGIME IS STEPPING UP
						}

					}
					else //else if the difference of time from the 3rd buffer till current is within 1 hour
					{
						//DISPLAY UNSUCCESSFUL BOLUS DUE TO BOLUS OVERDOSE IN 1 HR
						 //printf("The time is %.2lf",doubleTime);
						UPBolus++;
						PBFlag = 0;
						printf("The time is %d", minutes);
						printf(":%d", seconds);
						 printf(" timeBuffer[3] = %d",timeBuffer[3]);
						 printf(" Unsuccessful PCEA Bolus: Exceeded Hourly Limit \n");
					}
				}

				else
				{

					if(first)
					{
						if((doubleTime - timeBuffer[3] >3600) || ((doubleTime <= 3600) && (bolusCount < 4) )) //if the 4th bolus was more than an hour past
											{
												previousPressedTime = lastPressedTime;

												//*** LOG IN THE SAVE TIME INTO DATABASE ***//

												lastPressedTime = doubleTime; // last pressed time becomes current time
												lastStepDownTime = lastPressedTime; //save it to step down time

												pumpStopTimeFlag = doubleTime;

												updateBuffer();
												bolusCount++;
												PBolus++;
												infuseFlag = 1;
												PBFlag = 1;
												PumpStart();

												//*** LOG/SAVE/DISPLAY INFUSED VOLUME (???) ***//

												//DISPLAY SUCCESSFUL PCEA BOLUS

												 //printf("Time: %s", time_string);
												 //printf("The time is %.2lf",doubleTime);
												printf("The time is %d", minutes);
												printf(":%d", seconds);
												 printf(" Successful PCEA Bolus. \n\r");

												if(stage <4)
												{
													stage++;
													isStageSteppingUp = 1;
													//printf("Stage has stepped up! Stage number: ");
													//printf(+stage+"\n\r");
													printf("Stage has stepped up! Stage number: %d \n", stage);

												//DISPLAY THAT REGIME IS STEPPING UP
												}

											}
											else //else if the difference of time from the 3rd buffer till current is within 1 hour
											{
												UPBolus++;
												PBFlag = 0;
												//DISPLAY UNSUCCESSFUL BOLUS DUE TO BOLUS OVERDOSE IN 1 HR
												 //printf("The time is %.2lf",doubleTime);
												 printf("The time is %d", minutes);
												 printf(":%d", seconds);
												 printf(" timeBuffer[3] = %d",timeBuffer[3]);
												 printf(" Unsuccessful PCEA Bolus: Exceeded Hourly Limit \n\r");
											}
					}

					if(first == 0)
					{
						UPBolus++;
						//***DISPLAY UNSUCCESSFUL PCEA BOLUS, STILL IN LOCKOUT TIME
						 //printf("The time is %.2lf",doubleTime);
						 printf("The time is %d", minutes);
						 printf(":%d", seconds);
						 printf(" timeBuffer[3] = %d",timeBuffer[3]);
						 printf(" Unsuccessful PCEA Bolus: Still in Lockout Period \n\r");
					}

					first = 0;
				}
			} // end of PCEA flag check

			if(doubleTime - lastStepDownTime == 3600) //if its been 60 min since last pcea, step down
			{
				if(stage>0)
				{
					lastStepDownTime = doubleTime;
					stage--;
					printf("Stage is stepping down! Stage number: %d \n", stage);

				}
			}

			if((doubleTime - lastRegimeTime > 600) && (doubleTime - lastPressedTime > 600)) //must be 10 mins after
				//last AB and PB
			{

				if(stage == 0) //this is the default stage, ie, 5ml/hr
				{
					r1Once = 1;

					if(doubleTime - lastRegimeTime <3600) //one hour has not passed yet
					{
						//Do nothing
					}
					else //do this every 60 min
					{
						if((doubleTime - timeBuffer[3] >3600) ||((doubleTime <= 3600) && (bolusCount < 4)))
						{
							lastRegimeTime = doubleTime;
							updateBuffer();
							bolusCount++;
							ABolus++;
							infuseFlag = 1;

							pumpStopTimeFlag = doubleTime;

							PumpStart();

							//*** DISPLAY SUCCESSFUL AUTOMATED BOLUS(STAGE 0)
							//printf("Time: %s", time_string);
							//printf("The time is %.2lf",doubleTime);
							 printf("The time is %d", minutes);
							 printf(":%d", seconds);
							printf("Successful Automated Bolus (Stage 0) \n\r");

							showOnce = 1; //display error message only once
						}
						else
						{
							if(showOnce)
							{
								showOnce = 0;

								//*** DISPLAY UNSUCCESSFUL BOLUS (S0) AS IT EXCEEDED HOURLY LIMIT OF 20ML
								 //printf("The time is %.2lf",doubleTime);
								 printf("The time is %d", minutes);
								 printf(":%d", seconds);
								 printf(" timeBuffer[3] = %d",timeBuffer[3]);
								 printf(" Unsuccessful Automated Bolus: Exceeded Hourly Limit \n\r");
							}
						}
					}
				}

				if(stage == 1)
				{
					if(isStageSteppingUp == 1)
					{
						if(doubleTime - lastPressedTime   < 1800) // 1800s = 30 min, 30 min has not passed yet
						{
							//do nothing
						}
						else
						{
							if(r1Once == 1)
							{
								if((doubleTime - timeBuffer[3] > 3600) || ((doubleTime <= 3600) && (bolusCount < 4)))
								{
									r1Once = 0;
									lastRegimeTime = doubleTime;
									updateBuffer();
									bolusCount++;
									ABolus++;
									infuseFlag = 1;

									pumpStopTimeFlag = doubleTime;

									PumpStart();

									//*** DISPLAY SUCCESSFUL AUTOMATED BOLUS(STAGE 1)
									//printf("The time is %.2lf",doubleTime);
									 printf("The time is %d", minutes);
									 printf(":%d", seconds);
									printf(" Successful Automated Bolus (Stage 1) \n\r");

									showOnce = 1; //display error message only once
								}
								else
								{
									if(showOnce)
									{
										showOnce = 0;

										//*** DISPLAY UNSUCCESSFUL BOLUS (S1) AS IT EXCEEDED HOURLY LIMIT OF 20ML
										 //printf("The time is %.2lf",doubleTime);
										 printf("The time is %d", minutes);
										 printf(":%d", seconds);
										 printf(" timeBuffer[3] = %d",timeBuffer[3]);
										 printf(" Unsuccessful Automated Bolus: Exceeded Hourly Limit \n\r");
									}
								}
							}
						}
					}
					else
					{
						if(doubleTime - lastRegimeTime < 1800)
						{
							//do nothing
						}
						else
						{
							if(r1Once == 1)
							{
								if((doubleTime - timeBuffer[3] > 3600) || ((doubleTime <= 3600) && bolusCount < 4))
								{
									r1Once = 0;
									lastRegimeTime = doubleTime;
									updateBuffer();
									bolusCount++;
									ABolus++;
									infuseFlag = 1;

									pumpStopTimeFlag = doubleTime;

									PumpStart();

									//*** DISPLAY SUCCESSFUL AUTOMATED BOLUS(STAGE 1)
									//printf("The time is %.2lf",doubleTime);
									 printf("The time is %d", minutes);
									 printf(":%d", seconds);
									printf(" Successful Automated Bolus (Stage 1) \n\r");

									showOnce = 1; //display error message only once
								}
								else
								{
									if(showOnce)
									{
										showOnce = 0;
										//*** DISPLAY UNSUCCESSFUL BOLUS (S1) AS IT EXCEEDED HOURLY LIMIT OF 20ML
										 //printf("The time is %.2lf",doubleTime);
										 printf("The time is %d", minutes);
										 printf(":%d", seconds);
										 printf(" timeBuffer[3] = %d",timeBuffer[3]);
										 printf(" Unsuccessful Automated Bolus: Exceeded Hourly Limit \n\r");
									}
								}
							}
						}
					}
				}

				else if (stage == 2)
				{
					r1Once = 1;

					if(doubleTime - lastRegimeTime < 1800) //30 min has not passed yet
					{
						//do nothing
					}
					else //do this every 30 min
					{
						if((doubleTime - timeBuffer[3] > 3600) || ((doubleTime <= 3600) && (bolusCount < 4)))
						{
							lastRegimeTime = doubleTime;
							updateBuffer();
							bolusCount++;
							ABolus++;
							infuseFlag = 1;

							pumpStopTimeFlag = doubleTime;

							PumpStart();

							//*** DISPLAY SUCCESSFUL AUTOMATED BOLUS(STAGE 2)
							//printf("The time is %.2lf",doubleTime);
							 printf("The time is %d", minutes);
							 printf(":%d", seconds);
							printf(" Successful Automated Bolus (Stage 2) \n\r");

							showOnce = 1; //display error message only once


						}
						else
						{
							if(showOnce)
							{
								showOnce = 0;
								//*** DISPLAY UNSUCCESSFUL BOLUS (S2) AS IT EXCEEDED HOURLY LIMIT OF 20ML
								 //printf("The time is %.2lf",doubleTime);
								 printf("The time is %d", minutes);
								 printf(":%d", seconds);
								 printf(" timeBuffer[3] = %d",timeBuffer[3]);
								 printf(" Unsuccessful Automated Bolus: Exceeded Hourly Limit \n\r");
							}
						}
					}
				}

				else if(stage == 3)
				{
					r1Once = 1;

					if(doubleTime - lastRegimeTime < 1200)
					{
						//do nothing
					}
					else
					{
						if((doubleTime - timeBuffer[3] > 3600) || ((doubleTime <= 3600) && (bolusCount < 4)))
						{
							lastRegimeTime = doubleTime;
							updateBuffer();
							bolusCount++;
							ABolus++;
							infuseFlag = 1;
							pumpStopTimeFlag = doubleTime;

							PumpStart();

							//*** DISPLAY SUCCESSFUL AUTOMATED BOLUS(STAGE 3)
							//printf("The time is %.2lf",doubleTime);
							 printf("The time is %d", minutes);
							 printf(":%d", seconds);
							printf(" Successful Automated Bolus (Stage 3 \n\r");

							showOnce = 1; //display error message only once

						}
						else
						{
							if(showOnce)
							{
								showOnce = 0;
								//*** DISPLAY UNSUCCESSFUL BOLUS (S3) AS IT EXCEEDED HOURLY LIMIT OF 20ML
								 //printf("The time is %.2lf",doubleTime);
								 printf("The time is %d", minutes);
								 printf(":%d", seconds);
								 printf(" timeBuffer[3] = %d",timeBuffer[3]);
								 printf(" Unsuccessful Automated Bolus: Exceeded Hourly Limit \n\r");

							}
						}
					}
				}

				else if(stage == 4)
				{
					r1Once = 1;

					if(doubleTime - lastRegimeTime < 900)
					{
						// do nothing
					}
					else
					{
						if((doubleTime - timeBuffer[3] > 3600) || ((doubleTime <= 3600) && bolusCount < 4))
						{
							lastRegimeTime = doubleTime;
							updateBuffer();
							bolusCount++;
							ABolus++;
							infuseFlag = 1;

							pumpStopTimeFlag = doubleTime;

							PumpStart();

							//*** DISPLAY SUCCESSFUL AUTOMATED BOLUS(STAGE 4)
							//printf("The time is %.2lf",doubleTime);
							 printf("The time is %d", minutes);
							 printf(":%d", seconds);
							printf(" Successful Automated Bolus (Stage 4) \n\r");

							showOnce = 1; //display error message only once
						}
						else
						{
							if(showOnce)
							{
								showOnce = 0;
								//*** DISPLAY UNSUCCESSFUL BOLUS (S4) AS IT EXCEEDED HOURLY LIMIT OF 20ML
								 //printf("Time: %s", time_string);
								 printf("The time is %d", minutes);
								 printf(":%d", seconds);
								 printf(" timeBuffer[3] = %d",timeBuffer[3]);
								 printf(" Unsuccessful Automated Bolus: Exceeded Hourly Limit \n\r");
							}
						}
					}
				}
			}

			if(doubleTime - pumpStopTimeFlag == 180) //stop the pump after 3 min of infusion!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			{
				pumpStopTimeFlag = 0;
				//PumpStop();
				//printf("The time is %.2lf",doubleTime);
				 printf("The time is %d", minutes);
				 printf(":%d", seconds);
				printf(" Infusion Ended in 3 min \n\r");
			}

		}

	}
}

//void setTime()
//{
	//char date;
	//printf("Setting Time");

	//sprintf(cmd, "date %s",date);

	//system(cmd);

////}

void setIP(const char* ipadd)
{
	//FILE* f;
	char content[MAXBUF];
	char ip[20];
	//sprintf(ip,&ipadd);
	//strcat("ifconfig", content);
	//strcat(" ", content);
	//strcat("eth0", content);
	//strcat(" ", content);
	//strcat(ipadd, content);
	//strcat(" ", content);
	//strcat(sub, content);
	//strcat("up", content);

	//sprintf(cmd,content);
	sprintf(cmd,"ifconfig eth0 %s up", ipadd);
	system(cmd);

	printf("IP and Subnet Changed\n");
}

void btnStart()
{
//	setDiameter();
//	setRate();
//	setVolume();
	Regimen();

	doubleTime = 0;
	showOnce = 1;
	r1Once = 1;
	seconds = 0;
	minutes = 0;
	count = 0;
	isInfusing = 0;
	first = 1;
	start = 1;


}
void btnPause()
{
	startTime = 0;
	PumpStop();

	start = 0;
}

void btnStop()
{
	start = 0;
	startTimeFlag = 0;
	PumpStop();
	timeBuffer[0] = 0;
	timeBuffer[1] = 0;
	timeBuffer[2] = 0;
	timeBuffer[3] = 0;
	timeBuffer[4] = 0;
	timeBuffer[5] = 0;
	timeBuffer[6] = 0;
	timeBuffer[7] = 0;
	timeBuffer[8] = 0;
	timeBuffer[9] = 0;
	startTime = 0;
	patientFlag = 0;
	lastPressedTime = 0;
	lastRegimeTime = 0;
	lastStepDownTime = 0;
	totalInfused = 0;
	previousPressedTime = 0;
	doublePreviousTime = 0;
	pumpStopTimeFlag = 0;
	infuseFlag = 0;
	bolusCount = 0;
	stage = 0;
	isStageSteppingUp = 0;
	ABolus = 0;
	PBolus = 0;
	UPBolus = 0;
	PBFlag = 0;
	printf("Infusion stopped! The stop time is %.2lf \n",doubleTime);
}

float infusedVolumeReturn()
{
	return totalInfused;
}

int bolusCountReturn()
{
	return bolusCount;
}

int PBTotalReturn()
{
	return PBolus+UPBolus;
}

int ABReturn()
{
	return ABolus;
}

int PBReturn()
{
	return PBolus;
}

void *buttonPressed()
{
	//QUERY BUTTON

	while(1)
	{
		if(start == 1)
		{

			do
			{
				lastinval = inval;
				ioctl(fd_button, GPIO_READ_PIN_VAL, &inval);
				usleep(1000);
			}
			while (!((lastinval == 1) && (inval == 0)));

			//outval = !outval;
			if(PBFlag == 1)
			{
				outval = 1; //outval is green
				outval2 = 0;
			}
			else
			{
				outval = 0;
				outval2 = 1;
			}

			//if(outval==1)

			//	outval2 = 0;
			//else
			//	outval2 = 1;

			if(patientFlag== 0)
				{
					patientFlag = 1;
				}

			ioctl(fd_led, GPIO_WRITE_PIN_VAL, &outval);
			ioctl(fd_led2, GPIO_WRITE_PIN_VAL, &outval2);
		}


	}
}

void updateBuffer()
{
	for(i = 9; i > 0; i--)
		timeBuffer[i] = timeBuffer[i-1];

	timeBuffer[0] = doubleTime;
}

//THIS IS ALEX CODES!!!

void *keypad_Thread()
{
	char dev_pinRow2[64];
	char dev_pinRow3[64];
	char dev_pinRow4[64];
	char dev_pinCol6[64];
	char dev_pinCol7[64];
	char dev_pinCol8[64];

	int fd_pinRow2;
	int fd_pinRow3;
	int fd_pinRow4;
	int fd_pinCol6;
	int fd_pinCol7;
	int fd_pinCol8;
	int inval1 = 1;
	int inval2 = 1;
	int inval3 = 1;
	int outval1 = 1;
	int outval2 = 1;
	int outval3 = 1;
	int outvalTest1 = 0;
	int outvalTest2 = 0;
	int outvalTest3 = 0;

	/* Rows */
	snprintf(dev_pinRow2, sizeof(dev_pinRow2) - 1, "/dev/gpio/106");
	fd_pinRow2 = open(dev_pinRow2, O_RDWR);
	snprintf(dev_pinRow3, sizeof(dev_pinRow3) - 1, "/dev/gpio/107");
	fd_pinRow3 = open(dev_pinRow3, O_RDWR);
	snprintf(dev_pinRow4, sizeof(dev_pinRow4) - 1, "/dev/gpio/108");
	fd_pinRow4 = open(dev_pinRow4, O_RDWR);

	/* Columns */
	snprintf(dev_pinCol6, sizeof(dev_pinCol6) - 1, "/dev/gpio/109");
	fd_pinCol6 = open(dev_pinCol6, O_RDWR);
	snprintf(dev_pinCol7, sizeof(dev_pinCol7) - 1, "/dev/gpio/9");
	fd_pinCol7 = open(dev_pinCol7, O_RDWR);
	snprintf(dev_pinCol8, sizeof(dev_pinCol8) - 1, "/dev/gpio/1");
	fd_pinCol8 = open(dev_pinCol8, O_RDWR);

	/* Configure rows as input */
	ioctl(fd_pinRow2, GPIO_CONFIG_AS_INP);
	ioctl(fd_pinRow3, GPIO_CONFIG_AS_INP);
	ioctl(fd_pinRow4, GPIO_CONFIG_AS_INP);

	/* Configure columns as outputs */
	ioctl(fd_pinCol6, GPIO_CONFIG_AS_OUT);
	ioctl(fd_pinCol7, GPIO_CONFIG_AS_OUT);
	ioctl(fd_pinCol8, GPIO_CONFIG_AS_OUT);

	/* Initialize all columns with logic '1' */
	ioctl(fd_pinCol6, GPIO_WRITE_PIN_VAL, &outval1);
	ioctl(fd_pinCol7, GPIO_WRITE_PIN_VAL, &outval2);
	ioctl(fd_pinCol8, GPIO_WRITE_PIN_VAL, &outval3);

	while(1)
	{
		//printf("Thread1 created");

		ioctl(fd_pinCol6, GPIO_WRITE_PIN_VAL, &outvalTest1);
		ioctl(fd_pinRow2, GPIO_READ_PIN_VAL, &inval1);
		ioctl(fd_pinRow3, GPIO_READ_PIN_VAL, &inval2);
		ioctl(fd_pinRow4, GPIO_READ_PIN_VAL, &inval3);

		if(inval1==0 && outvalTest1==0)
		{
			do
			{
				ioctl(fd_pinRow2, GPIO_READ_PIN_VAL, &inval1);
			}
			while(inval1!=1);
			key_CheckAvailable = 1;
			key_Value = 1;
		}
		else if(inval2==0 && outvalTest1==0)
		{
			do
			{
				ioctl(fd_pinRow3, GPIO_READ_PIN_VAL, &inval2);
			}
			while(inval2!=1);
			key_CheckAvailable = 1;
			key_Value = 4;
		}
		else if(inval3==0 && outvalTest1==0)
		{
			do
			{
				ioctl(fd_pinRow4, GPIO_READ_PIN_VAL, &inval3);
			}
			while(inval3!=1);
			key_CheckAvailable = 1;
			key_Value = 7;
		}
		ioctl(fd_pinCol6, GPIO_WRITE_PIN_VAL, &outval1);



		ioctl(fd_pinCol7, GPIO_WRITE_PIN_VAL, &outvalTest2);
		ioctl(fd_pinRow2, GPIO_READ_PIN_VAL, &inval1);
		ioctl(fd_pinRow3, GPIO_READ_PIN_VAL, &inval2);
		ioctl(fd_pinRow4, GPIO_READ_PIN_VAL, &inval3);
		if(inval1==0 && outvalTest2==0)
		{
			do
			{
				ioctl(fd_pinRow2, GPIO_READ_PIN_VAL, &inval1);
			}
			while(inval1!=1);
			key_CheckAvailable = 1;
			key_Value = 2;
		}
		else if(inval2==0 && outvalTest2==0)
		{
			do
			{
				ioctl(fd_pinRow3, GPIO_READ_PIN_VAL, &inval2);
			}
			while(inval2!=1);
			key_CheckAvailable = 1;
			key_Value = 5;
		}
		else if(inval3==0 && outvalTest2==0)
		{
			do
			{
				ioctl(fd_pinRow4, GPIO_READ_PIN_VAL, &inval3);
			}
			while(inval3!=1);
			key_CheckAvailable = 1;
			key_Value = 8;
		}
		ioctl(fd_pinCol7, GPIO_WRITE_PIN_VAL, &outval2);



		ioctl(fd_pinCol8, GPIO_WRITE_PIN_VAL, &outvalTest3);
		ioctl(fd_pinRow2, GPIO_READ_PIN_VAL, &inval1);
		ioctl(fd_pinRow3, GPIO_READ_PIN_VAL, &inval2);
		ioctl(fd_pinRow4, GPIO_READ_PIN_VAL, &inval3);
		if(inval1==0 && outvalTest3==0)
		{
			do
			{
				ioctl(fd_pinRow2, GPIO_READ_PIN_VAL, &inval1);
			}
			while(inval1!=1);
			key_CheckAvailable = 1;
			key_Value = 3;
		}
		else if(inval2==0 && outvalTest3==0)
		{
			do
			{
				ioctl(fd_pinRow3, GPIO_READ_PIN_VAL, &inval2);
			}
			while(inval2!=1);
			key_CheckAvailable = 1;
			key_Value = 6;
		}
		else if(inval3==0 && outvalTest3==0)
		{
			do
			{
				ioctl(fd_pinRow4, GPIO_READ_PIN_VAL, &inval3);
			}
			while(inval3!=1);
			key_CheckAvailable = 1;
			key_Value = 9;
		}
		ioctl(fd_pinCol8, GPIO_WRITE_PIN_VAL, &outval3);
	}

}

int key_Available()
{
	if(key_CheckAvailable==1)
	{

		key_CheckAvailable = 0;
		return 1;
	}
	else
		return 0;
}

int key_Get()
{
	return key_Value;
}

//JIAN RONG THREAD
void *AlarmThread()
{

	char pin_DIGIO1[64];
	int fd_PinDigio1;
	int outSoundOn=1;
	int outSoundOff=0;
	int x=0;

	snprintf(pin_DIGIO1, sizeof(pin_DIGIO1) - 1, "/dev/gpio/174");
	fd_PinDigio1 = open(pin_DIGIO1, O_RDWR);

	ioctl(fd_PinDigio1, GPIO_CONFIG_AS_OUT);
while(1)
	{
		//x++;
	//	if(x < 1000 )
			//{
//				printf("RING!\n");
				//ioctl(fd_PinDigio1, GPIO_WRITE_PIN_VAL, &outSoundOn);

				//usleep(167);
		//	}
		//if(x>= 1000 && x < 2000)
			//{
			//	ioctl(fd_PinDigio1, GPIO_WRITE_PIN_VAL, &outSoundOff);
				//susleep(167);

			//}

		//if(x == 2000)
			//{
			//	x =0;
			//}
	}
}
//Enable
int Alarm_Enable()
{
	 Soundflag = 1;
}



void SoundthreadDeclare()
{
	int status;
	pthread_t tid1;
	pthread_create(&tid1,NULL,AlarmThread,NULL);
}
