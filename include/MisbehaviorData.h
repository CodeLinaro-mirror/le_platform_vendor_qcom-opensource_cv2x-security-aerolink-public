/*
*  Copyright (c) 2021, The Linux Foundation. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are
*  met:
*    * Redistributions of source code must retain the above copyright
*      notice, this list of conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above
*      copyright notice, this list of conditions and the following
*      disclaimer in the documentation and/or other materials provided
*      with the distribution.
*    * Neither the name of The Linux Foundation nor the names of its
*      contributors may be used to endorse or promote products derived
*      from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
*  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
*  ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
*  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
*  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
*  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
*  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
*  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*
*  Changes from Qualcomm Innovation Center are provided under the following license:
*
*  Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted (subject to the limitations in the
*  disclaimer below) provided that the following conditions are met:
*
*      * Redistributions of source code must retain the above copyright
*        notice, this list of conditions and the following disclaimer.
*
*      * Redistributions in binary form must reproduce the above
*        copyright notice, this list of conditions and the following
*        disclaimer in the documentation and/or other materials provided
*        with the distribution.
*
*      * Neither the name of Qualcomm Innovation Center, Inc. nor the names of its
*        contributors may be used to endorse or promote products derived
*        from this software without specific prior written permission.
*
*  NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
*  GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
*  HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
*  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
*  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
*  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
*  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
*  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
*  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
*  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
*  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MISBEHAVIOR_DATA_H
#define MISBEHAVIOR_DATA_H

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Constants used as flags to show optional fields are present
 */
// Constants for SupplementalVehicleExtensions
#define SVE_ClassificationPresent           0x0001
#define SVE_ClassDetailsPresent             0x0002
#define SVE_VehicleDataPresent              0x0004
#define SVE_WeatherReportPresent            0x0008
#define SVE_WeatherProbePresent             0x0010
#define SVE_ObstaclePresent                 0x0020
#define SVE_StatusPresent                   0x0040
#define SVE_SpeedProfilePresent             0x0080

// Constants for TrailerUnitDescription
#define TUD_VehicleHeightPresent            0x0001
#define TUD_TrailerMassPresent              0x0002
#define TUD_BumperHeightsPresent            0x0004
#define TUD_CenterOfGravityPresent          0x0008
#define TUD_RearPivotPresent                0x0010
#define TUD_RearWheelOffsetPresent          0x0020
#define TUD_ElevationOffsetPresent          0x0040
#define TUD_CrumbDataOffsetPresent          0x0080

// Constants for FullPositionVector
#define FPV_UtcTimePreset                   0x0001
#define FPV_ElevationPreset                 0x0002
#define FPV_HeadingPreset                   0x0004
#define FPV_SpeedPreset                     0x0008
#define FPV_PosAccuracyPreset               0x0010
#define FPV_TimeConfidencePreset            0x0020
#define FPV_PosConfidencePreset             0x0040

// Constants for VehicleData
#define VD_HeightPresent                    0x0001
#define VD_BumpersPresent                   0x0002
#define VD_MassPresent                      0x0004
#define VD_TrailerWeightPresent             0x0008

// Constants for WeatherReport
#define WR_RainRatePreset                   0x0001
#define WR_PrecipSituationPreset            0x0002
#define WR_SolarRadiationPreset             0x0004
#define WR_FrictionPreset                   0x0008
#define WR_RoadFrictionPreset               0x0010

// Constants for DDateTime
#define DDT_YearPreset                      0x0001
#define DDT_MonthPreset                     0x0002
#define DDT_DayPreset                       0x0004
#define DDT_HourPreset                      0x0008
#define DDT_MinutePreset                    0x0010
#define DDT_SecondPreset                    0x0020
#define DDT_OffsetPreset                    0x0040

// Constants for PathHistoryPoint
#define PHP_SpeedPreset                     0x0001
#define PHP_PosAccuracyPreset               0x0002
#define PHP_HeadingPreset                   0x0004

// Constants for BsmData
#define BD_SafetyExtensionPresent           0x0001
#define BD_SpecialExtensionsPresent         0x0002
#define BD_SupplementalExtensionsPresent    0x0004

// Constants for HostInformation
#define HI_PositionPresent                  0x0001
#define HI_DimensionsPresent                0x0002
#define HI_HeadingPresent                   0x0004

