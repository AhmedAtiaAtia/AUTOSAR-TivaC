/*
 * Dio_Cfg.c
 *
 *  Created on: Jul 5, 2021
 *      Author: AMIT
 */
#include "Dio_Cfg.h"
#include "Dio.h"

/* Data Structure required for initializing the Dio Driver */
/*typedef struct Dio_ConfigType
{
    Dio_ConfigChannel Channels[NUMBER_OF_CHANNELS] =
            {
             {DIO_u8_PIN_0 ,DIO_u8_PIN_7}  ,
             {DIO_u8_PIN_1 ,DIO_u8_PIN_17} ,
             {DIO_u8_PIN_8 ,DIO_u8_PIN_14} ,
             {DIO_u8_PIN_9 ,DIO_u8_PIN_10} ,
             {DIO_u8_PIN_2 ,DIO_u8_PIN_11}

            };
} Dio_ConfigType;*/
Dio_ConfigChannel Dio_ConfigType[NUMBER_OF_CHANNELS] =
            {
             {DIO_U8_PIN_0 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_1 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_2 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_3 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_4 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_5 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_6 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_7 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_8 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_9 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_10 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_11 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_12 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_13 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_14 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_15 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_16 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_17 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_18 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_19 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_20 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_21 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_22 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_23 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_24 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_25 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_26 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_27 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_28 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_29 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_30 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_31 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_32 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_33 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_34 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_35 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_36 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_37 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_38 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_39 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_40 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_41 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_42 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_43 ,    DIO_U8_INPUT}   ,
             {DIO_U8_PIN_44 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_45 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_46 ,    DIO_U8_OUTPUT}  ,
             {DIO_U8_PIN_47 ,    DIO_U8_OUTPUT}

            };

/*

DcMotor ArrayOfMotor [ NUMBER_OF_PORTS ] =
{
    {DIO_u8_PIN_0 ,DIO_u8_PIN_7}  ,
    {DIO_u8_PIN_1 ,DIO_u8_PIN_17} ,
    {DIO_u8_PIN_8 ,DIO_u8_PIN_14} ,
    {DIO_u8_PIN_9 ,DIO_u8_PIN_10} ,
    {DIO_u8_PIN_2 ,DIO_u8_PIN_11}


};
*/

