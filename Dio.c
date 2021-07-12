 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author:  AMIT
 ******************************************************************************/
#include "stdint.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Dio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif
//
//#define GPIO_PORTF_BASE *((uint32_t*)0x50000000)
//#define GPIO_PORT        GPIO_PORTF_BASE

/************************************************************************************
* Service Name: Dio_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Dio module.
************************************************************************************/
void Dio_Init(Dio_ConfigChannel * Dio_ConfigType)
{

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,
		     DIO_E_PARAM_CONFIG);
	}
	else
#endif
	{
	    /*  RCC Enable non autosar Function for enable GPIO peripherals RCC*/
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	    /*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
	    uint8_t i;
	    for(i = 0 ; i < 48 ; i++)
	    {
	        uint8_t Port_Num = (Dio_ConfigType[i].Ch_Num / 8);
	        switch(Port_Num)
	        {
	        case 0 :    if(Dio_ConfigType[i].Ch_Dir == DIO_U8_OUTPUT)
	                    {
	                        GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

	                    }
	                    else if(Dio_ConfigType[i].Ch_Dir == DIO_U8_INPUT)
	                    {

                            GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

	                    }
	                    else
	                    {
	                        /*                      Do Nothing                       */
	                    }
	        break;

            case 1 :    if(Dio_ConfigType[i].Ch_Dir == DIO_U8_OUTPUT)
                        {
                            GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

                        }
                        else if(Dio_ConfigType[i].Ch_Dir == DIO_U8_INPUT)
                        {

                            GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

                        }
                        else
                        {
                            /*                      Do Nothing                       */
                        }
            break;

            case 2 :    if(Dio_ConfigType[i].Ch_Dir == DIO_U8_OUTPUT)
                        {
                            GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

                        }
                        else if(Dio_ConfigType[i].Ch_Dir == DIO_U8_INPUT)
                        {

                            GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

                        }
                        else
                        {
                            /*                      Do Nothing                       */
                        }
            break;

            case 3 :    if(Dio_ConfigType[i].Ch_Dir == DIO_U8_OUTPUT)
                        {
                            GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

                        }
                        else if(Dio_ConfigType[i].Ch_Dir == DIO_U8_INPUT)
                        {

                            GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

                        }
                        else
                        {
                            /*                      Do Nothing                       */
                        }
            break;

            case 4 :    if(Dio_ConfigType[i].Ch_Dir == DIO_U8_OUTPUT)
                        {
                            GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

                        }
                        else if(Dio_ConfigType[i].Ch_Dir == DIO_U8_INPUT)
                        {

                            GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

                        }
                        else
                        {
                            /*                      Do Nothing                       */
                        }
            break;

            case 5 :    if(Dio_ConfigType[i].Ch_Dir == DIO_U8_OUTPUT)
                        {
                            GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

                        }
                        else if(Dio_ConfigType[i].Ch_Dir == DIO_U8_INPUT)
                        {

                            GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)));

                        }
                        else
                        {
                            /*                      Do Nothing                       */
                        }
            break;
	        }
	      }


		}
}

