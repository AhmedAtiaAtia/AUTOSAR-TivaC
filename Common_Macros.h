/******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: Comon_Macros.h
 *
 * Description:  This file contains the most important and frequently used macros in 
					embedded applications.
 *
 * Author:  AMIT
 *
 *******************************************************************************/

#ifndef COMMON_MACROS
#define COMMON_MACROS

/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :	SET_BIT
[DESCRIPTION]  :	This macro is responsible for setting certain bit in a certain register 
					or variable
[Args]		   :
				in  -> a_REG:
							This argument indicates the register or the variable in which 
							the bit will set
				in  -> a_BIT:
							This argument indicates the bit number which will set
------------------------------------------------------------------------------------------*/
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :	CLEAR_BIT
[DESCRIPTION]  :	This macro is responsible for clearing certain bit in a certain register 
					or variable
[Args]		   :
				in  -> a_REG:
							This argument indicates the register or the variable in which 
							the clear will be cleared
				in  -> a_BIT:
							This argument indicates the bit number which will be cleared
------------------------------------------------------------------------------------------*/
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :	TOGGLE_BIT
[DESCRIPTION]  :	This macro is responsible for toggling certain bit in a certain register 
					or variable
[Args]		   :
				in  -> a_REG:
							This argument indicates the register or the variable in which 
							the clear will be toggled
				in  -> a_BIT:
							This argument indicates the bit number which will be toggled
------------------------------------------------------------------------------------------*/
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :    GET_BIT
[DESCRIPTION]  :    This macro is responsible for return specific bit Value is clear in any
                    register or not
[Args]         :
                in  -> a_REG:
                            This argument indicates the register or the variable in which the
                            bit will be checked the bit
                in  -> a_BIT:
                            This argument indicates the bit number
[Return]       :
                Zero if the bit is clear

                One if the bit is set
------------------------------------------------------------------------------------------*/
#define GET_BIT(REG,BIT) ( (REG >> BIT)&1)


#endif