/**
* @brief Structures to hold the parsed BSM data to be used for misbehavior detection
*/
typedef struct {
    int16_t pivotOffset;                       // Range -1024..1023;  Range of +- 10.23 meters
    uint16_t pivotAngle;                       // Range 0..28800 LSB of 0.0125 degrees
    uint8_t pivots;                            // Boolean, 0 = False, all others = true
} PivotPointDescription;

typedef struct {
    uint16_t optionalFieldsPresent;
    uint16_t year;                             // Optional Range 0..4095 -- Units of years
    uint8_t  month;                            // Optional Range 0..12 -- Units of months
    uint8_t  day;                              // Optional Range 0..31 -- Units of days
    uint8_t  hour;                             // Optional Range 0..31 -- Units of hours,
    uint8_t  minute;                           // Optional Range 0..60 -- Units of minutes
    uint16_t second;                           // Optional Range 0..65535 -- Units of milliseconds
    int16_t  offset;                           // Optional Range -840..840 --Units of minutes from UTC time
} DDateTime;


typedef struct {
    uint8_t transmissionState;                 // Range 0..7
    uint16_t speed;                            // Range 0..8191 -- Units of 0.02 m/s
} TransmissionAndSpeed;

typedef struct {
    uint8_t  semiMajorAxisAccuracy;            // Range 0..255  --Units of 0.05m
    uint8_t  semiMinorAxisAccuracy;            // Range 0..255  --Units of 0.05m
    uint32_t semiMajorAxisOrientation;         // Range 0..65535. -- Units of 360/65535 deg
} PositionalAccuracy;

typedef struct {
    uint8_t positionConfidence;                // Range 0..15
    uint8_t elevationConfidence;               // Range 0..15
} PositionConfidenceSet;

typedef struct {
    uint8_t headingConfidence;                 // Range 0..8
    uint8_t speedConfidence;                   // Range 0..7
    uint8_t throttleConfidence;                // Range 0..3
} SpeedandHeadingandThrottleConfidence;

typedef struct {
    uint16_t optionalFieldsPresent;
    DDateTime utcTime;                         // Optional
    int32_t longitude;                         // Range -1799999999..1800000001   -- Units 1/10th microdegree
    int32_t latitude;                          // Range -900000000..900000001   -- Units 1/10th microdegree
    int32_t elevation;                         // Optional Range -4096..61439  -- Units of 10 cm
    uint16_t heading;                          // Optional Range 0..28800 -- Units of 0.0125 degrees
    TransmissionAndSpeed  speed;               // Optional,
    PositionalAccuracy posAccuracy;            // Optional,
    uint8_t timeConfidence;                    // Optional  Range 0..39
    PositionConfidenceSet  posConfidence;      // Optional,
    SpeedandHeadingandThrottleConfidence speedConfidence;  //  Optional,
} FullPositionVector;

typedef struct {
    uint16_t optionalFieldsPresent;
    int32_t latOffset ;                        // Range  -131072..131071 -- Units of 0.1 microdegrees
    int32_t lonOffset ;                        // Range  -131072..131071 -- Units of 0.1 microdegrees
    int8_t elevationOffset;                    // Range -64..63 -- units of 10 cm
    uint32_t timeOffset;                       // Range 1..65535 -- Units of 10 mSec,

    uint16_t speed;                            // Optional Range 0..8191 --Units of 0.02 m/s
    PositionalAccuracy  posAccuracy;           // Optional
    uint8_t heading;                           // Optional  Range 0..240 --Units of 1.5 degrees
} PathHistoryPoint;


typedef struct {
    FullPositionVector initialPosition;        // Optional
    uint8_t currGNSSstatus;                    // Optional BitMap: 8
    uint8_t numberPoints;                      // Range 1..23
    PathHistoryPoint crumbData;
} Path_History;


typedef struct {
    uint16_t pivotAngle;                       // Range 0..28800 LSB of 0.0125 degrees
    uint32_t timeOffset;                       // Range 1..65535 -- Units of 10 mSec,

    int16_t positionXOffset ;                  // Range: -2048..2047  -- Units of  1 cm
    int16_t positionYOffset ;                  // Range: -2048..2047  -- Units of  1 cm

    int8_t elevationOffset;                    // Optional Range -64..63 -- units of 10 cm
    uint8_t coarseHeading;                     // Optional  Range 0..240 --Units of 1.5 degrees
} TrailerHistoryPoint;

