
#include <VirtualWire.h>

char *data;

char input;     // to store input character received via BT.

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);  
  vw_set_tx_pin (3);
  vw_setup (2000);

  pinMode(5, LOW);
  pinMode(6, LOW);
  pinMode(10, LOW);
  pinMode(11, LOW);

  // pinMode(2,INPUT);
  // pinMode(3,INPUT);
  // pinMode(A0,INPUT);
  // pinMode(10, OUTPUT); // dark green 3rd and 4th motor
  // pinMode(5,OUTPUT); // red 1 and 2nd motor
}

void loop()
{
  // speed = analogRead(A0);
  // speed = speed * 0.249;
  // analogWrite(A,speed);
  // analogWrite(B,speed);

  while(Serial.available())
  {
    input =Serial.read();
    Serial.println(input);
    
    if(input == 'F')
    {
      data="f";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      left();
    }

    else if (input == 'R')
    {
      data="r";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();//turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    
      forward();
    }

    else if (input== 'L')
    {
      data="l";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      backward();
    }  

    else if (input== 'G')
    {
      data="g";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();

      right();
    }  
    else if (input== 'S')
    {
      data="s";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();//STOP (all motors stop)
      stop();
    
    }  
  }
}  


void backward()
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

void forward()
  {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void right()
  {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void left()
  {
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}