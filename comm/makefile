SOURCE_DIR = 
DATA_DIR =./data/

TARGET_ARCH=armv6vfphLinux3.xgcc4.7.2

# If undefined in the environment default NDDSHOME to install dir
ifndef NDDSHOME
NDDSHOME := /home/pi/rti_connext_dds-6.0.1
endif

JAVA_PATH = java
JAVAC_PATH = javac

JAVA_SOURCES = $(SOURCE_DIR)./communicator.java $(DATA_DIR)./comm.java $(DATA_DIR)./commSeq.java $(DATA_DIR)./commTypeSupport.java $(DATA_DIR)./commTypeCode.java $(DATA_DIR)./commDataReader.java $(DATA_DIR)./commDataWriter.java $(DATA_DIR)./commSubscriber.java $(DATA_DIR)./commPublisher.java
CLASS_FILES  = $(JAVA_SOURCES:%.java=%.class)

RTI_CLASSPATH := $(NDDSHOME)/lib/java/nddsjava.jar
RXTX_LIB := /usr/share/java/RXTXcomm.jar

%.class : %.java
	$(JAVAC_PATH)  -classpath ".:$(RTI_CLASSPATH):$(DATA_DIR):$(RXTX_LIB)" $<

all: $(CLASS_FILES)

#Clean classes to rebuild
clean:
	$(RM) $(CLASS_FILES)
 
#
# Convenient way to run the java programs
#

export LD_LIBRARY_PATH := $(NDDSHOME)/lib/armv6vfphLinux3.xgcc4.7.2:/usr/lib/lwp:$(LD_LIBRARY_PATH)

communicator: ./communicator.class

	$(JAVA_PATH) -classpath ".:$(RTI_CLASSPATH):$(DATA_DIR):$(RXTX_LIB)" communicator $(ARGS)

