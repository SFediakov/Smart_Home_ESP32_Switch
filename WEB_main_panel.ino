const char WEB_Scene_Main_Pannel [] = R"=====(
<!DOCTYPE html>
<html lang="en" class="js-focus-visible">
<title>Main Panel</title>   
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Centered Header Text</title>
   <script>
    function reloadPage() {
      // Check the status of checkboxes
      var relay1Checkbox = document.getElementById('checkbox_Relay1_EN');
      var relay2Checkbox = document.getElementById('checkbox_Relay2_EN');
      var relay3Checkbox = document.getElementById('checkbox_Relay3_EN');

      var address = "/";

      if (relay1Checkbox && relay1Checkbox.checked) {
        address += "Relay1_ON";
      } else {
        address += "Relay1_OFF";
      }

      if (relay2Checkbox && relay2Checkbox.checked) {
        address += "/Relay2_ON";
      } else {
        address += "/Relay2_OFF";
      }

      if (relay3Checkbox && relay3Checkbox.checked) {
        address += "/Relay3_ON";
      } else {
        address += "/Relay3_OFF";
      }

      // Redirect to the constructed address
      window.location.href = address;
    }

    // Auto-reload every 3 seconds
    setInterval(reloadPage, 1500);
  </script>
  <style>
    body {
      text-align: center;
    }

    h1 {
      display: inline-block;
      font-size: 2em; /* Adjust the font size as needed */
    }
  </style>
</head>
<body>
  <h1>MAIN PANEL</h1>
  <br><br>
</body>

)=====";


  void WEB_Client_Request_Main_Panel (String WEB_Respond){
    //check relay 1 status
if (WEB_Respond.indexOf("Relay1_OFF") != -1 ) {relay1_EN =0;}
if (WEB_Respond.indexOf("Relay1_ON") != -1 ) {relay1_EN =1;}

    //check relay 2 status
if (WEB_Respond.indexOf("Relay2_OFF") != -1 ) {relay2_EN =0;}
if (WEB_Respond.indexOf("Relay2_ON") != -1 ) {relay2_EN =1;}

    //check relay 1 status
if (WEB_Respond.indexOf("Relay3_OFF") != -1 ) {relay3_EN =0;}
if (WEB_Respond.indexOf("Relay3_ON") != -1 ) {relay3_EN =1;}

//check redirections to the another page
if (WEB_Respond.indexOf("WEB_SETTINGS") != -1 ) {current_WEB_Page =WEB_Settings;}
if (WEB_Respond.indexOf("WEB_SCENES") != -1 ) {current_WEB_Page =WEB_Scenes;}
  }