/*
   Copyright (c) 2015, The Linux Foundation. All rights reserved.

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
#include <fcntl.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#define RAW_ID_PATH     "/sys/devices/soc0/raw_id"
#define BUF_SIZE         64

static char tmp[BUF_SIZE];
static char buff_tmp[BUF_SIZE];

static int read_file2(const char *fname, char *data, int max_size)
{
    int fd, rc;

    if (max_size < 1)
        return 0;

    fd = open(fname, O_RDONLY);
    if (fd < 0) {
        ERROR("failed to open '%s'\n", fname);
        return 0;
    }

    rc = read(fd, data, max_size - 1);
    if ((rc > 0) && (rc < max_size))
        data[rc] = '\0';
    else
        data[0] = '\0';
    close(fd);

    return 1;
}


void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    int rc;
    unsigned long raw_id = -1;

    /* get raw ID */
    rc = read_file2(RAW_ID_PATH, tmp, sizeof(tmp));
    if (rc) {
        raw_id = strtoul(tmp, NULL, 0);
    }

    /* Z010D  */
    if (raw_id==1797) {
        property_set("ro.product.model", "ASUS_Z010D");
        property_set("ro.product.device", "ASUS_Z010");
        property_set("ro.product.carrier", "US-ASUS_Z010D-WW_Phone");
        property_set("ro.build.description", "WW_Phone-user 6.0.1 MMB29P 13.8.26.46-20160812 release-keys");
        property_set("ro.build.fingerprint", "asus/WW_Phone/ASUS_Z010:6.0.1/MMB29P/13.8.26.46-20160812:user/release-keys");
        property_set("ro.build.product", "ZC550KL");
        property_set("ro.build.csc.version", "WW_ZC550KL-13.8.26.46-20160812cccc");
        property_set("ro.build.product", "ZC550KL");
    } else {
        property_set("ro.product.model", "Zenfone Max"); // this should never happen.
    }
}
