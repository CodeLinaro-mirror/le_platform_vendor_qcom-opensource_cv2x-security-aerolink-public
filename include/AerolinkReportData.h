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
*  Copyright (c) 2021, 2023-2024 Qualcomm Innovation Center, Inc. All rights reserved.
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
    ARIB_SYSTEM_FILE_STATUS             = 0x00000002,
    ARIB_SIGNING_CERTIFICATE_STATUS     = 0x00000004,
    ARIB_MISBEHAVIOR_PROTECTION_STATUS  = 0x00000008,
    ARIB_SCMS_NETWORK_STATUS            = 0x00000010,
    ARIB_SCMS_ENROLLMENT_STATUS         = 0x00000020,
    ARIB_SCMS_SERVICE_STATUS            = 0x00000040,
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
 * @brief Enumeration type of detail certificate status
 */
typedef enum
{
    SCSB_VALID_CURRENT_CERTS            = 0x00000001,
    SCSB_CERTS_AVAILABLE                = 0x00000002,
    SCSB_HSM_ERROR                      = 0x00000004,
    SCSB_PRIVATE_PUBLIC_KEY_MISMATCH    = 0x00000008,
    SCSB_CERT_IN_CHAIN_MISSING          = 0x00000010,
    SCSB_CERTS_IN_CHAIN_INCONSISTENT    = 0x00000020,
    SCSB_CERT_IN_CHAIN_REVOKED          = 0x00000040,
} SigningCertificateStatusBitmap;


/**
 * @brief Data structure for detail certificate status
 * @param version  of data structure
 * @param status contains one or more values of type SigningCertificateStatusBitmap. //CertificateStatusBitmap.
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
} SigningCertificateStatusReport;


/**
 * @brief Enumeration type of system file status
 */
typedef enum
{
    SFSB_MISSING_SCMS_CERT_STORE    = 0x00000001,
    SFSB_CORRUPT_SCMS_CERT_STORE    = 0x00000002,
    SFSB_MISSING_CRL_INDEX          = 0x00000004,
    SFSB_MISSING_CTL_STATE          = 0x00000008,
    SFSB_CORRUPT_CTL_STATE          = 0x00000010,
} SystemFileStatusBitmap;

/**
 * @brief Data structure for system file status reports
 * @param status contains one or more values of type SystemFileStatusBitmap.
 */
typedef struct
{
    uint8_t   version;
    uint32_t status;
    uint32_t numberOfMissingCrls;
    uint32_t numberOfCorruptCrls;
    uint32_t numberOfOverdueCrls;
    uint32_t numberOfOverdueCrlsForSigning;
    uint32_t numberOfValidRctls;
    uint32_t numberOfUnserviceableRctls;
} SystemFileStatusReport;


/**
 * @brief Data structure for misbehavior status reports
 * @param version contains an integer specificity the version of the report data.
 * @param status contains one or more values of type MisbehaviorStatusBitmap.
 */
typedef struct
{
    uint8_t          version;
    AEROLINK_RESULT  mbpStatus;
} MisbehaviorProtectionStatusReport;


/**
 * @brief Enumeration type of SCMS network status
 */
typedef enum
{
    SCMS_NETWORK_NOT_NEEDED       = 0x00000000,
    SCMS_NETWORK_NEEDED           = 0x00000001,
} ScmsNetworkStatusBitmap;

/**
 * @brief Data structure for SCMS network status reports
 * @param version contains an integer specificity the version of the report data.
 * @param status contains one or more values of type ScmsNetworkStatusBitmap.
 */
typedef struct
{
    uint8_t        version;
    uint32_t       status;
} ScmsNetworkStatusReport;

/**
 * @brief Enumeration type of SCMS ernrollment status
 */
typedef enum
{
    SCMS_ENROLLMENT_ABSENT        = 0x00000000,
    SCMS_ENROLLMENT_PRESENT       = 0x00000001,   /// Setting this bit indicates the EC is valid.
    SCMS_ENROLLMENT_BLOCKED       = 0x00000002,
} ScmsEnrollmentStatusBitmap;

/**
 * @brief Data structure for SCMS enrollment status reports
 * @param version contains an integer specificity the version of the report data.
 * @param status contains one or more values of type ScmsEnrollmentStatusBitmap.
 * @param enrollmentNameLength contains the number of characters including a null terminator in the enrollmentName field.
 * @param enrollmentName contains the ascii character array of the enrollment name in EC config, including the null terminator.
 */
typedef struct
{
    uint8_t        version;
    uint32_t       status;
    uint32_t       enrollmentNameLength;
    uint8_t const *enrollmentName;
} ScmsEnrollmentStatusReport;

/**
 * @brief Enumeration type of SCMS service status
 */
