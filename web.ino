void handleRoot() {
  if (server.hasArg("color")) color = server.arg("color").substring(1);
  if (server.hasArg("delay")) delayTime = server.arg("delay").toInt();
  if (server.hasArg("effect")) effectNumber = server.arg("effect").toInt();
  if (server.hasArg("brightness")) brightness = server.arg("brightness").toInt();  // Luminozitatea
  if (server.hasArg("n")) n = server.arg("n").toInt();

  dataUpdated = true;

String html = "<!DOCTYPE html><html><head>";
    html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";

    html += "<style>";
    html += "body{margin:0;font-family:Arial,Helvetica,sans-serif;";
    html += "background:#111;color:#fff;}";
    html += ".container{max-width:480px;margin:60px auto;";
    html += "background:#1e1e1e;padding:20px;border-radius:15px;";
    html += "box-shadow:0 0 15px rgba(0,0,0,0.6);}";

    html += "h1{text-align:center;margin-bottom:20px;font-size:22px;}";
    html += "label{display:block;margin-top:12px;font-size:14px;}";
    html += "input,select,button{width:100%;margin-top:5px;";
    html += "padding:8px;font-size:14px;border-radius:6px;border:none;}";

    html += "input[type=color]{height:40px;padding:0;}";
    html += "input[type=checkbox]{width:auto;}";
    html += "button,input[type=submit]{background:#2196F3;color:white;";
    html += "cursor:pointer;margin-top:15px;}";

    html += "button.off{background:#f44336;}";
    html += ".row{display:flex;gap:10px;}";
    html += ".row > div{flex:1;}";

    html += ".small{max-width:100px;}";

    html += "</style>";

    html += "<script>";
    html += "let rainbowInterval=null;";
    html += "function updateBackgroundColor(){";
    html += "const e=document.getElementsByName('effect')[0];";
    html += "const c=document.getElementsByName('color')[0];";

    html += "if(rainbowInterval){clearInterval(rainbowInterval);rainbowInterval=null;}";

    html += "if(e.value=='10'){";
    html += "const colors=['#ff0000','#ff7f00','#ffff00','#00ff00','#0000ff','#4b0082','#9400d3'];";
    html += "let i=0;";
    html += "rainbowInterval=setInterval(()=>{";
    html += "document.body.style.background=colors[i];";
    html += "i=(i+1)%colors.length;";
    html += "},800);";
    html += "}else{document.body.style.background=c.value;}";
    html += "}";

    html += "window.onload=updateBackgroundColor;";
    html += "</script>";

    html += "</head><body>";

    html += "<div class='container'>";
    html += "<h1>WS2812B - Spider Control</h1>";

    html += "<form action='/' method='GET' oninput='updateBackgroundColor()'>";

    html += "<label>Culoare</label>";
    html += "<input type='color' name='color' value='#" + color + "'>";

    html += "<label>Delay (ms)</label>";
    html += "<input type='number' class='small' name='delay' value='" + String(delayTime) + "'>";

    html += "<label>Luminozitate</label>";
    html += "<input type='range' name='brightness' min='0' max='255' value='" + String(brightness) + "'>";

    html += "<label>Efect</label>";
    html += "<select name='effect'>";

    #define OPT(v,t) html += "<option value='" #v "'" + String(effectNumber==v?" selected":"") + ">" t "</option>"

    OPT(1,"Efect 1 - 0 -> N");
    OPT(2,"Efect 2 - N -> 0");
    OPT(3,"Efect 3 - Din 3 în 3");
    OPT(4,"Efect 4 - Invers din 3");
    OPT(5,"Efect 5 - Spre centru");
    OPT(6,"Efect 6 - Picior cu picior");
    OPT(7,"Efect 7 - Umplere picioare");
    OPT(8,"Efect 8 - Roza");
    OPT(9,"Efect 9 - Blink");
    OPT(10,"Efect 10 - Curcubeu");
    OPT(11,"Efect 11 - Disco");
    OPT(12,"Efect 12 - Bobo");
    OPT(13,"Efect 13 - Cometa 1");
    OPT(14,"Efect 14 - Cometa 2");
    OPT(15,"Efect 15 - Fulgi albi cazatotri");
    OPT(16,"Efect 16 - Fulgi colorati");
    OPT(17,"Efect 17 - Culoare schimbatoare");
    OPT(18,"Efect 18 - Picioare colorate 1");
    OPT(19,"Efect 19 - Picioare colorate 2");
    OPT(20,"Efect 20 - Test");
    OPT(99,"Efect 99 - Auto - toate efectele");

    html += "</select>";

    html += "<div class='row'>";
    html += "<div><label>Repetari ( efecte 5-19 )</label><input type='number' class='small' name='n' value='" + String(n) + "'></div>";
    html += "</div>";

    html += "<input type='submit' value='Aplica'>";
    html += "</form>";

    html += "<form action='/stingere' method='GET'>";
    html += "<button class='off'>Stingere</button>";
    html += "</form>";

    html += "</div></body></html>";

server.send(200, "text/html", html);
}

