#!/usr/bin/env python3
'''
This file acts as a setup script for the build environment as a shortcut for
having to call cmake with specific flags.
'''

import os
import subprocess
import sys

# Setup environment variables
os.environ['CC'] = "clang"
os.environ['CXX'] = "clang++"

# Create build directory and run cmake
os.system("mkdir -p build")
os.chdir("build")
os.system("cmake -G \"Unix Makefiles\" ..") # We want a 'Makefile' as output
