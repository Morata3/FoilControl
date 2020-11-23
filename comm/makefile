SOURCE_DIR = 
HEIGHT_DIR =./heightSensor/
IMU_DIR =./imu/
GPS_DIR =./gps/
PID_DIR =./pid/
DEBUG_DIR = ./debug/

TARGET_ARCH=armv6vfphLinux3.xgcc4.7.2

# If undefined in the environment default NDDSHOME to install dir
ifndef NDDSHOME
NDDSHOME := /opt/rti_connext_dds-6.0.1
endif

JAVA_PATH = java
JAVAC_PATH = javac

JAVA_SOURCES = $(SOURCE_DIR)./communicator.java \
	       $(SOURCE_DIR)$(HEIGHT_DIR)heightSensor.java $(SOURCE_DIR)$(HEIGHT_DIR)heightSensorSeq.java $(SOURCE_DIR)$(HEIGHT_DIR)heightSensorTypeSupport.java $(SOURCE_DIR)$(HEIGHT_DIR)heightSensorTypeCode.java $(SOURCE_DIR)$(HEIGHT_DIR)heightSensorDataReader.java $(SOURCE_DIR)$(HEIGHT_DIR)heightSensorDataWriter.java \
		       $(SOURCE_DIR)$(IMU_DIR)imu.java $(SOURCE_DIR)$(IMU_DIR)imuSeq.java $(SOURCE_DIR)$(IMU_DIR)imuTypeSupport.java $(SOURCE_DIR)$(IMU_DIR)imuTypeCode.java $(SOURCE_DIR)$(IMU_DIR)imuDataReader.java $(SOURCE_DIR)$(IMU_DIR)imuDataWriter.java \
		       $(SOURCE_DIR)$(GPS_DIR)gps.java $(SOURCE_DIR)$(GPS_DIR)gpsSeq.java $(SOURCE_DIR)$(GPS_DIR)gpsTypeSupport.java $(SOURCE_DIR)$(GPS_DIR)gpsTypeCode.java $(SOURCE_DIR)$(GPS_DIR)gpsDataReader.java $(SOURCE_DIR)$(GPS_DIR)gpsDataWriter.java \
		       $(SOURCE_DIR)$(PID_DIR)pid.java $(SOURCE_DIR)$(PID_DIR)pidSeq.java $(SOURCE_DIR)$(PID_DIR)pidTypeSupport.java $(SOURCE_DIR)$(PID_DIR)pidTypeCode.java $(SOURCE_DIR)$(PID_DIR)pidDataReader.java $(SOURCE_DIR)$(PID_DIR)pidDataWriter.java $(SOURCE_DIR)$(PID_DIR)pidSubscriber.java $(SOURCE_DIR)$(PID_DIR)pidPublisher.java \
		       $(SOURCE_DIR)$(DEBUG_DIR)debug.java $(SOURCE_DIR)$(DEBUG_DIR)debugSeq.java $(SOURCE_DIR)$(DEBUG_DIR)debugTypeSupport.java $(SOURCE_DIR)$(DEBUG_DIR)debugTypeCode.java $(SOURCE_DIR)$(DEBUG_DIR)debugDataReader.java $(SOURCE_DIR)$(DEBUG_DIR)debugDataWriter.java $(SOURCE_DIR)$(DEBUG_DIR)debugSubscriber.java $(SOURCE_DIR)$(DEBUG_DIR)debugPublisher.java 


CLASS_FILES  = $(JAVA_SOURCES:%.java=%.class)

RTI_CLASSPATH := $(NDDSHOME)/lib/java/nddsjava.jar

%.class : %.java
	$(JAVAC_PATH) -classpath ".:$(RTI_CLASSPATH):$(HEIGHT_DIR):$(IMU_DIR):$(GPS_DIR):$(PID_DIR):$(DEBUG_DIR):/usr/share/java/RXTXcomm.jar" $<

all: $(CLASS_FILES)

# Clean classes to rebuild
clean:
	$(RM) $(CLASS_FILES)

#
# Convenient way to run the java programs
#

export LD_LIBRARY_PATH := $(NDDSHOME)/lib/armv6vfphLinux3.xgcc4.7.2:/usr/lib/lwp:$(LD_LIBRARY_PATH)

communicator: ./communicator.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH):$(HEIGHT_DIR):$(IMU_DIR):$(GPS_DIR):$(PID_DIR):$(DEBUG_DIR):/usr/share/java/RXTXcomm.jar" communicator $(ARGS)
 
heightSensorSubscriber: ./heightSensorSubscriber.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH)" heightSensorSubscriber $(ARGS)

imuSubscriber: ./imuSubscriber.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH)" imuSubscriber $(ARGS)

pidSubscriber: ./pidSubscriber.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH)" pidSubscriber $(ARGS)
