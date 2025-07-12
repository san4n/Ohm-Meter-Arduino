
#include "LCD.h"

void DisplayResistance(void)
{
    const char Voltage[] = "Digital OhmMeter";
    unsigned char Unit = 0;
    const float R3 = 10000, Vcc = 5.0;               /*  vo = (10k/(90k + 10k)) vcc    */
    unsigned int ADC_Value = 0;
    float VoltageOutput = 0.0;
    unsigned long ResistanceMeasured = 0;           /*  32 bit wide data type          */



    ClearScreen_LCD();
    WriteString_LCD(Voltage);
    MoveCursorToPosition(SecondLine);
    ADC_Value = SamplingAndConversionADC();                 /*  Sampling                */

    VoltageOutput = ((float)(ADC_Value))* 0.0048828;        /* 0.0048828 = 5/1024       */
    

    ResistanceMeasured = (unsigned long)((VoltageOutput * R3)/(Vcc - VoltageOutput));
    
    //ResistanceMeasured *= 1000;                             /*  miliOhms conversion    */

    Unit = WriteLongAsFloatUptoFiveFigures(ResistanceMeasured);    /*  Printing integer value on LCD   */

    if (Unit ==2)
        WriteString_LCD(" MOhm");
    else if (Unit == 1)
        WriteString_LCD(" kOhm");
    else if (!Unit)
        WriteString_LCD(" Ohm");
    else
        WriteString_LCD("Too Large");

}

