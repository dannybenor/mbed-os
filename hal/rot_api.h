
/** \addtogroup hal */
/** @{*/
/* mbed Microcontroller Library
 * Copyright (c) 2016 ARM Limited
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

/**
 *  ROT - Root of Trust when provided by the platform is a secret and unique per-device value 128 or 256 bits long that will be used to generate additional keys.
 *  ROT API to be used to generate keys is presented by ROT driver. If ROT is not implemented in a platform, ROT driver will generate it from random.
 *
 */

#ifndef MBED_ROT_API_H
#define MBED_ROT_API_H

#include <stddef.h>
#include "device.h"
#define ROT_LEN 32   /* ROT key length in bytes */

#if DEVICE_ROT
/** ROT HAL structure. rot_s is declared in the target's HAL
 */



//typedef struct rot_s rot_t;
typedef int rot_t;


#ifdef __cplusplus
extern "C" {
#endif
/**
 * \defgroup hal_rot ROT hal functions
 * @{
 */

/** Initialize the ROT
 *
 *  peripheral
 *
 * @param obj The ROT object
 */
void rot_init(rot_t *obj);

/** Deinitialize the ROT peripheral
 *
 * @param obj The ROT object
 */
void rot_free(rot_t *obj);

/** Get  data for ROT from the platform
 *
 * @param obj The ROT object
 * @param output The pointer to an output array (must be 32 bytes min)
 * @param output_length The size of output data, to avoid buffer overwrite
 * @return 0 success, -1 fail
 */
int rot_get_256_bits(rot_t *obj, uint32_t *output, size_t output_length);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif

#endif

/** @}*/
