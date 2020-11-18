# If undefined in the environment default NDDSHOME to install dir
ifndef NDDSHOME
NDDSHOME := "/home/pi/rti_connext_dds-6.0.1"
endif

SOURCE_DIR =
HEIGHT_DIR =../pid/heightSensor/

TARGET_ARCH = armv6vfphLinux3.xgcc4.7.2
TARGET_HEIGHT = height

ifndef COMPILER
COMPILER = arm-linux-gnueabihf-gcc
endif
COMPILER_FLAGS =
ifndef LINKER
LINKER = arm-linux-gnueabihf-gcc
endif
LINKER_FLAGS =
SYSLIBS = -ldl -lnsl -lm -lpthread -lrt
DEFINES = -fpic -DRTI_UNIX -DRTI_LINUX -march=armv6 -mfpu=vfp -mfloat-abi=hard -mlong-calls 
ifndef DEBUG
DEBUG=0 
endif
ifeq ($(DEBUG),1)
COMPILER_FLAGS += -g -O0
LINKER_FLAGS += -g
DEBUG_SFX = d
else
DEBUG_SFX = 
endif
 
ifndef SHAREDLIB
SHAREDLIB=0
endif

ifeq ($(SHAREDLIB),1)
SHAREDLIB_SFX = 
else
SHAREDLIB_SFX = z
DEFINES += -DRTI_STATIC
endif



INCLUDES = -I. -I$(NDDSHOME)/include -I$(NDDSHOME)/include/ndds 
       
LIBS = -L$(NDDSHOME)/lib/$(TARGET_ARCH) \
        \
        \
        -lnddsc$(SHAREDLIB_SFX)$(DEBUG_SFX) -lnddscore$(SHAREDLIB_SFX)$(DEBUG_SFX) \
        $(SYSLIBS)

SOURCES_HEIGHT = $(HEIGHT_DIR)heightSensorPlugin.c $(HEIGHT_DIR)heightSensor.c $(HEIGHT_DIR)heightSensorSupport.c $(SOURCE_DIR)PID_height.c 

COMMONSOURCES_HEIGHT = $(notdir $(SOURCES_HEIGHT))

EXEC_HEIGHT       = heightSensor_subscriber heightSensor_publisher

DIRECTORIES_HEIGHT = objs.dir objs/$(TARGET_ARCH).dir objs/$(TARGET_ARCH)/$(TARGET_HEIGHT).dir

COMMONOBJS_HEIGHT    = $(COMMONSOURCES_HEIGHT:%.c=objs/$(TARGET_ARCH)/$(TARGET_HEIGHT)/%.o)

# We actually stick the objects in a sub directory to keep your directory clean.
$(TARGET_ARCH) : $(DIRECTORIES_HEIGHT) $(COMMONOBJS_HEIGHT)\
	$(EXEC_HEIGHT:%=objs/$(TARGET_ARCH)/$(TARGET_HEIGHT)/%.o) \
	$(EXEC_HEIGHT:%=objs/$(TARGET_ARCH)/$(TARGET_HEIGHT)/%)

objs/$(TARGET_ARCH)/$(TARGET_HEIGHT)/% : objs/$(TARGET_ARCH)/$(TARGET_HEIGHT)/%.o
	$(LINKER) $(LINKER_FLAGS)   -o $@ $@.o $(COMMONOBJS_HEIGHT) $(LIBS)

objs/$(TARGET_ARCH)/$(TARGET_HEIGHT)/%.o : $(HEIGHT_DIR)%.c   $(HEIGHT_DIR)heightSensor.h 
	$(COMPILER) $(COMPILER_FLAGS)  -o $@ $(DEFINES) $(INCLUDES) -c $<


