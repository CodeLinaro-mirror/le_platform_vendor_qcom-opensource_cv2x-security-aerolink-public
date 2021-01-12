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

#ifndef AEROLINK_MISBEHAVIOR_ERRORS_H
#define AEROLINK_MISBEHAVIOR_ERRORS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    SI_SUCCESS = 0,
    SI_ERR_BAD_ARGS,
    SI_ERR_SECURITY_LIBRARY_MISBEHAVIOR_CONFIGURATION,
    SI_ERR_SECURITY_LIBRARY_FAILURE,
    SI_ERR_NOT_SIGNED_SPDU,
    SI_ERR_NOT_INITIALIZED,
    SI_ERR_SECURITY_LIBRARY_NOT_INITIALIZED,
    SI_ERR_NO_REPORT_AVAILABLE,
    SI_ERR_BUFFER_TOO_SMALL,
    SI_ERR_NO_CERTIFICATE,
} SECURITY_INTERFACE_RESULT;


#ifdef __cplusplus
}
#endif

#endif //AEROLINK_MISBEHAVIOR_ERRORS_H
