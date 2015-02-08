# Noire, an Imgur desktop client.
# Copyright (c) 2015 Jeremy Othieno.
#
# This file is part of Noire.
#
# Noire is free software: you can redistribute it and/or modify it under the terms
# of the GNU General Public License as published by the Free Software Foundation,
# either version 3 of the License, or (at your option) any later version.
#
# Noire is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
# PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with Noire.
# If not, see <http://www.gnu.org/licenses/>.

CLIENT                  = Noire

TARGET                  = noire
TESTSUITE               = $(TARGET)-testsuite
BENCHMARK               = $(TARGET)-benchmark

SRC_DIR                 = src
BUILD_DIR               = build

TARGET_PRO              = $(TARGET).pro
TARGET_MAKEFILE         = $(BUILD_DIR)/Makefile.$(TARGET)

TESTSUITE_DIR           = test/unit
TESTSUITE_PRO           = $(TESTSUITE_DIR)/unit.pro
TESTSUITE_MAKEFILE      = $(BUILD_DIR)/Makefile.$(TESTSUITE)

BENCHMARK_DIR           = test/benchmark
BENCHMARK_PRO           = $(BENCHMARK_DIR)/benchmark.pro
BENCHMARK_MAKEFILE      = $(BUILD_DIR)/Makefile.$(BENCHMARK)

.PHONY: client tests benchmarks all run run-tests run-benchmarks format clean help

client     : $(TARGET_MAKEFILE)
tests      : $(TESTSUITE_MAKEFILE) client
benchmarks : $(BENCHMARK_MAKEFILE) client

client tests benchmarks:
	@$(MAKE) --directory $(BUILD_DIR) --file $(notdir $<) -$(MAKEFLAGS)

all: client tests benchmarks

run: client
	@$(BUILD_DIR)/$(TARGET)

run-tests: tests
	@$(BUILD_DIR)/$(TESTSUITE)

run-benchmarks: benchmarks
	@$(BUILD_DIR)/$(BENCHMARK)

format:
	@echo TODO

clean:
	@rm -rf $(BUILD_DIR)

help:
	@echo "Available targets:"
	@echo "  client            Build the $(CLIENT) client."
	@echo "  tests             Build the $(CLIENT) unit test suite."
	@echo "  benchmarks        Build the $(CLIENT) benchmark suite."
	@echo "  all               Build the $(CLIENT) client, as well as the unit test and benchmark suites."
	@echo "  run               Build and execute the $(CLIENT) client."
	@echo "  run-tests         Build and execute the $(CLIENT) unit test suite."
	@echo "  run-benchmarks    Build and execute the $(CLIENT) benchmark suite."
	@echo "  format            Format the project's codebase."
	@echo "  clean             Delete built project files."
	@echo "  help              Print this help page."
	@echo

$(TARGET_MAKEFILE)         : $(TARGET_PRO)
$(TESTSUITE_MAKEFILE)      : $(TESTSUITE_PRO)
$(BENCHMARK_MAKEFILE)      : $(BENCHMARK_PRO)

$(TARGET_MAKEFILE) $(TESTSUITE_MAKEFILE) $(BENCHMARK_MAKEFILE):
	@mkdir -p $(BUILD_DIR)
	@qtchooser -qt=5 -run-tool=qmake -makefile -Wall $< -o $@
