# openFABMAP #
![http://openfabmap.googlecode.com/files/surf_small.jpg](http://openfabmap.googlecode.com/files/surf_small.jpg)

This is an open and modifiable code-source which implements the Fast Appearance-based Mapping algorithm (FAB-MAP) originally developed by Mark Cummins and Paul Newman.  OpenFABMAP was designed from published FAB-MAP theory and is for personal and research use.

FAB-MAP is a Simultaneous Localisation and Mapping algorithm which operates in appearance space only. FAB-MAP performs location matching between places that have been visited within the world as well as providing a measure of the probability of being at a new, previously unvisited location. Camera images form the sole input to the system, from which bag-of-words models are formed through the extraction of appearance-based (e.g. SURF) features.

The code has implementations of
  * Feature Detection and Extraction and Bag-of-words models using OpenCV
  * Chow-Liu tree implementation
  * FAB-MAP v1.0 ([Cummins & Newman 2008](http://ijr.sagepub.com/content/27/6/647.short))
  * FAB-MAP v1.0 using a Look-up-table for improved computation speed
  * FAB-MAP with Fast-Bailout ([Cummins & Newman 2010](http://ieeexplore.ieee.org/xpls/abs_all.jsp?arnumber=5613942))
  * FAB-MAP v2.0 ([Cummins & Newman 2010](http://ijr.sagepub.com/content/30/9/1100.short))

For an overview of OpenFABMAP see ([Glover et al. 2012](http://eprints.qut.edu.au/50317/1/glover_ICRA2012_final.pdf)). OpenFABMAP was first used in  ([Glover et al. 2010](http://ieeexplore.ieee.org/xpls/abs_all.jsp?arnumber=5509547&tag=1)).

As of the latest version, openFABMAP is dependent solely on [OpenCV 2.3](http://opencv.willowgarage.com/wiki/) or higher. The project is designed to integrate with OpenCV2.3 2D feature-based methods and storage methods.  The project has a [CMake](http://www.cmake.org/) build environment for general use on both Linux and Windows systems. See the README file for more information on compiling the code.

OpenFABMAP is also designed to integrate with [Robot Operating System](http://www.ros.org/wiki/) (ROS). See the [CyPhy-ROS](https://wiki.qut.edu.au/display/cyphy/cyphy+ROS+wiki+page) page for a package that has implemented openFABMAP as a ROS node.

Check out the [wiki](Homepage.md) (under construction) for some instructions and tips on running openFABMAP.

For questions on how to modify the source to your specific implementation, bug reporting, comments and suggestions, or if you would like to become involved in developing the openFABMAP project beyond the current implementation contact via the [google group](http://groups.google.com/group/openfabmap).

_Citations_
[Endnote](http://openfabmap.googlecode.com/files/openFABMAP.enw)
[BibTex](http://openfabmap.googlecode.com/files/openFABMAP.bib)