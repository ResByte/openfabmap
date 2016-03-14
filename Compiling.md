[Home](Homepage.md)

# OpenCV2.4 Compatibility #

if using openCV2.4 you will need to replace

`//#define OPENCV2P4` with `#define OPENCV2P4`

at the beggining of openFABMAPcli.cpp

# Compiling openFABMAP #

using CMake

## OpenFABMAP 2.0 ##

Windows (Visual Studio 2008)

  1. install [openCV2.3 or openCV2.4](http://opencv.willowgarage.com/wiki/)
  1. install [cmake](http://www.cmake.org/)
  1. open the cmake gui, specify the source directory (the directory this README is in), a build directory for the code, and click configure
  1. you may have to specify the location of openCV in OPENCV\_PATH.
  1. click configure in the cmake gui again
  1. click generate
  1. open the visual studio solution, for default running right-click on openFABMAPcli project and select 'Set as StartUp project'. Compile openFABMAP within Visual studio.
  1. add required .dll files from openCV2.3 to your build/bin directory (respective debug versions for debug mode).
  1. you also may need an extra tbb .dll which can be downloaded [here](http://threadingbuildingblocks.org/ver.php?fid=171)
  1. under openFABMAPcli->properties->Debugging->command arguments specify the path to the settings file (e.g. "-s samples\settings.yml")
  1. Alter the settings file for your data
  1. openFABMAP should now run within the Visual Studio environment


Linux (g++)

  1. install openCV2.3
  1. get cmake and install it using your package manager
  1. install cmakecurses using your package manager
  1. make a build directory for your generated code
  1. use the command line to change into this directory
  1. run 'cmake /path/to/your/build/dir'
  1. Hopefully openCV was found. If not, you may have to specify the directory manually using ccmake. Try using the wizard option cmake -i.
  1. run 'make' in your build directory
  1. Alter the settings file for your application
  1. run openFABMAPcli in your build/bin directory


## OpenFABMAP 1.2 ##

Windows (Visual Studio 2008)

  1. install openCV2.1 (other dependencies are included in check-out)
  1. install cmake (www.cmake.org/)
  1. open the cmake gui, specify the source directory (the directory this README is in), a build directory for the code and click configure
  1. you may have to specify the location of opencv2.1 in OPENCV\_PATH. It will be "C:\OpenCV2.1" if you installed it in the default location
  1. click configure in the cmake gui again
  1. click generate
  1. open the visual studio solution, for default running right-click on openFABMAPexe project and select 'Set as StartUp project'. Compile openFABMAP within Visual studio.
  1. add cv210.dll, cxcore210.dll and highgui.dll to your build/bin directory (respective debug versions for debug mode).
  1. Alter the settings file for your application
  1. run openFABMAPexe either through visual studio or directly from your build/bin directory (respective debug versions for debug mode).


Linux (g++)

  1. install openCV2.1 (other dependencies are included in check-out)
  1. get cmake and install it using your package manager
  1. install cmakecurses using your package manager
  1. make a build directory for your generated code
  1. use the command line to change into this directory
  1. run 'cmake /path/to/your/build/dir'
  1. If openCV was not found, you may have to specify their directories manually using ccmake. Try using the wizard option cmake -i.
  1. run 'make' in your build directory
  1. Alter the settings file for your application
  1. run openFABMAPexe in your build/bin directory