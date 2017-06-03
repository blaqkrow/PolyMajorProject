/*
 * final.h
 *
 *      Author: Kevin
 */

#ifndef FINAL_H_
#define FINAL_H_

int setParameters();
int setParameters2();
int PumpStart();
int PumpStop();
int Reset();
int Exit();
int Phases();
int setRate();
int setVolume();
int setDirection();

int choice1, choice2, choice3, value;
int fd;

char Space = 0x20;			//Hexa for key Space
char Enter = 0x0D;			//Hexa for key Enter
char Rat[3] = "RAT";		//Command Function for rate
char rate[4];				//value of rate
char Vol[3] = "VOL";		//Command Function for volume
char vol[4];				//value of volume
char Dir[3] = "DIR";		//Command Function for Pumping Direction
char dir[3];				//"	"
char Phn[3] = "PHN";		//Command Function for Phases
char Run[3] = "RUN";		//Command Function for Start
char Stp[3] = "STP";		//Command Function for Stop
char Resets[5] = "RESET";	//Command Function for Reset
char Phase[2];				//value of Phases
char FUN[3] = "FUN";		//Command Function for Function in Phases
char fun[3];				//"	"

struct termios config2;

int setRate()
{
	printf("Enter value from 1~1000: ");

	scanf("%d", &value);

	sprintf(rate, "%d", value);

	write(fd, &Rat, 3);
	write(fd, &Space, 1);
	write(fd, &rate, 4);
	write(fd, &Enter, 1);

	return(0);
}

int setVolume()
{
	printf("Enter value from 1~1000: ");

	scanf("%d", &value);
	write(fd, &Space, 1);
	write(fd, &vol, 4);
	write(fd, &Enter, 1);

	return(0);
}

int setDirection()
{
	printf("Enter direction: ");
	scanf("%s", &dir[0]);

	write(fd, &Dir, 3);
	write(fd, &Space, 1);
	write(fd, &dir, 3);
	write(fd, &Enter, 1);

	return(0);
}

int PumpStart()
{
	write(fd, &Run, 3);
	write(fd, &Enter, 1);

	return(0);
}

int PumpStop()
{
	write(fd, &Stp, 3);
	write(fd, &Enter, 1);

	return(0);
}

int Exit()
{
	close(fd);
	exit(0);

	return(0);
}

int Reset()
{
	write(fd, &Resets, 5);
	write(fd, &Enter, 1);

	return(0);
}

int Phases()
{
	printf("Enter phase number: ");
	scanf("%d", &value);
	sprintf(Phase, "%d", value);

	printf("Enter Phase Function \n");
	printf("FUN ");
	scanf("%s", &fun[0]);

	write(fd, &Phn, 3);
	write(fd, &Phase, 2);
	write(fd, &Enter, 1);
	write(fd, &FUN, 3);
	write(fd, &Space, 1);
	write(fd, &fun, 3);
	write(fd, &Enter, 1);

	setParameters2();

	return(0);
}

int setParameters()
{
	do
	{
		printf("------------------ \n");
		printf("1. Set Rate \n");
		printf("2. Set Volume \n");
		printf("3. Direction \n");
		printf("4. Phases \n");
		printf("5. Back \n");
		printf("Select: ");
		scanf("%d",&choice1);
		printf("------------------ \n");

		switch(choice1)
		{
			case 1: setRate();
					break;
			case 2: setVolume();
					break;
			case 3: setDirection();
					break;
			case 4: Phases();
					break;
			case 5: printf("Back to main menu \n");
					break;
			default: printf("Wrong Selection!! \n");
		}

	}while(choice1 != 5);

	return(0);
}

int setParameters2()
{
	do
	{
		printf("------------------ \n");
		printf("1. Set Rate \n");
		printf("2. Set Volume \n");
		printf("3. Direction \n");
		printf("4. Done \n");
		printf("Select: ");
		scanf("%d",  &choice2);
		printf("\n");
		printf("------------------ \n");

		switch(choice2)
		{
			case 1: setRate();
					break;
			case 2: setVolume();
					break;
			case 3: setDirection();
					break;
			case 4: printf("Complete \n");
					break;
			default: printf("Wrong Selection!! \n");
		}
	}while(choice2 !=  4);

	return(0);
}


#endif /* FINAL_H_ */
