/*
*  Copyright (c) 2018-2021, The Linux Foundation. All rights reserved.
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
*  Copyright (c) 2021 Qualcomm Innovation Center, Inc. All rights reserved.
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

#ifndef AEROLINK_REPORT_DATA_H
#define AEROLINK_REPORT_DATA_H

#include <stdint.h>
#include <stddef.h>

#include "ws_errno.h"

#ifdef __cplusplus
extern "C" {
#endif


// Report Data Id bitmap
typedef enum
{
    ARIB_CERTIFICATE_STATUS         = 0x00000001,
    ARIB_SYSTEM_FILE_STATUS         = 0x00000002,
    ARIB_CERTIFICATE_STATUS_DETAILS = 0x00000004,
    ARIB_MISBEHAVIOR_STATUS         = 0x00000008,
} AerolinkReportIdBitmap;

/***
 * @brief Callback function to be registered to receive error and/or status messages
 *        from the library.
 * @param id identifies, with a single bit set, the type of report being provided.
 * @param report should be cast as a pointer to the type representing the report data
 * as follows:
 * id = ARIB_CERTIFICATE_STATUS => report is a CertificateStatusReport const*.
 * id = ARIB_SYSTEM_FILE_STATUS => report is a SystemFileStatusReport const*.
 * @param userData contains the data passed in when the callback function was registered.
 */
typedef void (*AerolinkReportCallback)(
    AerolinkReportIdBitmap  id,
    void const             *report,
    void                   *userData);

/**
 * @brief Enumeration type of certificate status
 */
typedef enum
{
    CSB_VALID_CURRENT_CERTS =0x00000001,
    CSB_CERTS_AVAILABLE     =0x00000002,
    CSB_VALID_ECTL          =0x00000004,
    CSB_VALID_CRL           =0x00000008,
} CertificateStatusBitmap;

/**
 * @brief Enumeration type of detail certificate status
 */
typedef enum
{
    CSDB_VALID_CURRENT_CERTS =0x00000001,
    CSDB_CERTS_AVAILABLE     =0x00000002,
} CertificateStatusDetailsBitmap;


/**
 * @brief Data structure for certificate status
 * @param status contains one or more values of type CertificateStatusBitmap.
 * @param lcmDirLength is the number of bytes in lcmDir including the null terminator.
 * @param lcmDir contains the ascii character array of the full path of the LCM directory, including the null terminator.
 */
typedef struct
{
    uint32_t       status;
    uint32_t       lcmDirLength;
    uint8_t const *lcmDir;
} CertificateStatusReport;

/**
 * @brief Data structure for detail certificate status
 * @param version  of data structure
 * @param status contains one or more values of type CertificateStatusBitmap.
 * @param currentPeriodNumberOfCertificates the number of certificates for the current period
 * @param nextPeriodNumberOfCertificates the number of certificates for the next period (UINT32_MAX if unknown)
 * @param lcmDirLength is the number of bytes in lcmDir including the null terminator.
 * @param lcmDir contains the ascii character array of the full path of the LCM directory, including the null terminator.
 */
typedef struct
{
    uint8_t        version;

    uint32_t       status;
    uint32_t       currentPeriodNumberOfCertificates;
    uint32_t       nextPeriodNumberOfCertificates;

    uint32_t       lcmDirLength;
    uint8_t const *lcmDir;
} CertificateStatusDetailsReport;



/**
 * @brief Enumeration type of system file status
 */
typedef enum
{
    SFSB_VALID_CRL = 0x00000001,
} SystemFileStatusBitmap;

/**
 * @brief Data structure for system file status reports
 * @param status contains one or more values of type SystemFileStatusBitmap.
 */
typedef struct
{
    uint32_t       status;
} SystemFileStatusReport;


/**
 * @brief Data structure for misbehavior status reports
 * @param version contains an integer specificity the version of the report data.
 * @param status contains one or more values of type MisbehaviorStatusBitmap.
 */
typedef struct
{
    uint8_t           version;
    AEROLINK_RESULT   maCertificateStatus;
} MisbehaviorStatusReport;


#ifdef __cplusplus
}
#endif

#endif //AEROLINK_REPORT_DATA_H
