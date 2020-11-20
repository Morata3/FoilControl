SOURCE_DIR = 
HEIGHT_DIR =./heightSensor
IMU_DIR =./imu
GPS_DIR =./gps
PID_DIR =./pid

TARGET_ARCH=armv6vfphLinux3.xgcc4.7.2

# If undefined in the environment default NDDSHOME to install dir
ifndef NDDSHOME
NDDSHOME := /opt/rti_connext_dds-6.0.1
endif

JAVA_PATH = java
JAVAC_PATH = javac

JAVA_SOURCES = $(SOURCE_DIR)./communicator.java \
	       $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensoir.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorSeq.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorTypeSupport.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorTypeCode.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorDataReader.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorDataWriter.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorSubscriber.java \
		       $(SOURCE_DIR)$(IMU_DIR)/imu.java $(SOURCE_DIR)$(IMU_DIR)/imuSeq.java $(SOURCE_DIR)$(IMU_DIR)/imuTypeSupport.java $(SOURCE_DIR)$(IMU_DIR)/imuTypeCode.java $(SOURCE_DIR)$(IMU_DIR)/imuDataReader.java $(SOURCE_DIR)$(IMU_DIR)/imuDataWriter.java $(SOURCE_DIR)$(IMU_DIR)/imuSubscriber.java $(SOURCE_DIR)$(IMU_DIR)/imuPublisher.java \
	       $(SOURCE_DIR)$(IMU_DIR)/imu.java $(SOURCE_DIR)$(IMU_DIR)/imuSeq.java $(SOURCE_DIR)$(IMU_DIR)/imuTypeSupport.java $(SOURCE_DIR)$(IMU_DIR)/imuTypeCode.java $(SOURCE_DIR)$(IMU_DIR)/imuDataReader.java $(SOURCE_DIR)$(IMU_DIR)/imuDataWriter.java $(SOURCE_DIR)$(IMU_DIR)/imuSubscriber.java $(SOURCE_DIR)$(IMU_DIR)/imuPublisher.java \
		$(SOURCE_DIR)$(PID_DIR)/pid.java $(SOURCE_DIR)$(PID_DIR)/pidSeq.java $(SOURCE_DIR)$(PID_DIR)/pidTypeSupport.java $(SOURCE_DIR)$(PID_DIR)/pidTypeCode.java $(SOURCE_DIR)$(PID_DIR)/pidDataReader.java $(SOURCE_DIR)$(PID_DIR)/pidDataWriter.java $(SOURCE_DIR)$(PID_DIR)/pidSubscriber.java $(SOURCE_DIR)$(PID_DIR)/pidPublisher.java

CLASS_FILES  = $(JAVA_SOURCES:%.java=%.class)

RTI_CLASSPATH := $(NDDSHOME)/lib/java/nddsjava.jar

#%.class : %.java
#	$(JAVAC_PATH)  -classpath ".:$(RTI_CLASSPATH):/usr/share/java/RXTXcomm.jar" $<

pid%.class : %.java
	$(JAVAC_PATH) -d $(PID_DIR) -classpath ".:$(RTI_CLASSPATH):$(PID_DIR):/usr/share/java/RXTXcomm.jar" $<

height%.class : %.java
	$(JAVAC_PATH) -d $(HEIGHT_DIR) -classpath ".:$(RTI_CLASSPATH):$(HEIGHT_DIR):/usr/share/java/RXTXcomm.jar" $<

imu%.class : %.java
	$(JAVAC_PATH) -d $(IMU_DIR) -classpath ".:$(RTI_CLASSPATH):$(IMU_DIR):/usr/share/java/RXTXcomm.jar" $<
gps%.class : %.java
	$(JAVAC_PATH) -d $(GPS_DIR) -classpath ".:$(RTI_CLASSPATH):$(GPS_DIR):/usr/share/java/RXTXcomm.jar" $<

communicator.class : communicator.java
	$(JAVAC_PATH) -classpath ".:$(RTI_CLASSPATH):$(HEIGHT_DIR):$(IMU_DIR):$(GPS_DIR):$(PID_DIR):/usr/share/java/RXTXcomm.jar" $<

all: $(CLASS_FILES)
 
#
# Convenient way to run the java programs
#

export LD_LIBRARY_PATH := $(NDDSHOME)/lib/armv6vfphLinux3.xgcc4.7.2:/usr/lib/lwp:$(LD_LIBRARY_PATH)

communicator: ./communicator.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH):$(HEIGHT_DIR):$(IMU_DIR):$(GPS_DIR):$(PID_DIR):/usr/share/java/RXTXcomm.jar" communicator $(ARGS)
 
heightSensorSubscriber: ./heightSensorSubscriber.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH)" heightSensorSubscriber $(ARGS)

imuSubscriber: ./imuSubscriber.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH)" imuSubscriber $(ARGS)

pidSubscriber: ./pidSubscriber.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH)" pidSubscriber $(ARGS)
