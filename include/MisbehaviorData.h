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
*/

#ifndef MISBEHAVIOR_DATA_H
#define MISBEHAVIOR_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Structure to hold the parsed BSM data to be used for misbehavior detection
*/
typedef struct {
    uint8_t version;
    uint32_t dataType;

    uint8_t  msgCount;
    uint32_t id;
    int32_t  latitude;
    int32_t  longitude;
    int32_t  elevation;
    int16_t  speed;
    uint16_t heading;
    int16_t  longitudeAcceleration;
    int16_t  latitudeAcceleration;
    int32_t  yawAcceleration;
    uint16_t brakes;
}BsmData_t;

/**
* @brief Structure specifying the detected misbehavior classes.
*/
typedef struct {
    uint8_t version;
    uint32_t dataType;

    uint64_t detectedMisbehaviorClass;
} MisbehaviorDetectedType_t;

// BSM Misbehavior Report Classes
#define MT_InconsistentBSM      0x0000000000000001
#define MT_SuspiciousBSM        0x0000000000000002
#define MT_SuspiciousBSMPlus    0x0000000000000004

#ifdef __cplusplus
}
#endif

#endif //MISBEHAVIOR_DATA_H