typedef struct {
    uint16_t optionalFieldsPresent;
    uint8_t isDolly;                           // Boolean
    uint16_t vehicleWidth;                     // Range 0..1023 -- Units of 1 cm
    uint16_t vehicleLength;                    // Range 0.. 4095) -- Units of 1 cm

    uint8_t vehicleHeight;                     // Optional Range 0..127   -- Units of 5 cm
    uint8_t trailerMass;                       // Optional Range 0..255   -- Units of  500 kg
    uint8_t frontBumper;                       // Optional Range 0..127 --Units of 0.01 meters
    uint8_t rearBumper;                        // Optional Range 0..127 --Units of 0.01 meters
    uint8_t centerOfGravity;                   // Optional  Range 0..127   -- Units of 5 cm

    PivotPointDescription frontPivot;
    PivotPointDescription rearPivot;           // Optional
    int16_t rearWheelOffset ;                  // Optional Range: -2048..2047  -- Units of  1 cm

    int16_t positionXOffset ;                  // Range: -2048..2047  -- Units of  1 cm
    int16_t positionYOffset ;                  // Range: -2048..2047  -- Units of  1 cm

    int8_t elevationOffset;                    // Optional Range -64..63 -- units of 10 cm

    uint8_t numberTrailerHistroyPoints;        // Range 1..23
    TrailerHistoryPoint  crumbData;            // Optional
} TrailerUnitDescription;



typedef struct {
    uint8_t sspIndex;   // Range: 0..31
    PivotPointDescription  pivotPointDescription;

    uint8_t numberTrailerUnits;
    TrailerUnitDescription trailerUnitDescriptions[8];
} Trailer_Data;

typedef struct {
    Path_History pathHistory;
    uint16_t exteriorLights;                // Upper 7 bits unused
} VehicleSafetyExtensions;

typedef struct {
    Trailer_Data trailerData;
} SpecialVehicleExtensions;

typedef struct {
    uint8_t keyType;                        // Optional Range 0..255
    uint8_t role;                           // Optional Range 0..22
    uint8_t iso3883;                        // Optional Range 0..100
    uint8_t hpmsType;                       // Optional Range 0..15

    uint16_t vehicleType;                   // Optional
    uint16_t responseEquip;                 // Optional
    uint16_t responderType;                 // Optional

    uint8_t FuelType;                       // Optional Range 0..15
} VehicleClassification;

typedef struct {
    uint16_t optionalFieldsPresent;
    uint8_t height;                         // Optional Range 0..127 --Units of 5 cm
    uint8_t frontBumper;                    // Optional Range 0..127 --Units of 0.01 meters
    uint8_t rearBumper;                     // Optional Range 0..127 --Units of 0.01 meters
    uint8_t mass;                           // Optional  Range 0..255
    uint16_t trailerWeight;                 // Optional  Range 0..64255
} VehicleData;


typedef struct {
    uint16_t optionalFieldsPresent;
    uint8_t isRaining;                      // 1 = yes 2 = no 3 = error
    uint32_t rainRate;                      // Optional Range 0..65535
    uint8_t  precipSituation;               // Optional Range 1..15
    uint32_t solarRadiation;                // Optional Range 0..65535
    uint8_t  friction;                      // Optional Range 0..101
    uint8_t  roadFriction;                  // Optional range 0..50
} WeatherReport;

typedef struct {
    uint8_t airTemp;                        // Optional Range 0..191  -- Units deg C
    uint8_t airPressure;                    // Optional Range 0..255
    // rainRates WiperSet OPTIONAL,
} WeatherProbe;

typedef struct {
    uint16_t obDist;                        // Range 0..32767 -- Units of meters
    uint32_t obDirect;                      // Range 0..32767 -- Units of meters
    uint16_t description;                   // Optional
    uint16_t locationDetails;               // Optional
    DDateTime  dateTime;
    uint8_t vertEvent;                      // Optional BitMap 5
} ObstacleDetection;

typedef struct {
    uint16_t statusDetails;
    uint32_t locationDetails;
} DisabledVehicle;

typedef struct {
    uint8_t grossSpeed;                     // Range 0..31 -- Units of 1.00 m/s
                                            // 31 indicate unavailable
} SpeedProfileMeasurement;

