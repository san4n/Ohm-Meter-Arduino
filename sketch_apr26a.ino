
/*
 Programme for OHM Meter - Using Arduino and Serial LCD
 dATE : 15 5 2017
 
*/

//LCD config
 
#include <Wire.h> // HEADER FILES FOR WRITE PROGRAM TO LCD
#include <LiquidCrystal_I2C.h> // HEADER FILE FOR DEFINE LCD

LiquidCrystal_I2C lcd(0x3f,20,4);  //sometimes the adress is not 0x3f. Change to 0x27 if it dosn't work.

int analogPin= 0; // DEFINE ANALOG PIN
int V_measured= 0; // VARIABLE
int Vin= 5;  // VARIABLE
float Vout= 0; // VARIABLE
int apply_voltage = 3;  // VARIABLE

float R2= 0; // VARIABLE
float buffer= 0; // BUFFER TO STORE THE VALUE

int ch2K = 6; // PIN ADDRESS
int ch20K = 5; // PIN ADDRESS
int ch200K = 4; // PIN ADDRESS
int ch1M = 7; // PIN ADDRESS


int Scale2k=13; // PIN ADDRESS FOR SCALE
int Scale20k=12; // PIN ADDRESS FOR SCALE
int Scale200k=11; // PIN ADDRESS FOR SCALE
int Scale1M=10; // PIN ADDRESS FOR SCALE


void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(V_measured,INPUT); 
  pinMode(analogPin,INPUT);
  pinMode(apply_voltage,OUTPUT);
  
  //Detect the range mode (0-1kK; 10k-100k; 100k-1M)
  pinMode(Scale2k,INPUT);
  pinMode(Scale20k,INPUT);
  pinMode(Scale200k,INPUT);
  pinMode(Scale1M,INPUT);


//We set this pins as input for now. 
  pinMode(ch2K,INPUT);
  pinMode(ch20K,INPUT);
  pinMode(ch200K,INPUT);
  pinMode(ch1M,INPUT);

}

