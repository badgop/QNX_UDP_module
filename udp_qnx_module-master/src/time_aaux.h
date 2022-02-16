/*
 * time_aaux.h
 *
 *  Created on: 13.09.2021
 *      Author: tatarchuk
 */

#ifndef TIME_AAUX_H_
#define TIME_AAUX_H_



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <stdint.h>



double getTimeDiff(struct timespec *start,struct timespec *stop);

#endif /* TIME_AAUX_H_ */
