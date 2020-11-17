SOURCE_DIR = 
<<<<<<< Updated upstream
=======
HEIGHT_DIR =./heightSensor
IMU_DIR =./imu
>>>>>>> Stashed changes

TARGET_ARCH=armv6vfphLinux3.xgcc4.7.2

# If undefined in the environment default NDDSHOME to install dir
ifndef NDDSHOME
NDDSHOME := /opt/rti_connext_dds-6.0.1
endif

JAVA_PATH = java
JAVAC_PATH = javac

<<<<<<< Updated upstream
JAVA_SOURCES = $(SOURCE_DIR)./heightSensor.java $(SOURCE_DIR)./heightSensorSeq.java $(SOURCE_DIR)./heightSensorTypeSupport.java $(SOURCE_DIR)./heightSensorTypeCode.java $(SOURCE_DIR)./heightSensorDataReader.java $(SOURCE_DIR)./heightSensorDataWriter.java $(SOURCE_DIR)./heightSensorSubscriber.java $(SOURCE_DIR)./communicator.java $(SOURCE_DIR)./JAVADUINO_heightSensor.java $(SOURCE_DIR)./imu.java $(SOURCE_DIR)./imuSeq.java $(SOURCE_DIR)./imuTypeSupport.java $(SOURCE_DIR)./imuTypeCode.java $(SOURCE_DIR)./imuDataReader.java $(SOURCE_DIR)./imuDataWriter.java $(SOURCE_DIR)./imuSubscriber.java $(SOURCE_DIR)./imuPublisher.java
=======
JAVA_SOURCES = $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensoir.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorSeq.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorTypeSupport.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorTypeCode.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorDataReader.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorDataWriter.java $(SOURCE_DIR)$(HEIGHT_DIR)/heightSensorSubscriber.java $(SOURCE_DIR)./communicator.java $(SOURCE_DIR)$(IMU_DIR)/imu.java $(SOURCE_DIR)$(IMU_DIR)/imuSeq.java $(SOURCE_DIR)$(IMU_DIR)/imuTypeSupport.java $(SOURCE_DIR)$(IMU_DIR)/imuTypeCode.java $(SOURCE_DIR)$(IMU_DIR)/imuDataReader.java $(SOURCE_DIR)$(IMU_DIR)/imuDataWriter.java $(SOURCE_DIR)$(IMU_DIR)/imuSubscriber.java $(SOURCE_DIR)$(IMU_DIR)/imuPublisher.java
>>>>>>> Stashed changes

CLASS_FILES  = $(JAVA_SOURCES:%.java=%.class)

RTI_CLASSPATH := $(NDDSHOME)/lib/java/nddsjava.jar

<<<<<<< Updated upstream
%.class : %.java
	$(JAVAC_PATH)  -classpath ".:$(RTI_CLASSPATH):/usr/share/java/RXTXcomm.jar" $<
=======
height%.class : %.java
	$(JAVAC_PATH) -d $(HEIGHT_DIR) -classpath ".:$(RTI_CLASSPATH):$(HEIGHT_DIR):/usr/share/java/RXTXcomm.jar" $<

imu%.class : %.java
	$(JAVAC_PATH) -d $(IMU_DIR) -classpath ".:$(RTI_CLASSPATH):$(IMU_DIR):/usr/share/java/RXTXcomm.jar" $<

comm%.class : %.java
	$(JAVAC_PATH) -classpath ".:$(RTI_CLASSPATH):/usr/share/java/RXTXcomm.jar" $<
>>>>>>> Stashed changes

all: $(CLASS_FILES)
 
#
# Convenient way to run the java programs
#

export LD_LIBRARY_PATH := $(NDDSHOME)/lib/armv6vfphLinux3.xgcc4.7.2:/usr/lib/lwp:$(LD_LIBRARY_PATH)

communicator: ./communicator.class
<<<<<<< Updated upstream
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH):/usr/share/java/RXTXcomm.jar" communicator $(ARGS)
=======
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH):$(HEIGHT_DIR):$(IMU_DIR):/usr/share/java/RXTXcomm.jar" communicator $(ARGS)
>>>>>>> Stashed changes
 
heightSensorSubscriber: ./heightSensorSubscriber.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH)" heightSensorSubscriber $(ARGS)

imuSubscriber: ./imuSubscriber.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH)" imuSubscriber $(ARGS)