void loop()
{
///////////////////-2k-/////////////////////
if (digitalRead(Scale2k))
{  
  digitalWrite(apply_voltage,HIGH);
  pinMode(ch2K,OUTPUT);
  pinMode(ch20K,INPUT);
  pinMode(ch200K,INPUT);
  pinMode(ch1M,INPUT);
  digitalWrite(ch2K,LOW);
  
  float R1= 2; // Set this values to the value of the used resistor in K ohms
  V_measured= analogRead(analogPin); //in 8bits
  
      buffer= V_measured * Vin;
      Vout= (buffer)/1024.0;  //in volts
      buffer= (Vin/Vout) -1;
      R2= R1 * buffer*1000; //*1000 because we express it in ohms 
  
      if (R2 > 2000)
      {
        Serial.print("Increase scale");
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("Select scale");
        delay(1000);
        lcd.setCursor(0,1); 
        lcd.print("or Insert R(Ohm)");       
        delay(1000);
      }
  
      if (R2 < 2000)
      {
        Serial.print("----[2K]----");
        Serial.print("\n");
        Serial.print("\n");
        Serial.print("Resistance: ");
        Serial.print(R2);
        Serial.print(" ");
        Serial.print("  ohms");
        Serial.print("\n");
        
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("SCALE:    0 - 2K");
        lcd.setCursor(0,1); 
        lcd.print(R2);

        lcd.setCursor(10,1); 
        lcd.print("  ohms");
        delay(1000);
      }
    
}
////////////////////////////////////////////






///////////////////-20k-/////////////////////
if (digitalRead(Scale20k))
{  
  digitalWrite(apply_voltage,HIGH);
  pinMode(ch2K,INPUT);
  pinMode(ch20K,OUTPUT);
  pinMode(ch200K,INPUT);
  pinMode(ch1M,INPUT);
  digitalWrite(ch20K,LOW);
  
  float R1= 20; // Set this values to the value of the used resistor in K ohms
  V_measured= analogRead(analogPin); //in 8bits
  
      buffer= V_measured * Vin;
      Vout= (buffer)/1024.0;  //in volts
      buffer= (Vin/Vout) -1;
      R2= R1 * buffer;
  
      if (R2 > 20)
      {
        Serial.print("Increase scale");
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("Select scale");
        delay(1000);
        lcd.setCursor(0,1); 
        lcd.print("or Insert R(Ohm)");       
        delay(1000);
      }
  
      if (R2 < 20)
      {
        Serial.print("----[20K]----");
        Serial.print("\n");
        Serial.print("\n");
        Serial.print("Resistance: ");
        Serial.print(R2);
        Serial.print(" ");
        Serial.print("K ohms");
        Serial.print("\n");
        
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("SCALE:   2 - 20K");
        lcd.setCursor(0,1); 
        lcd.print(R2);

        lcd.setCursor(10,1); 
        lcd.print("K ohms");
        delay(1000);
      }
    
}
////////////////////////////////////////////





///////////////////-200k-/////////////////////
if (digitalRead(Scale200k))
{  
  digitalWrite(apply_voltage,HIGH);
  pinMode(ch2K,INPUT);
  pinMode(ch20K,INPUT);
  pinMode(ch200K,OUTPUT);
  pinMode(ch1M,INPUT);
  digitalWrite(ch200K,LOW);
  
  float R1= 220; // Set this values to the value of the used resistor in K ohms
  V_measured= analogRead(analogPin); //in 8bits
  
      buffer= V_measured * Vin;
      Vout= (buffer)/1024.0;  //in volts
      buffer= (Vin/Vout) -1;
      R2= R1 * buffer;
  
      if (R2 > 200)
      {
        Serial.print("Increase scale");
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("Select scale");
        delay(1000);
        lcd.setCursor(0,1); 
        lcd.print("or Insert R(Ohm)");       
        delay(1000);
      }
  
      if (R2 < 200)
      {
        Serial.print("----[200K]----");
        Serial.print("\n");
        Serial.print("\n");
        Serial.print("Resistance: ");
        Serial.print(R2);
        Serial.print(" ");
        Serial.print("K ohms");
        Serial.print("\n");
        
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("SCALE: 20 - 200K");
        lcd.setCursor(0,1); 
        lcd.print(R2);

        lcd.setCursor(10,1); 
        lcd.print("K ohms");
        delay(1000);
      }
    
}
////////////////////////////////////////////





///////////////////-1M-/////////////////////
if (digitalRead(Scale1M))
{  
  digitalWrite(apply_voltage,HIGH);
  pinMode(ch2K,INPUT);
  pinMode(ch20K,INPUT);
  pinMode(ch200K,INPUT);
  pinMode(ch1M,OUTPUT);
  digitalWrite(ch1M,LOW);
  
  float R1= 1; // Set this values to the value of the used resistor in M ohms
  V_measured= analogRead(analogPin); //in 8bits
 
      buffer= V_measured * Vin;
      Vout= (buffer)/1024.0;  //in volts
      buffer= (Vin/Vout) -1;
      R2= R1 * buffer;
  
      if (R2 > 2)
      {
        Serial.print("Select scale");
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("Select scale");
        delay(1000);
        lcd.setCursor(0,1); 
        lcd.print("or insert");

        lcd.setCursor(10,1); 
        lcd.print("R(Ohm)");       
        delay(1000);
      }
  
      if (R2 < 2)
      {
        Serial.print("----[1M]----");
        Serial.print("\n");
        Serial.print("\n");
        Serial.print("Resistance: ");
        Serial.print(R2);
        Serial.print(" ");
        Serial.print("M ohms");
        Serial.print("\n");
        
        lcd.clear();
        lcd.setCursor(0,0); 
        lcd.print("SCALE:  200 - 1M");
        lcd.setCursor(0,1); 
        lcd.print(R2);

        lcd.setCursor(10,1); 
        lcd.print("M ohms");
        delay(1000);
      }
    
}
////////////////////////////////////////////







if (        (digitalRead(Scale2k)==LOW)  &&  (digitalRead(Scale20k)==LOW)  &&  (digitalRead(Scale200k)==LOW)   &&  (digitalRead(Scale1M)==LOW)      )
  { 
    Serial.print("Select scale");
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Select scale and");
    lcd.setCursor(0,1); 
    lcd.print("insert  resistor");
    Serial.print("\n");        
    delay(1000);
  }
}
