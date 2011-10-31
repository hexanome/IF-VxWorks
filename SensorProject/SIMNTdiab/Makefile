# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = SIMNTdiab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := Y:/IF/VxWorks
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/SensorProject



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simpc
CPU = SIMNT
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:vxworks67
VSB_DIR = $(WIND_BASE)/target/lib
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = SensorProject/$(MODE_DIR)/SensorProject.out \
	 SensorProject_partialImage/$(MODE_DIR)/SensorProject_partialImage.o


#Rules

# SensorProject
ifeq ($(DEBUG_MODE),1)
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SensorProject/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
SensorProject/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
SensorProject/$(MODE_DIR)/% : IDE_LIBRARIES = 
SensorProject/$(MODE_DIR)/% : PROJECT_TYPE = DKM
SensorProject/$(MODE_DIR)/% : DEFINES = 
SensorProject/$(MODE_DIR)/% : EXPAND_DBG = 0
SensorProject/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
SensorProject/$(MODE_DIR)/% : CPU = SIMNT
SensorProject/$(MODE_DIR)/% : TOOL_FAMILY = diab
SensorProject/$(MODE_DIR)/% : TOOL = diab
SensorProject/$(MODE_DIR)/% : TOOL_PATH = 
SensorProject/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks67
SensorProject/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
SensorProject/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
SensorProject/$(MODE_DIR)/% : LIBPATH = 
SensorProject/$(MODE_DIR)/% : LIBS = 
SensorProject/$(MODE_DIR)/% : OBJ_DIR := SensorProject/$(MODE_DIR)

OBJECTS_SensorProject = SensorProject_partialImage/$(MODE_DIR)/SensorProject_partialImage.o

SensorProject/$(MODE_DIR)/SensorProject.out : $(OBJECTS_SensorProject)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_SensorProject) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks67 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_SensorProject) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

SensorProject/$(MODE_DIR)/SensorProject_compile_file : $(FILE) ;

_clean :: SensorProject/$(MODE_DIR)/SensorProject_clean

SensorProject/$(MODE_DIR)/SensorProject_clean : 
	$(TRACE_FLAG)if [ -d "SensorProject" ]; then cd "SensorProject"; rm -rf $(MODE_DIR); fi


# SensorProject_partialImage
ifeq ($(DEBUG_MODE),1)
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SensorProject_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
SensorProject_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
SensorProject_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
SensorProject_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
SensorProject_partialImage/$(MODE_DIR)/% : DEFINES = 
SensorProject_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
SensorProject_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
SensorProject_partialImage/$(MODE_DIR)/% : CPU = SIMNT
SensorProject_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
SensorProject_partialImage/$(MODE_DIR)/% : TOOL = diab
SensorProject_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
SensorProject_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks67
SensorProject_partialImage/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
SensorProject_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
SensorProject_partialImage/$(MODE_DIR)/% : LIBPATH = 
SensorProject_partialImage/$(MODE_DIR)/% : LIBS = 
SensorProject_partialImage/$(MODE_DIR)/% : OBJ_DIR := SensorProject_partialImage/$(MODE_DIR)

SensorProject_partialImage/$(MODE_DIR)/Objects/SensorProject/sensorApplication/TestApplication.o : $(PRJ_ROOT_DIR)/sensorApplication/TestApplication.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


SensorProject_partialImage/$(MODE_DIR)/Objects/SensorProject/sensorDevice/sensorDevice.o : $(PRJ_ROOT_DIR)/sensorDevice/sensorDevice.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


SensorProject_partialImage/$(MODE_DIR)/Objects/SensorProject/sensorDriver/sensorDriver.o : $(PRJ_ROOT_DIR)/sensorDriver/sensorDriver.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


OBJECTS_SensorProject_partialImage = SensorProject_partialImage/$(MODE_DIR)/Objects/SensorProject/sensorApplication/TestApplication.o \
	 SensorProject_partialImage/$(MODE_DIR)/Objects/SensorProject/sensorDevice/sensorDevice.o \
	 SensorProject_partialImage/$(MODE_DIR)/Objects/SensorProject/sensorDriver/sensorDriver.o

SensorProject_partialImage/$(MODE_DIR)/SensorProject_partialImage.o : $(OBJECTS_SensorProject_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks67 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_SensorProject_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

SensorProject_partialImage/$(MODE_DIR)/SensorProject_partialImage_compile_file : $(FILE) ;

_clean :: SensorProject_partialImage/$(MODE_DIR)/SensorProject_partialImage_clean

SensorProject_partialImage/$(MODE_DIR)/SensorProject_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "SensorProject_partialImage" ]; then cd "SensorProject_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := SensorProject_partialImage/$(MODE_DIR)/Objects/SensorProject/sensorApplication/TestApplication.d SensorProject_partialImage/$(MODE_DIR)/Objects/SensorProject/sensorDevice/sensorDevice.d SensorProject_partialImage/$(MODE_DIR)/Objects/SensorProject/sensorDriver/sensorDriver.d
-include $(DEP_FILES)


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))

clean_scopetools :
	$(TRACE_FLAG)rm -rf $(PRJ_ROOT_DIR)/.coveragescope/db

CLEAN_STEP := clean_scopetools


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