typedef enum
{
    SCMS_SERVICE_SUCCESS     = 0,
    /// Following errors are detected when the SCMS processes service requests.
    SCMS_SERVICE_ERR_SERVER_UNAUTHORIZED_REQUEST,
    SCMS_SERVICE_ERR_SERVER_NO_REQUESTED_RESOURCE,
    SCMS_SERVICE_ERR_SERVER_INTERNAL_ERROR,
    SCMS_SERVICE_ERR_SERVER_SERVICE_UNAVAILABLE,
    SCMS_SERVICE_ERR_SERVER_SERVICE_FAILURE,
    SCMS_SERVICE_ERR_SERVER_EC_BLOCKED,
    SCMS_SERVICE_ERR_SERVER_DISALLOWED_REQ_PERMISSION,
    SCMS_SERVICE_ERR_SERVER_DISALLOWED_APP_PERMISSION,
    SCMS_SERVICE_ERR_SERVER_DISALLOWED_REGION,
    SCMS_SERVICE_ERR_SERVER_DISALLOWED_OTHER_FIELDS,
    SCMS_SERVICE_ERR_SERVER_INVALID_REQ_PERMISSION,
    SCMS_SERVICE_ERR_SERVER_INVALID_APP_PERMISSION,
    SCMS_SERVICE_ERR_SERVER_INVALID_AUTHORIZED_REGION,
    SCMS_SERVICE_ERR_SERVER_INACCURATE_SYSTEM_TIME,
    SCMS_SERVICE_ERR_SERVER_INVALID_REQUEST_HASH,
    SCMS_SERVICE_ERR_SERVER_INVALID_EC_CERT_ID,
    SCMS_SERVICE_ERR_SERVER_INVALID_OTHER_FIELDS,
    SCMS_SERVICE_ERR_SERVER_UNKNOWN_EC,
    SCMS_SERVICE_ERR_SERVER_UNKNOWN_ITSID,
    SCMS_SERVICE_ERR_SERVER_INVALID_ITS_STATE,
    /// Following errors are detected when Aerolink processes SCMS files/responses.
    SCMS_SERVICE_ERR_FILE_PROC_PARSE_FAIL = 255,
    SCMS_SERVICE_ERR_FILE_PROC_CERT_CHAIN_CONSISTENCY_CHECK_FAIL,
    SCMS_SERVICE_ERR_FILE_PROC_CERT_CHAIN_SIGNATURE_VERIFICATION_FAIL,
    SCMS_SERVICE_ERR_FILE_PROC_MESSAGE_SIGNATURE_VERIFICATION_FAIL,
    SCMS_SERVICE_ERR_FILE_PROC_DECRYPTION_FAIL,
    SCMS_SERVICE_ERR_FILE_PROC_CTL_CONSISTENCY_CHECK_FAIL,
    SCMS_SERVICE_ERR_FILE_PROC_CRL_CONSISTENCY_CHECK_FAIL,
    SCMS_SERVICE_ERR_FILE_PROC_REQUEST_HASH_MISMATCH,
    SCMS_SERVICE_ERR_FILE_PROC_PUBLIC_PRIVATE_KEY_MISMATCH,
    SCMS_SERVICE_ERR_FILE_PROC_HSM,
    SCMS_SERVICE_ERR_FILE_PROC_OVERDUE,
} ScmsServiceStatus;

/**
 * @brief Enumeration type of SCMS service identifier
 */
typedef enum
{
    SCMS_SERVICE_DOWNLOAD_TRCLA_CERT = 0,
    SCMS_SERVICE_DOWNLOAD_TRCLA_LINK_CERT,
    SCMS_SERVICE_DOWNLOAD_ROOT_CTL,
    SCMS_SERVICE_DOWNLOAD_PKI_CTL,
    SCMS_SERVICE_DOWNLOAD_TDCL,
    SCMS_SERVICE_DOWNLOAD_CRL,
    SCMS_SERVICE_DOWNLOAD_ARA_CERT,
    SCMS_SERVICE_DOWNLOAD_PRA_CERT,
    SCMS_SERVICE_REQUEST_AC,
    SCMS_SERVICE_DOWNLOAD_AC,
    SCMS_SERVICE_REQUEST_EC,
    SCMS_SERVICE_REQUEST_SUCCESSOR_EC,
    SCMS_SERVICE_DOWNLOAD_SUCCESSOR_EC,
    SCMS_SERVICE_SUBMIT_MBR,
    SCMS_SERVICE_DOWNLOAD_LPF,
    SCMS_SERVICE_SUBMIT_ER,
    SCMS_SERVICE_DOWNLOAD_CCRL_CTL,
    SCMS_SERVICE_DOWNLOAD_CTL,
    SCMS_SERVICE_DOWNLOAD_CCF,
    SCMS_SERVICE_DOWNLOAD_CA_CERT,
    SCMS_SERVICE_DOWNLOAD_RA_CERT,
    SCMS_SERVICE_DOWNLOAD_MA_CERT,
    SCMS_SERVICE_DOWNLOAD_CERT_MGRT_INFO,
} ScmsServiceIdType;

/**
 * @brief Data structure for SCMS service status reports
 * @param version contains an integer specificity the version of the report data.
 * @param serviceId contains an SCMS service identifier value of type ScmsServiceIdType.
 * @param status contains a value of type ScmsServiceStatus.
 * @param descLength contains the number of characters including a null terminator in the desc field. It shall be non-zero
 * only when the service is for requesting/downloading authorization certificates, or for requesting EC/EC successor.
 * @param desc contains the ascii character array (including the null terminator) of the LCM name in the security context
 * when the service is for requesting/downloading authorization certificates, or the enrollment name in EC config when
 * the service is for requesting EC/EC successor. It shall be a null pointer when descLength is 0.
 */
typedef struct
{
    uint8_t        version;
    uint16_t       serviceId;
    uint32_t       status;
    uint32_t       descLength;
    uint8_t const *desc;
} ScmsServiceStatusReport;

#ifdef __cplusplus
}
#endif

#endif //AEROLINK_REPORT_DATA_H