/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	//volatile uint32_t * Port_Ptr = NULL_PTR;
	bool  error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
	    GPIOPinWrite(0, ChannelId, Level);

	    uint8_t i;
	            for(i = 0 ; i < 48 ; i++)
	            {
	                uint8_t Port_Num = (Dio_ConfigType[i].Ch_Num / 8);
	                switch(Port_Num)
	                {
	                case 0 :    if(Dio_ConfigType[i].Ch_Dir == STD_HIGH)
	                            {
	                                GPIOPinWrite(GPIO_PORTA_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),(1 << (Dio_ConfigType[i].Ch_Num%8)));

	                            }
	                            else if(Dio_ConfigType[i].Ch_Dir == STD_LOW)
	                            {

	                                GPIOPinWrite(GPIO_PORTA_BASE, (0 << (Dio_ConfigType[i].Ch_Num%8)),0);

	                            }
	                            else
	                            {
	                                /*                      Do Nothing                       */
	                            }
	                break;

	                case 1 :    if(Dio_ConfigType[i].Ch_Dir == STD_HIGH)
	                            {
	                                GPIOPinWrite(GPIO_PORTB_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),(1 << (Dio_ConfigType[i].Ch_Num%8)));

	                            }
	                            else if(Dio_ConfigType[i].Ch_Dir == STD_LOW)
	                            {

	                                GPIOPinWrite(GPIO_PORTB_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),0);

	                            }
	                            else
	                            {
	                                /*                      Do Nothing                       */
	                            }
	                break;

	                case 2 :    if(Dio_ConfigType[i].Ch_Dir == STD_HIGH)
	                            {
	                                GPIOPinWrite(GPIO_PORTC_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),(1 << (Dio_ConfigType[i].Ch_Num%8)));

	                            }
	                            else if(Dio_ConfigType[i].Ch_Dir == STD_LOW)
	                            {

	                                GPIOPinWrite(GPIO_PORTC_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),0);

	                            }
	                            else
	                            {
	                                /*                      Do Nothing                       */
	                            }
	                break;

	                case 3 :    if(Dio_ConfigType[i].Ch_Dir == STD_HIGH)
	                            {
	                                GPIOPinWrite(GPIO_PORTD_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),(1 << (Dio_ConfigType[i].Ch_Num%8)));

	                            }
	                            else if(Dio_ConfigType[i].Ch_Dir == STD_LOW)
	                            {

	                                GPIOPinWrite(GPIO_PORTD_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),0);

	                            }
	                            else
	                            {
	                                /*                      Do Nothing                       */
	                            }
	                break;

	                case 4 :    if(Dio_ConfigType[i].Ch_Dir == STD_HIGH)
	                            {
	                                GPIOPinWrite(GPIO_PORTE_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),(1 << (Dio_ConfigType[i].Ch_Num%8)));

	                            }
	                            else if(Dio_ConfigType[i].Ch_Dir == STD_LOW)
	                            {

	                                GPIOPinWrite(GPIO_PORTE_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),0);

	                            }
	                            else
	                            {
	                                /*                      Do Nothing                       */
	                            }
	                break;

	                case 5 :    if(Dio_ConfigType[i].Ch_Dir == STD_HIGH)
	                            {
	                                GPIOPinWrite(GPIO_PORTF_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),(1 << (Dio_ConfigType[i].Ch_Num%8)));

	                            }
	                            else if(Dio_ConfigType[i].Ch_Dir == STD_LOW)
	                            {

	                                GPIOPinWrite(GPIO_PORTF_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8)),0);

	                            }
	                            else
	                            {
	                                /*                      Do Nothing                       */
	                            }
	                break;
	                }
	              }


	}
	else
	{
		/* No Action Required */
	}

}

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	//volatile uint32_t * Port_Ptr = NULL_PTR
	Dio_LevelType output = STD_LOW;
	bool error = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (DIO_NOT_INITIALIZED == Dio_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_SID, DIO_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
		/* Read the required channel */
	            uint8_t i;
	                   for(i = 0 ; i < 48 ; i++)
	                   {
	                       uint8_t Port_Num = (Dio_ConfigType[i].Ch_Num / 8);
	                       switch(Port_Num)
	                       {
	                       case 0 :    if(GPIOPinRead(GPIO_PORTA_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8))))
	                                   {
	                                       output = STD_HIGH;
	                                   }
	                                   else
	                                   {
	                                       output = STD_LOW;
	                                   }
	                       break;

	                       case 1 :    if(GPIOPinRead(GPIO_PORTB_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8))))
	                                   {
	                                       output = STD_HIGH;
	                                   }
	                                   else
	                                   {
	                                       output = STD_LOW;
	                                   }
	                       break;

	                       case 2 :    if(GPIOPinRead(GPIO_PORTC_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8))))
	                                   {
	                                        output = STD_HIGH;
	                                   }
	                                   else
	                                   {
	                                       output = STD_LOW;
	                                   }

	                       break;

	                       case 3 :    if(GPIOPinRead(GPIO_PORTD_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8))))
	                                   {
	                                       output = STD_HIGH;
	                                   }
	                                   else
	                                   {
	                                       output = STD_LOW;
	                                   }
	                       break;

	                       case 4 :    if(GPIOPinRead(GPIO_PORTE_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8))))
	                                   {
	                                       output = STD_HIGH;
	                                   }
	                                   else
	                                   {
	                                       output = STD_LOW;
	                                   }
	                       break;

	                       case 5 :    if(GPIOPinRead(GPIO_PORTF_BASE, (1 << (Dio_ConfigType[i].Ch_Num%8))))
	                                   {
	                                       output = STD_HIGH;
	                                   }
	                                   else
	                                   {
	                                       output = STD_LOW;
	                                   }
	                       break;
	                       }
	                     }
	}
	else
	{
		/* No Action Required */
	}
        return output;
}
