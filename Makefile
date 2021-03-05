##############################################################################
##                          Test Engineering Suite                          ##
##                                                                          ##
##                      Copyright © 2019-2020 Aquefir.                      ##
##                       Released under BSD-2-Clause.                       ##
##############################################################################

ifeq ($(strip $(AQ)),)
$(error "AQ was not found in your environment. You need to install the Slick Makefiles from github.com/aquefir/slick to continue.")
endif

include $(AQ)/lib/slick/base.mk

PROJECT := tes

# put a ‘1’ for the desired target types to compile
SOFILE := 1
AFILE  :=

# space-separated path list for #includes
# <system> includes
INCLUDES := include
# "local" includes
INCLUDEL := src

# space-separated library name list
LIBS    :=
LIBDIRS :=

# frameworks (macOS target only)
FWORKS :=

# ‘3P’ are in-tree 3rd-party dependencies
# 3PLIBDIR is the base directory
# 3PLIBS is the folder names in the base directory for each library
3PLIBDIR :=
3PLIBS   :=

# sources
CFILES    := \
	src/tes.c
PUBHFILES := \
	include/tes/battery.h \
	include/tes/program.h
CPPFILES  :=
PRVHFILES := \
	src/tes.h

NO_TES := 1
PREFIX := $(AQ)

# this defines all our usual targets
include $(AQ)/lib/slick/targets.mk
