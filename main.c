

/**
 * main.c
 */
#include "Platform_Types.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "Dio.h"

int main(void)
{
    Dio_Init(Dio_ConfigType);
   // SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  /*  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);//RED LED*/
  //  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);//BLUE LED
    //GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);//YELLOW LED
    /*GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);// BUTTON1*/
    /*GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);*/

    while(1)
    {
        if(Dio_ReadChannel(DIO_U8_PIN_44) == 0)
        {
            Dio_WriteChannel(DIO_U8_PIN_42, STD_HIGH);
        }
       /* if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4)==0)
        {
            //GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 2);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 4);
            //GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 8);
            while(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4)==0);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
        }
*/
    }
    return 0;
}
