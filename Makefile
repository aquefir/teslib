##############################################################################
##                                 Library1                                 ##
##                                                                          ##
##                        Copyright © 20XX Acme Inc.                        ##
##                       Released under BSD-2-Clause.                       ##
##############################################################################

include etc/base.mk

PROJECT := tes

# put a ‘1’ for the desired target types to compile
SOFILE :=
AFILE  := 1

# space-separated path list for #includes
# <system> includes
INCLUDES := include
# "local" includes
INCLUDEL := src

# space-separated library name list
LIBS      :=
LIBDIRS   :=

# frameworks (macOS target only)
FWORKS :=

# ‘3P’ are in-tree 3rd-party dependencies
# 3PLIBDIR is the base directory
# 3PLIBS is the folder names in the base directory for each library
3PLIBDIR := 3rdparty
3PLIBS   :=

# sources
CFILES   := \
	src/tes.c
HFILES   := \
	include/tes/battery.h \
	include/tes/program.h \
	src/tes.h
CPPFILES :=
HPPFILES :=

NO_TES := 1

# this defines all our usual targets
include etc/targets.mk
