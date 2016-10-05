LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional
LOCAL_C_INCLUDES := \
    system/core/init \
    device/asus/msm8916-common/init
LOCAL_CFLAGS := -Wall -DANDROID_TARGET=\"$(TARGET_BOARD_PLATFORM)\"
LOCAL_SRC_FILES := init_z010d.cpp
LOCAL_MODULE := libinit_z010d

include $(BUILD_STATIC_LIBRARY)
