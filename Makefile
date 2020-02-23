##############################################################################
##                          Test Engineering Suite                          ##
##                                                                          ##
##                    Copyright © 2019-2020 ARQADIUM LLC                    ##
##                       Released under BSD-2-Clause.                       ##
##############################################################################

include base.mk

PROJECT := tes
EXEFILE :=
SOFILE  :=
AFILE   := 1

# <system> includes
INCLUDES := include
# "local" includes
INCLUDEL := src

# libraries
LIBS      :=
LIBDIRS   :=

# frameworks (macOS only)
FWORKS :=

CFILES    := \
	src/main.c \
	src/tes.c
HFILES    := \
	include/tes/battery.h \
	include/tes/program.h \
	src/tes.h
CPPFILES  :=
HPPFILES  :=
OFILES    := $(CFILES:.c=.c.o) $(CPPFILES:.cpp=.cpp.o)
# address-sanitisation metadata
GCNOFILES := $(CFILES:.c=.c.gcno) $(CPPFILES:.cpp=.cpp.gcno)
GCDAFILES := $(CFILES:.c=.c.gcda) $(CPPFILES:.cpp=.cpp.gcda)

# this defines all our usual targets
include targets.mk
