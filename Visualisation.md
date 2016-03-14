[Home](Homepage.md)

# openFABMAP1.2 Visualisation #

## Feature Detection (v1.2) ##

_How-to?_

  1. specify the dataset video in the settings file VIDEO parameter.
  1. specify the feature detection type in the DETECT\_MODE parameter. Also specify the corresponding detectors properties.
  1. set the (rough) viewing frames per second using the VW\_FPS parameter.
  1. set the FUNCTION parameter to 1
  1. run openFABMAPexe

_Tips_

Visual features form the input to the openFABMAP algorithm. The results you get from running the program will depend on the quality of the input. It is worthwhile to ensure the that there are a good number of features detected in each frame and that they are detected at reasonable locations and scales. A 'good' number of features will depend on application and codebook size. Cummins & Newman IJRR 2008 detected approximately ~100-200 features for a ~10 000 word codebook.

There are three different interest point detectors currently available in openFABMAP(when v1.2 goes up). There are also many parameters for each detector that will determine the detection performance. The parameters and some understanding of the affect of each are summarised below. The SURF descriptor is calculated irrespective of which interest point detector is used. The descriptor can be set to upright or rotation invariant for each descriptor.

These parameters can be adjusted in the settings file.

### openSURF ###

The openSURF descriptor by Chris Evans is used to calculate interest points as well as form descriptors of the region. The OpenCV SURF implementation is not used as it crashes when no interest points can be detected (in version 2.1).

  * **octaves** -
  * **intervals** -
  * **initial** -
  * **threshold** -

### STAR ###

The OpenCV STAR descriptor is based on the 'CenSuRe' interest point. It was found that the STAR interest points were more stable than SURF over successive frames and was a good candidate for use with openFABMAP.

  * **maximum size** -
  * **threshold** -
  * **line threshold** -
  * **line bin** -
  * **suppression area** -

### MSER ###

The OpenCV MSER actually detects a stable region in the image space and therefore differs slightly from the above point detectors. It was found that it is was still possible to use the region to form a descriptor that was often more stable in successive frames than SURF.

  * **eccentricity ratio** -
  * **delta** -
  * **minimum area** -
  * **maximum area** -
  * **maximum variation** -
  * **minimum diversity** -


## Codewords (v1.2) ##

_How-to?_

  1. specify the dataset video in the settings file VIDEO parameter.
  1. specify the codebook file in the settings file CODEBOOK parameter.
  1. specify the feature detection type in the DETECT\_MODE parameter. Also specify the corresponding detectors properties.
  1. set the (rough) viewing frames per second using the VW\_FPS parameter.
  1. set the FUNCTION parameter to 3
  1. run openFABMAPexe

_Tips_

After a codebook is formed each descriptor detected can be represented by a single number. While visualising the codeword number has less meaning than perhaps ensuring good initial detection results as above, it can still provide some insight into the results obtained from the algorithm.

One example of this could be tracking the consistent word labelling of a detected feature over multiple frames when using a high frame rate image stream. Consistency will affect the 'revisiting of locations' and when the algorithm decides when a location is a 'new' location under these circumstances.

## Results (v1.2) ##

_How-to?_

  1. specify the dataset video in the settings file VIDEO parameter.
  1. specify the results file in the FM\_SAVE parameter.
  1. set your monitor size and thumbnail size using parameters under the FABMAP VISUALISATION heading in the settings file.
  1. set the FUNCTION parameter to 7
  1. run openFABMAPexe

_Tips_

Results can be viewed in a purely visual domain. Each location will have a number of frames that 'match' to it and images are shown according to this grouping. The images are shown as thumbnails (size can be adjusted in settings file) with the frame name describing the location number (L) and frame of the video file (F). If all frames of a particular location do not fit onto a single monitor (adjusted in settings file) then a key must be pressed to continue displaying more frames from the location. Pressing a key moves on to the frames that match the next location after all frames of the current location have been displayed.

This is visualisation works better using the 'location revisiting' option (i.e. FUNCTION #6) to generate results.

A more intuitive and revealing way to view the results is to combine the openFABMAP results with your odometry or ground truth and plot the matches against physical location. This feature is not in the project currently.