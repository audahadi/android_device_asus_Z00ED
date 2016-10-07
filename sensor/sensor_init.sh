#!/system/bin/sh

PROXM_SPEC_FILE="/data/data/proximity_spec"
LIGHT_SPEC_FILE="/data/data/lightsensor_spec"
PROXM_INF_FILE="/data/data/proximity_calibration_inf"
PROXM_HI_FILE="/factory/psensor_hi.nv"
PROXM_LOWI_FILE="/factory/psensor_low.nv"
LIGHT_200_FILE="/factory/lsensor_200lux.nv"
LIGHT_1000_FILE="/factory/lsensor_1000lux.nv"

sensor_chmod()
{
	if [ -f $1 ];
	then
		echo "File $FILE exists"
		chmod 660 $1
		chown system:shell $1
	else
		echo "File $FILE does not exists"
		echo 0 > $1
		chmod 660 $1
		chown system:shell $1
	fi
}

sensor_chmod $PROXM_SPEC_FILE
sensor_chmod $LIGHT_SPEC_FILE

sensor_chmod $PROXM_INF_FILE
sensor_chmod $PROXM_HI_FILE
sensor_chmod $PROXM_LOWI_FILE
sensor_chmod $LIGHT_200_FILE
sensor_chmod $LIGHT_1000_FILE

sensor_chmod_for_media()
{
        if [ -f $1 ];
        then
                echo "File $FILE exists"
                chmod 660 $1
                chown media:shell $1
        else
                echo "File $FILE does not exists"
                echo 0 > $1
                chmod 660 $1
                chown media:shell $1
        fi
}

#LASER_FOCUS_ON_FILE="/proc/driver/LaserFocus_on"
#LASER_FOCUS_VALUE_FILE="/proc/driver/LaserFocus_value"
#LASER_FOCUS_CAL_FILE="/proc/driver/LaserFocus_CalStart"
#LASER_FOCUS_STATUS_FILE="/proc/driver/LaserFocus_Status"
#LASER_FOCUS_STATUS_FILE_FOR_CAMERA="/proc/driver/LaserFocus_Status_For_Camera"
LASER_FOCUS_CAL_FILE_FOR_10="/factory/LaserFocus_Calibration10.txt"
LASER_FOCUS_CAL_FILE_FOR_40="/factory/LaserFocus_Calibration40.txt"

#sensor_chmod_for_media $LASER_FOCUS_ON_FILE
#sensor_chmod_for_media $LASER_FOCUS_VALUE_FILE
#sensor_chmod_for_media $LASER_FOCUS_CAL_FILE
#sensor_chmod_for_media $LASER_FOCUS_STATUS_FILE
#sensor_chmod_for_media $LASER_FOCUS_STATUS_FILE_FOR_CAMERA
sensor_chmod_for_media $LASER_FOCUS_CAL_FILE_FOR_10
sensor_chmod_for_media $LASER_FOCUS_CAL_FILE_FOR_40

chown system:shell /sys/bus/platform/devices/soc.0/hall_sensor/hall_sensor/switch

exit 0
