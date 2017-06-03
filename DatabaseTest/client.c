#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "DB_Api.h"
#include "sqlite3.h"
#include <pthread.h>
#include "client.h"

int sockfd, portno;
void error(char *msg)
{
	perror(msg);
//	exit(1);
}
void * ClientConnect()
	{
			int status;
			int PID;
			int count;
			char buffer[256];
			char PatientID[20];
			char DateTime[20];
			char CurrentInfRate[20];
			char TotalVolInfused[20];
			char State[20];
			char ClinicianLoginID[20];
			int TotalMaBolus;
			int TotalPaDemand;
			int TotalSuccessfulDemand;
			int BedNo;


			  while(1)
				{


			memset(PatientID,0,sizeof(PatientID));
			memset(DateTime,0,sizeof(DateTime));
			memset(CurrentInfRate,0,sizeof(CurrentInfRate));
			memset(TotalVolInfused,0,sizeof(TotalVolInfused));
			memset(State,0,sizeof(State));
			memset(ClinicianLoginID,0,sizeof(ClinicianLoginID));
			memset(&TotalMaBolus,0,sizeof(TotalMaBolus));
			memset(&TotalPaDemand,0,sizeof(TotalPaDemand));
			memset(&TotalSuccessfulDemand,0,sizeof(TotalSuccessfulDemand));
			memset(&BedNo,0,sizeof(BedNo));



		status = EventLog_GetTCP(PatientID,DateTime,&TotalMaBolus,&TotalPaDemand,&TotalSuccessfulDemand,CurrentInfRate,TotalVolInfused,State,&BedNo,ClinicianLoginID);


           printf("Status =%d \n",status);
			if(status == 0)
			{
//				printf("PatientID =%s \n",PatientID);
//				printf("DateTime =%s \n",DateTime);
//				printf("TotalMaBolus =%d \n",TotalMaBolus);
//				printf("TotalPaDemand =%d \n",TotalPaDemand);
//				printf("TotalSuccessfulDemand =%d \n",TotalSuccessfulDemand);
//				printf("CurrentInfRate =%d \n",CurrentInfRate);
//				printf("TotalVolInfused =%s \n",TotalVolInfused);
//				printf("State =%s \n",State);
//				printf("BedNo =%d \n",BedNo);
//				printf("ClinicianLoginID =%s \n",ClinicianLoginID);
//				printf("status =0\n");
				count = 0;
//				printf("count = 0;\n");
				memcpy(buffer+count,PatientID,20);
//				printf("memcpy(buffer+count,PatientID,20);\n");
				count += 20;
//				printf("count += 20;\n");
				memcpy(buffer+count,DateTime,20);
//				printf("memcpy(buffer+count,DateTime,20);\n");
				count += 20;
//				printf("		count += 20;\n");
				buffer[count++]=(unsigned char)TotalMaBolus;
//				printf("buffer[count++]=(unsigned char)TotalMaBolus;\n");
				buffer[count++]=(unsigned char)TotalPaDemand;
//				printf("buffer[count++]=(unsigned char)TotalPaDemand;\n");
				buffer[count++]=(unsigned char)TotalSuccessfulDemand;
//				printf("buffer[count++]=(unsigned char)TotalSuccessfulDemand;\n");
				memcpy(buffer+count,CurrentInfRate,20);
//				printf("memcpy(buffer+count,CurrentInfRate,20);\n");
				count += 20;
//				printf("count += 20;\n");
				memcpy(buffer+count,TotalVolInfused,20);
//				printf("memcpy(buffer+count,TotalVolInfused,20);\n");
				count += 20;
//				printf("count += 20;\n");
				memcpy(buffer+count,State,20);
//				printf("memcpy(buffer+count,State,20);\n");
				count += 20;
//				printf("count += 20;\n");
				buffer[count++]=(unsigned char)BedNo;
//				printf("	buffer[count++]=(unsigned char)BedNo;\n");
				memcpy(buffer+count,ClinicianLoginID,20);
//				printf("memcpy(buffer+count,ClinicianLoginID,20);\n");
				count += 20;
				printf("count += 20;\n");

					  struct sockaddr_in serv_addr;
					  portno = 190;
					  //printf("portno = 190;\n");
					  sockfd =socket(AF_INET, SOCK_STREAM, 0);
					 // printf("sockfd =socket(AF_INET, SOCK_STREAM, 0);\n");
					  bzero((char *) &serv_addr,sizeof(serv_addr));
					//  printf("bzero((char *) &serv_addr,sizeof(serv_addr));\n");
					  inet_aton("192.168.221.135", &serv_addr.sin_addr);
					//  printf("inet_aton(192.168.221.135, &serv_addr.sin_addr);\n");
					  serv_addr.sin_family=AF_INET;

					//  printf("serv_addr.sin_family=AF_INET;\n");

					  serv_addr.sin_port =htons(portno);
					//  printf("serv_addr.sin_port =htons(portno);\n");

		  		   if(connect(sockfd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) != 0)
		  			   continue;
		  		   else
		  		   {
		  		//  printf("Sockfd connected\n");

		  	//	  printf("PID = write(sockfd ,buffer ,124);\n");

		  			PID = write(sockfd ,buffer ,124);

		  			bzero(buffer,255);

		  			close(sockfd);
		  			printf("Sockfd disconnected\n");
		  		   }
			}
//				  sleep(10);
				  sleep(5);
				  printf("System Sleeping 5 seconds\n");

	  }


}
int ClientSetup()
{

                            printf("Creating Thread\n");
		  		  	 	 	pthread_t ClientThread;
		  		  			pthread_create(&ClientThread,NULL,ClientConnect,NULL);
		  		  			printf(" Thread created\n");


  }