void handleStingere() {
  sting();  // Apelăm funcția de stingere
  //server.send(200, "text/plain", "LED-urile au fost stinse!");
}



/*
// varianta 2

  // Generăm pagina HTML cu opțiunile de control
  String html = "<html><head>";
    html += "<style>";
    html += "body { font-size: 18px; }";  // Mărim fontul
    html += "</style>";
    html += "<script>";
    html += "function updateBackgroundColor() {";
    html += "  var effectSelect = document.getElementsByName('effect')[0];";
    html += "  if (effectSelect.value == '10') {";  // Verifică dacă efectul selectat este 'Curcubeu'
    html += "    var colors = ['#FF0000'];";  // Culori curcubeu
    html += "    var i = 0;";
    html += "    setInterval(function() {";
    html += "      document.body.style.backgroundColor = colors[i];";
    html += "      i = (i + 1) % colors.length;";  // Trece prin culorile curcubeului
    html += "    }, 1000);";  // Schimbă culoarea la fiecare secundă
    html += "  } else {";
    html += "    var colorPicker = document.getElementsByName('color')[0];";
    html += "    document.body.style.backgroundColor = colorPicker.value;";
    html += "  }";
    html += "}";
    html += "window.onload = function() { updateBackgroundColor(); };";
    html += "</script>";
    html += "</head><body>";
    html += "<h1>Control WS2812B LED Strip</h1>";
    html += "<form action=\"/\" method=\"GET\" oninput=\"updateBackgroundColor()\">";

    // Codul existent pentru selectorul de culoare, delay, efecte, etc.

    html += "Culoare: <input type=\"color\" name=\"color\" value=\"#";
    html += color;
    html += "\" onchange=\"updateBackgroundColor()\"><br><br>";
    html += "Delay (ms): <input type=\"number\" name=\"delay\" value=\"" + String(delayTime) + "\"><br><br>";
    html += "Luminozitate: <input type=\"range\" name=\"brightness\" min=\"0\" max=\"255\" value=\"" + String(brightness) + "\"><br><br>";
    
    html += "Efect: <select name=\"effect\" onchange=\"updateBackgroundColor()\">";  // Am adăugat onchange pentru efecte
    
    html += "<option value=\"1\"";  if (effectNumber == 1) html += " selected"; html += ">Efect 1 - Aprindere de la 0 la N</option>";
    html += "<option value=\"2\"";  if (effectNumber == 2) html += " selected"; html += ">Efect 2 - Aprindere inversă</option>";
    html += "<option value=\"3\"";  if (effectNumber == 3) html += " selected"; html += ">Efect 3 - Aprindere din 3 in 3 de la 0 la N</option>";
    html += "<option value=\"4\"";  if (effectNumber == 4) html += " selected"; html += ">Efect 4 - Aprindere din 3 in 3 de la N la 0</option>";
    html += "<option value=\"5\"";  if (effectNumber == 5) html += " selected"; html += ">Efect 5 - Aprindere catre jumate de la 0 si N</option>";
    html += "<option value=\"6\"";  if (effectNumber == 6) html += " selected"; html += ">Efect 6 - Picior cu Picior</option>";
    html += "<option value=\"7\"";  if (effectNumber == 7) html += " selected"; html += ">Efect 7 - Aprindere cu umplere picioare</option>";
    html += "<option value=\"8\"";  if (effectNumber == 8) html += " selected"; html += ">Efect 8 - Roza</option>";
    html += "<option value=\"9\"";  if (effectNumber == 9) html += " selected"; html += ">Efect 9 - blink la picior</option>";
    html += "<option value=\"10\""; if (effectNumber == 10) html += " selected"; html += ">Efect 10 - Curcubeu</option>";
    html += "<option value=\"11\""; if (effectNumber == 11) html += " selected"; html += ">Efect 11 - Disco</option>";
    html += "<option value=\"12\""; if (effectNumber == 12) html += " selected"; html += ">Efect 12 - Bobo</option>";
    html += "<option value=\"13\""; if (effectNumber == 13) html += " selected"; html += ">Efect 13 - Cometa 1</option>";
    html += "<option value=\"14\""; if (effectNumber == 14) html += " selected"; html += ">Efect 14 - Cometa 2</option>";
    html += "<option value=\"15\""; if (effectNumber == 15) html += " selected"; html += ">Efect 15 - Efect 15</option>";
    html += "<option value=\"16\""; if (effectNumber == 16) html += " selected"; html += ">Efect 16 - Efect 16</option>";
    html += "<option value=\"17\""; if (effectNumber == 17) html += " selected"; html += ">Efect 17 - Efect 17</option>";
    html += "<option value=\"18\""; if (effectNumber == 18) html += " selected"; html += ">Efect 18 - Picioare colorate</option>";   
    html += "<option value=\"19\""; if (effectNumber == 19) html += " selected"; html += ">Efect 19 - Picioare colorate 2</option>";
    html += "<option value=\"20\""; if (effectNumber == 20) html += " selected"; html += ">Efect 20 - Test</option>";
    html += "<option value=\"21\""; if (effectNumber == 21) html += " selected"; html += ">Efect 21 - Test 1</option>";   
    html += "<option value=\"22\""; if (effectNumber == 22) html += " selected"; html += ">Efect 22 - Test 2</option>";

    html += "</select><br><br>";
    html += "Auto Mode: <input type=\"checkbox\" name=\"autoMode\" value=\"1\"";
      if (autoMode == 1) html += " checked";
    html += "><br><br>";

    html += "Timp aprindere (secunde): <input type=\"number\" name=\"t\" value=\"" + String(t) + "\"><br><br>";
    html += "Numar de repetari la unele efecte (Efect 8,10,11,12): <input type=\"number\" name=\"n\" value=\"" + String(n) + "\"><br><br>";

    html += "<input type=\"submit\" value=\"Trimite\">";
    html += "</form>";

    // Buton de stingere
    html += "<br><br>";
    html += "<form action=\"/stingere\" method=\"GET\">";
    html += "<input type=\"submit\" value=\"Stingere\">";
    html += "</form>";

  server.send(200, "text/html", html);
}

void handleStingere() {
  sting();  // Apelăm funcția de stingere
  server.send(200, "text/plain", "LED-urile au fost stinse!");
}



//varianta 1

String html = "<html><head>";
  html += "<script>";
  html += "function updateBackgroundColor() {";
  html += "  var colorPicker = document.getElementsByName('color')[0];";
  html += "  document.body.style.backgroundColor = colorPicker.value;";
  html += "}";
  html += "window.onload = function() { updateBackgroundColor(); };";
  html += "</script>";
  html += "</head><body>";
  html += "<h1>Control WS2812B LED Strip</h1>";
  html += "<form action=\"/\" method=\"GET\" oninput=\"updateBackgroundColor()\">";
  html += "Culoare: <input type=\"color\" name=\"color\" value=\"#";
  html += color;
  html += "\" onchange=\"updateBackgroundColor()\"><br><br>";
  html += "Delay (ms): <input type=\"number\" name=\"delay\" value=\"" + String(delayTime) + "\"><br><br>";
  html += "Luminozitate: <input type=\"range\" name=\"brightness\" min=\"0\" max=\"255\" value=\"" + String(brightness) + "\"><br><br>";  // Slider pentru luminozitate
  html += "Efect: <select name=\"effect\">";
  html += "<option value=\"0\""; if (effectNumber == 0) html += " selected"; html += ">Efect 0 - Stingere";
  html += "<option value=\"1\""; if (effectNumber == 1) html += " selected"; html += ">Efect 1 - Aprindere de la 0 la N</option>";
  html += "<option value=\"2\""; if (effectNumber == 2) html += " selected"; html += ">Efect 2 - Aprindere inversă</option>";
  html += "<option value=\"3\""; if (effectNumber == 3) html += " selected"; html += ">Efect 3 - Aprindere din 3 in 3 de la 0 la N</option>";
  html += "<option value=\"4\""; if (effectNumber == 4) html += " selected"; html += ">Efect 4 - Aprindere din 3 in 3 de la N la 0</option>";
  html += "<option value=\"5\""; if (effectNumber == 5) html += " selected"; html += ">Efect 5 - Aprindere catre jumate de la 0 si N</option>";
  html += "<option value=\"6\""; if (effectNumber == 6) html += " selected"; html += ">Efect 6 - Picior cu Picior</option>";
  html += "<option value=\"7\""; if (effectNumber == 7) html += " selected"; html += ">Efect 7 - Aprindere cu umplere picioare</option>";
  html += "<option value=\"8\""; if (effectNumber == 8) html += " selected"; html += ">Efect 8 - Roza</option>";
  html += "<option value=\"9\""; if (effectNumber == 9) html += " selected"; html += ">Efect 9 - blink la picior</option>";
  html += "<option value=\"10\""; if (effectNumber == 10) html += " selected"; html += ">Efect 10 - Curcubeu</option>";
  html += "<option value=\"11\""; if (effectNumber == 11) html += " selected"; html += ">Efect 11 - Disco</option>";
  html += "<option value=\"12\""; if (effectNumber == 12) html += " selected"; html += ">Efect 12 - Bobo</option>";


  html += "</select><br><br>";

  html += "Auto Mode: <input type=\"checkbox\" name=\"autoMode\" value=\"1\"";
  if (autoMode == 1) html += " checked";
  html += "><br><br>";

  html += "Timp aprindere (secunde): <input type=\"number\" name=\"t\" value=\"" + String(t) + "\"><br><br>";
  html += "Numar de repetari la unele efecte (Efect 8,10,11,12): <input type=\"number\" name=\"n\" value=\"" + String(n) + "\"><br><br>";

  html += "<input type=\"submit\" value=\"Trimite\">";
  html += "</form>";

  // Buton de stingere
  html += "<br><br>";
  html += "<form action=\"/stingere\" method=\"GET\">";
  html += "<input type=\"submit\" value=\"Stingere\">";
  html += "</form>";

  html += "</body></html>";
 
 */


