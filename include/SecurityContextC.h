/*
*  Copyright (c) 2013-2019, The Linux Foundation. All rights reserved.
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

#ifndef SECURITY_CONTEXT_C_H
#define SECURITY_CONTEXT_C_H

/**
 * @file SecurityContextC.h
 * @brief C interface to the SecurityContext.
 */

#include <stdint.h>
#include "aerolink_api.h"
#include "ws_errno.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Handle to an allocated Security Context.
 */
typedef void* SecurityContextC;

/**
 * @brief Open a named security context.
 *
 * @param filename (IN) Name of the context file to open.
 * @param scHandle (OUT) Will point to the handle of the opened security context.
 *
 * @return AEROLINK_RESULT
 *
 * @retval WS_SUCCESS
 *     - operation was successful
 *
 * @retval WS_ERR_NOT_INITIALIZED
 *     - the security services have not been initialized.
 *
 * @retval WS_ERR_BAD_ARGS
 *     - name is NULL
 *     - scHandle is NULL
 *
 * @retval WS_ERR_ALREADY_OPEN
 *     - security context identified by name is already open
 *
 * @retval WS_ERR_INVALID_CONTEXT_CONFIG
 *     - no context configuration file for the given name
 */
AEROLINK_EXPORT AEROLINK_RESULT
sc_open(
        char const       *filename,
        SecurityContextC *scHandle);

/**
 * @brief Close a handle that was opened with sc_open(). After this call
 * the context will no longer be open and all generator and parsers associated
 * with this context will no longer be valid.
 *
 * @param scHandle (IN) Handle to a previously opened security context.
 *
 * @return AEROLINK_RESULT
 *
 * @retval WS_SUCCESS
 *     - operation was successful
 *
 * @retval WS_ERR_BAD_ARGS
 *     - scHandle is NULL
 *
 * @retval WS_ERR_INVALID_HANDLE
 *     - scHandle does not refer to a valid open security context.
 */
AEROLINK_EXPORT AEROLINK_RESULT
sc_close(
        SecurityContextC scHandle);

/**
 * @brief Return a pointer to the name of the context. This is the name provided to sc_open().
 *
 * @param scHandle (IN) Handle to a previously opened security context.
 * @param name (OUT) Will point to the name of the security context.
 *    This pointer is NOT to be freed by the caller and is valid only as long as the security context is open.
 *
 * @return AEROLINK_RESULT
 *
 * @retval WS_SUCCESS
 *     - operation was successful
 *
 * @retval WS_ERR_BAD_ARGS
 *     - scHandle is NULL
 *     - name is NULL
 *
 * @retval WS_ERR_INVALID_HANDLE
 *     - scHandle does not refer to a valid open security context.
 */
AEROLINK_EXPORT AEROLINK_RESULT
sc_getName(
        SecurityContextC   scHandle,
        char const       **name);


#ifdef __cplusplus
}
#endif

#endif /* SECURITY_CONTEXT_C_H */
