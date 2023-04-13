#include <IRremote.h>

IRsend irsend(10);

#define BRIGHTER 0xF700FF //1
#define DARKER 0xF7807F
#define OFF 0xF740BF
#define ON 0xF7C03F
#define RED 0xF720DF
#define REDDISH 0xF710EF
#define ORANGE 0xF730CF
#define YELLOWISH 0xF708F7
#define YELLOW 0xF728D7
#define GREEN 0xF7A05F
#define GREENISH 0xF7906F
#define TURQUOISE 0xF7B04F
#define CYAN 0xF78877
#define AQUA 0xF7A857
#define BLUE 0xF7609F
#define DEEPBLUE 0xF750AF
#define PURPLE 0xF7708F
#define MAGENTA 0xF748B7
#define PINK 0xF76897
#define WHITE 0xF7E01F
#define FLASH 0xF7D02F
#define STROBE 0xF7F00F
#define SMOOTH 0xF7E817
#define FADE 0xF7C837 //24


int input=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);//active low built in led
}

void loop() 
{
  while( Serial.available() )//while serial port is open, take input
  {
    input = Serial.read();//input
    switch (input)
    {
      case '1':
        digitalWrite(LED_BUILTIN, HIGH);
        irsend.sendNEC(ON, 32); // Send ON command
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        break;
        
      case '2':
        digitalWrite(LED_BUILTIN, HIGH);
        irsend.sendNEC(OFF, 32); // Send OFF command
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        break;
        
      case '3':
        digitalWrite(LED_BUILTIN, HIGH);
        irsend.sendNEC(RED, 32); // Send RED command
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        break;
        
      case '4':
        digitalWrite(LED_BUILTIN, HIGH);
        irsend.sendNEC(GREEN, 32); // Send GREEN command
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        break;

      case '5':
        digitalWrite(LED_BUILTIN, HIGH);
        irsend.sendNEC(BLUE, 32); // Send BLUE command
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        break;
        
      default:
        break;
    }
    // if(input == '1')//on
    // {
    //   digitalWrite(LED_BUILTIN, HIGH);
    //   irsend.sendNEC(ON, 32);
    //   delay(500);//wait
    // }
    // if(input == '2')//off
    // {
    //   digitalWrite(LED_BUILTIN, LOW);
    //   irsend.sendNEC(OFF, 32);
    //   delay(1000);//wait
    // }
  }
}
