/**********************************************************************************************************************
 * [FILE] : ADC.c
 * [Description] : source file of adc driver
 * [Author] : Mohamed Nabil
 * [Created at] : 4/10/2022
 * ********************************************************************************************************************/


/**********************************************************************************************************************
 * INCLUDES
 * ********************************************************************************************************************/
#include "../std_types.h"
#include "../common_macros.h"
#include "avr/io.h"
#include "adc.h"

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

void ADC_init(const ADC_ConfigType* conf){
	/*set the reference of the ADC*/
    ADMUX = (ADMUX & 0x3F)|(conf->refSel<<REFS0);
	/*enable the adc */
	ADCSRA |= (1<<ADEN);
	/*enable or disable the auto trigger*/
	ADMUX |= (conf->autoTrigger<<ADATE);
	/*set the auto trigger option*/
	SFIOR = (SFIOR&0x1F)|(conf->autoTriggerSource);
	/*set the prescalar*/
	ADCSRA = (ADCSRA&0xF8)|(conf->prescalar);
}

/*
 * function name: ADC_readChannel
 * return type: uint16
 * params(in): channel
 * params(in&out): None
 * params(out): None
 * desciption: this function to read analog input from specific channel
 * */
uint16 ADC_readChannel(uint8 channel){
	/*set the channel*/
	ADMUX = (ADMUX&0xE0)|(channel&0x07);
	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);
	/*wait till ADC completes the conversion*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	/*when conversion is comleted clear flag bit then return the result*/
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}


/*
 * function name: ADC_deInit
 * return type: void
 * params(in): None
 * params(in&out): None
 * params(out): None
 * desciption: this function to deinit and disable the ADC
 * */
void ADC_deInit(void){
    ADMUX = 0;
    ADCSRA = 0;
}
