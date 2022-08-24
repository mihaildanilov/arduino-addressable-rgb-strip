#include <C:\Users\Mihail Danilov\Desktop\Gatavs Projekts\COM\CCOM.h>



void setup() {
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(10);
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );//инициализирует ленту
  FastLED.setBrightness( brightness );// устанавливает яркость 
}

void loop() {
switch (mode)//switch проверяет номер режима и идеи по режимам переключая их 
{
  case 0:
  {
 
    off();
    FastLED.show();
    FastLED.delay(1000 / FRAMES_PER_SECOND);
    break;
  }
  case 1:
  {
  
    Fire2012();
    FastLED.show();
    FastLED.delay(1000 / FRAMES_PER_SECOND);
    break;
  }
  case 2:
  {
    CylonBounce(red, green, blue, 10, 20, 50);
    break;
  }
   case 3:
  {
 
    RunningLights(red,green,blue, 50);
    break;
  }
   case 15:
  {
  
    white();
    break;
  }
  case 16:{
    
    EVERY_N_MILLISECONDS( 20) {
    pacifica_loop();
    FastLED.show();
   
  }
    break;}
    case 24:{
    rainbowCycle(20);
   
    break;}
  case 20:
  {
    
    meteorRain(0xff,0xff,0xff,10, 64, true, 30);
    break;
  }
}
}

void serialEvent() { //принимает режимы от второго МК и прерывает цикл переключения режимов
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    
    if (inChar == '\n') {
      
        //if (inputString.toInt() !=24){Running = false;}
      switch (inputString.toInt())
      {
        case 1:{
        if( (brightness + 25 )>= 250){
          brightness = 250;
          }
         
        
        Serial.println(brightness);
        break;}
        case 2:{
          if( (brightness - 25 )<= 25){
          brightness = 25;
          }else{
            brightness = brightness - 25;
          }
        
        brightness = brightness - 25;
        Serial.println(brightness);
        break;}
        case 3:{
        eepromMode = mode;
        mode = 0;

        break;}
        case 4:{
        mode =eepromMode;
 
        break;}
        case 5:{
            red = 255;
            green = 0;
            blue =0;
        break;}
        case 6:{
          
        red = 0;
        green = 255;
        blue =0;
        
        break;}
        case 7:{
          
        red = 0;
        green = 0;
        blue =255;

        break;}
        case 8:{
          
        red = 255;
        green = 255;
        blue =255;
        
        break;}
        case 9:{
        
        red = 255;
        green = 67;
        blue =20;
        
        break;}
        case 10:{
        red = 171;
        green = 255;
        blue =185;
        
        break;}
        case 11:{
        mode = 1;
        break;}
        case 12:{
        mode=2;
        break;}
        case 13:{
        red = 255;
        green = 149;
        blue =0;
        
        break;}
        case 14:{
        red = 0;
        green = 251;
        blue =255;
        
        break;}
        case 15:{
       //static 
        mode=15;
        break;}
        case 16:{
        //pacifica
        mode = 16;
        break;}
        case 17:{
        red = 255;
        green = 187;
        blue =0;
        
        break;}
        case 18:{
        red = 0;
        green = 153;
        blue =225;
       // darkCyan
        
        break;}
        case 19:{
        red = 0;
        green = 251;
        blue =255;
        //purple
        break;}
        case 20:{
       
        mode=20;
        break;}
        case 21:{
        red = 255;
        green = 255;
        blue =0;  
        
        //yellow
        break;}
        case 22:{
        red = 0;
        green = 251;
        blue =255;
        //cyan
        break;}
        case 23:{
        red = 255;
        green = 8;
        blue =247;
        //pink 
        break;}
        case 24:{
        Running = true;
        mode=24;
        // rainbow Mode
        break;}
        
      }
      
      inputString = "";
    }
  }
}
