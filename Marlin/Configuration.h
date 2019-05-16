#define MachineCR10SPro
#define TM3DTouchscreenUpdates // Enables TM3D Error screens and eeprom screen not found in Creality screen firmware
#define HotendStock
#define BedDC
#define MeshStd

/**
   Marlin 3D Printer Firmware
   Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]

   Based on Sprinter and grbl.
   Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

/**
   Configuration.h

   Basic settings such as:

   - Type of electronics
   - Type of temperature sensor
   - Printer geometry
   - Endstop configuration
   - LCD controller
   - Extra features

   Advanced settings can be found in Configuration_adv.h

*/


#if(ENABLED(MachineCR10SPro))
  #if DISABLED(GraphicLCD)
    #define CREALITY_DWIN
     #define FIL_RUNOUT_PIN 2
     #define FIL_RUNOUT_INVERTING false
  #endif
  #define MachineCR10Std
  #if DISABLED(ABL_BLTOUCH)
    #define ABL_NCSW
  #endif
  #if DISABLED(ABL_UBL)
    #define ABL_BI
  #endif
  #define MeshStd
  #define BoardRev2
  #define SD_DETECT_PIN 49
#endif

#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#define CONFIGURATION_H_VERSION 010109

// @section info

// User-specified version info of this build to display in [Pronterface, etc] terminal window during
// startup. Implementation of an idea by Prof Braino to inform user that any changes made to this
// build by the user have been successfully uploaded into firmware.

#define STRING_CONFIG_H_AUTHOR "SiHyoen" // Who made the changes.
#define SHOW_BOOTSCREEN
#define STRING_SPLASH_LINE1 SHORT_BUILD_VERSION // will be shown during bootup in line 1
#define STRING_SPLASH_LINE2 WEBSITE_URL         // will be shown during bootup in line 2

#define CUSTOM_MACHINE_NAME "CR-10S Pro"

#define DETAILED_BUILD_VERSION SHORT_BUILD_VERSION " TM3D SSSDNU"

/**
   Select the serial port on the board to use for communication with the host.
   This allows the connection of wireless adapters (for instance) to non-default port pins.
   Serial port 0 is always used by the Arduino bootloader regardless of this setting.

   :[0, 1, 2, 3, 4, 5, 6, 7]
*/
#define SERIAL_PORT 0

/**
   This setting determines the communication speed of the printer.

   250000 works in most cases, but you might try a lower speed if
   you commonly experience drop-outs during host printing.
   You may try up to 1000000 to speed up SD file transfer.

   :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
*/

#define BAUDRATE 115200

// The following define selects which electronics board you have.
// Please choose the name from boards.h that matches your setup
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_RAMPS_13_EEB
#endif

#define CUSTOM_MACHINE_NAME "CR-10S Pro"

// @section extruder

// This defines the number of extruders
// :[1, 2, 3, 4, 5]

#define EXTRUDERS 1

// Generally expected filament diameter (1.75, 2.85, 3.0, ...). Used for Volumetric, Filament Width Sensor, etc.
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

/**
   Select your power supply here. Use 0 if you haven't connected the PS_ON_PIN

   0 = No Power Switch
   1 = ATX
   2 = X-Box 360 203Watts (the blue wire connected to PS_ON and the red wire to VCC)

   :{ 0:'No power switch', 1:'ATX', 2:'X-Box 360' }
*/
#define POWER_SUPPLY 0

// @section temperature

//===========================================================================
//============================= Thermal Settings ============================
//===========================================================================

/**
   --NORMAL IS 4.7kohm PULLUP!-- 1kohm pullup can be used on hotend sensor, using correct resistor and table

   Temperature sensors available:

      -3 : thermocouple with MAX31855 (only for sensor 0)
      -2 : thermocouple with MAX6675 (only for sensor 0)
      -1 : thermocouple with AD595
       0 : not used
       1 : 100k thermistor - best choice for EPCOS 100k (4.7k pullup)
       2 : 200k thermistor - ATC Semitec 204GT-2 (4.7k pullup)
       3 : Mendel-parts thermistor (4.7k pullup)
       4 : 10k thermistor !! do not use it for a hotend. It gives bad resolution at high temp. !!
       5 : 100K thermistor - ATC Semitec 104GT-2/104NT-4-R025H42G (Used in ParCan & J-Head) (4.7k pullup)
       6 : 100k EPCOS - Not as accurate as table 1 (created using a fluke thermocouple) (4.7k pullup)
       7 : 100k Honeywell thermistor 135-104LAG-J01 (4.7k pullup)
      71 : 100k Honeywell thermistor 135-104LAF-J01 (4.7k pullup)
       8 : 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup)
       9 : 100k GE Sensing AL03006-58.2K-97-G1 (4.7k pullup)
      10 : 100k RS thermistor 198-961 (4.7k pullup)
      11 : 100k beta 3950 1% thermistor (4.7k pullup)
      12 : 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup) (calibrated for Makibox hot bed)
      13 : 100k Hisens 3950  1% up to 300°C for hotend "Simple ONE " & "Hotend "All In ONE"
      15 : 100k thermistor calibration for JGAurora A5 hotend
      20 : the PT100 circuit found in the Ultimainboard V2.x
      60 : 100k Maker's Tool Works Kapton Bed Thermistor beta=3950
      66 : 4.7M High Temperature thermistor from Dyze Design
      70 : the 100K thermistor found in the bq Hephestos 2
      75 : 100k Generic Silicon Heat Pad with NTC 100K MGB18-104F39050L32 thermistor

         1k ohm pullup tables - This is atypical, and requires changing out the 4.7k pullup for 1k.
                                (but gives greater accuracy and more stable PID)
      51 : 100k thermistor - EPCOS (1k pullup)
      52 : 200k thermistor - ATC Semitec 204GT-2 (1k pullup)
      55 : 100k thermistor - ATC Semitec 104GT-2 (Used in ParCan & J-Head) (1k pullup)

    1047 : Pt1000 with 4k7 pullup
    1010 : Pt1000 with 1k pullup (non standard)
     147 : Pt100 with 4k7 pullup
     110 : Pt100 with 1k pullup (non standard)

           Use these for Testing or Development purposes. NEVER for production machine.
     998 : Dummy Table that ALWAYS reads 25°C or the temperature defined below.
     999 : Dummy Table that ALWAYS reads 100°C or the temperature defined below.

   :{ '0': "Not used", '1':"100k / 4.7k - EPCOS", '2':"200k / 4.7k - ATC Semitec 204GT-2", '3':"Mendel-parts / 4.7k", '4':"10k !! do not use for a hotend. Bad resolution at high temp. !!", '5':"100K / 4.7k - ATC Semitec 104GT-2 (Used in ParCan & J-Head)", '6':"100k / 4.7k EPCOS - Not as accurate as Table 1", '7':"100k / 4.7k Honeywell 135-104LAG-J01", '8':"100k / 4.7k 0603 SMD Vishay NTCS0603E3104FXT", '9':"100k / 4.7k GE Sensing AL03006-58.2K-97-G1", '10':"100k / 4.7k RS 198-961", '11':"100k / 4.7k beta 3950 1%", '12':"100k / 4.7k 0603 SMD Vishay NTCS0603E3104FXT (calibrated for Makibox hot bed)", '13':"100k Hisens 3950  1% up to 300°C for hotend 'Simple ONE ' & hotend 'All In ONE'", '20':"PT100 (Ultimainboard V2.x)", '51':"100k / 1k - EPCOS", '52':"200k / 1k - ATC Semitec 204GT-2", '55':"100k / 1k - ATC Semitec 104GT-2 (Used in ParCan & J-Head)", '60':"100k Maker's Tool Works Kapton Bed Thermistor beta=3950", '66':"Dyze Design 4.7M High Temperature thermistor", '70':"the 100K thermistor found in the bq Hephestos 2", '71':"100k / 4.7k Honeywell 135-104LAF-J01", '147':"Pt100 / 4.7k", '1047':"Pt1000 / 4.7k", '110':"Pt100 / 1k (non-standard)", '1010':"Pt1000 / 1k (non standard)", '-3':"Thermocouple + MAX31855 (only for sensor 0)", '-2':"Thermocouple + MAX6675 (only for sensor 0)", '-1':"Thermocouple + AD595",'998':"Dummy 1", '999':"Dummy 2" }
*/

