#include "core_driver.h"

inline void write_data_1(bool data)
{
  if(data)
    {
      #ifdef DEBUG_DRIVER 
      Serial.print(1); 
      #endif
      digitalWrite(DS, HIGH);
      delayMicroseconds(1);
    }
    #ifdef DEBUG_DRIVER 
    else Serial.print(0); 
    #endif
 
    digitalWrite(SH_CP, HIGH);
    delayMicroseconds(1);
    digitalWrite(SH_CP, LOW);
    delayMicroseconds(1);

    if(data & 1)
    {
      digitalWrite(DS, LOW);
      delayMicroseconds(1);
    }
}
inline void write_data_8(byte data)
{
  for(int i = 0; i < sizeof(unsigned char)*8; i++)
  {
    // write first bit and shift right
    write_data_1(data & 1);
    data >>= 1;
  }
  #ifdef DEBUG_DRIVER
  Serial.println(); 
  #endif
}


inline void write_data_32(unsigned long int data)
{
  for(int i = 0; i < sizeof(unsigned long int)*8; i++)
  {
    // write first bit and shift right
    write_data_1(data & 1);
    data >>= 1;
  }
  #ifdef DEBUG_DRIVER
  Serial.println(); 
  #endif
}

inline void pulse_out()
{
  digitalWrite(ST_CP, LOW);
  digitalWrite(ST_CP, HIGH);
  delay(PULSE_LENGTH);
  digitalWrite(MR, LOW);
  digitalWrite(MR, HIGH);
}

