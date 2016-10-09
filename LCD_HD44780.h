// ���������� ��� ������ � LCD HD44780 ��������
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>

////////////////////////���������������////////////////////////////////////////
//#define F_CPU 8000000L
#define PORT_SIG 	  PORTB//���� ����������
#define DDR_SIG	      DDRB//
#define PIN_SIG   	  PINB//
#define E      	      PB0//�����
#define RW	   	   	  PB1//�����������:1 ������ �������, 0 ������ � �������
#define RS  	      PB2//1 �������� ������, 0 �������� �������
#define PORT_DATA	  PORTA//���� ������
#define DDR_DATA	  DDRA//
#define PIN_DATA	  PINA//
#define BF       	  PA7//���� ��������� ���� 1 �� ����� ������� ���� 0 �� ��������
#define RS_COM   	  0//�������� �������
#define RS_DATA  	  1//�������� ������
#define ON			  1//��������� 
#define OFF			  0//����������
#define BUS_LINE	  0x28//2 ����� ������, 4 ���� ����
#define SEC_LINE	  0xA8//������ ����� ������ ������
#define FIRS_LINE 	  0x80//������ ����� ������ ������
#define FIRST		  0x80//����� ������ ������ 
#define THIRD		  0x82//
#define FOURTH		  0x83//����� ��������� ������	  
#define SEVENTH		  0x86//����� ������� ������
#define EIGHTH		  0x87//
#define ELEVENTH	  0x8B//
#define THIRTEENTH 	  0x8C//
#define THIRD_S	      0xC2//
#define SEVENTH_S	  0xC6//
#define EIGHTH_S	  0xC8//
#define ELEVENTH_S 	  0xB2//
#define THIRTEENTH_S  0xCD//
#define FIFTEENTH_S   0xB6//
//////////////////////////////////////�������///////////////////////////////
void LCD_init();//������� ������������� ������� 
void LCD_write(uint8_t data, uint8_t BIT_RS);//������� ������ � �������
void LCD_read_BF();//������� ������ ����� BF ���������� �� ������� �� ������ ������ �� ��������!!!������ ����� delay)))
void LCD_write_adress(uint8_t data, uint8_t adress);//������� ������ � ������� �� ����������� ������
void LCD_write_str(int8_t *string);//������ ������ �� �������
void line_wrapping(int8_t number);//������������ �� ������ ������
void clean_display();//������� �������
void kursor_adress(uint8_t adress);//��������� ������� �� ������ �����
void LCD_alignment(int16_t str, uint8_t adress);// ������� ������������ �� ������� ��������
