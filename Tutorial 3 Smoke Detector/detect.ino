#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


#define buzzer 9

#define sensor A0    

#define load_Res 10    

#define air_factor 9.83  

                                                    

float SmokeCurve[3] ={2.3,0.53,-0.44};    // (x, y, slope) x,y coordinate of one point and the slope between two points

                                                                                        

float Res=0;                


void setup()

{   

  lcd.begin(16,2);

  lcd.print("Calibrating.....");                

  Res = SensorCalibration();                                                                                          

  lcd.print("Calibration done.");

  lcd.setCursor(0,1); 

  lcd.print("Res=");

  lcd.print(Res);

  lcd.print("kohm");

  delay(2000);

  lcd.clear();

  pinMode(buzzer, OUTPUT);

}


void loop()

{  

   lcd.setCursor(0,0); 

   lcd.print("SMOKE:"); 

   float res=resistance(5,50);

   res/=Res;

   int result=pow(10,(((log(res)-SmokeCurve[1])/SmokeCurve[2]) + SmokeCurve[0]));

   lcd.print(result);

   lcd.print( " ppm        ");

   if(result>1000)

   {

      digitalWrite(buzzer, HIGH);

      delay(2000);

   }

   else

   digitalWrite(buzzer, LOW);

   delay(500);

}


float resistance(int samples, int interval)

{

   int i;

   float res=0; 

   for (i=0;i<samples;i++) 

   {

      int adc_value=analogRead(sensor);

      res+=((float)load_Res*(1023-adc_value)/adc_value);

      delay(interval);

   }

   res/=samples;

   return res;

}

 

 

float SensorCalibration()

{

  int i;

  float val=0;    

  val=resistance(50,500);                

  val = val/air_factor;  

  return val; 

}
