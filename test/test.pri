# This include file must be prepended to unit.pro and benchmark.pro, and NOT appended.

# Include the project file to get the current source code tree configuration.
!include(../noire.pro): error(Could not locate the source project file.)

# Add the testlib module.
QT += testlib

# Remove noire.cpp since it will create an entry point conflict (two main functions).
SOURCES -= src/noire.cpp

# Remove files that are not pertinent to the testing process.
FORMS =
RESOURCES =

# Prefix the include path directories, as well as the header and source files.
# TODO Find out if this can be done faster with the ~= operator and regular expressions.
paths       = $$INCLUDEPATH
headers     = $$HEADERS
sources     = $$SOURCES

# Empty the variables before modifying them.
INCLUDEPATH =
HEADERS     =
SOURCES     =

for (path, paths):     INCLUDEPATH += ../$$path
for (header, headers): HEADERS += ../$$header
for (source, sources): SOURCES += ../$$source
