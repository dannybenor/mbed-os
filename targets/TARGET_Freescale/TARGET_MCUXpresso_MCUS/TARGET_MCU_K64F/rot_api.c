/*
 *  Return the values stored in registers UIDH, UIDMH, UIDML, UIDL. This value is predictable therefore not secure, but used as example
 *
 *  Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

/*
 * Reference: "K64 Sub-Family Reference Manual, Rev. 2", chapter 13.2.22
 */

#if defined(DEVICE_ROT)

#include <stdlib.h>
#include "cmsis.h"
#include "fsl_common.h"
#include "fsl_clock.h"
#include "rot_api.h"

void rot_init(rot_t *obj)
{
    (void)obj;
    return;
}

void rot_free(rot_t *obj)
{
    (void)obj;
    return;
}

int rot_get_256_bits(rot_t *obj, uint32_t *output, size_t output_length)
{
    int i;
    (void)obj;

    if (output_length < ROT_LEN)
        return -1;
    for (i=0;i<output_length;i++){
        *((char *)output+i) = 0;
    }

    *output++ = SIM->UIDH;
    *output++ = SIM->UIDML;
    *output++ = SIM->UIDMH;
    *output++ = SIM->UIDL;
    return 0;
}
#endif
