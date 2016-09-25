#include "core_driver.cpp"

// control pin config
int serial_data = 11;
int output_enable = 10; //active low
int serial_refresh = 9;
int serial_clock = 8;
int master_reset = 7; //active low



void write_data(unsigned char data)
{
  write_data_8(data);
}


void setup()
{
  // setup serial connection
  Serial.begin(9600);
  
  // config pins
  pinMode(DS, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  pinMode(MR, OUTPUT);
  
  // set default pin states
  digitalWrite(DS, LOW);
  digitalWrite(OE, LOW);
  digitalWrite(ST_CP, LOW);
  digitalWrite(SH_CP, LOW);
  digitalWrite(MR, HIGH);
}


unsigned long int a = 1;
void loop()
{ 
  write_data((char) (a));
  write_data((char) (a >> 8));
  write_data((char) (a >> 16));
  write_data((char) (a >> 24));
  pulse_out();
//  digitalWrite(ST_CP, HIGH);
//  delay(250);
//  digitalWrite(ST_CP, LOW);
//  delay(250);
  a = a == 0 ? 1 : a << 1;
}

