/* 
 * File:   main.c
 * Author: IBRAHIM NAZIR SANGI
 *
 * Created on July 18, 2013, 5:15 AM
 */

#define CRYSTAL_FRQUENCY   10000000             /*  10MHz crystal   */
#define FCY CRYSTAL_FRQUENCY/2UL                /*  Cycle frequency */

#include <p24F16KA102.h>
#include <libpic30.h>
#include "LCD.h"
#include "ADC.h"

/******************************************************************************/

/*  *** Configuration Bits Setting  *** */

_FGS(GWRP_OFF & GCP_OFF)
_FOSCSEL(FNOSC_PRI & IESO_OFF)
_FOSC(POSCMOD_HS & OSCIOFNC_ON & POSCFREQ_HS & FCKSM_CSDCMD)
_FWDT(WINDIS_OFF & FWDTEN_OFF)
_FPOR(BOREN_BOR2 & PWRTEN_OFF  & MCLRE_ON)
_FDS(DSBOREN_OFF & DSWDTEN_OFF)

/******************************************************************************/
/*
 *
 */
int main(void)
{   
    Initilize_LCD();
    
    ConfigModuleADC();          /*  Configure ADC module    */
    ChangeChannelADC(0);        /*  AN0 channel             */
     
    while(1)
    {
        DisplayResistance();
        __delay_ms(100);                        /*  200m Second delay  */
    }
    return 0;
}
