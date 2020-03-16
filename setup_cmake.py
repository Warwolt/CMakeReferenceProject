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
os.system("mkdir -p build/release")
os.system("mkdir -p build/debug")
os.chdir("build/release")
os.system("cmake -G \"Unix Makefiles\" -DCMAKE_BUILD_TYPE=Release ../..")
os.chdir("../debug")
os.system("cmake -G \"Unix Makefiles\" -DCMAKE_BUILD_TYPE=Debug ../..")
