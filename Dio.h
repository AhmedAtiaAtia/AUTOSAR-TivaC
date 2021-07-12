 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author:  AMIT
 ******************************************************************************/

#ifndef DIO_H
#define DIO_H

/* Id for the company in the AUTOSAR
 * for example AMIT's ID = 1419 :) */
#define DIO_VENDOR_ID    (1419U)

/* Dio Module Id */
#define DIO_MODULE_ID    (120U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define DIO_SW_MAJOR_VERSION           (1U)
#define DIO_SW_MINOR_VERSION           (0U)
#define DIO_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.2.2
 */
#define DIO_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_AR_RELEASE_MINOR_VERSION   (0U)
#define DIO_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Dio Status
 */
#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "stdint.h"
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Dio Pre-Compile Configuration Header file */






/* Non AUTOSAR files */
#include "Common_Macros.h"

#include "Dio_Cfg.h"
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8_t)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8_t)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8_t)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8_t)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8_t)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8_t)0x05

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       (uint8_t)0x12

/* Service ID for DIO Init Channel */
#define DIO_INIT_SID                   (uint8_t)0x10

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8_t)0x11

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8_t)0x0A

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             (uint8_t)0x10

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8_t)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      (uint8_t)0x1F

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define DIO_E_PARAM_POINTER             (uint8_t)0x20

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.2.2 DIO SWS Document.
 */
#define DIO_E_UNINIT                   (uint8_t)0xF0
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8_t Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8_t Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8_t Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8_t Dio_PortLevelType;


typedef struct
{
	/* Member contains the ID of the Channel*/
	Dio_ChannelType Ch_Num;
    /* Member contains the Direction of the channel belongs to */
	Dio_LevelType Ch_Dir;
}Dio_ConfigChannel;


/**************************************************/
/* Description : PINS Definitions                 */
/*               PORT A PINS                      */

#define DIO_U8_PIN_0           0
#define DIO_U8_PIN_1           1
#define DIO_U8_PIN_2           2
#define DIO_U8_PIN_3           3
#define DIO_U8_PIN_4           4
#define DIO_U8_PIN_5           5
#define DIO_U8_PIN_6           6
#define DIO_U8_PIN_7           7

/*               PORT B PINS                      */

#define DIO_U8_PIN_8           8
#define DIO_U8_PIN_9           9
#define DIO_U8_PIN_10          10
#define DIO_U8_PIN_11          11
#define DIO_U8_PIN_12          12
#define DIO_U8_PIN_13          13
#define DIO_U8_PIN_14          14
#define DIO_U8_PIN_15          15

/*               PORT C PINS                      */

#define DIO_U8_PIN_16         16
#define DIO_U8_PIN_17         17
#define DIO_U8_PIN_18         18
#define DIO_U8_PIN_19         19
#define DIO_U8_PIN_20         20
#define DIO_U8_PIN_21         21
#define DIO_U8_PIN_22         22
#define DIO_U8_PIN_23         23

/*               PORT D PINS                      */

#define DIO_U8_PIN_24         24
#define DIO_U8_PIN_25         25
#define DIO_U8_PIN_26         26
#define DIO_U8_PIN_27         27
#define DIO_U8_PIN_28         28
#define DIO_U8_PIN_29         29
#define DIO_U8_PIN_30         30
#define DIO_U8_PIN_31         31

/*               PORT E PINS                      */

#define DIO_U8_PIN_32         32
#define DIO_U8_PIN_33         33
#define DIO_U8_PIN_34         34
#define DIO_U8_PIN_35         35
#define DIO_U8_PIN_36         36
#define DIO_U8_PIN_37         37
#define DIO_U8_PIN_38         38
#define DIO_U8_PIN_39         39

/*               PORT F PINS                      */

#define DIO_U8_PIN_40         40
#define DIO_U8_PIN_41         41
#define DIO_U8_PIN_42         42
#define DIO_U8_PIN_43         43
#define DIO_U8_PIN_44         44
#define DIO_U8_PIN_45         45
#define DIO_U8_PIN_46         46
#define DIO_U8_PIN_47         47

#define DIO_U8_OUTPUT        0x01U       /* Standard HIGH */
#define DIO_U8_INPUT         0x00U       /* Standard LOW */

/* Extern PB structures to be used by Dio and other modules */
extern /*const*/ Dio_ConfigChannel Dio_ConfigType [ NUMBER_OF_CHANNELS ] ;
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for DIO read Port API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Function for DIO Initialization API */
void Dio_Init(/*const*/Dio_ConfigChannel * Dio_ConfigType);

/* Function for DIO Get Version Info API */
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/


//extern const Dio_ConfigType Dio_Configuration;

#endif /* DIO_H */
