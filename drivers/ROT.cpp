/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "hal/rot_api.h"
#include "drivers/ROT.h"
#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif


#include "mbedtls/pkcs5.h"
#include "mbedtls/asn1.h"
#include "mbedtls/cipher.h"
#include "mbedtls/oid.h"

#include <string.h>
#include <stdio.h>


namespace mbed {



ROT * ROT::_instance = (ROT*)NULL;

ROT *ROT::get() {

    if (NULL == _instance) {
        _instance = new ROT();
    }
    return _instance;
}

ROT::ROT() {
    return;
}

void ROT::destroy() {
    if (NULL != _instance) {
        delete _instance;
        _instance = (ROT*)NULL;
    }
}

ROT::~ROT() {
    return;
}

int ROT::derive_key(const unsigned char *salt, size_t salt_length, unsigned char *output, size_t out_length)
{
    mbedtls_md_context_t sha1_ctx;
    const mbedtls_md_info_t *info_sha1;
    int result=0;
    uint32_t i, key[ROT_LEN/sizeof(uint32_t)];

    //for (i=0;i<ROT_LEN/sizeof(uint32_t);i++){
    //        key[i] = 0;
     //   }
#if DEVICE_ROT
    rot_t rot_obj;
        rot_init(&rot_obj);
        result = rot_get_256_bits(&rot_obj, key, sizeof(key));
        printf("ROT=%llu\n",*(long long unsigned int *)key);
#else
        for (i=0;i<ROT_LEN/sizeof(uint32_t);i++){
            key[i]=(uint32_t)i;
        }
#endif
        if (result == 0){
            mbedtls_md_init( &sha1_ctx );
            info_sha1 = mbedtls_md_info_from_type( MBEDTLS_MD_SHA1 );
            if( info_sha1 == NULL ){
                result = -1;
            }
        }
        if (result == 0){
            result = mbedtls_md_setup( &sha1_ctx, info_sha1, 1 );
        }
        if (result == 0){
            result = mbedtls_pkcs5_pbkdf2_hmac( &sha1_ctx, (unsigned char *)key, ROT_LEN, salt,salt_length, 100, out_length, output );
        }

        mbedtls_md_free( &sha1_ctx );
        if (result == 0){
            return result;
        }
        else{
            return -1;
        }

}

} // namespace mbed

