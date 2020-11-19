Welcome to your first Connext DDS example! 

This example was generated for architecture armv6vfphLinux3.xgcc4.7.2, using the
data type imu from imu.idl.
This example builds two applications, named imu_publisher and
imu_subscriber.

To Build this example:
======================
 
From your command shell, type:
> make -f makefile_imu_armv6vfphLinux3.xgcc4.7.2
This command will build a release executable.
 
To build a debug version instead:
> make -f makefile_imu_armv6vfphLinux3.xgcc4.7.2 DEBUG=1

To Modify the Data:
===================
To modify the data being sent, edit the imu_publisher.c
file where it says:
/* Modify the instance to be written here */

To Run this Example:
====================
Make sure you are in the directory where the USER_QOS_PROFILES.xml file was
generated (the same directory this README file is in).
Run /home/pi/rti_connext_dds-6.0.1/resource/scripts/rtisetenv_armv6vfphLinux3.xgcc4.7.2.bash
to make sure the Connext libraries are in the path, especially if you opened
a new command prompt window.
Run the publishing or subscribing application by typing:
> objs/armv6vfphLinux3.xgcc4.7.2/imu_publisher <domain_id> <sample_count>
> objs/armv6vfphLinux3.xgcc4.7.2/imu_subscriber <domain_id> <sample_count>
