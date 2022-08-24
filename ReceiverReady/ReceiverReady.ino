
#include <IRremote.h>



const int RECV_PIN = 2;
byte mode=1;



IRrecv irrecv(RECV_PIN);
decode_results results;





 
 
void setup(){
  irrecv.enableIRIn();
  Serial.begin(9600);  
}

void loop(){                //switch которые проверяет нажатые кнопки
  if (irrecv.decode(&results)){
    switch (results.value){
      case 16187647://код кнопки
      {
        mode=1;
        
        break;
      }
      case 16220287:
      {
        mode=2;
        
        break;
      }
      case 16203967:
      {
        mode = 3;
        
        break;
      }
      case 16236607:
      {
        mode=4;
        
        break;
      }
      case 16195807:
      {
        mode=5;
        
        break;
      }
      case 16228447:
      {
        mode = 6;
        
        break;
      }
      case 16212127:
      {
        mode=7;
        
        break;
      }
      case 16244767:
      {
        mode=8;
        
        break;
      }
      case 16191727:
      {
        mode = 9;
        
        break;
      }
      case 16224367:
      {
        mode=10;
        
        break;
      }
      case 16208047:
      {
        mode=11;
        
        break;
      }
      case 16240687:
      {
        mode = 12;
        
        break;
      }
	  case 16199887:
      {
        mode=13;
        
        break;
      }
      case 16232527:
      {
        mode=14;
        
        break;
      }
      case 16216207:
      {
        mode = 15;
        
        break;
      }
      case 16248847:
      {
        mode=16;
        
        break;
      }
      case 16189687:
      {
        mode=17;
        
        break;
      }
      case 16222327:
      {
        mode = 18;
        
        break;
      }
      case 16206007:
      {
        mode=19;
        
        break;
      }
      case 16238647:
      {
        mode=20;
        
        break;
      }
      case 16197847:
      {
        mode = 21;
        
        break;
      }
      case 16230487:
      {
        mode=22;
        
        break;
      }
      case 16214167:
      {
        mode=23;
        
        break;
      }
      case 16246807:
      {
        mode = 24;
        
        break;
      }
    }
    //Serial.println(results.value);
        Serial.println(mode);// печатает пременную mode и отправляет её на второй МК
        irrecv.resume();// разрешает прием данных
        
  }

 }
 
