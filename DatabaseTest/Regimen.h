/*
 * Regimen.h
 *
 *  Created on: Jul 22, 2013
 *      Author: kevin
 */

#ifndef REGIMEN_H_
#define REGIMEN_H_

int Regimen();

char RegVol[1] = "5";
char RegRate[3] = "100";
char RegUnits[2] = "ML";

int Regimen() //Infusing 5ml in 3min
{
	write(fd, &Vol, 3);
	write(fd, &Space, 1);
	write(fd, &RegUnits, 2);
	write(fd, &Enter, 1);	//Set volume units to be in Ml

	write(fd, &Vol, 3);
	write(fd, &Space, 1);
	write(fd, &RegVol, 1);
	write(fd, &Enter, 1);	//Volume to be dispensed 5ml

	write(fd, &Rat, 3);
	write(fd, &Space, 1);
	write(fd, &RegRate, 3);
	write(fd, &Enter, 1);	//Rate 100ml/hr, 60min -> 100ml = 3min -> 5ml

	write(fd, &Run, 3);
	write(fd, &Enter, 1);

	return(0);
}

#endif /* REGIMEN_H_ */