#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_BED 1

// Dummy thermistor constant temperature readings, for use with 998 and 999
#define DUMMY_THERMISTOR_998_VALUE 25
#define DUMMY_THERMISTOR_999_VALUE 100

// Use temp sensor 1 as a redundant sensor with sensor 0. If the readings
// from the two sensors differ too much the print will be aborted.
//#define TEMP_SENSOR_1_AS_REDUNDANT
#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

// Extruder temperature must be close to target for this long before M109 returns success
#define TEMP_RESIDENCY_TIME 3  // (seconds)
#define TEMP_HYSTERESIS 5       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_WINDOW     1       // (degC) Window around target to start the residency timer x degC early.

// Bed temperature must be close to target for this long before M190 returns success
#define TEMP_BED_RESIDENCY_TIME 3  // (seconds)
#define TEMP_BED_HYSTERESIS 5       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_BED_WINDOW     1       // (degC) Window around target to start the residency timer x degC early.

// The minimal temperature defines the temperature below which the heater will not be enabled It is used
// to check that the wiring to the thermistor is not broken.
// Otherwise this would lead to the heater being powered on all the time.
#define HEATER_0_MINTEMP 5
#define HEATER_1_MINTEMP 5
#define HEATER_2_MINTEMP 5
#define HEATER_3_MINTEMP 5
#define HEATER_4_MINTEMP 5
#define BED_MINTEMP 5

// When temperature exceeds max temp, your heater will be switched off.
// This feature exists to protect your hotend from overheating accidentally, but *NOT* from thermistor short/failure!
// You should use MINTEMP for thermistor short/failure protection.
#define HEATER_0_MAXTEMP 275
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define BED_MAXTEMP 150  // 350 //

//===========================================================================
//============================= PID Settings ================================
//===========================================================================
// PID Tuning Guide here: http://reprap.org/wiki/PID_Tuning

// Comment the following line to disable PID and enable bang-bang.
#define PIDTEMP
#define BANG_MAX 255     // Limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // Limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#define PID_K1 0.95      // Smoothing factor within any PID loop
#if ENABLED(PIDTEMP)
  #define PID_FUNCTIONAL_RANGE 10 // If the temperature difference between the target temperature and the actual temperature

  // If you are using a pre-configured hotend then you can use one of the value sets by uncommenting it
  // Stock CR-10 Hotend fan 100%
  // #define  DEFAULT_Kp 17.42
  // #define  DEFAULT_Ki 1.27
  // #define  DEFAULT_Kd 59.93

  #define  DEFAULT_Kp 20.84
  #define  DEFAULT_Ki 1.96
  #define  DEFAULT_Kd 55.47

#endif // PIDTEMP

//===========================================================================
//============================= PID > Bed Temperature Control ===============
//===========================================================================

/**
   PID Bed Heating

   If this option is enabled set PID constants below.
   If this option is disabled, bang-bang will be used and BED_LIMIT_SWITCHING will enable hysteresis.

   The PID frequency will be the same as the extruder PWM.
   If PID_dT is the default, and correct for the hardware/configuration, that means 7.689Hz,
   which is fine for driving a square wave into a resistive load and does not significantly
   impact FET heating. This also works fine on a Fotek SSR-10DA Solid State Relay into a 250W
   heater. If your configuration is significantly different than this and you don't understand
   the issues involved, don't use bed PID until someone else verifies that your hardware works.
*/
#if(DISABLED(MachineCR10Orig) && DISABLED(LowMemoryBoard))
#define PIDTEMPBED
#endif
//#define BED_LIMIT_SWITCHING

/**
   Max Bed Power
   Applies to all forms of bed control (PID, bang-bang, and bang-bang with hysteresis).
   When set to any value below 255, enables a form of PWM to the bed that acts like a divider
   so don't use it unless you are OK with PWM on your bed. (See the comment on enabling PIDTEMPBED)
*/
#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current

#if ENABLED(PIDTEMPBED)

//#define PID_BED_DEBUG // Sends debug data to the serial port.
//Stock Bed Tuned for 50C
#define  DEFAULT_bedKp 690.34
#define  DEFAULT_bedKi 111.47
#define  DEFAULT_bedKd 1068.83
//120V 250W silicone heater into 4mm borosilicate (MendelMax 1.5+)
//from FOPDT model - kp=.39 Tp=405 Tdead=66, Tc set to 79.2, aggressive factor of .15 (vs .1, 1, 10)
//#define  DEFAULT_bedKp 10.00
//#define  DEFAULT_bedKi .023
//#define  DEFAULT_bedKd 305.4

//120V 250W silicone heater into 4mm borosilicate (MendelMax 1.5+)
//from pidautotune
//#define  DEFAULT_bedKp 97.1
//#define  DEFAULT_bedKi 1.41
//#define  DEFAULT_bedKd 1675.16

// FIND YOUR OWN: "M303 E-1 C8 S90" to run autotune on the bed at 90 degreesC for 8 cycles.
#endif // PIDTEMPBED

// @section extruder

// This option prevents extrusion if the temperature is below EXTRUDE_MINTEMP.
// It also enables the M302 command to set the minimum extrusion temperature
// or to allow moving the extruder regardless of the hotend temperature.
// *** IT IS HIGHLY RECOMMENDED TO LEAVE THIS OPTION ENABLED! ***
#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 180

// This option prevents a single extrusion longer than EXTRUDE_MAXLENGTH.
// Note that for Bowden Extruders a too-small value here may prevent loading.
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 500

//===========================================================================
//======================== Thermal Runaway Protection =======================
//===========================================================================

/**
   Thermal Protection provides additional protection to your printer from damage
   and fire. Marlin always includes safe min and max temperature ranges which
   protect against a broken or disconnected thermistor wire.

   The issue: If a thermistor falls out, it will report the much lower
   temperature of the air in the room, and the the firmware will keep
   the heater on.

   If you get "Thermal Runaway" or "Heating failed" errors the
   details can be tuned in Configuration_adv.h
*/

#define THERMAL_PROTECTION_HOTENDS // Enable thermal protection for all extruders
#define THERMAL_PROTECTION_BED     // Enable thermal protection for the heated bed

// @section homing

// Specify here all the endstop connectors that are connected to any endstop or probe.
// Almost all printers will be using one per axis. Probes will use one or more of the
// extra connectors. Leave undefined any used for non-endstop and non-probe purposes.
#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG

#define ENDSTOPPULLUPS

#if DISABLED(ENDSTOPPULLUPS)
#endif


// Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).

#define X_MIN_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING false // set to true to invert the logic of the probe.

// Enable this feature if all enabled endstop pins are interrupt-capable.
// This will remove the need to poll the interrupt pins, saving many CPU cycles.
//#define ENDSTOP_INTERRUPTS_FEATURE

//=============================================================================
//============================== Movement Settings ============================
//=============================================================================
// @section motion

/**
   Default Settings

   These settings can be reset by M502

   Note that if EEPROM is enabled, saved values will override these.
*/

/**
   With this option each E stepper can have its own factors for the
   following movement settings. If fewer factors are given than the
   total number of extruders, the last value applies to the rest.
*/
//#define DISTINCT_E_FACTORS

