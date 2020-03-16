# CMake Reference Project
This is a reference project structure for C++ codebases using CMake as the
primary build tool. It was created as a way for me (Rasmus) to learn CMake and
to make preparations for a professional coding project, that was to use this as
a possible organizational starting point.

Some of the design goals for this reference project:
- Support for multiple targets (Release, Debug, Tests)
- Out of the box ready to be built on both Windows, MacOS and Linux
- Module based directory structure with local `src`, `inc` and `test` folders

## Table of Content
- [CMake Reference Project](#cmake-reference-project)
  - [Table of Content](#table-of-content)
  - [Building the project](#building-the-project)
  - [Project structure](#project-structure)
  - [How to: Add a new module](#how-to-add-a-new-module)
  - [How to: Add an external library](#how-to-add-an-external-library)
  - [Best practice references](#best-practice-references)

## Building the project
This project forces out-of-source compilation, which means that the CMake
script should not be ran from the project root, but rather in a build folder.
To build the project the first time, use the helper script `setup_make.py`
(requires Python3).

Linux/MacOS:
```
./setup_make.py
 ```

Windows:
```
setup_make.py
```

This will generate GNU Make scripts adapted to your local environment, one for
the Release build (`build/release`) and one for the Debug build (`build/debug`).
To run the makefiles and compile one of the targets and then immediately
execute the resulting binary (if successfully compiled), navigate to either
the `release` or the `debug` directory and run:

Linux/MacOS:
```
make <target> && ./<target>
```

Windows:
```
make <target> && <target>.exe
```

Where the  available targets are:

| Target | Purpose                                      |
|--------|----------------------------------------------|
| app    | The project application                      |
| tests  | Test runner will all of the unit test suites |

## Project structure
This project is module based, where a module can be described as a grouping of
code with a clear responsibility and a public interface. The modules all have
local `inc`, `src` and `test` folders that contains the header files, source
files and unit test files respectively, and a local `CMakeLists.txt` file that
specifies how to build the module.

**The name of a module is the same as the module directory name!**

This convention is followed in some of the automation in the project `.cmake`
helper scripts and need to be followed by developers.

Each module `foo` is compiled into a static library `libfoo.a` for production
code and `libfoo_test.a` for unit test code. These libraries are the used to
link together the targets.

The `app` target uses `main.cpp` as its entry point, and the `test` target uses
`test_main.cpp` to call into Google Test.

An illustration of how the project structure is:

```
.
├── CMakeLists.txt
├── build
│   ├── debug
|   |   └── ...
│   └── release
|       └── ...
├── software
│   ├── CMakeLists.txt
│   ├── foo
│   │   ├── CMakeLists.txt
│   │   ├── inc
│   │   │   ├── foo1.h
│   │   │   └── foo2.h
│   │   ├── src
│   │   │   ├── foo1.cpp
│   │   │   └── foo2.cpp
│   │   └── test
│   │       ├── foo1_test.cpp
│   │       └── foo2_test.cpp
│   ├── bar
│   │   ├── CMakeLists.txt
│   │   ├── inc
│   │   │   └── bar.h
│   │   ├── src
│   │   │   └── bar.cpp
│   │   └── test
│   │       └── bar_test.cpp
│   ├── main.cpp
│   └── test_main.cpp
└── thirdparty
    └── extlib
        ├── CMakeLists.txt
        └── include
            └── extlib.h

```

## How to: Add a new module
When you have new code that you want to add to the project that doesn't fit
into any existing module, you should create a new one. To create a new
module `example` you would:

- Create a new directory `example`
- Create a `CMakeLists.txt` file in the directory (see reference below)
  - Add a `add_module_library` call for the module-library and the
    test-library
  - Use the keyword `MODULE` to add a module-library (production code), and
    `TEST` for the unit tests.
  - When adding the module-library, list all files the the `src` directory
    after the `SOURCE` keyword. When adding the test-library, list all files in
    the `test` directory.
  - If the added module needs to call into functions in other modules, you must
    list the names of those modules after the `MODULE_DEPS` keyword.
- Add the subdirectories `inc`, `src` and `test` and adding your new source,
  header and test files there.
- Modify the `CMakeLists.txt` file in the `software` directory with an
  inclusion of your module i.e. adding the module name to the MODULE variable.

Module CMakeLists.txt file example:

```CMake
cmake_minimum_required(VERSION 3.16)
include(${CMAKE_SOURCE_DIR}/scripts/cmake/module_util.cmake)
project(YourModuleName)

add_module_library(MODULE
    SOURCES
    foo.cpp
    bar.cpp

    MODULE_DEPS
    other_module1
    other_module2
)

add_module_library(TEST
    SOURCES
    foo_test.cpp
    bar_test.cpp

    MODULE_DEPS
    other_module1
)
```

The helper macro `add_module_library` wraps up some other function calls
so that each module file doesn't repeat anything shared between modules.
It has the following API:

```
Brief: Wrapper to add_library() for module libraries

This macro acts as a wrapper for declaring a library target for a local
module, and for the module unit tests.

- MODULE:  Flag for adding module source library
- TEST:    Flag for adding module unit tests library
- SOURCES: A list of all source files names (e.g. foo.cpp bar.cpp)
- MODULE_DEPS: List of other modules that this module depends
```

## How to: Add an external library
(TODO: write about how to integrate an externa library into the project)

## Best practice references
Here are some links to resources that were used to inform the decisions made
when creating this reference project:
- [CMakePrimer](https://llvm.org/docs/CMakePrimer.html)
- [GoogleTest readme](https://github.com/google/googletest/blob/master/googletest/README.md)
- [Modern CMake](https://cliutils.gitlab.io/modern-cmake/)
- [Gtest demo project by Bast](https://github.com/bast/gtest-demo)
