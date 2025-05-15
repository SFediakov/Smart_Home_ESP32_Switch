int ADC_Measure (int port, int steps){
int ADC_MEASURE =0;

for (int i=0; i < steps; i++){
  ADC_MEASURE = ADC_MEASURE + analogRead (port);
}
ADC_MEASURE = ADC_MEASURE/steps;
return ADC_MEASURE;
}

#define Current_CH1 35 
#define Current_CH2 32
#define Current_CH3 33
#define Voltage_Pin 4

//for power measure
float TEMP_Power_CH1=0;
float TEMP_Power_CH2=0;
float TEMP_Power_CH3=0;
float TEMP_Voltage=0;




void Power_Measure (){

Micros_Delay= micros();
TEMP_Voltage= 0;
for (int j=0; j < 200; j ++){
  while (Micros_Delay > micros()){
    //important();
  }

  Micros_Delay = Micros_Delay +100;
  float RealTime_Voltage = (ADC_Measure(Voltage_Pin, 5))/4095*3.3;
  RealTime_Voltage = (RealTime_Voltage/10000)-((3.3-RealTime_Voltage)/10000)*(-2000000);
  TEMP_Voltage =TEMP_Voltage + RealTime_Voltage;
}

WEB_AC_Voltage = TEMP_Voltage/200;
}