/*
 * times_wrapper.h
 *
 *  Created on: 10.09.2021
 *      Author: tatarchuk
 */

#ifndef TIMES_WRAPPER_H_
#define TIMES_WRAPPER_H_
#include "vRtApi.h"
#include <hw/inout.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <time.h>


class Timer {
public:
	Timer(uint8_t flag,uint32_t notifyType, uint32_t priorityType, uint8_t  sigevCodein);
	int32_t start(uint32_t startsec, uint32_t startnsec,uint32_t repeatsec, uint32_t repeatnsec );
	int32_t checkTime();
	virtual ~Timer();

	struct sigevent         timerEvent;
	timer_t                 timerTimer_id;
	int                     timerChid;
	int                     timerRcvid;
	_pulse					timerPulse;

	char                    sigevCode;
	bool                    errorCreate;
private:
    // код определяющий импульс какого таймера был выработан ОС


};

#endif /* TIMES_WRAPPER_H_ */
