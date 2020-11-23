#!/bin/bash

pkill -9 -f ./pid/objs/armv6vfphLinux3.xgcc4.7.2/imu/imu_subscriber
pkill -9 -f ./pid/objs/armv6vfphLinux3.xgcc4.7.2/height/heightSensor_subscriber
pkill -9 -f ./debugger/objs/armv6vfphLinux3.xgcc4.7.2/debug_subscriber
