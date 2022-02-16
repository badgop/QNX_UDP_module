/*
 * bit_field_pack.c
 *
 *  Created on: 26 марта 2018 г.
 *      Author: Ivan
 */


#include "bit_field_pack.h"









/*
 * Запаковать структуру типа битовое поле в 32 разрядный регистр
 *
 *	reg -  переменная содержащая ТЕКУЩЕЕ значени регистра
 *	bit_field - само битовое поле
 *	bit_mask- битовая маска поля, определяется его длиной, которая указана в описании поля *
 */
uint32_t  bit_field_pack_u32(uint32_t reg_in,uint32_t bit_field,uint8_t shift , uint32_t bit_mask)

{
	reg_in=reg_in & (~((bit_mask)<<shift));
	reg_in=reg_in | ((bit_field&bit_mask)<<shift);

	return reg_in;
}
