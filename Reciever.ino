#include <VirtualWire.h>
char input;
char *data;

void setup ()
{
  pinMode (5, OUTPUT); //left motors forward
  pinMode (6, OUTPUT); //left motors reverse
  pinMode (10, OUTPUT); //right motors forward
  pinMode (11, OUTPUT); //right motors reverse

  Serial.begin(9600);

  vw_set_rx_pin(3);
  vw_setup (2000);
  pinMode(3,INPUT);
  vw_rx_start();
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen=VW_MAX_MESSAGE_LEN;
  Serial.println(buf[0]);
  if(vw_get_message(buf,&buflen)){
    if(buf[0]=='f')
    {
      forward();
    }
    else if(buf[0]=='g')
    {
      backward();
    }
    else if(buf[0]=='l')
    {
      left(); 
    }
    else if(buf[0]=='r')
    {
      right();  
    }
    else if(buf[0]=='s')
    { 
      stop(); 
    }
  }
}

void right() //right
  {
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void stop()
  {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void left() 
  {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void forward() //forward
  {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void backward() //backward
  {
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}