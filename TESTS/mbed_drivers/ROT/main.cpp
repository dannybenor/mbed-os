/* mbed Microcontroller Library
 * Copyright (c) 2017 ARM Limited
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

#include "mbed.h"
#include "greentea-client/test_env.h"
#include "unity/unity.h"
#include "utest/utest.h"
#include <stdlib.h>
#include <stdio.h>

#include "drivers/ROT.h"

using namespace utest::v1;


void test_case_rot()
{
char salt[100];
unsigned char key[16];
int ret,i;
     ROT * pROT = ROT::get();
     sprintf(salt,"my key %d",1);
     ret = pROT->derive_key((const unsigned char *)salt, (size_t)strlen(salt),key , (size_t)16);
     printf("\nsalt =%s my derived key%i is %llu\n",salt,i,*(long long unsigned int *)key);
     ret = pROT->derive_key((const unsigned char *)salt, (size_t)strlen(salt),key , (size_t)16);
     printf("\nsalt =%s my derived key%i is %llu\n",salt,i,*(long long unsigned int *)key);
     sprintf(salt,"my key %d",2);
     ret = pROT->derive_key((const unsigned char *)salt, (size_t)strlen(salt),key , (size_t)16);
     printf("\nsalt =%s my derived key%i is %llu\n",salt,i,*(long long unsigned int *)key);
     ret = pROT->derive_key((const unsigned char *)salt, (size_t)strlen(salt),key , (size_t)16);
     printf("\nsalt =%s my derived key%i is %llu\n",salt,i,*(long long unsigned int *)key);
     sprintf(salt,"my key %d",1);
     ret = pROT->derive_key((const unsigned char *)salt, (size_t)strlen(salt),key , (size_t)16);
     printf("\nsalt =%s my derived key%i is %llu\n",salt,i,*(long long unsigned int *)key);
     ret = pROT->derive_key((const unsigned char *)salt, (size_t)strlen(salt),key , (size_t)16);
     printf("\nsalt =%s my derived key%i is %llu\n",salt,i,*(long long unsigned int *)key);
     sprintf(salt,"my key %d",2);
     ret = pROT->derive_key((const unsigned char *)salt, (size_t)strlen(salt),key , (size_t)16);
     printf("\nsalt =%s my derived key%i is %llu\n",salt,i,*(long long unsigned int *)key);
     ret = pROT->derive_key((const unsigned char *)salt, (size_t)strlen(salt),key , (size_t)16);
     printf("\nsalt =%s my derived key%i is %llu\n",salt,i,*(long long unsigned int *)key);

#if 0
     for (i=0;i<100;i++){
        // sprintf(salt,"my key %d",i);
         ret = pROT->derive_key((const unsigned char *)salt, (size_t)strlen(salt),key , (size_t)16);
         printf("\nsalt =%s my derived key%i is %llu\n",salt,i,*(long long unsigned int *)key);

     }
#endif
    TEST_ASSERT_EQUAL_INT32(0, ret);
}


utest::v1::status_t greentea_failure_handler(const Case *const source, const failure_t reason) {
    greentea_case_failure_abort_handler(source, reason);
    return STATUS_CONTINUE;
}

Case cases[] = {
    Case("ROT", test_case_rot, greentea_failure_handler)
};

utest::v1::status_t greentea_test_setup(const size_t number_of_cases) {
    GREENTEA_SETUP(50, "default_auto");
    return greentea_test_setup_handler(number_of_cases);
}

Specification specification(greentea_test_setup, cases, greentea_test_teardown_handler);

int main() {
    Harness::run(specification);
}
