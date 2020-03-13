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
To build the project, starting in root, run:

```
$ mkdir build
$ cd build
$ cmake ..
 ```

This will generate a gnu make script adapted to your local environment. To run
the makefile and compile one of the targets and then immediately execute the
resulting binary (if successfully compiled), you can run:

```
$ make <target> && ./<target>
```

Where the  available targets are:

| Target  | Purpose                                                      |
|---------|--------------------------------------------------------------|
| Release | The release candidate binary that could be deployed          |
| Debug   | Binary for use during development with debug tooling enabled |
| Tests   | Test runner will all of the unit test suites                 |

## Project structure
(TODO: write more about the module based approach)
- Each module is comprised of (at minimum) a local `src`, `inc` and `test`
  directory where `*.cpp` and `*.h` files reside.
- The local files are built into a static library `module.a` that is then used
  to build the target binaries.
- (TODO: write about what should go in each of the folders?)
- (TODO: write about local CMakeLists.txt files)

## How to: Add a new module
(TODO: write about editing CMakeLists.txt files for adding new modules)

## How to: Add an external library
(TODO: write about how to integrate an externa library into the project)

## Best practice references
(TODO: add some links to the resources that this reference project is based on)