/**
   Default Axis Steps Per Unit (steps/mm)
   Override with M92
                                        X, Y, Z, E0 [, E1[, E2[, E3[, E4]]]]
*/

#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.00, 80.00, 400.00, 140.00 }

/**
   Default Max Feed Rate (mm/s)
   Override with M203
                                        X, Y, Z, E0 [, E1[, E2[, E3[, E4]]]]
*/

#define DEFAULT_MAX_FEEDRATE          { 500, 500, 20, 60 }
#define DEFAULT_MAX_ACCELERATION      { 750, 750, 100, 25 }
#define DEFAULT_ACCELERATION          300    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   300    // X, Y, Z acceleration for travel (non printing) moves
#define DEFAULT_XJERK                 8.0
#define DEFAULT_YJERK                 8.0
#define DEFAULT_ZJERK                 0.4
#define DEFAULT_EJERK                 5.0

//===========================================================================
//============================= Z Probe Options =============================
//===========================================================================
// @section probes

//
// See http://marlinfw.org/docs/configuration/probes.html
//

/**
   Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

   Enable this option for a probe connected to the Z Min endstop pin.
*/
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

/**
   The "Manual Probe" provides a means to do "Auto" Bed Leveling without a probe.
   Use G29 repeatedly, adjusting the Z height at each point with movement commands
   or (with LCD_BED_LEVELING) the LCD controller.
*/

#if (DISABLED(ABL_EZABL) &&DISABLED(ABL_NCSW) &&  DISABLED(ABL_BLTOUCH) )
#define PROBE_MANUALLY
#define MANUAL_PROBE_START_Z 0.2
#endif

/**
   A Fix-Mounted Probe either doesn't deploy or needs manual deployment.
     (e.g., an inductive probe or a nozzle-based probe-switch.)
*/

#define FIX_MOUNTED_PROBE

/**

   Enable one or more of the following if probing seems unreliable.
   Heaters and/or fans can be disabled during probing to minimize electrical
   noise. A delay can also be added to allow noise and vibration to settle.
   These options are most useful for the BLTouch probe, but may also improve
   readings with inductive probes and piezo sensors.
*/
#if ((ENABLED(ABL_EZABL) || ENABLED(ABL_NCSW)) && ENABLED(BED_AC))
  #define PROBING_HEATERS_OFF       // Turn heaters off when probing
#endif

#if ENABLED(PROBING_HEATERS_OFF)
  #define WAIT_FOR_BED_HEATER     // Wait for bed to heat back up between probes (to improve accuracy)
#endif
//#define PROBING_FANS_OFF          // Turn fans off when probing

//#define DELAY_BEFORE_PROBING 200  // (ms) To prevent vibrations from triggering piezo sensors

// A probe that is deployed and stowed with a solenoid pin (SOL1_PIN)
#if ENABLED(ABL_BLTOUCH)
  #define PROBING_FANS_OFF          // Turn fans off when probing
#if(ENABLED(MachineCR10Orig))
  #define SOLENOID_PROBE PIN_27
  #define SERVO0_PIN 27
#elif(ENABLED(MachineEnder4))
  #define SOLENOID_PROBE PIN_15
#else
  #define SOLENOID_PROBE PIN_11
#endif
#endif
// A sled-mounted probe like those designed by Charles Bell.
//#define Z_PROBE_SLED
//#define SLED_DOCKING_OFFSET 5  // The extra distance the X axis must travel to pickup the sled. 0 should be fine but you can push it further if you'd like.

//
// For Z_PROBE_ALLEN_KEY see the Delta example configurations.
//

/**
     Z Probe to nozzle (X,Y) offset, relative to (0, 0).
     X and Y offsets must be integers.

     In the following example the X and Y offsets are both positive:
     #define X_PROBE_OFFSET_FROM_EXTRUDER 10
     #define Y_PROBE_OFFSET_FROM_EXTRUDER 10

        +-- BACK ---+
        |           |
      L |    (+) P  | R <-- probe (20,20)
      E |           | I
      F | (-) N (+) | G <-- nozzle (10,10)
      T |           | H
        |    (-)    | T
        |           |
        O-- FRONT --+
      (0,0)
*/

#define X_PROBE_OFFSET_FROM_EXTRUDER -27  // X offset: -left  +right  [of the nozzle]
#define Y_PROBE_OFFSET_FROM_EXTRUDER 0  // Y offset: -front +behind [the nozzle]
#define Z_PROBE_OFFSET_FROM_EXTRUDER 0   // Z offset: -below +above  [the nozzle]

// Certain types of probes need to stay away from edges
#define MIN_PROBE_EDGE 10

// X and Y axis travel speed (mm/m) between probes
#define XY_PROBE_SPEED (200 * 60)

// Speed for the first approach when double-probing (MULTIPLE_PROBING == 2)
#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z

// Speed for the "accurate" probe of each point
#define Z_PROBE_SPEED_SLOW Z_PROBE_SPEED_FAST

// The number of probes to perform at each point.
//   Set to 2 for a fast/slow probe, using the second probe result.
//   Set to 3 or more for slow probes, averaging the results.
//#define MULTIPLE_PROBING 2

/**
   Z probes require clearance when deploying, stowing, and moving between
   probe points to avoid hitting the bed and other hardware.
   Servo-mounted probes require extra space for the arm to rotate.
   Inductive probes need space to keep from triggering early.

   Use these settings to specify the distance (mm) to raise the probe (or
   lower the bed). The values set here apply over and above any (negative)
   probe Z Offset set with Z_PROBE_OFFSET_FROM_EXTRUDER, M851, or the LCD.
   Only integer values >= 1 are valid here.

   Example: `M851 Z-5` with a CLEARANCE of 4  =>  9mm from bed to nozzle.
       But: `M851 Z+1` with a CLEARANCE of 2  =>  2mm from bed to nozzle.
*/
#define Z_CLEARANCE_DEPLOY_PROBE   2 // Z Clearance for Deploy/Stow
#define Z_CLEARANCE_BETWEEN_PROBES  1 // Z Clearance between probe points
#define Z_AFTER_PROBING           2 // Z position after probing is done

#define Z_PROBE_LOW_POINT          -3 // Farthest distance below the trigger-point to go before stopping

// For M851 give a range for adjusting the Z probe offset
#define Z_PROBE_OFFSET_RANGE_MIN -20
#define Z_PROBE_OFFSET_RANGE_MAX 20

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
// :{ 0:'Low', 1:'High' }
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

// Disables axis stepper immediately when it's not being used.
// WARNING: When motors turn off there is a chance of losing position accuracy!
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false
// Warn on display about possibly reduced accuracy
//#define DISABLE_REDUCED_ACCURACY_WARNING

// @section extruder

#define DISABLE_E false // For all extruders
#define DISABLE_INACTIVE_EXTRUDER true // Keep only the active extruder enabled.

// @section machine

#define	CARDSTATUS	0// CR-X, 0 for TF card, 1 for SD card.
#if CARDSTATUS
#define INVERT_X_DIR true
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false
#else
#define INVERT_X_DIR false
#define INVERT_Y_DIR true
#define INVERT_Z_DIR true
#endif //CARDSTATUS

// Enable this option for Toshiba stepper drivers
//#define CONFIG_STEPPERS_TOSHIBA

// @section extruder

// For direct drive extruder v9 set to true, for geared extruder set to false.

#if CARDSTATUS
#define INVERT_E0_DIR true
#define INVERT_E1_DIR false
#else
#define INVERT_E0_DIR false
#define INVERT_E1_DIR true 
#endif //CARDSTATUS

#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false

// @section homing

