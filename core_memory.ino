#include "core_driver.cpp"


bool values[8][8] = 
  {
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1}
  };

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
  digitalWrite(OE, HIGH);
  digitalWrite(ST_CP, LOW);
  digitalWrite(SH_CP, LOW);
  digitalWrite(MR, HIGH);
}



//unsigned long int a = 1;
bool a = 1;
void loop()
{ 
    write_core_array(values);
    for(int i = 0; i < 8; i++)
    {
      for(int j = 0; j < 8; j++)
      {
        values[i][j] = !values[i][j];
      }
    }
    write_core_array(values);
    for(int i = 0; i < 8; i++)
    {
      for(int j = 0; j < 8; j++)
      {
        values[i][j] = !values[i][j];
      }
    }
}

