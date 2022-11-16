/******************************************************************************
 * File Name: lm35_sensor.h
 *
 * Description: header file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Nabil
 *
 * Date created: 06/10/2022
 *******************************************************************************/




/******************************************************************************
 *  INCLUDES
 *******************************************************************************/

#include "motor/motor.h"
#include "LCD/lcd.h"
#include "tempsensor/lm35_sensor.h"
#include "std_types.h"
#include "ADC/ADC.h"


int main(void)
{

	uint8 temperature;
	/*init the ADC*/
	ADC_ConfigType ADC_conf = {INTERNAL,DISABLE,FREE,F_CPU_8};
	ADC_init(&ADC_conf);
	/*init the lcd*/
	LCD_init();
	/*init the motor*/
	DcMotor_Init();
	while(1)
	{
		/*read the temperature*/
		temperature = LM35_getTemperature();
		if(temperature > 120)
		{
			/*the fan will run by speed 100*/
			LCD_displayStringRowColumn(0, 0, "FAN speed = 100");
			DcMotor_Rotate(CW,100);
		}
		else if(temperature>90)
		{
			/*the fan will run by speed 75*/
			LCD_displayStringRowColumn(0, 0, "FAN speed = 075");
			DcMotor_Rotate(CW,75);
		}
		else if(temperature > 60)
		{
			/*the fan will run by speed 60*/
			LCD_displayStringRowColumn(0, 0, "FAN speed = 060");
			DcMotor_Rotate(CW,60);
		}
		else if(temperature > 30 )
		{
			/*the fan will run by speed 25*/
			LCD_displayStringRowColumn(0, 0, "FAN speed = 025");
			DcMotor_Rotate(CW,25);
		}
		else
		{
			/*the fan is off*/
			LCD_displayStringRowColumn(0, 0, "FAN IS OFF     ");
			DcMotor_Rotate(STOP, 0);
		}
		/*update the temperature on lcd*/
		LCD_displayStringRowColumn(1, 0,"Temp =");
		LCD_intgerToString(temperature);
		LCD_displayString("   ");
	}
}
