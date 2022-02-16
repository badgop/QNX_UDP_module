/*
 * bit_field_pack.h
 *
 *  Created on: 26 марта 2018 г.
 *      Author: Ivan
 */

#include <stdio.h>
#include <stdint.h>


#ifndef SRC_BIT_FIELD_PACK_H_
#define SRC_BIT_FIELD_PACK_H_


/*
 * Запаковать структуру типа битовое поле в 32 разрядный регистр
 *
 *	reg -  переменная содержащая ТЕКУЩЕЕ значени регистра
 *	bit_field - само битовое поле
 *	bit_mask- битовая маска поля, определяется его длиной, которая указана в описании поля
 */
uint32_t bit_field_pack_u32(uint32_t reg_in,uint32_t bit_field,uint8_t shift , uint32_t bit_mask);



#endif /* SRC_BIT_FIELD_PACK_H_ */
