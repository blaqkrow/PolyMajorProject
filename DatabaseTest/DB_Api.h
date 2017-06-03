/*
 * DB_Api.h
 *
 *  Created on: Jul 5, 2013
 *      Author: clarified
 */



#ifdef __cplusplus
extern "C"
{
#endif

// Constants:

// Error codes:
#define DB_SUCCESSFUL               0
#define DB_ERR_OPEN_FAIL            1
#define DB_ERR_PREPARE_FAIL         2
#define DB_ERR_STEP_FAIL 			3
#define DB_ERR_FINALIZE_FAIL		4


// Prototypes
int EventLog_OnLogin(const char *PatientId,const char *Password);
int EventLog_OnPeriod(const char *Patient_Id,int TotalMaBolus,int TotalPaDemand,int TotalSuccessfulDemand,const char *CurrentInfRate,const char *Total_Vol_Infused,const char *State,int Bed_No,const char *CLinicianLoginID);
int EventLog_OnTriggered(const char *EventType);
int EventLog_GetTCP(char *PatientID,char *DateTime,int *TotalMaBolus,int *TotalPaDemand,int *TotalSuccessfulDemand,char *CurrentInfRate,char *TotalVolInfused,char *State,int *BedNo,char *ClinicianLoginID);
int EventLog_UpdateTCP(const char *PatientID,int TotalMaBolus,int TotalPaDemand,int TotalSuccessfulDemand,const char *CurrentInfRate,const char *TotalVolInfused,const char *State,int BedNo,const char *ClinicianLoginID);
int CgfChangeIp(const char *IpAddress);
int EventLog_RegisterClinician(const char *Clinician,const char *ClinicianPW);
#ifdef __cplusplus
}

#endif /* DB_API_H_ */
