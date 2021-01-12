/*
*  Copyright (c) 2015-2019, The Linux Foundation. All rights reserved.
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

#ifndef PEERTOPEERC_H
#define PEERTOPEERC_H

/**
 * @file PeerToPeer.h
 * @brief C interface to the Peer Cert Distribution.
 */

#include <stdint.h>
#include "aerolink_api.h"
#include "ws_errno.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Structure for Aerolink configuration.
 */

typedef uint8_t (*P2PCallback)(void     *userData,  // OUT
                               uint32_t  pduLength, // OUT
                               uint8_t  *pdu);      // OUT


/**
 * @brief Set the callback function for P2P CA cert replies.
 *
 * @param userData (IN) Pointer to user data returned in a callback
 * @param p2pCallback (IN) Pointer to the callback method
 *    Set pointer to NULL to disable callbacks
 *
 * @return AEROLINK_RESULT
 *
 * @retval WS_SUCCESS
 *     - operation was successful
 *
 */
AEROLINK_EXPORT AEROLINK_RESULT
p2p_setCallback(
        void         *userData,
        P2PCallback   p2pCallback);

/**
 * @brief Process an incomming P2P Cert reply message
 *
 * @param pduLength (IN) Length of data unit
 * @param pdu (IN) Pointer to the data unit
 *
 * @return AEROLINK_RESULT
 *
 * @retval WS_SUCCESS
 *     - operation was successful
 *
 */
AEROLINK_EXPORT AEROLINK_RESULT
p2p_process(
        uint32_t    pduLength,
        uint8_t    *pdu);

#ifdef __cplusplus
}
#endif

#endif /* PEER2PEERC_H */
