/*
 * time_aux.c
 *
 *  Created on: 13.09.2021
 *      Author: tatarchuk
 */

#include "time_aaux.h"


double getTimeDiff(struct timespec *start,struct timespec *stop)

{
	using namespace std;

	const int billion = 1000000000L;
	double diff_sec;
	double diff_n;
	double diff;
	int32_t sec;
	int64_t nsec;



	sec = -(stop->tv_sec - start->tv_sec);
	nsec = -(stop->tv_nsec-start->tv_nsec);


	diff_n =  (double)(nsec)/(double)(billion);
	diff_sec = (double)( sec);


	diff = diff_n+ diff_sec;


	return diff;

}
