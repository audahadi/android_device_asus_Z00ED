#!/bin/sh

set -e

export DEVICE=Z00L
export VENDOR=asus
./../../$VENDOR/msm8916-common/setup-makefiles.sh $@
