[Home](Homepage.md)

## Version 2.0 ##

### Version 2.01 ###

  * added openCV's featureDetectorAdaptor as a usable option
  * added compatibility with openCV2.4
  * added filtering frames with low feature counts
  * fixed bug in results file generation

### Version 2.0 ###

  * major upgrade to openCV2.3 interface
  * added FAB-MAP2.0 algorithm
  * added sampling based new location calculation
  * compatible with openCV2.3 feature detectors, descriptor extractors and image descriptor extractors
  * different FAB-MAP algorithms are modular
  * data extraction and running FAB-MAP algorithms now more modular
  * now using yml containers to save all data

## Version 1.0 ##
### Version 1.2 ###

  * included multiple feature detectors available for use. In addition to the openSURF detector users may now use STAR ( based on CenSuRe ) and MSER to detect interest points.
  * major bug fix causing slow processing on Linux machines caused by implementation differences in list.size() between windows and linux.
  * added a nomatchbound to the full FAB-MAP calculation.
  * option to resize images before detection

### Version 1.1 ###

  * modified the build environment. No longer a Visual Studio 2008 project, added C-Make scripts for cross-platform compiling
  * made some minor changes to make cross-platform compatible
  * some minor bug fixes


### Version 1.0 ###

  * initial version of the code implementing feature extraction and viewing, bag-of-words models, and two formats to run the FAB-MAP algorithm. Original FAB-MAP 1.0 (in which every frame is a separate location) and Location Revisiting in which frames are not added if they match to a previous location. The latter also uses fast bail-out to improve matching speeds on large datasets.