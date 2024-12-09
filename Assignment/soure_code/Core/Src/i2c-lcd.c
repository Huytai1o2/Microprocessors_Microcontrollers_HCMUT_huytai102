/*
 * lcd.c
 *
 *  Created on: Nov 7, 2024
 *      Author: DELL
 */
#include "i2c-lcd.h"
I2C_HandleTypeDef hi2c1;

#define SLAVE_ADDRESS_LCD (0x21 << 1) // address of slave - LCD

void lcd_send_cmd (char cmd)
{
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_init (void) {
	lcd_send_cmd (0x33); /* set 4-bits interface */
	lcd_send_cmd (0x32);
	HAL_Delay(50);
	lcd_send_cmd (0x28); /* start to set LCD function */
	HAL_Delay(50);
	lcd_send_cmd (0x01); /* clear display */
	HAL_Delay(50);
	lcd_send_cmd (0x06); /* set entry mode */
	HAL_Delay(50);
	lcd_send_cmd (0x0c); /* set display to on */
	HAL_Delay(50);
	lcd_send_cmd (0x02); /* move cursor to home and set data address to 0 */
	HAL_Delay(50);
	lcd_send_cmd (0x80);
}

void lcd_send_string (char *str)
{
	while (*str) lcd_send_data (*str++);
}

void lcd_send_num (int num){
	char buffer[8];
	sprintf(buffer, "%d", num);
	lcd_send_string(buffer);
}

void lcd_clear_display (void)
{
	lcd_send_cmd (0x01); //clear display
	HAL_Delay(20);
}

void lcd_goto_XY (int row, int col)
{
	switch (row){
		case 0:
			col |= 0x80;
			break;
		case 1:
			col |= 0xC0;
			break;
	}
	lcd_send_cmd (col);
}