//#define NO_MOTION_BEFORE_HOMING  // Inhibit movement until all axes have been homed
//#define UNKNOWN_Z_NO_RAISE // Don't raise Z (lower the bed) if Z is "unknown." For beds that fall when Z is powered off.

#define Z_HOMING_HEIGHT 2  // (in mm) Minimal z height before homing (G28) for Z clearance above the bed, clamps, ...
// Be sure you have this distance over your Z_MAX_POS in case.

// Direction of endstops when homing; 1=MAX, -1=MIN
// :[-1,1]
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

// @section machine

#define X_BED_SIZE 310
#define Y_BED_SIZE 310
#define Z_MAX_POS 400

// Travel limits (mm) after homing, corresponding to endstop positions.
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE

/**
   Software Endstops

   - Prevent moves outside the set machine bounds.
   - Individual axes can be disabled, if desired.
   - X and Y only apply to Cartesian robots.
   - Use 'M211' to set software endstops on/off or report current state
*/

// Min software endstops constrain movement within minimum coordinate bounds
#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
#endif

// Max software endstops constrain movement within maximum coordinate bounds
#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif
#if(DISABLED(MachineCR10Orig) && DISABLED(LowMemoryBoard))
#if ENABLED(MIN_SOFTWARE_ENDSTOPS) || ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define SOFT_ENDSTOPS_MENU_ITEM  // Enable/Disable software endstops from the LCD
#endif
#endif
/**
 * Filament Runout Sensors
 * Mechanical or opto endstops are used to check for the presence of filament.
 *
 * RAMPS-based boards use SERVO3_PIN for the first runout sensor.
 * For other boards you may need to define FIL_RUNOUT_PIN, FIL_RUNOUT2_PIN, etc.
 * By default the firmware assumes HIGH=FILAMENT PRESENT.
 */
#if ((DISABLED(MachineCR10Orig) && DISABLED(MachineCR20) && DISABLED(MachineEnder4) && DISABLED(MachineCRX)) || ENABLED(AddonFilSensor)) && DISABLED(CREALITY_DWIN)
  #define FILAMENT_RUNOUT_SENSOR
#endif
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
#if ENABLED(DualFilSensors)
  #define NUM_RUNOUT_SENSORS   2     // Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each.
  #define FIL_RUNOUT2_PIN 15
#else
  #define NUM_RUNOUT_SENSORS   1     // Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each.
#endif
#if ENABLED(lerdgeFilSensor)
  #define FIL_RUNOUT_INVERTING false // set to true to invert the logic of the sensor.
#else
  #define FIL_RUNOUT_INVERTING true // set to true to invert the logic of the sensor.
#endif
#define FIL_RUNOUT_PULLUP          // Use internal pullup for filament runout pins.
#if ENABLED(CREALITY_DWIN)
  #define FILAMENT_RUNOUT_SCRIPT "M300 S440 P200"
#else
  #define FILAMENT_RUNOUT_SCRIPT "M600"
#endif
  #define FIL_RUNOUT_PIN 2
#endif

//===========================================================================
//=============================== Bed Leveling ==============================
//===========================================================================
// @section calibrate

/**
   Choose one of the options below to enable G29 Bed Leveling. The parameters
   and behavior of G29 will change depending on your selection.

    If using a Probe for Z Homing, enable Z_SAFE_HOMING also!

   - AUTO_BED_LEVELING_3POINT
     Probe 3 arbitrary points on the bed (that aren't collinear)
     You specify the XY coordinates of all 3 points.
     The result is a single tilted plane. Best for a flat bed.

   - AUTO_BED_LEVELING_LINEAR
     Probe several points in a grid.
     You specify the rectangle and the density of sample points.
     The result is a single tilted plane. Best for a flat bed.

   - AUTO_BED_LEVELING_BILINEAR
     Probe several points in a grid.
     You specify the rectangle and the density of sample points.
     The result is a mesh, best for large or uneven beds.

   - AUTO_BED_LEVELING_UBL (Unified Bed Leveling)
     A comprehensive bed leveling system combining the features and benefits
     of other systems. UBL also includes integrated Mesh Generation, Mesh
     Validation and Mesh Editing systems.

   - MESH_BED_LEVELING
     Probe a grid manually
     The result is a mesh, suitable for large or uneven beds. (See BILINEAR.)
     For machines without a probe, Mesh Bed Leveling provides a method to perform
     leveling in steps so you can manually adjust the Z height at each grid-point.
     With an LCD controller the process is guided step-by-step.
*/
//#define AUTO_BED_LEVELING_3POINT
//#define AUTO_BED_LEVELING_LINEAR
#if (ENABLED(ABL_EZABL)|| ENABLED(ABL_BLTOUCH) || ENABLED(ABL_NCSW))
  #if ((ENABLED(ABL_UBL)))
    #define AUTO_BED_LEVELING_UBL
    #endif
    #if ((ENABLED(ABL_BI)))
      #define AUTO_BED_LEVELING_BILINEAR
    #endif
#elif (DISABLED(OrigLA))
  #define MESH_BED_LEVELING
#endif
/**
 * Normally G28 leaves leveling disabled on completion. Enable
 * this option to have G28 restore the prior leveling state.
 */
#define RESTORE_LEVELING_AFTER_G28

/**
   Enable detailed logging of G28, G29, M48, etc.
   Turn on with the command 'M111 S32'.
   NOTE: Requires a lot of PROGMEM!
*/
//#define DEBUG_LEVELING_FEATURE

#if ENABLED(MESH_BED_LEVELING) || ENABLED(AUTO_BED_LEVELING_BILINEAR) || ENABLED(AUTO_BED_LEVELING_UBL)
// Gradually reduce leveling correction until a set height is reached,
// at which point movement will be level to the machine's XY plane.
// The height can be set with M420 Z<height>
#define ENABLE_LEVELING_FADE_HEIGHT

// For Cartesian machines, instead of dividing moves on mesh boundaries,
// split up moves into short segments like a Delta. This follows the
// contours of the bed more closely than edge-to-edge straight moves.
#define SEGMENT_LEVELED_MOVES
#define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Length of all segments (except the last one)

  /**
   * Enable the G26 Mesh Validation Pattern tool.
   */
#if(DISABLED(MachineCR10Orig))
#define G26_MESH_VALIDATION   // Enable G26 mesh validation
#endif
#if ENABLED(G26_MESH_VALIDATION)
#define MESH_TEST_NOZZLE_SIZE    0.4  // (mm) Diameter of primary nozzle.
#define MESH_TEST_LAYER_HEIGHT   0.2  // (mm) Default layer height for the G26 Mesh Validation Tool.
#define MESH_TEST_HOTEND_TEMP  205.0  // (°C) Default nozzle temperature for the G26 Mesh Validation Tool.
#define MESH_TEST_BED_TEMP      0  // (°C) Default bed temperature for the G26 Mesh Validation Tool.
#endif

#endif
#if ENABLED(MeshFast)
#define GRID_MAX_POINTS_X 3
#elif (ENABLED(MeshStd) )
  #if ENABLED(CREALITY_DWIN)
    #define GRID_MAX_POINTS_X 5
  #else
    #define GRID_MAX_POINTS_X 5
  #endif
#elif ENABLED( MeshFine)
#define GRID_MAX_POINTS_X 8
#elif ENABLED(MeshExtreme)
#define GRID_MAX_POINTS_X 15
#else
GRID_MAX_POINTS_X 3
#endif

#if ENABLED(AUTO_BED_LEVELING_LINEAR) || ENABLED(AUTO_BED_LEVELING_BILINEAR)

// Set the number of grid points per dimension.
#define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

// The Z probe minimum outer margin (to validate G29 parameters).
#define MIN_PROBE_EDGE 10

