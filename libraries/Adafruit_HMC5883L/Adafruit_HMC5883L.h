#ifndef __HMC5883L_H__
#define __HMC5883L_H__

#include <Arduino.h>
#include <Wire.h>



#define HMC5883L_ADDRESS 0x1E
#define CONFIGURATION_REGISTERA 0x00
#define CONFIGURATION_REGISTERB 0x01
#define MODE_REGISTER 0x02
#define DATA_REGISTER_BEGIN 0x03

#define MEASUREMENT_CONTINUOUS 0x00
#define MEASUREMENT_SINGLE_SHOT 0x01
#define MEASUREMENT_IDLE 0x03

#define ERRORCODE_1 "Entered scale was not valid, valid gauss values are: 0.88, 1.3, 1.9, 2.5, 4.0, 4.7, 5.6, 8.1"
#define ERRORCODE_1_NUM 1

struct MagnetometerScaled
{
	float XAxis;
	float YAxis;
	float ZAxis;
};

struct MagnetometerRaw
{
	int XAxis;
	int YAxis;
	int ZAxis;
};

class HMC5883L
{
	public:
	  HMC5883L();

	  MagnetometerRaw readRawAxis();
	  MagnetometerScaled readScaledAxis();
  
	  int setMeasurementMode(uint8_t mode);
	  int setScale(float gauss);

	  char* getErrorText(int errorCode);

	protected:
	  void write(int address, int byte);
	  uint8_t* read(int address, int length);

	private:
	  float m_Scale;
};

#endif
