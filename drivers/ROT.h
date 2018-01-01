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
#ifndef MBED_ROT_H
#define MBED_ROT_H

#include "platform/NonCopyable.h"
#include <string.h>

namespace mbed {
/** \addtogroup drivers */

/** Use this singleton if you need to derive a new key from the device root of trust.
 *
 *
 * @endcode
 * @ingroup drivers
 */

class ROT {
public:
    /** Get the instance of ROT Class
     *
     *  @return the only instance of this class
     */

    static ROT* get();

    static void destroy();
    /** Derive a new key based on the salt string. Key length will be according to input value of out_length

     *  @param salt         input buffer used to create the new key. Same input will generate always the same key
     *  @param salt_length  size of the data in salt
     *  @param output       buffer to receive the derived key
     *  @param out_length   Size of the required key
     *  @return       0 on success, negative error code on failure
     */
    int derive_key(const unsigned char *salt, size_t salt_length, unsigned char *output, size_t out_length);
private:
    ROT();
    ~ROT();
    int dummy;

    static ROT * _instance;
};

} // namespace mbed

#endif