// Set the boundaries for probing (where the probe can reach).

#if( (X_PROBE_OFFSET_FROM_EXTRUDER + 15) > 0 )
#define LEFT_PROBE_BED_POSITION (X_PROBE_OFFSET_FROM_EXTRUDER + 5)
#else
#define LEFT_PROBE_BED_POSITION 10
#endif

#if( (X_BED_SIZE + X_PROBE_OFFSET_FROM_EXTRUDER - 10) < X_BED_SIZE)
#define RIGHT_PROBE_BED_POSITION (X_BED_SIZE + X_PROBE_OFFSET_FROM_EXTRUDER - 5)
#else
#define RIGHT_PROBE_BED_POSITION (X_BED_SIZE - 10)
#endif

#if ( (Y_PROBE_OFFSET_FROM_EXTRUDER + 25) > 10 )
#define FRONT_PROBE_BED_POSITION (Y_PROBE_OFFSET_FROM_EXTRUDER + 25)
#else
#define FRONT_PROBE_BED_POSITION 25
#endif

#if( (Y_BED_SIZE + Y_PROBE_OFFSET_FROM_EXTRUDER - 25) < Y_BED_SIZE)
#define BACK_PROBE_BED_POSITION (Y_BED_SIZE + Y_PROBE_OFFSET_FROM_EXTRUDER - 25)
#else
#define BACK_PROBE_BED_POSITION (Y_BED_SIZE - 25)
#endif



// Probe along the Y axis, advancing X after each column
//#define PROBE_Y_FIRST

#if ENABLED(AUTO_BED_LEVELING_BILINEAR)

// Beyond the probed grid, continue the implied tilt?
// Default is to maintain the height of the nearest edge.
//#define EXTRAPOLATE_BEYOND_GRID

//
// Experimental Subdivision of the grid by Catmull-Rom method.
// Synthesizes intermediate points to produce a more detailed mesh.
//
//#define ABL_BILINEAR_SUBDIVISION
#if ENABLED(ABL_BILINEAR_SUBDIVISION)
// Number of subdivisions between probe points
#define BILINEAR_SUBDIVISIONS 3
#endif

#endif

#elif ENABLED(AUTO_BED_LEVELING_3POINT)

// 3 arbitrary points to probe.
// A simple cross-product is used to estimate the plane of the bed.
#define ABL_PROBE_PT_1_X 15
#define ABL_PROBE_PT_1_Y 180
#define ABL_PROBE_PT_2_X 15
#define ABL_PROBE_PT_2_Y 20
#define ABL_PROBE_PT_3_X 170
#define ABL_PROBE_PT_3_Y 20

#elif ENABLED(AUTO_BED_LEVELING_UBL)

//===========================================================================
//========================= Unified Bed Leveling ============================
//===========================================================================

#if(DISABLED(MachineCR10Orig) && DISABLED(MachineEnder4) && DISABLED(CREALITY_DWIN))
#define MESH_EDIT_GFX_OVERLAY   // Display a graphics overlay while editing the mesh
#endif
#if ENABLED(MachineMini)
#define PROBE_PT_1_X 50       // Probing points for 3-Point leveling of the mesh
#define PROBE_PT_1_Y 180
#define PROBE_PT_2_X 180
#define PROBE_PT_2_Y 180
#define PROBE_PT_3_X 180
#define PROBE_PT_3_Y 50
#define MESH_INSET 15
#endif
#if ENABLED(MachineEnder2)
#define PROBE_PT_1_X 50       // Probing points for 3-Point leveling of the mesh
#define PROBE_PT_1_Y 130
#define PROBE_PT_2_X 100
#define PROBE_PT_2_Y 130
#define PROBE_PT_3_X 100
#define PROBE_PT_3_Y 50
#define MESH_INSET 15
#endif
#if ENABLED(MachineEnder3)
#define PROBE_PT_1_X 50       // Probing points for 3-Point leveling of the mesh
#define PROBE_PT_1_Y 180
#define PROBE_PT_2_X 180
#define PROBE_PT_2_Y 180
#define PROBE_PT_3_X 180
#define PROBE_PT_3_Y 50
#define MESH_INSET 15
#endif
#if ENABLED(MachineEnder4)
#define PROBE_PT_1_X 50       // Probing points for 3-Point leveling of the mesh
#define PROBE_PT_1_Y 180
#define PROBE_PT_2_X 150
#define PROBE_PT_2_Y 180
#define PROBE_PT_3_X 150
#define PROBE_PT_3_Y 50
#define MESH_INSET 15
#endif

#if ENABLED(MachineCR20)
#define PROBE_PT_1_X 50       // Probing points for 3-Point leveling of the mesh
#define PROBE_PT_1_Y 180
#define PROBE_PT_2_X 150
#define PROBE_PT_2_Y 180
#define PROBE_PT_3_X 150
#define PROBE_PT_3_Y 50
#define MESH_INSET 15
#endif

#if (ENABLED(MachineCR10Std) )
#define PROBE_PT_1_X 50       // Probing points for 3-Point leveling of the mesh
#define PROBE_PT_1_Y 270
#define PROBE_PT_2_X 250
#define PROBE_PT_2_Y 270
#define PROBE_PT_3_X 250
#define PROBE_PT_3_Y 50
#define MESH_INSET 25
#endif

#if ENABLED( MachineS4)
#define PROBE_PT_1_X 60       // Probing points for 3-Point leveling of the mesh
#define PROBE_PT_1_Y 340
#define PROBE_PT_2_X 340
#define PROBE_PT_2_Y 340
#define PROBE_PT_3_X 340
#define PROBE_PT_3_Y 60
#define MESH_INSET 20
#endif
#if ENABLED(MachineS5)
#define PROBE_PT_1_X 80       // Probing points for 3-Point leveling of the mesh
#define PROBE_PT_1_Y 420
#define PROBE_PT_2_X 420
#define PROBE_PT_2_Y 420
#define PROBE_PT_3_X 420
#define PROBE_PT_3_Y 80
#define MESH_INSET 25
#endif
// Mesh inset margin on print area
#define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

#define UBL_MESH_EDIT_MOVES_Z     // Sophisticated users prefer no movement of nozzle
#define UBL_SAVE_ACTIVE_ON_M500   // Save the currently active mesh in the current slot on M500

#define RESTORE_LEVELING_AFTER_G28
#define UBL_Z_RAISE_WHEN_OFF_MESH 0.0 // When the nozzle is off the mesh, this value is used
// as the Z-Height correction value.

#elif ENABLED(MESH_BED_LEVELING)

//===========================================================================
//=================================== Mesh ==================================
//===========================================================================

#define MESH_INSET 20          // Mesh inset margin on print area
#define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

//#define MESH_G28_REST_ORIGIN // After homing all axes ('G28' or 'G28 XYZ') rest Z at Z_MIN_POS

#endif // BED_LEVELING

/**
   Use the LCD controller for bed leveling
   Requires MESH_BED_LEVELING or PROBE_MANUALLY
*/
#if (!ENABLED(ABL_EZABL)&& !ENABLED(ABL_BLTOUCH) &&!ENABLED(OrigLA) && DISABLED(ABL_NCSW) && DISABLED(CREALITY_DWIN))
#define LCD_BED_LEVELING
#endif

#if ENABLED(LCD_BED_LEVELING)
#define MBL_Z_STEP 0.025    // Step size while manually probing Z axis.
#define LCD_PROBE_Z_RANGE 8 // Z Range centered on Z_MIN_POS for LCD Z adjustment
#endif

// Add a menu item to move between bed corners for manual bed adjustment
#define LEVEL_BED_CORNERS

