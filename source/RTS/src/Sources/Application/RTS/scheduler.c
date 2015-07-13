/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         scheduler.c
* Instance:         RPL_1
* %version:         1.1
* %created_by:      Misael Alvarez Dom�nguez
* %date_created:    Wednesday, July 8, 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 04/04/2014  |  Dummy functions              |Francisco Martinez*/
/*  1.1      | 08/07/2015  |  Scheduler file & template    | Misael Alvarez   */
/*============================================================================*/

/* Includes */
/* -------- */
#include "scheduler.h"
#include "GPIO.h"
#include "typedefs.h"
#include "scheduler_Tasks.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */
TASKSTRUCT function_table_def[]=		/* Task's tables initialization */
{
	{ 0,  10, 0, &scheduler_5ms   },
	{ 0,  20, 1, &scheduler_10ms  },
	{ 0, 100, 2, &scheduler_50ms  },
	{ 0, 200, 3, &scheduler_100ms }	
};

TASKSTRUCT *rps_TaskPtr[]=				/* Pointers to tasks structures initialization */
{
	&function_table_def[0],
	&function_table_def[1],
	&function_table_def[2],
	&function_table_def[3]
};

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : Test
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void Test(void)
{
    static T_UWORD rub_U16Counter = 0;
    
    rub_U16Counter++;
    
    if (rub_U16Counter == 1000)
    {
    	LED_TOGGLE(LED1);
    	rub_U16Counter = 0;	
    }

}

/**************************************************************
 *  Name                 : scheduler_tick
 *  Description          :	Scheduler OS tick
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void scheduler_tick(void)
{
	T_UBYTE i;
	for(i=0;i<4;i++)		
	{
		rps_TaskPtr[i]->ruw_Counter++;			/* Increase counters */
		if( (rps_TaskPtr[i]->ruw_Counter) == ((rps_TaskPtr[i]->ruw_TopCount)+(rps_TaskPtr[i]->ruw_Offset)) )
		{
			rps_TaskPtr[i]->ruw_Counter=0;		/* Clear counter */
			rps_TaskPtr[i]->cpfu_PerFunct();	/* Call periodic function */
		}
	}
}

/**************************************************************
 *  Name                 : scheduler_endless_loop
 *  Description          :	
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void scheduler_endless_loop(void)
{
	for(;;)
	{
		/* Do nothing */	
	}
}

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
