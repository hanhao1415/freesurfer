## 
## Makefile.am 
##

AM_CFLAGS=-I$(top_srcdir)/include
AM_LDFLAGS=

bin_PROGRAMS = mris_jacobian

mris_jacobian_SOURCES=mris_jacobian.c mris_jacobian.help.xml.h
mris_jacobian_LDADD= $(addprefix $(top_builddir)/, $(LIBS_MGH))
mris_jacobian_LDFLAGS=$(OS_LDFLAGS)

foodir=$(prefix)/docs/xml
foo_DATA=mris_jacobian.help.xml
foo2dir=$(prefix)/docs/html
foo2_DATA=mris_jacobian.help.xml.html

TESTS=$(top_builddir)/scripts/help_xml_validate

clean-local:
	rm -f $(BUILT_SOURCES) 

EXTRA_DIST=$(foo_DATA) $(BUILT_SOURCES)

# Our release target. Include files to be excluded here. They will be
# found and removed after 'make install' is run during the 'make
# release' target.
EXCLUDE_FILES=""
include $(top_srcdir)/Makefile.extra

BUILT_SOURCES=mris_jacobian.help.xml.h mris_jacobian.help.xml.html

