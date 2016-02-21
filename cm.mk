$(call inherit-product, device/asus/Z00L/full_Z00L.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_NAME := cm_Z00L
PRODUCT_BRAND := asus
PRODUCT_MODEL := ASUS_Z00LD
PRODUCT_MANUFACTURER := asus
PRODUCT_DEVICE := Z00L

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_NAME=WW_Z00L \
    BUILD_FINGERPRINT="asus/WW_Z00L/ASUS_Z00L:5.0.2/LRX22G/WW_user_1.17.40.1106_20160202:user/release-keys" \
    PRIVATE_BUILD_DESC="Z00L-user 5.0.2 LRX22G WW_user_1.17.40.1106_20160202 release-keys"

PRODUCT_GMS_CLIENTID_BASE := android-asus
