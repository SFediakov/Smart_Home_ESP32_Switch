
void begin_WiFi (){
    
  Serial.println("Began");
  Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}


void WiFi_Loop () {
   //Application_Loop ();
   WiFiClient client = server.available();   

  if (client) {                            


    //ADC_Measure(Voltage_Pin, 5)/4095*3.3;
    Application_Loop ();
    Serial.println("New Client.");           
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            
      //loop when client just updated page
      
      
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte
        //Serial.write(c);                    
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            
            client.println("HTTP/1.1 200 OK");
          
            client.println();

            //transmitting to the client dedicated page
            if (current_WEB_Page==WEB_Main_panel){
              client.print(WEB_Scene_Main_Pannel);
//channel1 panel
client.print("<div style='display: flex; justify-content: space-between; font-size: 20px;'>");
client.print("<span>Relay1 ");
if (relay1_EN == 0){
  client.print("<input type='checkbox' id='checkbox_Relay1_EN'>");
}
else {
  client.print("<input type='checkbox' id='checkbox_Relay1_EN' checked>");
}
client.print("</span>");
client.print("<span>Power &nbsp;");
client.print(power_CH1, 3);
client.print("&nbsp;kW</span>");
client.print("</div>"); 
client.print("<p style='text-align: right; font-size: 20px;'>used ");
client.print(kWh_CH1);
client.print(" kWh during that week</p>");

//channel2 panel
client.print("<div style='display: flex; justify-content: space-between; font-size: 20px;'>");
client.print("<span>Relay2 ");
if (relay2_EN == 0){
  client.print("<input type='checkbox' id='checkbox_Relay2_EN'>");
}
else {
  client.print("<input type='checkbox' id='checkbox_Relay2_EN' checked>");
}
client.print("</span>");
client.print("<span>Power &nbsp;");
client.print(power_CH2, 3);
client.print("&nbsp;kW</span>");
client.print("</div>"); 
client.print("<p style='text-align: right; font-size: 20px;'>used ");
client.print(kWh_CH2);
client.print(" kWh during that week</p>");

//channel3 panel
client.print("<div style='display: flex; justify-content: space-between; font-size: 20px;'>");
client.print("<span>Relay3 ");
if (relay3_EN == 0){
  client.print("<input type='checkbox' id='checkbox_Relay3_EN'>");
}
else {
  client.print("<input type='checkbox' id='checkbox_Relay3_EN' checked>");
}
client.print("</span>");
client.print("<span>Power &nbsp;");
client.print(power_CH3, 3);
client.print("&nbsp;kW</span>");
client.print("</div>"); 
client.print("<p style='text-align: right; font-size: 20px;'>used ");
client.print(kWh_CH3);
client.print(" kWh during that week</p>");
client.print("<p>&nbsp;</p>");

//Time & Voltage
client.print("<p style='text-align: center; font-size: 20px;'>Time&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Voltage</p>");
client.print("<p style='text-align: center; font-size: 20px;'>");
if (hour <10) {
  client.print("0");
  }
  client.print(hour);
  client.print(":");
if (minute <10) {
  client.print("0");
  }
  client.print(minute);
  client.print("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
  client.print(WEB_AC_Voltage);
  client.print("V&nbsp;&nbsp;&nbsp;</p>");
  client.print("<p>&nbsp;</p>");

  //go to another Web page
  client.print("<p style='text-align: center; font-size: 22px;'><a href=\"/WEB_SETTINGS\">SETTINGS</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=\"/WEB_SCENES\">SCENES</a></p>");
 
              
            }

                        if (current_WEB_Page==WEB_Scenes){
              client.println(WEB_Scene_Scenes);
              
            }

                        if (current_WEB_Page==WEB_Settings){
              client.println(WEB_Scene_Settings);
            }
            client.print("</html>");

            // The HTTP response ends with another blank line:
            client.println();
            
            break;
          } else {    
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }

if (currentLine.startsWith("GET") && currentLine.endsWith("HTTP/1.1") && currentLine.indexOf("favicon.ico") == -1 && WEB_Current_Line_Old != currentLine){
  WEB_Current_Line_Old = currentLine;
  Serial.println (currentLine);

        // Check  the client reques depending from currently opened page
                    if (current_WEB_Page==WEB_Main_panel){
              WEB_Client_Request_Main_Panel (currentLine);

            }

                        if (current_WEB_Page==WEB_Scenes){
              WEB_Client_Request_Scenes ();
            }

                        if (current_WEB_Page==WEB_Settings){
              WEB_Client_Request_Settings ();
            }
}

        

      }
    }
   
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