#if ENABLED(LEVEL_BED_CORNERS)
#define LEVEL_CORNERS_INSET 40    // (mm) An inset for corner leveling
//#define LEVEL_CENTER_TOO        // Move to the center after the last corner
#endif

/**
   Commands to execute at the end of G29 probing.
   Useful to retract or move the Z probe out of the way.
*/
#define Z_PROBE_END_SCRIPT "M280 P0 S90"


// @section homing

// The center of the bed is at (X=0, Y=0)
//#define BED_CENTER_AT_0_0

// Manually set the home position. Leave these undefined for automatic settings.
// For DELTA this is the top-center of the Cartesian print volume.
//#define MANUAL_X_HOME_POS 0
//#define MANUAL_Y_HOME_POS 0
//#define MANUAL_Z_HOME_POS 0

// Use "Z Safe Homing" to avoid homing with a Z probe outside the bed area.
//
// With this feature enabled:
//
// - Allow Z homing only after X and Y homing AND stepper drivers still enabled.
// - If stepper drivers time out, it will need X and Y homing again before Z homing.
// - Move the Z probe (or nozzle) to a defined XY point before Z Homing when homing all axes (G28).
// - Prevent Z homing when the Z probe is outside bed area.
//
#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT 130    // X point for Z homing when homing all axis (G28).
  #define Z_SAFE_HOMING_Y_POINT 150    // Y point for Z homing when homing all axis (G28).
#endif

// Homing speeds (mm/m)
#define HOMING_FEEDRATE_XY (120*60)
#define HOMING_FEEDRATE_Z  (100*60)

//=============================================================================
//============================= Additional Features ===========================
//=============================================================================

// @section extras

//
// EEPROM
//
// The microcontroller can store settings in the EEPROM, e.g. max velocity...
// M500 - stores parameters in EEPROM
// M501 - reads parameters from EEPROM (if you need reset them after you changed them temporarily).
// M502 - reverts to the default "factory settings".  You still need to store them in EEPROM afterwards if you want to.
//
#define EEPROM_SETTINGS // Enable for M500 and M501 commands
//#define DISABLE_M503    // Saves ~2700 bytes of PROGMEM. Disable for release!
#if(DISABLED(MachineCR10Orig))
#define EEPROM_CHITCHAT   // Give feedback on EEPROM commands. Disable to save PROGMEM.
#endif
//
// Host Keepalive
//
// When enabled Marlin will send a busy status message to the host
// every couple of seconds when it can't accept commands.
//
#define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113.
#define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating

//
// M100 Free Memory Watcher
//
//#define M100_FREE_MEMORY_WATCHER    // Add M100 (Free Memory Watcher) to debug memory usage

//
// G20/G21 Inch mode support
//
//#define INCH_MODE_SUPPORT

//
// M149 Set temperature units support
//
//#define TEMPERATURE_UNITS_SUPPORT

// @section temperature

// Preheat Constants
#define PREHEAT_1_TEMP_HOTEND 195
#define PREHEAT_1_TEMP_BED      0
#define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255

#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255

/**
   Nozzle Park

   Park the nozzle at the given XYZ position on idle or G27.

   The "P" parameter controls the action applied to the Z axis:

      P0  (Default) If Z is below park Z raise the nozzle.
      P1  Raise the nozzle always to Z-park height.
      P2  Raise the nozzle by Z-park amount, limited to Z_MAX_POS.
*/
#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
// Specify a park position as { X, Y, Z }
#if(ENABLED(MachineEnder2))
#define NOZZLE_PARK_POINT { (0), (0), 20 }
#else
#define NOZZLE_PARK_POINT { (20), (20), 20 }
#endif
#define NOZZLE_PARK_XY_FEEDRATE 100   // X and Y axes feedrate in mm/s (also used for delta printers Z axis)
#define NOZZLE_PARK_Z_FEEDRATE 5      // Z axis feedrate in mm/s (not used for delta printers)
#endif

/**
   Print Job Timer

   Automatically start and stop the print job timer on M104/M109/M190.

     M104 (hotend, no wait) - high temp = none,        low temp = stop timer
     M109 (hotend, wait)    - high temp = start timer, low temp = stop timer
     M190 (bed, wait)       - high temp = start timer, low temp = none

   The timer can also be controlled with the following commands:

     M75 - Start the print job timer
     M76 - Pause the print job timer
     M77 - Stop the print job timer
*/
 #if DISABLED(MachineCR10Orig)
 #define PRINTJOB_TIMER_AUTOSTART
#endif

/**
   Print Counter

   Track statistical data such as:

    - Total print jobs
    - Total successful print jobs
    - Total failed print jobs
    - Total time printing

   View the current statistics with M78.
*/
 #if(DISABLED(MachineCR10Orig))
 #define PRINTCOUNTER
#endif
//=============================================================================
//============================= LCD and SD support ============================
//=============================================================================

// @section lcd

/**
   LCD LANGUAGE

   Select the language to display on the LCD. These languages are available:

      en, an, bg, ca, cn, cz, cz_utf8, de, el, el-gr, es, es_utf8, eu, fi, fr, fr_utf8,
      gl, hr, it, kana, kana_utf8, nl, pl, pt, pt_utf8, pt-br, pt-br_utf8, ru, sk_utf8,
      tr, uk, zh_CN, zh_TW, test

   :{ 'en':'English', 'an':'Aragonese', 'bg':'Bulgarian', 'ca':'Catalan', 'cn':'Chinese', 'cz':'Czech', 'cz_utf8':'Czech (UTF8)', 'de':'German', 'el':'Greek', 'el-gr':'Greek (Greece)', 'es':'Spanish', 'es_utf8':'Spanish (UTF8)', 'eu':'Basque-Euskera', 'fi':'Finnish', 'fr':'French', 'fr_utf8':'French (UTF8)', 'gl':'Galician', 'hr':'Croatian', 'it':'Italian', 'kana':'Japanese', 'kana_utf8':'Japanese (UTF8)', 'nl':'Dutch', 'pl':'Polish', 'pt':'Portuguese', 'pt-br':'Portuguese (Brazilian)', 'pt-br_utf8':'Portuguese (Brazilian UTF8)', 'pt_utf8':'Portuguese (UTF8)', 'ru':'Russian', 'sk_utf8':'Slovak (UTF8)', 'tr':'Turkish', 'uk':'Ukrainian', 'zh_CN':'Chinese (Simplified)', 'zh_TW':'Chinese (Taiwan)', test':'TEST' }
*/
#define LCD_LANGUAGE en

/**
   LCD Character Set

   Note: This option is NOT applicable to Graphical Displays.

   All character-based LCDs provide ASCII plus one of these
   language extensions:

    - JAPANESE ... the most common
    - WESTERN  ... with more accented characters
    - CYRILLIC ... for the Russian language

   To determine the language extension installed on your controller:

    - Compile and upload with LCD_LANGUAGE set to 'test'
    - Click the controller to view the LCD menu
    - The LCD will display Japanese, Western, or Cyrillic text

   See http://marlinfw.org/docs/development/lcd_language.html

   :['JAPANESE', 'WESTERN', 'CYRILLIC']
*/
#define DISPLAY_CHARSET_HD44780 JAPANESE

/**
   LCD TYPE

   Enable ULTRA_LCD for a 16x2, 16x4, 20x2, or 20x4 character-based LCD.
   Enable DOGLCD for a 128x64 (ST7565R) Full Graphical Display.
   (These options will be enabled automatically for most displays.)

   IMPORTANT: The U8glib library is required for Full Graphic Display!
              https://github.com/olikraus/U8glib_Arduino
*/
//#define ULTRA_LCD   // Character based
//#define DOGLCD      // Full graphics display

/**
   SD CARD

   SD Card support is disabled by default. If your controller has an SD slot,
   you must uncomment the following option or it won't work.

*/

