
#-----------------------------------------------------------------------------
# Definitions

DEBUG = false

# compiler
CXX = g++

# directories
BIN_DIR = bin
OBJ_DIR = obj
LIB_DIR = lib
SRC_DIR = datastructures
INC_DIR = datastructures
MAIN_DIR = main

# ROOT and RooFit
ROOTCONFIG   = root-config
ROOTCXXFLAGS = $(shell $(ROOTCONFIG) --cflags)
ROOTLIBS     = $(shell $(ROOTCONFIG) --libs) -lTreePlayer -lTMVA -lMinuit -lXMLIO -lMLP -lRIO -lRooFit -lRooStats

# boost
#BOOST       = $(LCG_external_area)/Boost/1.48.0_python2.6/$(CMTCONFIG)
#BOOST_INC_DIR  = $(LCGBOOST)/include
#BOOST_LIB_OPT  = -L$(LCGBOOST)/lib -lboost_program_options ##-lboost_filesystem -lboost_system##-gcc46-mt-1_48 ##-lboost_system #-gcc46-mt-1_50  
# GSL
#LCGGSL      = $(LCG_external_area)/GSL/1.10/$(CMTCONFIG)
#GSL_INC_DIR = $(LCGGSL)/include
#GSL_LIB_OPT = -L$(LCGGSL)/lib/libgsl.so -lgsl -lgslcblas #-ln
#GSL_LIB_OPT = -L$(LCGGSL)/lib/ -lgsl -lgslcblas #-ln
# libraries and flags
#LIBS = $(ROOTLIBS) $(BOOST_LIB_OPT) $(GSL_LIB_OPT)
INC = -I$(INC_DIR) # -I$(BOOST_INC_DIR) -I$(GSL_INC_DIR)
# do something like 
#  make DEBUG=true
# to activate the debug options
ifeq ($(DEBUG),true)
	CXXFLAGS     = -g -Wall -ggdb -fPIC $(INC)
else
	CXXFLAGS     = -O2 -Wall -fPIC -Xlinker -zdefs $(INC) 
endif

SOFLAGS      = -shared -Wl,-export-dynamic
SHLIB        = $(LIB_DIR)/libPractice.so
SHLIBINC        = -Llib -lPractice


#-----------------------------------------------------------------------------
# Build lists

SRCS=$(filter-out $(wildcard $(SRC_DIR)/_*), $(wildcard $(SRC_DIR)/*.cpp))
OBJS_SRC=$(subst $(SRC_DIR), $(OBJ_DIR), $(subst .cpp,.o,$(SRCS)))

EXES=$(filter-out $(wildcard $(MAIN_DIR)/_*), $(wildcard $(MAIN_DIR)/*.cpp))
OBJS_EXE=$(subst $(MAIN_DIR), $(OBJ_DIR), $(subst .cpp,.o,$(EXES)))
BINS=$(subst $(MAIN_DIR), $(BIN_DIR), $(subst .cpp,,$(EXES)))

#-----------------------------------------------------------------------------
# Main targets
all :  $(SHLIB) $(BINS)
#$(SRCS)  $(OBJS_SRC)
#$(OBJS_EXE) 

# connect classes, namespaces, libraries
$(SRC_DIR)/%.cpp : $(INC_DIR)/%.hpp

# build all objects (classes, namespaces, libraries) i.e. everything in src
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(SHLIB) : $(OBJS_SRC) 
	@echo -e "\nNow building shared object ..."
	$(CXX) $(SOFLAGS) $(CXXFLAGS) $(OBJS_SRC) -o $(SHLIB) $(LIBS)


# make all 'main' actions exectutables into objects
$(OBJ_DIR)/%.o : $(MAIN_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
#
# compile 'main' actions into executables
$(BIN_DIR)/% : $(OBJ_DIR)/%.o 
	$(CXX) $(CXXFLAGS) -o  $@  $^ $(LIBS) $(SHLIBINC)

#-----------------------------------------------------------------------------
# to cleanup
clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*/*.o $(BIN_DIR)/* 
	rm -f $(LIB_DIR)/*
	rm -f $(INC_DIR)/eventdict.*


#-----------------------------------------------------------------------------
# to help debugging makefile problems
info:
	@echo -e "ROOTCXXFLAGS:" $(ROOTCXXFLAGS) "\n"
	@echo -e "ROOTLIBS:" $(ROOTLIBS) "\n"
	@echo -e "BOOST_INC_DIR:" $(BOOST_INC_DIR) "\n"
	@echo -e "BOOST_LIB_OPT:" $(BOOST_LIB_OPT) "\n"
	@echo -e "SRCS:" $(SRCS) "\n"
	@echo -e "OBJS_SRC:" $(OBJS_SRC) "\n\n"
	@echo -e "EXES:" $(EXES) "\n"
	@echo -e "OBJS_EXE:" $(OBJS_EXE) "\n"
	@echo -e "BINS:" $(BINS) "\n\n"
	@echo -e "TESTS:" $(TESTS) "\n"
	@echo -e "OBJS_TST:" $(OBJS_TST) "\n"
	@echo -e "TESTB:" $(TESTB) "\n"
	@echo -e "INCS_CINT:" $(INCS_CINT) "\n"


