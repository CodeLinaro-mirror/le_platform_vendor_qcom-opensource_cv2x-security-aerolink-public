/*
*  Copyright (c) 2019, The Linux Foundation. All rights reserved.
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

#ifndef AEROLINK_MISBEHAVIORC_H
#define AEROLINK_MISBEHAVIORC_H

#include <stdint.h>
#include "ws_errno.h"

#include "MisbehaviorErrors.h"

#ifdef __cplusplus
extern "C" {
#endif

/***
 * @brief Initialize the misbehavior library
 *        This routine must to be called once prior to any other library function.

 * @return SECURITY_INTERFACE_RESULT
 *
 * @retval WS_SUCCESS
 *     - operation was successful
 *
 * @retval SI_SECURITY_LIBRARY_NOT_INITIALIZED
 *     - the security library has not been previously initialized.
 *
 */
AEROLINK_EXPORT SECURITY_INTERFACE_RESULT
misbehavior_initialize(void);

/***
 * @brief Shut down the misbehavior library
 *
 * @return SECURITY_INTERFACE_RESULT
 *
 * @retval WS_SUCCESS
 *     - operation was successful
 *
 * @retval SI_NOT_INITIALIZED
 *     - the misbehavior library has not been previously initialized.
 *
 * @retval SI_SECURITY_LIBRARY_NOT_INITIALIZED
 *     - the security library has not been previously initialized.
 */
AEROLINK_EXPORT SECURITY_INTERFACE_RESULT
misbehavior_shutdown(void);


AEROLINK_EXPORT SECURITY_INTERFACE_RESULT
misbehavior_prepareSpduForReport(
    uint8_t const *sourceSpdu,
    uint32_t sourceSpduLength,
    uint8_t *updatedSpdu,
    uint32_t *updatedSpduLength,
    uint8_t *certificateBuffer,
    uint32_t *certificateBufferLength);



AEROLINK_EXPORT SECURITY_INTERFACE_RESULT
misbehavior_signEncryptReport (
    uint8_t const *	reportData,
    uint32_t 		reportDataLength,
    uint8_t *		preparedReport,
    uint32_t *		preparedReportLength);

AEROLINK_EXPORT SECURITY_INTERFACE_RESULT
misbehavior_getCurrentLocation(
    int32_t *   latitude,
    int32_t *   longitude,
    uint16_t *  elevation);


/**
 * @brief Convert the SECURITY_INTERFACE_RESULT to a string
 * @param errorCode
 * @return
 */
AEROLINK_EXPORT char const *
si_errid(
    SECURITY_INTERFACE_RESULT err);

#ifdef __cplusplus
}
#endif

#endif //AEROLINK_MISBEHAVIORC_H