#define SDSUPPORT

/**
   SD CARD: SPI SPEED

   Enable one of the following items for a slower SPI transfer speed.
   This may be required to resolve "volume init" errors.
*/
//#define SPI_SPEED SPI_HALF_SPEED
//#define SPI_SPEED SPI_QUARTER_SPEED
//#define SPI_SPEED SPI_EIGHTH_SPEED

/**
   SD CARD: ENABLE CRC

   Use CRC checks and retries on the SD communication.
*/
//#define SD_CHECK_AND_RETRY

//
// ENCODER SETTINGS
//
// This option overrides the default number of encoder pulses needed to
// produce one step. Should be increased for high-resolution encoders.
//
#define ENCODER_PULSES_PER_STEP 4

//
// Use this option to override the number of step signals required to
// move between next/prev menu items.
//
#define ENCODER_STEPS_PER_MENU_ITEM 1

/**
   Encoder Direction Options

   Test your encoder's behavior first with both options disabled.

    Reversed Value Edit and Menu Nav? Enable REVERSE_ENCODER_DIRECTION.
    Reversed Menu Navigation only?    Enable REVERSE_MENU_DIRECTION.
    Reversed Value Editing only?      Enable BOTH options.
*/

//
// This option reverses the encoder direction everywhere.
//
//  Set this option if CLOCKWISE causes values to DECREASE
//
//#define REVERSE_ENCODER_DIRECTION

//
// This option reverses the encoder direction for navigating LCD menus.
//
//  If CLOCKWISE normally moves DOWN this makes it go UP.
//  If CLOCKWISE normally moves UP this makes it go DOWN.
//
//#define REVERSE_MENU_DIRECTION

//
// Individual Axis Homing
//
// Add individual axis homing items (Home X, Home Y, and Home Z) to the LCD menu.
//
#if(DISABLED(MachineCR10Orig))
#define INDIVIDUAL_AXIS_HOMING_MENU
#endif
//
// SPEAKER/BUZZER
//
// If you have a speaker that can produce tones, enable it here.
// By default Marlin assumes you have a buzzer with a fixed frequency.
//
#if(DISABLED(MachineCR10Orig))
#define SPEAKER
#endif

//
// The duration and frequency for the UI feedback sound.
// Set these to 0 to disable audio feedback in the LCD menus.
//
// Note: Test audio output with the G-Code:
//  M300 S<frequency Hz> P<duration ms>
//
//#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2
//#define LCD_FEEDBACK_FREQUENCY_HZ 5000

//
// CONTROLLER TYPE: Standard
//
// Marlin supports a wide variety of controllers.
// Enable one of the following options to specify your controller.
//

//
// ULTIMAKER Controller.
//
//#define ULTIMAKERCONTROLLER

//
// ULTIPANEL as seen on Thingiverse.
//
//#define ULTIPANEL

//
// PanelOne from T3P3 (via RAMPS 1.4 AUX2/AUX3)
// http://reprap.org/wiki/PanelOne
//
//#define PANEL_ONE

//
// MaKr3d Makr-Panel with graphic controller and SD support.
// http://reprap.org/wiki/MaKr3d_MaKrPanel
//
//#define MAKRPANEL

//
// ReprapWorld Graphical LCD
// https://reprapworld.com/?products_details&products_id/1218
//
//#define REPRAPWORLD_GRAPHICAL_LCD

//
// Activate one of these if you have a Panucatt Devices
// Viki 2.0 or mini Viki with Graphic LCD
// http://panucatt.com
//
//#define VIKI2
//#define miniVIKI

//
// Adafruit ST7565 Full Graphic Controller.
// https://github.com/eboston/Adafruit-ST7565-Full-Graphic-Controller/
//
//#define ELB_FULL_GRAPHIC_CONTROLLER

//
// RepRapDiscount Smart Controller.
// http://reprap.org/wiki/RepRapDiscount_Smart_Controller
//
// Note: Usually sold with a white PCB.
//
//#define REPRAP_DISCOUNT_SMART_CONTROLLER

//
// GADGETS3D G3D LCD/SD Controller
// http://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
//
// Note: Usually sold with a blue PCB.
//
//#define G3D_PANEL

//
// RepRapDiscount FULL GRAPHIC Smart Controller
// http://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
//
#if(ENABLED(MachineEnder4) && DISABLED(GraphicLCD))
#define REPRAP_DISCOUNT_SMART_CONTROLLER
#elif(ENABLED(MachineEnder2) )
#define MINIPANEL
#elif ENABLED(MachineCR20)
  #define MKS_MINI_12864
#elif(DISABLED(OrigLCD) && DISABLED(CREALITY_DWIN))
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
#endif
#if(ENABLED(OrigLCD))
#define CR10_STOCKDISPLAY
#endif
//
// MakerLab Mini Panel with graphic
// controller and SD support - http://reprap.org/wiki/Mini_panel
//
//#define MINIPANEL

//
// RepRapWorld REPRAPWORLD_KEYPAD v1.1
// http://reprapworld.com/?products_details&products_id=202&cPath=1591_1626
//
// REPRAPWORLD_KEYPAD_MOVE_STEP sets how much should the robot move when a key
// is pressed, a value of 10.0 means 10mm per click.
//
//#define REPRAPWORLD_KEYPAD
//#define REPRAPWORLD_KEYPAD_MOVE_STEP 1.0

//
// RigidBot Panel V1.0
// http://www.inventapart.com/
//
//#define RIGIDBOT_PANEL

//
// BQ LCD Smart Controller shipped by
// default with the BQ Hephestos 2 and Witbox 2.
//
//#define BQ_LCD_SMART_CONTROLLER

//
// Cartesio UI
// http://mauk.cc/webshop/cartesio-shop/electronics/user-interface
//
//#define CARTESIO_UI

//
// ANET and Tronxy Controller supported displays.
//
//#define ZONESTAR_LCD            // Requires ADC_KEYPAD_PIN to be assigned to an analog pin.
// This LCD is known to be susceptible to electrical interference
// which scrambles the display.  Pressing any button clears it up.
// This is a LCD2004 display with 5 analog buttons.

//#define ANET_FULL_GRAPHICS_LCD  // Anet 128x64 full graphics lcd with rotary encoder as used on Anet A6
// A clone of the RepRapDiscount full graphics display but with
// different pins/wiring (see pins_ANET_10.h).

//
// LCD for Melzi Card with Graphical LCD
//
//#define LCD_FOR_MELZI

//
// LCD for Malyan M200 printers.
// This requires SDSUPPORT to be enabled
//
//#define MALYAN_LCD

//
// CONTROLLER TYPE: I2C
//
// Note: These controllers require the installation of Arduino's LiquidCrystal_I2C
// library. For more info: https://github.com/kiyoshigawa/LiquidCrystal_I2C
//

//
// Elefu RA Board Control Panel
// http://www.elefu.com/index.php?route=product/product&product_id=53
//
//#define RA_CONTROL_PANEL

//
// Sainsmart (YwRobot) LCD Displays
//
// These require F.Malpartida's LiquidCrystal_I2C library
// https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home
//
//#define LCD_SAINSMART_I2C_1602
//#define LCD_SAINSMART_I2C_2004

//
// Generic LCM1602 LCD adapter
//
//#define LCM1602

//
// PANELOLU2 LCD with status LEDs,
// separate encoder and click inputs.
//
// Note: This controller requires Arduino's LiquidTWI2 library v1.2.3 or later.
// For more info: https://github.com/lincomatic/LiquidTWI2
//
// Note: The PANELOLU2 encoder click input can either be directly connected to
// a pin (if BTN_ENC defined to != -1) or read through I2C (when BTN_ENC == -1).
//
//#define LCD_I2C_PANELOLU2

