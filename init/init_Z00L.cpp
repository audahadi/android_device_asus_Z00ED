/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char PRJ_ID[PROP_VALUE_MAX];
    char RF_SKU[PROP_VALUE_MAX];
    int rc;
    FILE *fp;

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    fp = fopen("/proc/apid" , "r");
    fgets(PRJ_ID, sizeof(PRJ_ID), fp);
    pclose(fp);

    fp = fopen("/proc/aprf" , "r");
    fgets(RF_SKU, sizeof(RF_SKU), fp);
    pclose(fp);

    /* Common properties */
    property_set("ro.build.product", "Z00L");
    property_set("ro.build.description", "Z00L-user 5.0.2 LRX22G WW_user_1.17.40.1531_20160428 release-keys");

    if (ISMATCH(PRJ_ID, "0\n")) {
        if (ISMATCH(RF_SKU, "3\n")) {
            /* ZE550KG */
            property_set("ro.product.model", "ASUS_Z00WD");
            property_set("ro.product.device", "ASUS_Z00W_63");
            property_set("ro.product.carrier", "US-ASUS_Z00W-WW_Z00W");
            property_set("ro.build.fingerprint", "asus/WW_Z00W/ASUS_Z00W_63:5.0.2/LRX22G/WW_user_1.17.40.1531_20160428:user/release-keys");
        } else {
            /* ZE550KL */
            property_set("ro.product.model", "ASUS_Z00LD");
            property_set("ro.product.device", "ASUS_Z00L");
            property_set("ro.product.carrier", "US-ASUS_Z00L-WW_Z00L");
            property_set("ro.build.fingerprint", "asus/WW_Z00L/ASUS_Z00L:5.0.2/LRX22G/WW_user_1.17.40.1531_20160428:user/release-keys");
        }
    } else if (ISMATCH(PRJ_ID, "1\n")) {
        /* ZE601KL */
        property_set("ro.product.model", "ASUS_Z00MD");
        property_set("ro.product.device", "ASUS_Z00M");
        property_set("ro.product.carrier", "US-ASUS_Z00M-WW_Z00M");
        property_set("ro.build.fingerprint", "asus/WW_Z00M/ASUS_Z00M:5.0.2/LRX22G/WW_user_1.17.40.1531_20160428:user/release-keys");
    }

    property_get("ro.product.device", device);
    INFO("Found project id: %s sku id: %s setting build properties for %s device\n", PRJ_ID, RF_SKU, device);
}
