/*
 * Algo.h
 *
 *  Created on: Jul 18, 2013
 *      Author: blaqkrow
 */

#ifdef __cplusplus
extern "C"
{
#endif

void updateBuffer();
void btnStart();
void btnStop();
void btnPause();
void *buttonPressed();
void *algo();
int statusMSG();
void algoMain(void);
void join();
void setIP(const char* ipadd);
void setTime();
int bolusCountReturn();
int ABReturn();
int PBReturn();
int PBTotalReturn();
void *AlarmThread();
int Alarm_Enable();
void SoundthreadDeclare();
float infusedVolumeReturn();

#ifdef __cplusplus
}

#endif /* DB_API_H_ */