//
// Panucatt VIKI LCD with status LEDs,
// integrated click & L/R/U/D buttons, separate encoder inputs.
//
//#define LCD_I2C_VIKI

//
// SSD1306 OLED full graphics generic display
//
//#define U8GLIB_SSD1306

//
// SAV OLEd LCD module support using either SSD1306 or SH1106 based LCD modules
//
//#define SAV_3DGLCD
#if ENABLED(SAV_3DGLCD)
//#define U8GLIB_SSD1306
#define U8GLIB_SH1106
#endif

//
// Original Ulticontroller from Ultimaker 2 printer with SSD1309 I2C display and encoder
// https://github.com/Ultimaker/Ultimaker2/tree/master/1249_Ulticontroller_Board_(x1)
//
//#define ULTI_CONTROLLER

//
// CONTROLLER TYPE: Shift register panels
//
// 2 wire Non-latching LCD SR from https://goo.gl/aJJ4sH
// LCD configuration: http://reprap.org/wiki/SAV_3D_LCD
//
//#define SAV_3DLCD

//
// TinyBoy2 128x64 OLED / Encoder Panel
//
//#define OLED_PANEL_TINYBOY2

//
// Makeboard 3D Printer Parts 3D Printer Mini Display 1602 Mini Controller
// https://www.aliexpress.com/item/Micromake-Makeboard-3D-Printer-Parts-3D-Printer-Mini-Display-1602-Mini-Controller-Compatible-with-Ramps-1/32765887917.html
//
//#define MAKEBOARD_MINI_2_LINE_DISPLAY_1602

//
// MKS MINI12864 with graphic controller and SD support
// http://reprap.org/wiki/MKS_MINI_12864
//
//#define MKS_MINI_12864

//
// Factory display for Creality CR-10
// https://www.aliexpress.com/item/Universal-LCD-12864-3D-Printer-Display-Screen-With-Encoder-For-CR-10-CR-7-Model/32833148327.html
//

//
// MKS OLED 1.3" 128 × 64 FULL GRAPHICS CONTROLLER
// http://reprap.org/wiki/MKS_12864OLED
//
// Tiny, but very sharp OLED display
//
//#define MKS_12864OLED          // Uses the SH1106 controller (default)
//#define MKS_12864OLED_SSD1306  // Uses the SSD1306 controller

//
// Silvergate GLCD controller
// http://github.com/android444/Silvergate
//
//#define SILVER_GATE_GLCD_CONTROLLER

//=============================================================================
//=============================== Extra Features ==============================
//=============================================================================

// @section extras

// Increase the FAN PWM frequency. Removes the PWM noise but increases heating in the FET/Arduino
//#define FAST_PWM_FAN

// Use software PWM to drive the fan, as for the heaters. This uses a very low frequency
// which is not as annoying as with the hardware PWM. On the other hand, if this frequency
// is too low, you should also increment SOFT_PWM_SCALE.
//#define FAN_SOFT_PWM

// Incrementing this by 1 will double the software PWM frequency,
// affecting heaters, and the fan if FAN_SOFT_PWM is enabled.
// However, control resolution will be halved for each increment;
// at zero value, there are 128 effective control positions.
#define SOFT_PWM_SCALE 0

// If SOFT_PWM_SCALE is set to a value higher than 0, dithering can
// be used to mitigate the associated resolution loss. If enabled,
// some of the PWM cycles are stretched so on average the desired
// duty cycle is attained.
//#define SOFT_PWM_DITHER

// Temperature status LEDs that display the hotend and bed temperature.
// If all hotends, bed temperature, and target temperature are under 54C
// then the BLUE led is on. Otherwise the RED led is on. (1C hysteresis)
//#define TEMP_STAT_LEDS

// M240  Triggers a camera by emulating a Canon RC-1 Remote
// Data from: http://www.doc-diy.net/photo/rc-1_hacked/
//#define PHOTOGRAPH_PIN     23

// SkeinForge sends the wrong arc g-codes when using Arc Point as fillet procedure
//#define SF_ARC_FIX

// Support for the BariCUDA Paste Extruder
//#define BARICUDA

// Support for BlinkM/CyzRgb
//#define BLINKM

// Support for PCA9632 PWM LED driver
//#define PCA9632

/**
   RGB LED / LED Strip Control

   Enable support for an RGB LED connected to 5V digital pins, or
   an RGB Strip connected to MOSFETs controlled by digital pins.

   Adds the M150 command to set the LED (or LED strip) color.
   If pins are PWM capable (e.g., 4, 5, 6, 11) then a range of
   luminance values can be set from 0 to 255.
   For Neopixel LED an overall brightness parameter is also available.

 * *** CAUTION ***
    LED Strips require a MOFSET Chip between PWM lines and LEDs,
    as the Arduino cannot handle the current the LEDs will require.
    Failure to follow this precaution can destroy your Arduino!
    NOTE: A separate 5V power supply is required! The Neopixel LED needs
    more current than the Arduino 5V linear regulator can produce.
 * *** CAUTION ***

   LED Type. Enable only one of the following two options.

*/
//#define RGB_LED
//#define RGBW_LED

#if ENABLED(RGB_LED) || ENABLED(RGBW_LED)
#define RGB_LED_R_PIN 34
#define RGB_LED_G_PIN 43
#define RGB_LED_B_PIN 35
#define RGB_LED_W_PIN -1
#endif

// Support for Adafruit Neopixel LED driver
//#define NEOPIXEL_LED
#if ENABLED(NEOPIXEL_LED)
#define NEOPIXEL_TYPE   NEO_GRBW // NEO_GRBW / NEO_GRB - four/three channel driver type (defined in Adafruit_NeoPixel.h)
#define NEOPIXEL_PIN    4        // LED driving pin on motherboard 4 => D4 (EXP2-5 on Printrboard) / 30 => PC7 (EXP3-13 on Rumba)
#define NEOPIXEL_PIXELS 30       // Number of LEDs in the strip
#define NEOPIXEL_IS_SEQUENTIAL   // Sequential display for temperature change - LED by LED. Disable to change all LEDs at once.
#define NEOPIXEL_BRIGHTNESS 127  // Initial brightness (0-255)
//#define NEOPIXEL_STARTUP_TEST  // Cycle through colors at startup
#endif

/**
   Printer Event LEDs

   During printing, the LEDs will reflect the printer status:

    - Gradually change from blue to violet as the heated bed gets to target temp
    - Gradually change from violet to red as the hotend gets to temperature
    - Change to white to illuminate work surface
    - Change to green once print has finished
    - Turn off after the print has finished and the user has pushed a button
*/
#if ENABLED(BLINKM) || ENABLED(RGB_LED) || ENABLED(RGBW_LED) || ENABLED(PCA9632) || ENABLED(NEOPIXEL_LED)
#define PRINTER_EVENT_LEDS
#endif

/**
   R/C SERVO support
   Sponsored by TrinityLabs, Reworked by codexmas
*/

/**
   Number of servos

   For some servo-related options NUM_SERVOS will be set automatically.
   Set this manually if there are extra servos needing manual control.
   Leave undefined or set to 0 to entirely disable the servo subsystem.
*/
//#define NUM_SERVOS 3 // Servo index starts with 0 for M280 command

// Delay (in milliseconds) before the next move will start, to give the servo time to reach its target angle.
// 300ms is a good value but you can try less delay.
// If the servo can't reach the requested position, increase it.
#define SERVO_DELAY { 300 }

// Servo deactivation
//
// With this option servos are powered only during movement, then turned off to prevent jitter.
//#define DEACTIVATE_SERVOS_AFTER_MOVE

#endif // CONFIGURATION_H
