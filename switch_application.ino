//terminal with 192.168.4.1 as IP address and 80 as port

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

unsigned long millis_Wait =0;
unsigned long Micros_Delay=0;

// Set these to your desired credentials.
const char *ssid = "E-Ion-Switch";
const char *password = "ElectricIon";

#define WEB_Main_panel 1
#define WEB_Scenes 2
#define WEB_Settings 3 

int current_WEB_Page = WEB_Main_panel;

int relay1_EN =0;
int relay2_EN =0;
int relay3_EN =0;

float power_CH1 =0;
float power_CH2 =0;
float power_CH3 =0;

float kWh_CH1 =0;
float kWh_CH2 =0;
float kWh_CH3 =0;

float WEB_AC_Voltage =0;

int hour =0;
int minute = 0;

String WEB_Current_Line_Old ="";

WiFiServer server(80);
void setup() {
Initiation ();
begin_WiFi ();

}

void loop() {
  WiFi_Loop ();
  //Smart_Sin_On (1, 0, 1);

}
