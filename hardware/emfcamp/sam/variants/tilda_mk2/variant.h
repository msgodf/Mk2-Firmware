/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*
 Orignal from Arduino 1.5.5-r2
 Modified my EMF Camp for the TiLDA Mk2
*/

#ifndef _VARIANT_TILDA_MK2_
#define _VARIANT_TILDA_MK2_

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		12000000

/** Master clock frequency */
#define VARIANT_MCK			84000000

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "Arduino.h"
#ifdef __cplusplus
#include "UARTClass.h"
#include "USARTClass.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/**
 * Libc porting layers
 */
#if defined (  __GNUC__  ) /* GCC CS3 */
#    include <syscalls.h> /** RedHat Newlib minimal stub */
#endif

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (97u)
#define NUM_DIGITAL_PINS     (54u)
#define NUM_ANALOG_INPUTS    (12u)

#define digitalPinToPort(P)        ( g_APinDescription[P].pPort )
#define digitalPinToBitMask(P)     ( g_APinDescription[P].ulPin )
#define digitalPinToTimer(P)       (  )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->PIO_ODSR) )
#define portInputRegister(port)    ( &(port->PIO_PDSR) )
//#define portModeRegister(P)        (  )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

// Interrupts
#define digitalPinToInterrupt(p)  ((p) < NUM_DIGITAL_PINS ? (p) : -1)

// LEDs
#define PIN_LED_13           (13u)
#define PIN_LED_RXL          (72u)
#define PIN_LED_TXL          (73u)
#define PIN_LED              PIN_LED_13
#define PIN_LED2             PIN_LED_RXL
#define PIN_LED3             PIN_LED_TXL
#define LED_BUILTIN          13

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define SPI_INTERFACE        SPI0
#define SPI_INTERFACE_ID     ID_SPI0
#define SPI_CHANNELS_NUM 4
#define PIN_SPI_SS0          (77u)
#define PIN_SPI_SS1          (105u)
#define PIN_SPI_SS2          (104u)
#define PIN_SPI_SS3          (78u)
#define PIN_SPI_MOSI         (75u)
#define PIN_SPI_MISO         (74u)
#define PIN_SPI_SCK          (76u)
#define BOARD_SPI_SS0        (10u)
#define BOARD_SPI_SS1        (4u)
#define BOARD_SPI_SS2        (52u)
#define BOARD_SPI_SS3        PIN_SPI_SS3
#define BOARD_SPI_DEFAULT_SS BOARD_SPI_SS3

#define BOARD_PIN_TO_SPI_PIN(x) \
	(x==BOARD_SPI_SS0 ? PIN_SPI_SS0 : \
	(x==BOARD_SPI_SS1 ? PIN_SPI_SS1 : \
	(x==BOARD_SPI_SS2 ? PIN_SPI_SS2 : PIN_SPI_SS3 )))
#define BOARD_PIN_TO_SPI_CHANNEL(x) \
	(x==BOARD_SPI_SS0 ? 0 : \
	(x==BOARD_SPI_SS1 ? 1 : \
	(x==BOARD_SPI_SS2 ? 2 : 3)))

#define SS   BOARD_SPI_SS0
#define SS1  BOARD_SPI_SS1
#define SS2  BOARD_SPI_SS2
#define SS3  BOARD_SPI_SS3
#define MOSI PIN_SPI_MOSI
#define MISO PIN_SPI_MISO
#define SCK  PIN_SPI_SCK

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 2

#define PIN_WIRE_SDA         (20u)
#define PIN_WIRE_SCL         (21u)
#define WIRE_INTERFACE       TWI1
#define WIRE_INTERFACE_ID    ID_TWI1
#define WIRE_ISR_HANDLER     TWI1_Handler
#define WIRE_ISR_ID          TWI1_IRQn
    
#define PIN_WIRE1_SDA        (70u)
#define PIN_WIRE1_SCL        (71u)
#define WIRE1_INTERFACE      TWI0
#define WIRE1_INTERFACE_ID   ID_TWI0
#define WIRE1_ISR_HANDLER    TWI0_Handler
#define WIRE1_ISR_ID         TWI0_IRQn

/*
 * UART/USART Interfaces
 */
// Serial
#define PINS_UART            (99u)
// Serial1
#define PINS_USART0          (100u)
// Serial2
#define PINS_USART1          (101u)
// Serial3
#define PINS_USART3          (102u)

/*
 * USB Interfaces
 */
#define PINS_USB             (103u)

/*
 * Analog pins
 */
#define A0    54
#define A1    55
#define A2    56
#define A3    57
#define A4    58
#define A5    59
#define A6    60
#define A7    61
#define A8    62
#define A9    63
#define A10   64
#define A11   65
#define DAC0  66
#define DAC1  67
#define CANRX 68
#define CANTX 69
#define ADC_RESOLUTION		12

