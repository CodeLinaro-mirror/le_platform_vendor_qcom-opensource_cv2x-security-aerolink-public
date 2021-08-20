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
#ifndef DIRECTED_VERIFICATION_DISPATCHER_H
#define DIRECTED_VERIFICATION_DISPATCHER_H

#include "verification_dispatcher.h"

typedef enum {
    DIRECTED_ECCPK_SUCCESS,
    DIRECTED_ECCPK_BAD_ARGS,
    DIRECTED_ECCPK_BUFFER_TOO_SMALL,
    DIRECTED_ECCPK_INTERNAL_ERROR,
    DIRECTED_ECCPK_VERIFICATION_FAILED,
    DIRECTED_ECCPK_UNSUPPORTED_OPERATION,
    DIRECTED_ECCPK_UNSUPPORTED_CPU,
    DIRECTED_ECCPK_BAD_CACHE_LEVEL,
    DIRECTED_ECCPK_BAD_CACHE_INDEX
} DIRECTED_ECCPK_RESULT;

typedef enum
{
    DIRECTED_ECCPK_ARM,
    DIRECTED_ECCPK_ADSP,
    DIRECTED_ECCPK_CDSP,
    DIRECTED_ECCPK_MVM,
    DIRECTED_ECCPK_XDJA
} DIRECTED_ECCPK_CPU;

typedef enum
{
    DIRECTED_ECCPK_NO_CACHE,    /* Perform verification without using cache. */
    DIRECTED_ECCPK_BUILD_CACHE, /* Build cache entry at specified index, and
                                   perform verification using built entry. */
    DIRECTED_ECCPK_USE_CACHE    /* Perform verification using cache entry already
                                   built at the specified index. */
} DIRECTED_ECCPK_CACHE_INSTRUCTION;

typedef struct
{
    DIRECTED_ECCPK_CPU                  cpu_to_use;
    uint8_t                             max_concurrent;
    DIRECTED_ECCPK_CACHE_INSTRUCTION    cache_instruction;
    int                                 cache_level; /* Which cache level (for
                                                        multi-level cache
                                                        implementation) */
    int                                 cache_index; /* Cache entry index (within
                                                        the indicated cache level) */
} DIRECTED_ECCPK_INSTRUCTION;

typedef struct
{
    uint32_t time_spent_blocked_in_queue_us;
    uint32_t time_spent_doing_verification_us;
} DIRECTED_ECCPK_STATS;

DIRECTED_ECCPK_RESULT directed_eccpk_init();

void directed_eccpk_shutdown();

size_t directed_eccpk_key_size(
    ECCPK_CURVE curve);

DIRECTED_ECCPK_RESULT directed_eccpk_import_key(
    uint8_t        priority,
    ECCPK_CURVE    curve,
    size_t         key_bytes_len,
    uint8_t const *key_bytes,
    ECCPK_KEY     *key);

DIRECTED_ECCPK_RESULT directed_eccpk_export_key(
    ECCPK_KEY const *key,
    uint8_t          priority,
    ECCPK_CURVE     *curve,
    size_t          *key_bytes_len,
    uint8_t         *key_bytes);

DIRECTED_ECCPK_RESULT directed_eccpk_ecdsa_verify(
    ECCPK_KEY const *key,
    uint8_t          priority,
    size_t           digest_len,
    uint8_t const   *digest,
    uint8_t          fast_verify_flag,
    size_t           rs_len,
    uint8_t const   *r,
    uint8_t const   *s,
    DIRECTED_ECCPK_INSTRUCTION const *instruction,
    DIRECTED_ECCPK_STATS     *stats);

DIRECTED_ECCPK_RESULT directed_eccpk_sm2_verify(
    ECCPK_KEY const *key,
    uint8_t          priority,
    size_t           digest_len,
    uint8_t const   *digest,
    size_t           rs_len,
    uint8_t const   *r,
    uint8_t const   *s,
    DIRECTED_ECCPK_INSTRUCTION const *instruction,
    DIRECTED_ECCPK_STATS     *stats);

DIRECTED_ECCPK_RESULT directed_eccpk_build_cache_entry(
    ECCPK_KEY const *key,
    DIRECTED_ECCPK_INSTRUCTION const *instruction,
    ECCPK_CURVE     curve);

DIRECTED_ECCPK_RESULT directed_eccpk_set_cache_entries(
    int cache_level,    /* Which cache level (for multi-level cache implementation) */
    int cache_entries   /* Number of cache entries in this cache level */
);

size_t directed_eccpk_cache_entry_size();

#endif /* DIRECTED_VERIFICATION_DISPATCHER_H */

