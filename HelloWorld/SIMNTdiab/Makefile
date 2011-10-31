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
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/HelloWorld



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
PROJECT_TARGETS = HelloWorld/$(MODE_DIR)/HelloWorld.out \
	 HelloWorld_partialImage/$(MODE_DIR)/HelloWorld_partialImage.o


#Rules

# HelloWorld
ifeq ($(DEBUG_MODE),1)
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
HelloWorld/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
HelloWorld/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
HelloWorld/$(MODE_DIR)/% : IDE_LIBRARIES = 
HelloWorld/$(MODE_DIR)/% : PROJECT_TYPE = DKM
HelloWorld/$(MODE_DIR)/% : DEFINES = 
HelloWorld/$(MODE_DIR)/% : EXPAND_DBG = 0
HelloWorld/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
HelloWorld/$(MODE_DIR)/% : CPU = SIMNT
HelloWorld/$(MODE_DIR)/% : TOOL_FAMILY = diab
HelloWorld/$(MODE_DIR)/% : TOOL = diab
HelloWorld/$(MODE_DIR)/% : TOOL_PATH = 
HelloWorld/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks67
HelloWorld/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
HelloWorld/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
HelloWorld/$(MODE_DIR)/% : LIBPATH = 
HelloWorld/$(MODE_DIR)/% : LIBS = 
HelloWorld/$(MODE_DIR)/% : OBJ_DIR := HelloWorld/$(MODE_DIR)

OBJECTS_HelloWorld = HelloWorld_partialImage/$(MODE_DIR)/HelloWorld_partialImage.o

HelloWorld/$(MODE_DIR)/HelloWorld.out : $(OBJECTS_HelloWorld)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_HelloWorld) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks67 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_HelloWorld) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

HelloWorld/$(MODE_DIR)/HelloWorld_compile_file : $(FILE) ;

_clean :: HelloWorld/$(MODE_DIR)/HelloWorld_clean

HelloWorld/$(MODE_DIR)/HelloWorld_clean : 
	$(TRACE_FLAG)if [ -d "HelloWorld" ]; then cd "HelloWorld"; rm -rf $(MODE_DIR); fi


# HelloWorld_partialImage
ifeq ($(DEBUG_MODE),1)
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
HelloWorld_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
HelloWorld_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
HelloWorld_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
HelloWorld_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
HelloWorld_partialImage/$(MODE_DIR)/% : DEFINES = 
HelloWorld_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
HelloWorld_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
HelloWorld_partialImage/$(MODE_DIR)/% : CPU = SIMNT
HelloWorld_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
HelloWorld_partialImage/$(MODE_DIR)/% : TOOL = diab
HelloWorld_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
HelloWorld_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks67
HelloWorld_partialImage/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
HelloWorld_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
HelloWorld_partialImage/$(MODE_DIR)/% : LIBPATH = 
HelloWorld_partialImage/$(MODE_DIR)/% : LIBS = 
HelloWorld_partialImage/$(MODE_DIR)/% : OBJ_DIR := HelloWorld_partialImage/$(MODE_DIR)

HelloWorld_partialImage/$(MODE_DIR)/Objects/HelloWorld/HelloWorld.o : $(PRJ_ROOT_DIR)/HelloWorld.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL  -D_VSB_CONFIG_FILE=\"$(VSB_CONFIG_FILE)\"   $(DEFINES) -o "$@" -c "$<"


OBJECTS_HelloWorld_partialImage = HelloWorld_partialImage/$(MODE_DIR)/Objects/HelloWorld/HelloWorld.o

HelloWorld_partialImage/$(MODE_DIR)/HelloWorld_partialImage.o : $(OBJECTS_HelloWorld_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks67 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_HelloWorld_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

HelloWorld_partialImage/$(MODE_DIR)/HelloWorld_partialImage_compile_file : $(FILE) ;

_clean :: HelloWorld_partialImage/$(MODE_DIR)/HelloWorld_partialImage_clean

HelloWorld_partialImage/$(MODE_DIR)/HelloWorld_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "HelloWorld_partialImage" ]; then cd "HelloWorld_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := HelloWorld_partialImage/$(MODE_DIR)/Objects/HelloWorld/HelloWorld.d
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
