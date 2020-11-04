Welcome to your first Connext DDS example! 

This example was generated for architecture armv6vfphLinux3.xgcc4.7.2, using the
data type imu from imu.idl.
This example builds two applications, named imuPublisher
and imuSubscriber.

To Build this example:
======================
 
Build with Ant:
---------------
If you plan to use ant to build, make sure that ant is in your path.
 
From your command shell, in the directory where you generated this example, type:
> ant
 
Build with Eclipse:
-------------------
Import the generated code:
1. From the File menu, choose "Open Projects from File System..."
2. In "Import Projects from File System or Archive", use the "Directory..." button
   to browse to the directory where you generated this example. Select the
   directory and click Finish.
 
After you import, the project builds automatically.
 
Build with makefile:
--------------------
 
Make sure that java and javac are in your path before you start. From your
command shell, type:
> make -f makefile_imu_armv6vfphLinux3.xgcc4.7.2

To Modify the Data:
===================
To modify the data being sent, in the default package (or module you specified),
open/double-click and edit the imuPublisher.java file
where it says:
/* Modify the instance to be written here */

To Run This Example:
====================
 
Run with Ant:
-------------
Type 
> ant imuPublisher
or
> ant imuSubscriber
 
Run with Eclipse:
-----------------
Select Run > Run and choose either the imuPublisher or imuSubscriber
application.
To run the other application, select Run > Run Configurations and select the
one you want to run. 
Click Run.
The output appears in Eclipse's console window.

Run with makefile:
------------------
 
Make sure that java and javac are in your path before you start. From your
command shell, type:
> make -f makefile_imu_armv6vfphLinux3.xgcc4.7.2 imuPublisher
> make -f makefile_imu_armv6vfphLinux3.xgcc4.7.2 imuSubscriber
