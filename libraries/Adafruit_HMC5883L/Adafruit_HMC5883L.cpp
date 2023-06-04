#include <Arduino.h> 
#include "HMC5883L.h"

HMC5883L::HMC5883L()
{
  m_Scale = 1;
}

MagnetometerRaw HMC5883L::readRawAxis()
{
  uint8_t* buffer = read(DATA_REGISTER_BEGIN, 6);
  MagnetometerRaw raw = MagnetometerRaw();
  raw.XAxis = (buffer[0] << 8) | buffer[1];
  raw.ZAxis = (buffer[2] << 8) | buffer[3];
  raw.YAxis = (buffer[4] << 8) | buffer[5];
  return raw;
}

MagnetometerScaled HMC5883L::readScaledAxis()
{
  MagnetometerRaw raw = readRawAxis();
  MagnetometerScaled scaled = MagnetometerScaled();
  scaled.XAxis = raw.XAxis * m_Scale;
  scaled.ZAxis = raw.ZAxis * m_Scale;
  scaled.YAxis = raw.YAxis * m_Scale;
  return scaled;
}

int HMC5883L::setScale(float gauss)
{
    const float DELTA = .00001;
    
	uint8_t regValue = 0x00;
	if(fabs(gauss - 0.88) <= DELTA)
	{
		regValue = 0x00;
		m_Scale = 0.73;
	}
	else if(fabs(gauss - 1.3) <= DELTA)
	{
		regValue = 0x01;
		m_Scale = 0.92;
	}
	else if(fabs(gauss - 1.9) <= DELTA)
	{
		regValue = 0x02;
		m_Scale = 1.22;
	}
	else if(fabs(gauss - 2.5) <= DELTA)
	{
		regValue = 0x03;
		m_Scale = 1.52;
	}
	else if(fabs(gauss - 4.0) <= DELTA)
	{
		regValue = 0x04;
		m_Scale = 2.27;
	}
	else if(fabs(gauss - 4.7) <= DELTA)
	{
		regValue = 0x05;
		m_Scale = 2.56;
	}
	else if(fabs(gauss - 5.6) <= DELTA)
	{
		regValue = 0x06;
		m_Scale = 3.03;
	}
	else if(fabs(gauss - 8.1) <= DELTA)
	{
		regValue = 0x07;
		m_Scale = 4.35;
	}
	else
		return ERRORCODE_1_NUM;
	
	// Setting is in the top 3 bits of the register.
	regValue = regValue << 5;
	write(CONFIGURATION_REGISTERB, regValue);
    return 0;
}

int HMC5883L::setMeasurementMode(uint8_t mode)
{
	write(MODE_REGISTER, mode);
    return 0;
}

void HMC5883L::write(int address, int data)
{
  Wire.beginTransmission(HMC5883L_ADDRESS);
  Wire.write(address);
  Wire.write(data);
  Wire.endTransmission();
}

uint8_t* HMC5883L::read(int address, int length)
{
  Wire.beginTransmission(HMC5883L_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.beginTransmission(HMC5883L_ADDRESS);
  Wire.requestFrom(HMC5883L_ADDRESS, length);

  uint8_t buffer[length];
  if(Wire.available() == length)
  {
	  for(uint8_t i = 0; i < length; i++)
	  {
		  buffer[i] = Wire.read();
	  }
  }
  Wire.endTransmission();

  return buffer;
}

char* HMC5883L::getErrorText(int errorCode)
{
	if(ERRORCODE_1_NUM == 1)
		return ERRORCODE_1;
	
	return "Error not defined.";
}
