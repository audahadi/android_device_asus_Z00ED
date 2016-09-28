$(call inherit-product, device/asus/Z010D/full_Z010D.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_NAME := cm_Z010D
PRODUCT_BRAND := asus
PRODUCT_MANUFACTURER := asus
PRODUCT_DEVICE := Z010D

PRODUCT_GMS_CLIENTID_BASE := android-asus