typedef struct {
    uint8_t numberProfiles;                 // Range 1..20
    SpeedProfileMeasurement speedReports[20];
} SpeedProfile;

typedef struct {
    uint16_t optionalFieldsPresent;
    uint8_t classification;                 // Optional Range 0..255
    VehicleClassification  classDetails;    // Optional
    VehicleData  vehicleData;               // Optional

    WeatherReport weatherReport ;           // Optional
    WeatherProbe  weatherProbe;             // Optional
    ObstacleDetection   obstacle;           // Optional
    DisabledVehicle    status ;             // Optional
    SpeedProfile speedProfile ;             // Optional
} SupplementalVehicleExtensions;

typedef struct {
    uint16_t optionalFieldsPresent;

    // Position
    int32_t  latitude;
    int32_t  longitude;
    int32_t  elevation;

    // Dimensions
    uint16_t vehicleWidth;              // Range 0..1023 -- Units of 1 cm
    uint16_t vehicleLength;             // Range 0..4095 -- Units of 1 cm

    // Heading
    uint16_t heading;
} HostInformation;


typedef struct {
    uint8_t version;
    uint32_t dataType;

    uint8_t  msgCount;
    uint32_t id;
    int32_t  latitude;
    int32_t  longitude;
    int32_t  elevation;
    PositionalAccuracy  posAccuracy;
    int16_t  speed;
    uint16_t heading;
    int8_t   steeringWheelAngle;         // Range -126..127  --Units of 1.5 degrees,
    uint8_t  verticalAcceleration;       // Range -127..127  --Units of 0.02G
    int16_t  longitudeAcceleration;
    int16_t  latitudeAcceleration;
    int32_t  yawAcceleration;
    uint16_t brakes;                    // BitMap: WWWWWTTAASSBBXXZ
    uint16_t vehicleWidth;              // Range 0..1023 -- Units of 1 cm
    uint16_t vehicleLength;             // Range 0..4095 -- Units of 1 cm

    uint16_t optionalFieldsPresent;
    VehicleSafetyExtensions  safetyExtension;
    SpecialVehicleExtensions specialExtensions;
    SupplementalVehicleExtensions supplementalExtensions;

    HostInformation hostInformation;
} BsmData;



/**
* @brief Structure specifying the detected misbehavior classes.
*/
typedef struct {
    uint8_t version;
    uint32_t dataType;

    uint64_t detectedMisbehavior;
} MisbehaviorDetectedType;

// Detectors Flags
#define MD_BrakeAcceleration                     0x0000000000000001
#define MD_ConstantPositionSpeedAcceleration     0x0000000000000002
#define MD_RandomPositionSpeedAcceleration       0x0000000000000004
#define MD_MaxSpeed                              0x0000000000000008
#define MD_MaxLongitudinalAcceleration           0x0000000000000010
#define MD_MaxLongitudinalDeceleration           0x0000000000000020
#define MD_MaxLateralAcceleration                0x0000000000000040
#define MD_MaxYawRate                            0x0000000000000080
#define MD_PositionOverlap                       0x0000000000000100
#define MD_MaxBeaconFrequency                    0x0000000000000200
#define MD_MaxLength                             0x0000000000000400
#define MD_MaxWidth                              0x0000000000000800
#define MD_SpeedAcceleration                     0x0000000000001000
#define MD_SuddenAppearanceWarning               0x0000000000002000
#define MD_KalmanBasedVerification               0x0000000000004000
#define MD_LocationPlausibility                  0x0000000000008000
#define MD_MaxDensityThreshold                   0x0000000000010000
#define MD_PlausibleSpeed                        0x0000000000020000
#define MD_PlausibleAcceleration                 0x0000000000040000
#define MD_OutlierDetection                      0x0000000000080000
#define MD_RareDistributionDetection             0x0000000000100000
#define MD_ChangeNormalDistribution              0x0000000000200000
#define MD_MovementPlausibility                  0x0000000000400000
#define MD_PositionDifference                    0x0000000000800000
#define MD_SpeedDifference                       0x0000000001000000
#define MD_AccelerationDifference                0x0000000002000000
#define MD_HeadingDifference                     0x0000000004000000
#define MD_InvalidNeighborCount                  0x0000000008000000
#define MD_EnergyDetectDecode                    0x0000000010000000


#ifdef __cplusplus
}
#endif

#endif //MISBEHAVIOR_DATA_H
