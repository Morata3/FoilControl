# If undefined in the environment default NDDSHOME to install dir
ifndef NDDSHOME
NDDSHOME := "/home/pi/rti_connext_dds-6.0.1"
endif

SOURCE_DIR = 
DATA_DIR = ./data/

TARGET_ARCH = armv6vfphLinux3.xgcc4.7.2

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

CDRSOURCES    = dataControl.idl
SOURCES = $(DATA_DIR)dataControlPlugin.c $(DATA_DIR)dataControl.c $(DATA_DIR)dataControlSupport.c $(DATA_DIR)dataControl_publisher.c $(SOURCE_DIR)PID_pitch.c $(SOURCE_DIR)PID_roll.c $(SOURCE_DIR)PID_height.c $(SOURCE_DIR)logger.c
COMMONSOURCES = $(notdir $(SOURCES))

EXEC          = dataControl_subscriber  
DIRECTORIES   = objs.dir objs/$(TARGET_ARCH).dir
COMMONOBJS    = $(COMMONSOURCES:%.c=objs/$(TARGET_ARCH)/%.o)

# We actually stick the objects in a sub directory to keep your directory clean.
$(TARGET_ARCH) : $(DIRECTORIES) $(COMMONOBJS) \
	$(EXEC:%=objs/$(TARGET_ARCH)/%.o) \
	$(EXEC:%=objs/$(TARGET_ARCH)/%)

objs/$(TARGET_ARCH)/% : objs/$(TARGET_ARCH)/%.o
	$(LINKER) $(LINKER_FLAGS)   -o $@ $@.o $(COMMONOBJS) $(LIBS)

objs/$(TARGET_ARCH)/%.o : $(DATA_DIR)%.c  $(DATA_DIR)dataControl.h
	$(COMPILER) $(COMPILER_FLAGS)  -o $@ $(DEFINES) $(INCLUDES) -c $<

objs/$(TARGET_ARCH)/PID%.o : $(SOURCE_DIR)PID%.c $(SOURCE_DIR)PID.h
	$(COMPILER) -o $@ $(DEFINES) -c $<

objs/$(TARGET_ARCH)/logger.o : $(SOURCE_DIR)logger.c $(SOURCE_DIR)logger.h
	$(COMPILER) -o $@ $(DEFINES) -c $<

#
# Uncomment these lines if you want the support files regenerated when idl
# file is modified
#
#
#  $(DATA_DIR)dataControlPlugin.c $(DATA_DIR)dataControl.c $(DATA_DIR)dataControlSupport.c \
#  $(DATA_DIR)dataControl.h $(DATA_DIR)dataControlPlugin.h $(DATA_DIR)dataControlSupport.h : \
#		$(DATA_DIR)dataControl.idl
#	$(NDDSHOME)/bin/rtiddsgen $(DATA_DIR)dataControl.idl -replace -language C
#
# Here is how we create those subdirectories automatically.
%.dir : 
	@echo "Checking directory $*"
	@if [ ! -d $* ]; then \
		echo "Making directory $*"; \
		mkdir -p $* ; \
	fi;

