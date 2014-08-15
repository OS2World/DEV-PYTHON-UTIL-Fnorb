######################################################################
#
# Top-Level Makefile for Building Python Extension Modules for OS/2
#
# This makefile was developed for use with IBM's VisualAge C/C++
# for OS/2 compiler, version 3.0, with Fixpack 8 applied.  It uses
# version 4.0 of the NMAKE tool that comes with that package.
#
# History (Most Recent First)
#
# 26-Mar-99 jrr Original, For Use with Python/2 1.5.2b2
#
######################################################################

###################
# Places and Things
###################
PY_INCLUDE      = ..\..\..\Include;..\..\..\PC\os2vacpp

PY_INCLUDES     = .;$(PY_INCLUDE)

# File to Collect Wordy Compiler Output re Errors
ERRS		= make.out

# Where to Put the .OBJ Files, To Keep Them Out of the Way
PATHOBJ		= obj

# Search Path for Include Files
PROJINCLUDE	= .;$(PY_INCLUDES)

OTHERLIBS	= ..\..\..\PC\os2vacpp\Python15.lib

DYNDIR		= ..\..\..\Lib\lib-dynload

#################
# Inference Rules
#################
.c{$(PATHOBJ)\}.obj:			# Compile C Code into a .OBJ File
	@ Echo Compiling $<
	@ $(CC) -c $(CFLAGS) -Fo$@ $< >>$(ERRS)

##################
# Macros and Flags
##################
_BASE		= /Q /W2 /I$(PROJINCLUDE)
		# /Q   = Omit IBM Copyright
		# /W2  = Show Warnings/Errors Only
		# /W3  = Show All Informationals/Warnings/Errors
		# /Fi  = Create Precompiled Headers
		# /Si  = Utilize Precompiled Headers

_GEN		= /G4 /Gm /Gd- /B"/STACK:360000"
		# /G4  = Generate Code for 486 (Use 386 for Debugger)
		# /Gm  = Use Multithread Runtime
		# /Gd- = Statically Load Runtime
		# /B"/STACK:n" = Set Stack Size

_OPT		= /O /Gl
		# /O   = Enable Speed-Optimizations
		# /Gl  = Have Linker Remove Unused Fns

_DBG		= /Wpro- /Ti- /DHAVE_CONFIG_H
                # /Wall= Generate All Compiler Warnings
                # /Wpro= Generate Compiler Warnings re Missing Prototypes
		# /Ti  = Embed Debugger/Analyzer Recs
		# /DHAVE_CONFIG_H = Causes Use of CONFIG.H Settings

_OUT		= 
		# /Fb  = Embed Browser Recs
		# /Gh  = Generate Code for Profiler Hooks
		# /Fl  = Output C/C++ Listing Files
                # /Lf  = Provide Full (Detailed) Listing Files
		# /Fm. = Output Linker Map File

_MAP		= /FmNoise\$(@R).map

_DLL		= /Ge-
_EXE		= /Ge
		# /Ge = Create an EXE, not DLL

CFLAGS		= $(_BASE) $(_GEN) $(_OPT) $(_DBG) $(_OUT) $(_EXE) /Ss

###################
# Primary Target(s)
###################
All:  obj noise $(DYNDIR)\cdr.pyd $(DYNDIR)\bison.pyd

# Directory to Keep .OBJ Files Out of the Way
obj:
	@-mkdir obj >>NUL

# Directory to Keep .MAP and Such Text Files Out of the Way
noise:
	@-mkdir noise >>NUL

##############
#
##############

$(DYNDIR)\cdr.pyd: $(PATHOBJ)\cdr.obj $(PATHOBJ)\cdrmodule.obj $(PATHOBJ)\longlong.obj cdr.def
	@ Echo Linking $@ As DLL
	@ $(CC) $(CFLAGS) /B"/NOE" $(_DLL) /Fe$@ $(_MAP) $** $(OTHERLIBS) >>$(ERRS)

