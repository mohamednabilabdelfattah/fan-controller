/**********************************************************************************************************************
 * [FILE] : ADC.h
 * [Description] : header file of adc driver
 * [Author] : Mohamed Nabil
 * [Created at] : 4/10/2022
 * ********************************************************************************************************************/


#ifndef ADC_H_
#define ADC_H_

/**********************************************************************************************************************
 * INCLUDES
 * ********************************************************************************************************************/
#include "../std_types.h"
/**********************************************************************************************************************
 * DEFINITIONS
 * ********************************************************************************************************************/
#define ADC_REF_VOLT_VALUE 2.56
#define ADC_MAXIMUM_VALUE 1023
/**********************************************************************************************************************
 * ENUMERATIOMS
 * ********************************************************************************************************************/

/*type of reference voltage*/
typedef enum{
    AREF,
    AVCC,
    INTERNAL = 3
}ADC_ReferenceSelection;

/*type of start of conversion*/
typedef enum{
    DISABLE,
    ENABLE
}ADC_AutoTrigger;

/*type of trigger source*/
typedef enum{
    FREE,
    ANALOG_COMPARATOR,
    EXTERNAL_INT_0,
    TIMER0_CMP,
    TIMER0_OVR,
    TIMER1_CMP,
    TIMER1_OVR,
    TIMER1_ICA
}ADC_AutoTriggerSource;

/*type of prescalar*/
typedef enum{
    F_CPU_2 = 1,
    F_CPU_4 ,
    F_CPU_8 ,
    F_CPU_16 ,
    F_CPU_32 ,
    F_CPU_64 ,
    F_CPU_128
}ADC_Prescalar;

/**********************************************************************************************************************
 * STRUCTURES
 * ********************************************************************************************************************/
typedef struct{
	ADC_ReferenceSelection refSel;
    ADC_AutoTrigger autoTrigger;
    ADC_AutoTriggerSource autoTriggerSource;
    ADC_Prescalar prescalar;
}ADC_ConfigType;


/**********************************************************************************************************************
 * functions
 * ********************************************************************************************************************/

/*
 * function name: ADC_init
 * return type: void
 * params(in): ADC_ConfigType
 * params(in&out): None
 * params(out): None
 * desciption: this function to init according to ADC configurations
 * */
void ADC_init(const ADC_ConfigType*);

/*
 * function name: ADC_readChannel
 * return type: uint16
 * params(in): channel
 * params(in&out): None
 * params(out): None
 * desciption: this function to read analog input from specific channel
 * */


uint16 ADC_readChannel(uint8 channel);


/*
 * function name: ADC_deInit
 * return type: void
 * params(in): None
 * params(in&out): None
 * params(out): None
 * desciption: this function to deinit and disable the ADC
 * */
void ADC_deInit(void);

#endif
