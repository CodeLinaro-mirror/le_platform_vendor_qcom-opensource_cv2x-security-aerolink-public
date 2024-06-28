/*
*  Copyright (c) 2018-2019, The Linux Foundation. All rights reserved.
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
*  Copyright (c) 2024 Qualcomm Innovation Center, Inc. All rights reserved.
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

/*
 * Demo program using the C API for encrypting data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "viicsec.h"

#define LOG(text, result)                         \
    (void) printf("%s line %d: %s; result = %s\n", \
            __FILE__, __LINE__, text, ws_errid(result))


/*
 * Print a label and then the contents of the supplied buffer to stdout.
 */
static void printBytes(char *label, uint8_t const buffer[], uint32_t length)
{
    uint32_t i = 0;

    (void) printf("%s", label);

    for( i = 0; i < length; i++ ) {
        (void) printf("%02x ", buffer[i] & 0xffU);
    }

    (void) printf("\n");
}


int main (int argc, char *argv[])
{
    /* General variables */
    int32_t printMessage = 0;
    int32_t printKey = 0;
    int32_t i;

    char *contextName = "smdemo.wsc";
    SecurityContextC context;

    /* Parsing variables */
    SecuredMessageParserC smp = NULL;
    uint8_t const *receivedMessage = NULL;
    uint32_t receivedMessageLength = 0;

    /* Generation variables */
    SecuredMessageGeneratorC smg = NULL;
    uint8_t plainText[] = "some payload";
    uint32_t plainTextLength = sizeof plainText;

    /* Encryption variables */
    AerolinkEncryptionKey encryptionKey;
    uint8_t encryptedData[512];
    uint32_t encryptedDataLength = sizeof encryptedData;

    PayloadType     spduType = PLT_NOT_SET;
    PayloadType     payloadType = PLT_NOT_SET;
    uint8_t const *receivedExternalDataHash = NULL;
    ExternalDataHashAlg receivedExternalDataHashAlg = EDHA_NONE;

    PublicEncryptionAlgorithm publicEncryptionAlg = PEA_ECIES_NISTP256;

    AEROLINK_RESULT result;

    /*
     * Command line argument processing.
     */
    for( i = 1; i < argc; ++i )
    {
        if( strcmp("-pm", argv[i]) == 0 )
        {
            printMessage = 1;
        }

        else if( strcmp("-pk", argv[i]) == 0 )
        {
            printKey = 1;
        }

        else if ( strcmp("-curveChoice", argv[i]) == 0 )
        {
            if (i+1 < argc)
            {
                if ( strcmp("nistp256", argv[i+1]) == 0 )
                {
                    publicEncryptionAlg = PEA_ECIES_NISTP256;
                }
                else if ( strcmp("brainpoolp256r1", argv[i+1]) == 0 )
                {
                    publicEncryptionAlg = PEA_ECIES_BRAINPOOL256R1;
                }
                else if ( strcmp("sm2", argv[i+1]) == 0 )
                {
                    publicEncryptionAlg = PEA_ECENC_SM2;
                }
                else
                {
                    (void) printf("Invalid argument provided: -curveChoice requires one of the following strings: nistp256, brainpoolp256r1, or sm2.\n");
                    return 2;
                }
                i++;
            }
            else
            {
                (void) printf("Invalid argument: -curveChoice requires one of the following strings: nistp256, brainpoolp256r1, or sm2.\n");
                return 3;
            }
        }

        else
        {
            (void) printf("Invalid argument: %s is not supported\n", argv[i]);
            return 4;
        }
    }

    /*
     * Get the library version.
     */
    (void) printf("\nLibrary version is '%s'\n", securityServices_getVersion());


    /*
     * Initialize security services.
     */
    (void) printf ("\nInitializing security services\n");
    result = securityServices_initialize();
    if (result != WS_SUCCESS)
    {
        LOG("securityServices_initialize() failed", result);
        return result;
    }


    /*
     * Open application's security context.
     */
    (void) printf("Opening security context\n");
    result = sc_open(contextName, &context);
    if (result != WS_SUCCESS)
    {
        LOG("Failed to open wsc", result);
        (void) securityServices_shutdown();
        return result;
    }


    /*
     * Create Secured Message Generator.
     */
    (void) printf("Creating a secured message generator\n");
    result = smg_new(context, &smg);
    if (result != WS_SUCCESS)
    {
        LOG("Unable to create a secured message generator", result);
        (void) sc_close(context);
        (void) securityServices_shutdown();
        return result;
    }


    /*
     * Create Secured Message Parser.
     */
    (void) printf("Creating a secured message parser\n");
    result = smp_new(context, &smp);
    if (result != WS_SUCCESS)
    {
        LOG("Unable to create a secured message parser", result);
        (void) smg_delete(smg);
        (void) sc_close(context);
        (void) securityServices_shutdown();
        return result;
    }

    /*
     * Generate encryption keypair.
     */
    (void) printf ("Creating public encryption key pair\n");
    result = securityServices_generatePublicEncryptionKeyPair(publicEncryptionAlg, &encryptionKey);
    if (result != WS_SUCCESS)
    {
        LOG("securityServices_generatePublicEncryptionKeyPair() failed", result);
        (void) smg_delete(smg);
        (void) smp_delete(smp);
        (void) sc_close(context);
        (void) securityServices_shutdown();
        return result;
    }

    if (printKey)
    {
        printBytes("returned encryption key: ", encryptionKey.blob, encryptionKey.blobLen);
    }


    /*
     * Generate encrypted data.
     */
    (void) printf("\nEncrypting data\n");
    AerolinkEncryptionKey const * recipients[] =  {&encryptionKey};
    size_t numRecipients = sizeof recipients / sizeof recipients[0];
    result = smg_encrypt(smg, recipients, numRecipients,
                         plainText, plainTextLength, 0, encryptedData, &encryptedDataLength);
    if (result != WS_SUCCESS)
    {
        LOG("smg_encrypt() failed", result);
        (void) securityServices_deleteEncryptionKey(&encryptionKey);
        free((uint8_t *)encryptionKey.blob);
        (void) smg_delete(smg);
        (void) smp_delete(smp);
        (void) sc_close(context);
        (void) securityServices_shutdown();
        return result;
    }

    (void) printf("Encrypted data generated correctly\n");
    if (printMessage)
    {
        printBytes("\nEncrypted data is:\n  ",
                   encryptedData, encryptedDataLength);
    }



    /*
     * Process the encrypted data.
     */
    (void) printf("\nProcessing \"received\" encrypted message\n");
    (void) printf("Parsing encrypted message\n");
    result = smp_extract(smp,
                         encryptedData, encryptedDataLength, &spduType,
                         &receivedMessage, &receivedMessageLength, &payloadType,
                         &receivedExternalDataHash, &receivedExternalDataHashAlg);
    if (result != WS_SUCCESS)
    {
        LOG("Failed to parse the encrypted data", result);
        (void) securityServices_deleteEncryptionKey(&encryptionKey);
        free((uint8_t *)encryptionKey.blob);
        (void) smg_delete(smg);
        (void) smp_delete(smp);
        (void) sc_close(context);
        (void) securityServices_shutdown();
        return result;
    }

    else
    {
        (void) printf("Message decrypted\n");

        if ((receivedMessageLength != plainTextLength) ||
            (strncmp((char *) plainText, (char *) receivedMessage, receivedMessageLength) != 0))
        {
            LOG( "Returned payload does not match the payload passed to smg_encrypt()", result);
            (void) securityServices_deleteEncryptionKey(&encryptionKey);
            free((uint8_t *)encryptionKey.blob);
            (void) smg_delete(smg);
            (void) smp_delete(smp);
            (void) sc_close(context);
            (void) securityServices_shutdown();
            return result;
        }
    }
    if (spduType != PLT_ENCRYPTED_SPDU)
    {
        (void) printf("Returned input SPDU type incorrect %d\n", spduType);
        (void) securityServices_deleteEncryptionKey(&encryptionKey);
        free((uint8_t *)encryptionKey.blob);
        (void) smg_delete(smg);
        (void) smp_delete(smp);
        (void) sc_close(context);
        (void) securityServices_shutdown();
        return result;
    }
    else
    {
        (void) printf("Input SPDU type = PLT_ENCRYPTED_SPDU\n");
    }
    if (payloadType != PLT_UNSECURED_APP_PAYLOAD)
    {
        (void) printf("Returned output payload type incorrect %d\n", payloadType);
        (void) securityServices_deleteEncryptionKey(&encryptionKey);
        free((uint8_t *)encryptionKey.blob);
        (void) smg_delete(smg);
        (void) smp_delete(smp);
        (void) sc_close(context);
        (void) securityServices_shutdown();
        return result;
    }
    else
    {
        (void) printf("Output payload type = PLT_UNSECURED_APP_PAYLOAD\n");
    }


    /*
     * Delete encryption key.
     */
    (void) printf ("\nDeleting encryption key\n");
    result = securityServices_deleteEncryptionKey(&encryptionKey);
    if (result != WS_SUCCESS)
    {
        LOG("securityServices_deleteEncryptionKey() failed", result);
        free((uint8_t *)encryptionKey.blob);
        (void) smg_delete(smg);
        (void) smp_delete(smp);
        (void) sc_close(context);
        (void) securityServices_shutdown();
        return result;
    }

    /*
     * Delete the blob pointer.
     */
    if (encryptionKey.blob)
    {
        free((uint8_t *)encryptionKey.blob);
    }

    /*
     * Delete secured message generator.
     */
    (void) printf("Deleting secured message generator\n");
    result = smg_delete(smg);
    if (result != WS_SUCCESS)
    {
        LOG("Error deleting smg", result);
        (void) smp_delete(smp);
        (void) sc_close(context);
        (void) securityServices_shutdown();
        return result;
    }

    /*
     * Delete secured message parser.
     */
    (void) printf("Deleting secured message parser\n");
    result = smp_delete(smp);
    if (result != WS_SUCCESS)
    {
        LOG("Error deleting smp", result);
        (void) sc_close(context);
        (void) securityServices_shutdown();
        return result;
    }


    /*
     * Close security context.
     */
    (void) printf("Closing security context\n");
    result = sc_close(context);
    if (result != WS_SUCCESS)
    {
        LOG("Error closing wsc", result);
        (void) securityServices_shutdown();
        return result;
    }

    /*
     * Shutdown security services.
     */
    (void) printf("Shutting down security services\n");
    result = securityServices_shutdown();
    if (result != WS_SUCCESS)
    {
        LOG("Error shutting down security services", result);
    }

    (void) printf("\n");
    return result;
}