/*
 * Complementary CAN pins
 */
#define CAN1RX 106
#define CAN1TX 107

// CAN0
#define PINS_CAN0            (108u)
// CAN1
#define PINS_CAN1            (109u)

// EMAC (TiLDA Mk2)
#define PINS_EMAC            (110u)
#define PIN_EMAC_EEXTINT     (95u) // pa5
#define PIN_EMAC_CLKEN       (84u) // pc11
/** EMAC PHY address */
#define BOARD_EMAC_PHY_ADDR  0
/** EMAC RMII mode */
#define BOARD_EMAC_MODE_RMII 1

/*
 * DACC
 */
#define DACC_INTERFACE		DACC
#define DACC_INTERFACE_ID	ID_DACC
#define DACC_RESOLUTION		12
#define DACC_ISR_HANDLER    DACC_Handler
#define DACC_ISR_ID         DACC_IRQn

/*
 * PWM
 */
#define PWM_INTERFACE		PWM
#define PWM_INTERFACE_ID	ID_PWM
#define PWM_FREQUENCY		1000
#define PWM_MAX_DUTY_CYCLE	255
#define PWM_MIN_DUTY_CYCLE	0
#define PWM_RESOLUTION		8

/*
 * TC
 */
#define TC_INTERFACE        TC0
#define TC_INTERFACE_ID     ID_TC0
#define TC_FREQUENCY        1000
#define TC_MAX_DUTY_CYCLE   255
#define TC_MIN_DUTY_CYCLE   0
#define TC_RESOLUTION		8

// TiLDA Mk2 additional pins and handy defines
// Test pads
#define TP4                   (22u) //D22
#define TP5                   (79u)
#define TP6                   (78u) //SS3
#define TP7                   (80u)
#define TP8                   (83u)
#define TP9                   (81u)
#define TP10                  (23u) //D23
#define TP11                  (16u) //Serial2 TXD
#define TP12                  (17u) //Serial2 RXD
#define TP15                  (14u) //Serial3 TXD
#define TP16                  (15u) //Serial3 RXD
    
// RGB LED's
#define LED1_RED              (37u)
#define LED1_GREEN            (39u)
#define LED1_BLUE             (41u)
#define LED2_RED              (82u)
#define LED2_GREEN            (44u)
#define LED2_BLUE             (45u)
    
// epaper display
#define EPD_CS                BOARD_SPI_SS2
#define EPD_BUSY              (38u)
#define EPD_RESET             (34u)
#define EPD_PWM               (35u)
#define EPD_DISCHARGE         (32u)
#define EPD_BORDER_CONTROL    (40u)
#define EPD_PANEL_ON          (33u)
    
// SD socket
#define SD_CS                 BOARD_SPI_SS1
#define SD_CARD_DECTECT       (36u)
    
// Flash
#define FLASH_CS              BOARD_SPI_SS0
#define FLASH_HOLD            (49u)

// IMU (MPU & HMC)
#define MPU_INT               (31u)
#define HMC_DRDY              (30u)
    
// Radio (SRF)
#define SRF_SLEEP             (61u)
#define SRF_AT_COMMAND        (60u)  // should be 43 but seems I forgot to swap with LIGHT
    
//IR
#define IR_TX_PWM             (6u)
#define IR_RX                 (42u)
    
//Buttons
#define BUTTON_LIGHT          (43u) // should be 60 but seems I forgot to swap the trace with SRF_AT_COMMAND
#define BUTTON_SCREEN_RIGHT   (46u)
#define BUTTON_SCREEN_LEFT    (29u)
#define BUTTON_A              (47u)
#define BUTTON_B              (48u)
#define BUTTON_UP             (27u)
#define BUTTON_RIGHT          (25u)
#define BUTTON_DOWN           (26u)
#define BUTTON_LEFT           (28u)
#define BUTTON_CENTER         (24u)
    
//PMIC
#define VBATT_MON             A11
#define PMIC_ENOTG            (96u)
#define PMIC_VUSBGD           (64u)
#define PMIC_FAULT            (63u)
#define PMIC_CHRG             (62u)
#define PMIC_ILIM1            (51u)
#define PMIC_ILIM0            (50u)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

extern UARTClass Serial;
extern USARTClass Serial1;
extern USARTClass Serial2;
extern USARTClass Serial3;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR         Serial
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_HARDWARE_OPEN   Serial1
#define SERIAL_PORT_HARDWARE_OPEN1  Serial2
#define SERIAL_PORT_HARDWARE_OPEN2  Serial3
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE1       Serial1
#define SERIAL_PORT_HARDWARE2       Serial2
#define SERIAL_PORT_HARDWARE3       Serial3

#endif /* _VARIANT_TILDA_MK2_ */
