/*
 * DD.c
 *
 *  Created on: Jul 5, 2013
 *      Author: clarified
 *
 *  The below codes are used to interact with the database file using the standard sqlite API
 *  sqlite3_open()
 *  sqlite3_prepare()
 *  sqlite3_step()
 *  sqlite3_column() this is only used when there is a need to display the results out to the user
 *  sqlite3_finalise()
 *  sqlite3_close()
 *
 *  Name:
 *  Description:
 *  Input: a.
 *  	   b.
 *  Output: 0 if successful; else  rc code.
 *  Comments:
 *  Usage:
 *
 *
 *
 *
 *
 */


#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "sqlite3.h"
#include "DB_Api.h"


//#define DATABASEFILE "D:\\project1\\MP_pump.db"
#define DATABASEFILE "/usr/MP_pump.db"




//to record the loginID

/*
 *  Name: EventLog_OnLogin
 *  Description:
 *  Input: a. Id - Patient ID
 *  	   b.
 *  Output: 0 if successful; else  rc code.
 *  Comments:
 *  Usage:
 *  	char *PatientId,*Password
 *
 *  	....
 *  	ret = EventLog_OnLogin(Id);
 *
 */

int EventLog_OnLogin(const char *LoginID,const char *Password)
{
	sqlite3 *conn;
	sqlite3_stmt *res;
    int  rc ;
    const char *tail;
    char sql_stmt[500];


    rc = sqlite3_open(DATABASEFILE, &conn);
    if (rc != SQLITE_OK)
	{
         return (DB_ERR_OPEN_FAIL);
    }

    sprintf(sql_stmt, "SELECT * FROM Clinician WHERE LoginID = '%s' and Password = '%s'",LoginID,Password);

    rc = sqlite3_prepare(conn,sql_stmt,strlen(sql_stmt),&res,&tail);
    if (rc != SQLITE_OK)
    {
         return (DB_ERR_PREPARE_FAIL);
    }

    rc = sqlite3_step(res);
    if(rc != SQLITE_ROW)
	{
		sqlite3_finalize(res);
		sqlite3_close(conn);
        return (DB_ERR_STEP_FAIL);
	}

	sqlite3_finalize(res);
	sqlite3_close(conn);
    return DB_SUCCESSFUL;
}


int EventLog_OnTriggered(const char *EventType)
{
	sqlite3 *conn;
	sqlite3_stmt *res;
	const char *tail;
	int rc;
	char sql_stmt[500];

	rc = sqlite3_open(DATABASEFILE,&conn);
    if (rc != SQLITE_OK)
	{
         return (DB_ERR_OPEN_FAIL);
    }
    sprintf(sql_stmt,"INSERT INTO PatientSessionEventLog(EventDateTime,EventType) VALUES (datetime(),'%s')",EventType);
    rc=sqlite3_prepare(conn,sql_stmt,strlen(sql_stmt),&res,&tail);
    if (rc != SQLITE_OK)
    {
    	sqlite3_close(conn);
    	return (DB_ERR_PREPARE_FAIL);
    }
    rc=sqlite3_step(res);
    if(rc != SQLITE_DONE)
    {
    	sqlite3_finalize(res);
    	sqlite3_close(conn);
    	return DB_ERR_STEP_FAIL;
    }
    rc = sqlite3_finalize(res);
    if(rc)
    {
    	sqlite3_finalize(res);
    	sqlite3_close(conn);
    	return DB_ERR_FINALIZE_FAIL;
    }
    sqlite3_close(conn);
    return DB_SUCCESSFUL;
}

/* Name:EventLog_OnPeriod
*  Description:to log the MA bolus and total vol infused on a periodic basis.
*  Input: a.TotalVolume
*  	   	  b.PatientBolus
*  	      c.
*  Output: 0 if successful; else  rc code.
*  Comments:
*  Usage:
*/

int EventLog_OnPeriod(const char *Patient_Id,int TotalMaBolus,int TotalPaDemand,int TotalSuccessfulDemand,const char *CurrentInfRate,const char *Total_Vol_Infused,const char *State,int Bed_No,const char *CLinicianLoginID)
{
	sqlite3 *conn;
	sqlite3_stmt *res;
	char sql_stmt[500];
	const char *tail;
	int rc;

	rc = sqlite3_open(DATABASEFILE ,&conn);
    if (rc != SQLITE_OK)
	{
         return (DB_ERR_OPEN_FAIL);
    }
    sprintf(sql_stmt,"INSERT INTO PatientSessionDetailedLog(PatientID,CurrDateTime,TotalMachineBolus,TotalPatDemand,TotalSuccessfulDemand,CurrentInfRate,TotalVolInfused,State,BedNo,ClinicianLoginID) VALUES ('%s',datetime(),%d,%d,%d,'%s','%s','%s',%d,'%s')",Patient_Id,TotalMaBolus,TotalPaDemand,TotalSuccessfulDemand,CurrentInfRate,Total_Vol_Infused,State,Bed_No,CLinicianLoginID);
    rc = sqlite3_prepare(conn,sql_stmt,strlen(sql_stmt),&res,&tail);
    if (rc != SQLITE_OK)
    {
    	sqlite3_close(conn);
    	return (DB_ERR_PREPARE_FAIL);
    }
    rc= sqlite3_step(res);
    if(rc != SQLITE_DONE)
    {
    	sqlite3_finalize(res);
    	sqlite3_close(conn);
    	return DB_ERR_STEP_FAIL;
    }
    rc =sqlite3_finalize(res);
    if(rc)
    {
    	sqlite3_finalize(res);
    	sqlite3_close(conn);
    	return DB_ERR_FINALIZE_FAIL;
    }
    sqlite3_close(conn);
    return DB_SUCCESSFUL;

}

//EventLog_TCP(PatientID,DateTime,CurrentInfRate,TotalVolInfused,State,BedNo,ClinicianLoginID);
/* Name:EventLog_GetTcp
*  Description:to get data from TCPData and pass it to kaye for sending
*  Input: a.
*  	   	  b.
*  	      c.
*  Output: 0 if successful; else  rc code.
*  Comments:
*  Usage:
*/
//const char *PatientID,int TotalMaBolus,int TotalPaDemand,int TotalSuccessfulDemand,const char *CurrentInfRate,const char *Total_Vol_Infused,const char *State,int Bed_No,const char *CLinicianLoginID)
int EventLog_GetTCP(char *PatientID,char *DateTime,int *TotalMaBolus,int *TotalPaDemand,int *TotalSuccessfulDemand,char *CurrentInfRate,char *TotalVolInfused,char *State,int *BedNo,char *ClinicianLoginID)
{
	sqlite3 *conn;
	sqlite3_stmt *res;
	const char *tail;
	char sql_stmt[500];
	int rc;

	rc = sqlite3_open(DATABASEFILE,&conn);
	if(rc != SQLITE_OK)
	{
		return DB_ERR_OPEN_FAIL;
	}
	strcpy(sql_stmt,"SELECT * FROM TCPData");
	rc = sqlite3_prepare(conn,sql_stmt,strlen(sql_stmt),&res,&tail);
	if(rc != SQLITE_OK)
	{
		sqlite3_close(conn);
		return DB_ERR_PREPARE_FAIL;
	}
	rc = sqlite3_step(res);
	if(rc == SQLITE_ROW)
	{
		strcpy(PatientID,(const char*)sqlite3_column_text(res,1));
		strcpy(DateTime,(const char*)sqlite3_column_text(res,2));
		*TotalMaBolus = sqlite3_column_int(res,3);
		*TotalPaDemand = sqlite3_column_int(res,4);
		*TotalSuccessfulDemand = sqlite3_column_int(res,5);
		strcpy(CurrentInfRate,(const char*)sqlite3_column_text(res,6));
		strcpy(TotalVolInfused,(const char*)sqlite3_column_text(res,7));
		strcpy(State,(const char*)sqlite3_column_text(res,8));
		*BedNo = sqlite3_column_int(res,9);
		strcpy(ClinicianLoginID,(const char*)sqlite3_column_text(res,10));

	}
	rc = sqlite3_finalize(res);
	if(rc != SQLITE_OK)
	{
		sqlite3_close(conn);
		return DB_ERR_FINALIZE_FAIL;
	}
	sqlite3_close(conn);
	return DB_SUCCESSFUL;

}
/* Name:EventLog_UpdateTCP
*  Description:to log the MA bolus and total vol infused on a periodic basis.
*  Input: a.as below
*  	   	  b.
*  	      c.
*  Output: 0 if successful; else  rc code.
*  Comments:for use by kaye
*  Usage:
*/
int EventLog_UpdateTCP(const char *PatientID,int TotalMaBolus,int TotalPaDemand,int TotalSuccessfulDemand,const char *CurrentInfRate,const char *TotalVolInfused,const char *State,int BedNo,const char *ClinicianLoginID)
{
		sqlite3 *conn;
		sqlite3_stmt *res;
		char sql_stmt[500];
		const char *tail;
		int rc;

		rc = sqlite3_open(DATABASEFILE ,&conn);
	    if (rc != SQLITE_OK)
		{
	         return (DB_ERR_OPEN_FAIL);
	    }
	    sprintf(sql_stmt,"UPDATE TCPData SET PatientID = '%s',CurrDateTime = datetime(),TotalMachineBolus = %d,TotalPatDemand = %d,TotalSuccessfulDemand = %d,CurrInfusionRate = '%s',TotalVolInfused = '%s',State = '%s',BedNo = %d,ClinicianLoginID = '%s' WHERE Id = 1",PatientID,TotalMaBolus,TotalPaDemand,TotalSuccessfulDemand,CurrentInfRate,TotalVolInfused,State,BedNo,ClinicianLoginID);
	    rc = sqlite3_prepare(conn,sql_stmt,strlen(sql_stmt),&res,&tail);
	    if (rc != SQLITE_OK)
	    {
	    	sqlite3_close(conn);
	    	return (DB_ERR_PREPARE_FAIL);
	    }
	    rc= sqlite3_step(res);
	    if(rc != SQLITE_DONE)
	    {
	    	sqlite3_finalize(res);
	    	sqlite3_close(conn);
	    	return DB_ERR_STEP_FAIL;
	    }
	    rc =sqlite3_finalize(res);
	    if(rc)
	    {
	    	sqlite3_finalize(res);
	    	sqlite3_close(conn);
	    	return DB_ERR_FINALIZE_FAIL;
	    }
	    sqlite3_close(conn);
	    return DB_SUCCESSFUL;
}





