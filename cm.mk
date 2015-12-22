$(call inherit-product, device/asus/Z00L/full_Z00L.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_RELEASE_NAME := Z00L
PRODUCT_NAME := cm_Z00L

PRODUCT_GMS_CLIENTID_BASE := android-asus