$(PATHOBJ)\cdr.obj: cdr.c
	@ Echo Compiling $**
	@ $(CC) -c $(CFLAGS) -D__FNORB_LITTLE_ENDIAN $(_DLL) -Fo$@ $** >>$(ERRS)

$(PATHOBJ)\cdrmodule.obj: cdrmodule.c
	@ Echo Compiling $**
	@ $(CC) -c $(CFLAGS) -D__FNORB_LITTLE_ENDIAN $(_DLL) -Fo$@ $** >>$(ERRS)

$(PATHOBJ)\longlong.obj: longlong.c longlong.h
	@ Echo Compiling $**
	@ $(CC) -c $(CFLAGS) -D__FNORB_LITTLE_ENDIAN $(_DLL) -Fo$@ $** >>$(ERRS)


$(DYNDIR)\bison.pyd: $(PATHOBJ)\bisonmodule.obj $(PATHOBJ)\grammar.obj $(PATHOBJ)\lexer.obj bison.def
	@ Echo Linking $@ As DLL
	@ $(CC) $(CFLAGS) /B"/NOE" $(_DLL) /Fe$@ $(_MAP) $** $(OTHERLIBS) >>$(ERRS)

$(PATHOBJ)\bisonmodule.obj: bisonmodule.c
	@ Echo Compiling $**
	@ $(CC) -c $(CFLAGS) $(_DLL) -Fo$@ $** >>$(ERRS)

$(PATHOBJ)\grammar.obj: grammar.c
	@ Echo Compiling $**
	@ $(CC) -c $(CFLAGS) $(_DLL) -Fo$@ $** >>$(ERRS)

$(PATHOBJ)\lexer.obj: lexer.c
	@ Echo Compiling $**
	@ $(CC) -c $(CFLAGS) $(_DLL) -Fo$@ $** >>$(ERRS)

#######################
# Miscellaneous Targets
#######################

# Remove Intermediate Targets but Leave Executable Binaries
clean:
	-- Del /Q $(PATHOBJ)\*.obj		>NUL 2>&1
	-- Del /Q /Y Noise			>NUL 2>&1
	-- Del /Q $(ERRS)			>NUL 2>&1

bins:   All fnb101.zip fns101.zip fnd101.zip

binpkg: fnb101.zip
srcpkg: fns101.zip
docpkg: fnd101.zip

# Binaries Package
fnb101.zip: $(DYNDIR)\cdr.pyd $(DYNDIR)\bison.pyd
	cd ..\..\..
	-- Del /Q    $@ >NUL 2>&1
        zip -r -9    $@ Lib\site-packages\Fnorb
        zip -r -9    $@ Lib\lib-dynload\cdr.pyd Lib\lib-dynload\bison.pyd
        zip    -9    $@ fn*.cmd
        zip    -9    $@ Add-Ons\Fnorb\ANNOUNCE
        zip    -9    $@ Add-Ons\Fnorb\CHANGES
        zip    -9    $@ Add-Ons\Fnorb\LICENSE.HTML
        zip    -9    $@ Add-Ons\Fnorb\README
	cd Add-Ons\Fnorb\src

# Source Code Package
fns101.zip:
	cd ..\..\..
	-- Del /Q    $@ >NUL 2>&1
        zip -r -9    $@ Add-Ons\Fnorb\src -x *.obj -x *.map -x *.exe -x *.dll -x *.lib -x make.out
        zip    -9    $@ Add-Ons\Fnorb\ANNOUNCE
        zip    -9    $@ Add-Ons\Fnorb\CHANGES
        zip    -9    $@ Add-Ons\Fnorb\LICENSE.HTML
        zip    -9    $@ Add-Ons\Fnorb\README
	cd Add-Ons\Fnorb\src

# Documentation Package
fnd101.zip:
	cd ..\..\..
	-- Del /Q    $@ >NUL 2>&1
        zip -r -9    $@ Add-Ons\Fnorb\examples
        zip    -9    $@ Add-Ons\Fnorb\Fnorb-Guide.*
	cd Add-Ons\Fnorb\src

