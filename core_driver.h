#define DEBUG_DRIVER

#define DS 12    // serial data pin
#define OE 11    // output enable (active low)
#define ST_CP 10 // serial refresh (output latch) 
#define SH_CP 9  // serial clock
#define MR 8     // master reset (active low)

#define PULSE_LENGTH 100
#define PULSE_SPACE 100

#include <stdbool.h>
#include <Arduino.h>




void write_data_1(bool data);
void write_data_8(byte data);
void write_data_32(unsigned long int data);

void pulse();
void pulse_reset();
bool pulse_sense();
bool pulse_sense_reset();

void write_core(char x, char y, bool value);
void write_core_array(bool** values);

bool read_preserve(char x, char y);
bool read_destroy(char x, char y);

bool** read_all_preserve();
bool** read_all_destroy();





