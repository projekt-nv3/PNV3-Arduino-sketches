#include <SoftwareSerial.h>

#define esc 9  // chose where yo wire your esc
SoftwareSerial programmer (9, esc); // RX, TX

/*
   realized by Vincenzo G.
   for a lot of HK esc, check it:
   http://www.hobbyking.com/hobbyking/store/__17204__HobbyKing_ESC_Programming_Card.html
*/

// select which setting do you wish to upload
// choose only a define for every group
// default settings:


#define brake_off
//#define brake_on

#define battType_lipo
//#define battType_NiMH

#define timing_auto
//#define timing_7-22
//#define timing_22-30

#define rotation_normal
//#define rotation_reversed

#define protection_reduced
//#define protection_stop

#define battProtection_3V
//#define battProtection_2_8V
//#define battProtection_3_2V

#define start_soft
//#define start_ACC
//#define start_verySoft


void setup() {

  programmer.begin(4800);

  delay(2000);

  program();

}

void loop() {}


void program () {
  init_esc();
  set_battType();
  set_protection();
  programmer.write(248);
  set_battProtection();
  programmer.write(128);
  set_rotation();
  set_timing();
  programmer.write(248);
  set_start();
  programmer.write(120);
  set_brake();
  end_esc();
}


void init_esc() {
  programmer.write ((byte)0);
  programmer.write (248);
  programmer.write (248);
  programmer.write (120);
  programmer.write (248);
  programmer.write (120);
  programmer.write (248);
}

void set_battType() {
  int battType;
  int battType2;

#ifdef battType_lipo
  battType = 120;
  battType2 = 128;
#else battType_NiMH
  battType = 0;
  battType2 = 0;
#endif

  programmer.write(battType);
  programmer.write(128);
  if (battType2 != 0)  programmer.write(battType2);
}

void set_protection() {
  int protection;

#ifdef protection_reduced
  protection = 120;
#else protection_stop
  protection = 0;
#endif

  programmer.write(protection);
}

void set_battProtection() {
  int battProtection;
  int battProtection2;

#ifdef battProtection_3V
  battProtection = 248;
  battProtection2 = 248;
#endif

#ifdef battProtection_2_8V
  battProtection = 120;
  battProtection2 = 248;
#endif

#ifdef battProtection_3_2V
  battProtection = 120;
  battProtection2 = 0;
#endif

  programmer.write(battProtection);
  if (battProtection2 == 248) programmer.write(battProtection2);
}

void set_rotation() {
  int rotation;

#ifdef rotation_normal
  rotation = 0;
#else rotation_reversed
  rotation = 120;
#endif

  programmer.write(rotation);
}

void set_timing() {
  int timing;

#ifdef timing_auto
  timing = 128;
#endif

#ifdef timing_7-22
  timing = 0;
#endif

#ifdef timing_22-30
  timing = 120;
#endif

  programmer.write(timing);
  if (timing == 128) programmer.write((byte)0);
}

void set_start() {
  int start;
  int start2;

#ifdef start_soft
  start = 120;
  start2 = 0;
#endif

#ifdef start_ACC
  start = 128;
  start2 = 128;
#endif

#ifdef start_verySoft
  start = 0;
  start2 = 0;
#endif

  programmer.write(start);
  if (start2 != 0)  programmer.write(start2);
}

void set_brake() {
  int brake;

#ifdef brake_off
  brake = 0;
#else brake_on
  brake = 120;
#endif

  programmer.write(brake);
}

void end_esc() {
  programmer.write (248);
  programmer.write (128);
  programmer.write (248);
  programmer.write ((byte)0);
}