/*
*  Copyright (c) 2012-2021, The Linux Foundation. All rights reserved.
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
*  Copyright (c) 2021-2024 Qualcomm Innovation Center, Inc. All rights reserved.
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

/* 'ws_errno.h'
 *
 * AUTOMATICALLY GENERATED -- DO NOT EDIT
 *
 * Defines error codes for the Aerolink project.
 *
 */

#ifndef WS_ERRNO_H
#define WS_ERRNO_H

#include <aerolink_api.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Get ID string (e.g. "WS_SUCCESS") corresponding to error number. */
AEROLINK_EXPORT const char *
ws_errid(int err);

/* Get description string corresponding to error number. */
AEROLINK_EXPORT const char *
ws_strerror(int err);

typedef enum {
     WS_SUCCESS                                          = (  0), /* No error */
     WS_ERR_BAD_ARGS                                     = (  1), /* Bad arguments to method. */
     WS_ERR_UNABLE_TO_DECRYPT_MESSAGE                    = (  2), /* Error decrypting message. */
     WS_ERR_MESSAGE_REPLAY                               = (  3), /* Duplicate message -- possible replay attack. */
     WS_ERR_CERTIFICATE_EXPIRED                          = (  4), /* Expired certificate. */
     WS_ERR_NO_CERTIFICATE                               = (  5), /* Missing end-entity certificate or no valid signing certificate. */
     WS_ERR_NO_CA_CERTIFICATE                            = (  6), /* Missing CA certificate in chain. */
     WS_ERR_INVALID_CERTIFICATE                          = (  7), /* Certificate contains a disallowed set of field values. */
     WS_ERR_MESSAGE_GEN_BEFORE_CERT_VALIDITY_PERIOD      = (  8), /* Message generated before certificate is valid. */
     WS_ERR_MESSAGE_GEN_AFTER_CERT_VALIDITY_PERIOD       = (  9), /* Message generated after certificate expiration. */
     WS_ERR_MESSAGE_EXP_BEFORE_CERT_VALIDITY_PERIOD      = ( 10), /* Message expiration is before certificate is valid. */
     WS_ERR_MESSAGE_EXP_AFTER_CERT_VALIDITY_PERIOD       = ( 11), /* Message expiration is after certificate expiration. */
     WS_ERR_NO_KEY_AVAILABLE                             = ( 12), /* Could not find a key to perform the requested operation. */
     WS_ERR_NO_MATCHING_KEY                              = ( 13), /* No private key to match key in imported cert. */
     WS_ERR_CERTIFICATE_REVOKED                          = ( 14), /* Certificate is revoked. */
     WS_ERR_UNKNOWN_CA_CERTIFICATE                       = ( 15), /* Unknown certificate authority certificate. */
     WS_ERR_PARSE_FAIL                                   = ( 16), /* Parsing error. */
     WS_ERR_UNSUPPORTED_CRYPTO_OPERATION                 = ( 17), /* The operation is not supported by the crypto libraries. */
     WS_ERR_WRONG_KEY_TYPE                               = ( 18), /* Key does not support an operation of the specified type. */
     WS_ERR_CRYPTO_INTERNAL                              = ( 19), /* Undocumented internal error in crypto libraries. */
     WS_ERR_INCOMPLETE_STATE                             = ( 20), /* Object has not been given all the information needed to carry out this action. */
     WS_ERR_CONFIG_VAL                                   = ( 21), /* Unexpected value in configuration file. */
     WS_ERR_ENCODE                                       = ( 22), /* Encoding error. */
     WS_ERR_SYMMETRIC_AUTHENTICATION_CHECK_FAILED        = ( 23), /* Symmetric authentication check failed. */
     WS_ERR_NO_GENERATION_TIME                           = ( 24), /* Generation time required, but not available. */
     WS_ERR_NO_GENERATION_LOCATION                       = ( 25), /* Generation location required, but not available. */
     WS_ERR_NO_EXPIRY_TIME                               = ( 26), /* Expiry time required, but not available. */
     WS_ERR_LCM_FEATURE_UNSUPPORTED                      = ( 27), /* The Local Certificate Manager does not support this feature. */
     WS_ERR_INTERNAL                                     = ( 28), /* Internal error. */
     WS_ERR_ALREADY_OPEN                                 = ( 29), /* The specified Security Context is already open. */
     WS_ERR_INVALID_PSID                                 = ( 30), /* The PSID in the message does not match the PSID in the context. */
     WS_ERR_INVALID_PERMISSIONS                          = ( 31), /* The provided permissions are not a valid format. */
     WS_ERR_NOT_INITIALIZED                              = ( 32), /* The security services has not been initialized. */
     WS_ERR_CONTEXT_NOT_INITIALIZED                      = ( 33), /* The security context has not been initialized. */
     WS_ERR_BUFFER_TOO_SMALL                             = ( 34), /* The supplied buffer is too small. */
     WS_ERR_INVALID_CONTEXT                              = ( 35), /* The object is not associated with a valid Security Context. */
     WS_ERR_INVALID_HANDLE                               = ( 36), /* The provided handle is not valid. */
     WS_ERR_PSID_NOT_IN_CONTEXT                          = ( 37), /* The provided Security Context does not contain the specified PSID. */
     WS_ERR_NOT_IMPLEMENTED                              = ( 38), /* Feature is currently unsupported. */
     WS_ERR_INVALID_GLOBAL_CONFIG                        = ( 39), /* An error with the global configuration file occurred. */
     WS_ERR_INVALID_PROFILE_CONFIG                       = ( 40), /* An error with a profile configuration file occurred. */
     WS_ERR_INVALID_CONTEXT_CONFIG                       = ( 41), /* An error with a context configuration file occurred. */
     WS_ERR_MESSAGE_EXPIRED                              = ( 42), /* Message has expired. */
     WS_ERR_MESSAGE_IN_FUTURE                            = ( 43), /* Message is in the future. */
     WS_ERR_DATA_NOT_EXTRACTED                           = ( 44), /* Parser has not been given all the information needed to carry out this action. */
     WS_ERR_EXTERNAL_DATA_MISSING                        = ( 45), /* Message requires external data be provided for this operation. */
     WS_ERR_MESSAGE_SIGNED_OUTSIDE_REGION                = ( 46), /* Cert not authorized to sign where it did. */
     WS_ERR_UNAUTHORIZED_PERMISSIONS                     = ( 47), /* Psid/ITS-AID not found in signing certificate. */
     WS_ERR_VALUE_ALREADY_SET                            = ( 48), /* Value cannot be overwritten. */
     WS_ERR_PSID_NOT_IN_CERTIFICATE                      = ( 49), /* Specified psid is not in the certificate permissions list. */
     WS_ERR_NOT_SUPPORTED_FOR_THIS_MESSAGE_SECURITY_TYPE = ( 50), /* Function does not support this message's security type. */
     WS_ERR_DUPLICATE_ENCRYPTION_ID                      = ( 51), /* The encryption id is already used. */
     WS_ERR_INVALID_SIGNER_ID_TYPE                       = ( 52), /* The SignerIdentifier is not valid. */
     WS_ERR_INVALID_PRIVATE_KEY_ENCODING                 = ( 53), /* The private key encoding is not supported. */
     WS_ERR_CRYPTO_QUEUE_FULL                            = ( 54), /* All threads in the pool are in use. */
     WS_ERR_CERTIFICATES_INCONSISTENT                    = ( 55), /* Data in the certificate chain is inconsistent. */
     WS_ERR_MEMORY_FAILURE                               = ( 56), /* Memory cannot be allocated. */
     WS_ERR_MESSAGE_EXPIRY_BEFORE_GENERATION             = ( 57), /* Message expiry time is before the message generation time. */
     WS_ERR_MESSAGE_FROM_TOO_FAR_AWAY                    = ( 58), /* Message was generated too far from the current location. */
     WS_ERR_MESSAGE_TOO_OLD                              = ( 59), /* Message was signed too far in the past. */
     WS_ERR_MESSAGE_SIGNATURE_VERIFICATION_FAILED        = ( 60), /* Message signature fails to verify. */
     WS_ERR_CERTIFICATE_SIGNATURE_VERIFICATION_FAILED    = ( 61), /* Certificate signature fails to verify. */
     WS_ERR_INVALID_FIELD                                = ( 62), /* Field has an invalid value. */
     WS_ERR_UNABLE_TO_DECRYPT_DATA                       = ( 63), /* Failed to decrypt the data with the symmetric key. */
     WS_ERR_UNABLE_TO_DECRYPT_SYMMETRIC_KEY              = ( 64), /* Failed to decrypt symmetric key. */
     WS_ERR_UNAUTHORIZED_REGION                          = ( 65), /* Certificate is not allowed to sign a message at the current location. */
     WS_ERR_ALREADY_REGISTERED                           = ( 66), /* The context/lcm combination is already registered. */
     WS_ERR_ID_CHANGE_ABORT                              = ( 67), /* Id change aborted. */
     WS_ERR_ID_CHANGE_BLOCKED                            = ( 68), /* Id changes have been blocked. */
     WS_ERR_ID_CHANGE_NOT_LOCKED                         = ( 69), /* No locks to release. */
     WS_ERR_NOT_REGISTERED                               = ( 70), /* The context/lcm combination is not registered. */
     WS_ERR_UNKNOWN_LCM                                  = ( 71), /* The specified LCM name is not known. */
     WS_ERR_INCONSISTENT_SIGNING_KEY_TYPE                = ( 72), /* The ACF's signing key type is not valid. */
     WS_ERR_PARSE_FAIL_EXTRA_DATA                        = ( 73), /* The parse failed due to extra data present. */
     WS_ERR_DATA_NOT_SIGNED                              = ( 74), /* The processed data was not a Signed Message as expected. */
     WS_ERR_NO_PROFILES                                  = ( 75), /* No configured profiles. */
     WS_ERR_DUPLICATE_PROFILES                           = ( 76), /* Multiple profiles found with the same psid. */
     WS_ERR_NO_ASSURANCE_LEVEL                           = ( 77), /* Expected but did not find assurance level. */
     WS_ERR_PKI_GENERATE_REQUEST                         = ( 78), /* PKI: Failed to generate service request. */
     WS_ERR_PKI_SERVICE_REQUEST                          = ( 79), /* PKI: Failed to request service. */
     WS_ERR_PKI_SERVICE_RESPONSE                         = ( 80), /* PKI: Failed to process response. */
     WS_ERR_PKI_INVALID_LCM_TYPE                         = ( 81), /* PKI: Invalid LCM type. */
     WS_ERR_PKI_INVALID_URL                              = ( 82), /* PKI: Invalid URL. */
     WS_ERR_PKI_INVALID_CONFIG                           = ( 83), /* PKI: Invalid PKI config detected. */
     WS_ERR_PKI_ENCODE_BASE64                            = ( 84), /* PKI: Failed to encode base64. */
     WS_ERR_SAVE_FILE                                    = ( 85), /* Failed to save file. */
     WS_ERR_UNSUPPORTED_CUSTOM_SETTINGS_TYPE             = ( 86), /* Unsupported Aerolink custom settings type. */
     WS_ERR_UNSUPPORTED_CUSTOM_SETTING                   = ( 87), /* Unsupported Aerolink custom setting. */
     WS_ERR_INVALID_CUSTOM_SETTING_FORMAT                = ( 88), /* Invalid Aerolink custom setting format. */
     WS_ERR_CUSTOM_SETTINGS_TYPE_DISABLED                = ( 89), /* The specified Aerolink custom settings type is disabled. */
     WS_ERR_INVALID_ENCRYPTION_KEY                       = ( 90), /* Encryption key is invalid. */
     WS_ERR_ENCRYPTION_KEY_NOT_FOUND                     = ( 91), /* Encryption key not found. */
     WS_ERR_CMAC_VERIFICATION_FAILED                     = ( 92), /* CMAC verification failed. */
     WS_ERR_INVALID_CA_CERTIFICATE_STORE                 = ( 93), /* Invalid CA certificate store format. */
     WS_ERR_CA_CERTIFICATE_STORE_VERIFICATION_FAILED     = ( 94), /* Failed to verify CA certificate store. */
     WS_ERR_PAYLOAD_NOT_SPDU                             = ( 95), /* The provided SPDU payload is not valid. */
     WS_ERR_NO_PROFILE_FOR_PERMISSION                    = ( 96), /* There is no profile for the requested permission. */
     WS_ERR_INVALID_CRL_TYPE                             = ( 97), /* The crl type is not supported by this crl processor. */
     WS_ERR_READ_FILE                                    = ( 98), /* Failed to read file. */
     WS_ERR_INVALID_SPDU_HASH                            = ( 99), /* The hash algorithm in the signed SPDU does not match the hash algorithm used by the signer. */
     WS_ERR_PKI_SERVICE_RESPONSE_PARTIAL_DATA            = (100), /* PKI: server response contains partial data. */
     WS_ERR_INVALID_ACF_HEADER                           = (101), /* The provided data cannot be encoded into an acf header. */
     WS_ERR_CRL_TOO_OVERDUE                              = (102), /* A valid CRL for the certificate is not available. */
     WS_ERR_CRL_SIGNER_INCONSISTENT                      = (103), /* The signer of a CRL is inconsistent with the CraCa ID in the CRL contents. */
     WS_ERR_CRL_TIMES_INCONSISTENT                       = (104), /* The issue date of a CRL is not strictly before the nextCrl date. */
     WS_ERR_NO_REPORT_AVAILABLE                          = (105), /* No misbehavior reports are available. */
     WS_ERR_SECURITY_LIBRARY_NOT_INITIALIZED             = (106), /* The security library is not initialized. */
     WS_ERR_CERTIFICATE_LINKAGE_I_NOT_CURRENT            = (107), /* Linkage values for the time period indicated by the i value in a certificate's linkage revocation data have not been calculated, so a revocation check cannot be made. */
     WS_ERR_NO_DEVICE_REGISTRATION                       = (108), /* Cannot find valid device registration information. */
     WS_ERR_LCM_DIR_DOES_NOT_EXIST                       = (109), /* The LCM directory provided to the AT Record does not exist. */
     WS_ERR_ATRECORD_NOT_INITIALIZED                     = (110), /* The AT Record has not been initialized. */
     WS_ERR_CREATE_DIRECTORY                             = (111), /* Failed to create the directory. */
     WS_ERR_DELETE_FILE                                  = (112), /* Failed to delete the file. */
     WS_ERR_REQUEST_HASH_NOT_BEING_SERVICED              = (113), /* The request hash associated with the certificate is not being serviced. */
     WS_ERR_PKI_LCM_NOT_INITIALIZED                      = (114), /* The LCM has not be initialized for SCMS service. */
     WS_ERR_INVALID_ENROLLMENT_CONFIG                    = (115), /* The enrollment.conf file has one or more invalid entries. */
     WS_ERR_INVALID_PKI_SCMS_SERVICE_CONFIG              = (116), /* A PKI SCMS service configuration file has one or more invalid entries. */
     WS_ERR_INVALID_ENROLLMENT_DATA                      = (117), /* The enrollment certificate and/or its signing key is invalid. */
     WS_ERR_INVALID_PKICONN_CONFIG                       = (118), /* An error with the PKI connection configuration file occurred. */
     WS_ERR_MISBEHAVIOR_NOT_ENABLED                      = (119), /* Misbehavior system has not been enabled. */
     WS_ERR_MISBEHAVIOR_APPLICATION_NOT_SUPPORTED        = (120), /* The requested PSID value is not supported by the Misbehavior system. */
     WS_ERR_MISBEHAVIOR_APPLICATION_NOT_ENABLED          = (121), /* The application misbehavior system has not been enabled. */
     WS_ERR_INVALID_MISBEHAVIOR_DATATYPE                 = (122), /* The application data is not valid for the type of misbehavior detector. */
     WS_ERR_FAILED_REPORT_ENCODING                       = (123), /* Failed to encode misbehavior report. */
     WS_ERR_MISBEHAVIOR_DETECTED                         = (124), /* Misbehavior was detected. */
     WS_ERR_MISBEHAVIOR_STORE_REPORT                     = (125), /* Unable to store report. */
     WS_ERR_BUFFER_TOO_LARGE                             = (126), /* The supplied buffer is too large. */
     WS_ERR_HSM_NOT_INITIALIZED                          = (127), /* The HSM has not been initialized. */
     WS_ERR_HSM_INVALID_INITIALIZATION_DATA              = (128), /* The HSM initialization files are invalid in some way. */
     WS_ERR_FILE_SECURITY                                = (129), /* Secured file failed security checks. */
     WS_ERR_NOT_LICENSED                                 = (130), /* The requested feature is not licensed. */
     WS_ERR_FILE_ALREADY_OPEN                            = (131), /* The specified file is already open. */
     WS_ERR_ACF_NOT_FOUND                                = (132), /* Unable to find specified ACF. */
     WS_ERR_INVALID_THROTTLEMANAGER_CONFIG               = (133), /* An error with the throttle manager configuration occurred. */
     WS_ERR_THROTTLE_MANAGER_NOT_RUNNING                 = (134), /* The throttle manager service cannot be reached. */
     WS_ERR_NO_FILE                                      = (135), /* File does not exist. */
     WS_ERR_INVALID_MISBEHAVIOR_CONFIG                   = (136), /* An error with the misbehavior configuration file occurred */
     WS_ERR_NO_ENROLLMENT                                = (137), /* Missing enrollment information */
     WS_ERR_LOAD_CRYPTO_INTERFACE_LIB                    = (138), /* Failed to load crypto interface library and required functions. */
     WS_ERR_INVALID_MANIFEST_FILE                        = (139), /* A manifest file has one or more invalid entries. */
     WS_ERR_TRCL_OVERDUE                                 = (140), /* Trusted root CA certificate list is overdue. */
     WS_ERR_TDCL_OVERDUE                                 = (141), /* Trusted domain CA certificate list is overdue. */
     WS_ERR_KEY_MISMATCH                                 = (142), /* Public key calculated from private key does not match expected public key */
     WS_ERR_DEVICE_NOT_INITIALIZED                       = (143), /* The device is not initialized with required SCMS information. */

} AEROLINK_RESULT;

#ifdef __cplusplus
}
#endif

#endif /* WS_ERRNO_H */
