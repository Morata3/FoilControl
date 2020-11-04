SOURCE_DIR = 

TARGET_ARCH=armv6vfphLinux3.xgcc4.7.2

# If undefined in the environment default NDDSHOME to install dir
ifndef NDDSHOME
NDDSHOME := /opt/rti_connext_dds-6.0.1
endif

JAVA_PATH = java
JAVAC_PATH = javac

JAVA_SOURCES = $(SOURCE_DIR)./heightSensor.java $(SOURCE_DIR)./heightSensorSeq.java $(SOURCE_DIR)./heightSensorTypeSupport.java $(SOURCE_DIR)./heightSensorTypeCode.java $(SOURCE_DIR)./heightSensorDataReader.java $(SOURCE_DIR)./heightSensorDataWriter.java $(SOURCE_DIR)./heightSensorSubscriber.java $(SOURCE_DIR)./communicator.java $(SOURCE_DIR)./JAVADUINO_heightSensor.java $(SOURCE_DIR)./imu.java $(SOURCE_DIR)./imuSeq.java $(SOURCE_DIR)./imuTypeSupport.java $(SOURCE_DIR)./imuTypeCode.java $(SOURCE_DIR)./imuDataReader.java $(SOURCE_DIR)./imuDataWriter.java $(SOURCE_DIR)./imuSubscriber.java $(SOURCE_DIR)./imuPublisher.java

CLASS_FILES  = $(JAVA_SOURCES:%.java=%.class)

RTI_CLASSPATH := $(NDDSHOME)/lib/java/nddsjava.jar

%.class : %.java
	$(JAVAC_PATH)  -classpath ".:$(RTI_CLASSPATH):/usr/share/java/RXTXcomm.jar" $<

all: $(CLASS_FILES)
 
#
# Convenient way to run the java programs
#

export LD_LIBRARY_PATH := $(NDDSHOME)/lib/armv6vfphLinux3.xgcc4.7.2:/usr/lib/lwp:$(LD_LIBRARY_PATH)

communicator: ./communicator.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH):/usr/share/java/RXTXcomm.jar" communicator $(ARGS)
 
heightSensorSubscriber: ./heightSensorSubscriber.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH)" heightSensorSubscriber $(ARGS)

imuSubscriber: ./imuSubscriber.class
	$(JAVA_PATH)  -classpath ".:$(RTI_CLASSPATH)" imuSubscriber $(ARGS)

