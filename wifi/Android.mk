LOCAL_PATH:= $(call my-dir)

ifeq ($(strip $(BOARD_HAS_QCOM_WLAN)),true)

include $(CLEAR_VARS)
LOCAL_MODULE       := WCNSS_qcom_wlan_nv.bin
LOCAL_MODULE_TAGS  := optional
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := $(LOCAL_MODULE)
LOCAL_MODULE_PATH  := $(TARGET_OUT_ETC)/firmware/wlan/prima
include $(BUILD_PREBUILT)

endif
