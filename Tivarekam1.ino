/*
  REKAM1 Interpreter

  This program interprets REKAM1 get and put commands and sets appropriate PWM values and retrieves relevant analog values. This version will be specific to the Tiva C Launchpad.
  Move (pin number) (microseconds) will return 1024 samples with microsecond specified as sampling period for a given pin.
  Leo Estevez 6/13/2014
  This example code will be in the public domain.

*/

int inByte = 0; // incoming serial byte
String inData;
char charBuf[20];
char pinnumber[3];
char valuenumber[5];
int command = 0;
int pin = 0;
int capture[1024];
int i;
int value;

void setup()
{
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
//  Serial.setPins(UART1_PORTB);

    pinMode(8, OUTPUT); 
    pinMode(9, OUTPUT); 
    pinMode(10, OUTPUT); 
    pinMode(11, OUTPUT); 
    pinMode(12, OUTPUT); 
    pinMode(13, OUTPUT); 
    pinMode(14, OUTPUT); 
    pinMode(15, OUTPUT); 
    pinMode(17, INPUT_PULLUP); 
    pinMode(31, INPUT_PULLUP); 
    pinMode(18, OUTPUT); 
    pinMode(19, OUTPUT);
    pinMode(30, OUTPUT); 
    pinMode(40, OUTPUT);
  establishContact(); // send a byte to establish contact until receiver responds 
}

void loop()
{

      while (Serial.available() > 0)
    {
        char received = Serial.read();
        inData += received; 
 
        // Process message when new line character is recieved
        if(received == '\n' || received == '\r'){
          inData.toCharArray(charBuf, 20);
          if(!strncmp(charBuf,"get ",4)){
            command=1;
          }else if(!strncmp(charBuf,"put ",4)){
            command=2;
          }else if(!strncmp(charBuf,"move",4)){
            command=3;
          }
          for(i=0;i<3;i++){
            pinnumber[i]=charBuf[i+4];
          }
          for(i=0;i<5;i++){
            valuenumber[i]=charBuf[i+7];
          }
          value=atoi(valuenumber);
          pin = atoi(pinnumber);
          if(command==1){
            switch(pin){
              case 6:
                Serial.print(analogRead(A8));
              break;
              case 5:
                Serial.print(analogRead(A9));
              break;
              case 7:
                Serial.print(analogRead(A10));
              break;
              case 2:
                Serial.print(analogRead(A11));
              break;
              case 17:
                Serial.print(digitalRead(PUSH2));
              break;
              case 31:
                Serial.print(digitalRead(PUSH1));
              break;
              case 18:
                Serial.print(analogRead(A3));
              break;
              case 23:
                Serial.print(analogRead(A7));
              break;
              case 24:
                Serial.print(analogRead(A6));
              break;
              case 25:
                Serial.print(analogRead(A5));
              break;
              case 26:
                Serial.print(analogRead(A4));
              break;
              case 27:
                Serial.print(analogRead(A2));
              break;
              case 28:
                Serial.print(analogRead(A1));
              break;
              case 29:
                Serial.print(analogRead(A0));
              break;
            }
            Serial.print("\n");
          }else if(command==2){
//            command=0;
            value=value*2.55;
            Serial.print("OK\n");
            switch(pin){
              case 2:
              analogWrite(PB_5,value);
              break;
              case 5:
//              analogWrite(PE_4,value);
              break;
              case 6:
//              analogWrite(PE_5,value);
              break;
              case 7:
              analogWrite(PB_4,value);
              break; 
              case 8:
//              analogWrite(PA_5,value);
              break;
              case 9:
//              analogWrite(PA_6,value);
              break; 
              case 10:
//              analogWrite(PA_7,value);
              break;
              case 11:
//              analogWrite(PA_2,value);
              break;
              case 12:
//              analogWrite(PA_3,value);
              break;
              case 13:
//              analogWrite(PA_4,value);
              break;
              case 14:
              analogWrite(PB_6,value);
              break; 
              case 15:
              analogWrite(PB_7,value);
              break;
              case 17:
              analogWrite(PF_0,value);
              break; 
              case 18:
//              analogWrite(PE_0,value);
              break;    
              case 19:
              analogWrite(PB_2,value);
              break;  
              case 30:
              analogWrite(RED_LED,value);
              break;
              case 40:
              analogWrite(BLUE_LED,value);
              break;         
            }
          }else if(command==3){
//            Serial.print("OK\n");
            switch(pin){
              case 6:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A8);
                }
              break;
              case 5:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A9);
                }
              break;
              case 7:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A10);
                }              
              break;
              case 2:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A11);
                }
              break;
              case 18:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A3);
                }
              break;
              case 23:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A7);
                }
              break;
              case 24:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A6);
                }
              break;
              case 25:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A5);
                }
              break;
              case 26:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A4);
                }
              break;
              case 27:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A2);
                }
              break;
              case 28:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A1);
                }
              break;
              case 29:
                for(i=0;i<1024;i++){
                  delayMicroseconds(value);
                  capture[i]=analogRead(A0);
                }
              break;
            } 
                 for(i=0;i<1024;i++){
                  Serial.print(capture[i]);
                  Serial.print("\n");
                }      
          }
          inData = ""; // Clear recieved buffer

        }
    }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("0,0,0"); // send an initial string
    delay(300);
  }
}
