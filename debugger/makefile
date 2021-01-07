# If undefined in the environment default NDDSHOME to install dir
ifndef NDDSHOME
NDDSHOME := "/home/pi/rti_connext_dds-6.0.1"
endif

SOURCE_DIR = 

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

CDRSOURCES    = debugger.idl
SOURCES = $(SOURCE_DIR)debuggerPlugin.c $(SOURCE_DIR)debugger.c $(SOURCE_DIR)debuggerSupport.c
COMMONSOURCES = $(notdir $(SOURCES))

EXEC          = debugger_subscriber debugger_publisher
DIRECTORIES   = objs.dir objs/$(TARGET_ARCH).dir
COMMONOBJS    = $(COMMONSOURCES:%.c=objs/$(TARGET_ARCH)/%.o)

# We actually stick the objects in a sub directory to keep your directory clean.
$(TARGET_ARCH) : $(DIRECTORIES) $(COMMONOBJS) \
	$(EXEC:%=objs/$(TARGET_ARCH)/%.o) \
	$(EXEC:%=objs/$(TARGET_ARCH)/%)

objs/$(TARGET_ARCH)/% : objs/$(TARGET_ARCH)/%.o
	$(LINKER) $(LINKER_FLAGS)   -o $@ $@.o $(COMMONOBJS) $(LIBS)

objs/$(TARGET_ARCH)/%.o : $(SOURCE_DIR)%.c   $(SOURCE_DIR)debugger.h 
	$(COMPILER) $(COMPILER_FLAGS)  -o $@ $(DEFINES) $(INCLUDES) -c $<

#
# Uncomment these lines if you want the support files regenerated when idl
# file is modified
#  $(SOURCE_DIR)debuggerPlugin.c $(SOURCE_DIR)debugger.c $(SOURCE_DIR)debuggerSupport.c \
#  $(SOURCE_DIR)debugger.h $(SOURCE_DIR)debuggerPlugin.h $(SOURCE_DIR)debuggerSupport.h : \
#		$(SOURCE_DIR)debugger.idl
#	$(NDDSHOME)/bin/rtiddsgen $(SOURCE_DIR)debugger.idl -replace -language C
#
# Here is how we create those subdirectories automatically.
%.dir : 
	@echo "Checking directory $*"
	@if [ ! -d $* ]; then \
		echo "Making directory $*"; \
		mkdir -p $* ; \
	fi;