/* Name:CfgChangeIp
*  Description:to change the Ip Address
*  Input: a.
*  	   	  b.
*  	      c.
*  Output: 0 if successful; else  rc code.
*  Comments:
*  Usage:
*/
int CgfChangeIp(const char *IpAddress)
{
	sqlite3 *conn;
	sqlite3_stmt *res;
	const char *tail;
	char sql_stmt[500];
	int rc;

	rc = sqlite3_open(DATABASEFILE,&conn);
	if(rc != SQLITE_OK)
	{
		return DB_ERR_OPEN_FAIL;
	}
	sprintf(sql_stmt,"UPDATE CONFIGURATION SET IpAdress = '%s'",IpAddress);
	rc = sqlite3_prepare(conn,sql_stmt,strlen(sql_stmt),&res,&tail);
	if(rc != SQLITE_OK)
	{
		sqlite3_close(conn);
		return DB_ERR_PREPARE_FAIL;
	}
	rc = sqlite3_step(res);
	if(rc != SQLITE_DONE)
	{
		sqlite3_finalize(res);
		sqlite3_close(conn);
		return DB_ERR_STEP_FAIL;
	}
	rc = sqlite3_finalize(res);
	if(rc)
	{
		sqlite3_finalize(res);
		sqlite3_close(conn);
		return DB_ERR_FINALIZE_FAIL;
	}
	sqlite3_close(conn);
	return DB_SUCCESSFUL;

}


/* Name:EventLog_RegisterClinician
*  Description:to change the Ip Address
*  Input: a.
*  	   	  b.
*  	      c.
*  Output: 0 if successful; else  rc code.
*  Comments:
*  Usage:
*/

int EventLog_RegisterClinician(const char *Clinician,const char *ClinicianPW)
{
	sqlite3 *conn;
	sqlite3_stmt *res;
	const char *tail;
	char sql_stmt[500];
	int rc;

	rc = sqlite3_open(DATABASEFILE,&conn);
	if(rc != SQLITE_OK)
	{
		return DB_ERR_OPEN_FAIL;
	}
	sprintf(sql_stmt,"INSERT INTO Clinician(LoginID,Password) values('%s','%s')",Clinician,ClinicianPW);
	rc = sqlite3_prepare(conn,sql_stmt,strlen(sql_stmt),&res,&tail);
	if(rc != SQLITE_OK)
	{
		sqlite3_close(conn);
		return DB_ERR_PREPARE_FAIL;
	}
	rc = sqlite3_step(res);
	if(rc != SQLITE_DONE)
	{
		sqlite3_finalize(res);
		sqlite3_close(conn);
		return DB_ERR_STEP_FAIL;
	}
	rc = sqlite3_finalize(res);
	if(rc)
	{
		sqlite3_finalize(res);
		sqlite3_close(conn);
		return DB_ERR_FINALIZE_FAIL;
	}
	sqlite3_close(conn);
	return DB_SUCCESSFUL;
}
