
void Application_Loop (){
  if (millis_Wait < millis()){
  Power_Measure ();
  millis_Wait = millis ()+500;
  }

  }
