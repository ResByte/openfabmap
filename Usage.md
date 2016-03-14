[Home](Homepage.md)

see also: [Application Programming Interface](http://openfabmap.googlecode.com/files/openFABMAP_API.pdf)

# Steps #

The following is an overview of the steps to run openFABMAP in a batch processing mode. When using the example program provided the steps should follow sequentially with the running mode in the settings.yml file. To perform subsequent steps the settings.yml file must be altered.

  1. Validate Feature Extraction
    * View the features being detected on your training dataset
  1. Build a feature vocabulary
    * Extract all features from Training Dataset
    * Run a clustering algorithm to train the vocabulary
  1. Build a Chow-liu tree
    * Extract bag-of-words image descriptors from training data
    * Train chow-liu tree
  1. Run FAB-MAP algorithm
    * Extract bag-of-words image descriptors from test data
    * Run FAB-MAP using Chow-liu tree, train BOWs, and test BOWs
  1. Evaluate Results
    * Import confusion matrix into matlab



# Tips #

## Features ##

Making sure 'good' detection of features is occurring is important to achieving positive results. The result of the FAB-MAP calculation is highly dependent on the statistics collected from training data. If the feature detection is noisy and inconsistent it will be reflecting in the results. It is often poor feature detection that hinders performance.

Good detection should:
  * Have similar amounts of features in each frame. Depending on the video resolution and richness of the environment this could be ~50 - 500.
  * Not detect features on bland/uninformative areas on an image. This is just added noise to the system.
  * Consistently detect features in the same location or from the same objects. In continuous videos you should be able to 'track' features along with the movement of the object yourself.

Feature detection can be adjusted:
  * Change feature detection type. Many features exist in openCV (SIFT, SURF, STAR, MSER)
  * Change feature detection thresholds. The default thresholds for detection may not work for every dataset and environment type.

## Vocabulary ##

The visual vocabulary is another common source of reduced performance. The vocabulary quantises the high dimensional feature descriptor by assigning it part of a single class.

Factors affecting the vocabulary:
  * The number of words. More words in the vocabulary makes openFABMAP more specific. The number of words that should be chosen will be dependent on the size and variance in appearance of the physical environment, as well as the number of features extracted from the training data. As a reference point:
    * [Cummins & Newman 2008](http://ijr.sagepub.com/content/27/6/647.short) - high definition outdoor dataset ~10,000 words
    * [Glover et al. 2010](http://ieeexplore.ieee.org/xpls/abs_all.jsp?arnumber=5509547&tag=1) - standard definition outdoor dataset ~6,000 words.
    * [Cummins & Newman 2010](http://ijr.sagepub.com/content/30/9/1100.short) - 1,000km outdoor dataset ~100,000 words.
  * The clustering method. [Cummins & Newman 2010](http://ijr.sagepub.com/content/30/9/1100.short) discusses the use of the popular k-means algorithm, concluding in a reduced performance for FAB-MAP applications. The modified sequential clustering algorithm provided is an alternative that avoids the over-generalising that affects k-means.
  * The more data you can throw at the codebook training stage the better!

## Training Dataset ##

  * The training dataset should have no repeated paths. Viewing the same scene multiple times biases the algorithm and will not produce an accurate statistical model of the features observed in the environment.
  * Use separate training and test datasets. Desirably from completely separate environments which are somewhat similar in appearance. Lacking a suitable training environment do not use exactly the same images for training and testing as this will decrease performance, especially when using the sample-based new-place method.
  * [Cummins & Newman 2008](http://ijr.sagepub.com/content/27/6/647.short) suggests using disjoint (non-overlapping) for training and testing. OpenFABMAP can be trained on continuous data but it is possible it can result in over-training. In addition, varying your speed through the environment when using a continuous dataset can also lead to biased statistics as per the first point.
  * Again the more data you can include in the training dataset the better, erring in the direction of continuous datasets over low amounts of data.

# Visualising Results #

The results file is a confusion matrix stored as text. This can be analysed with your preferred method. A simple qualitative method is as follow:
  * Import the confusion matrix into matlab.
    * Navigate to the results.txt file within the matlab directory window
    * Select 'import data' within the right-click context menu
  * Use the 'imagesc' command. e.g. imagesc(results)
  * For better contrast set the colour map to gray. e.g. colormap('gray')
  * Sections of the dataset which are 'loop closures' should appear as strongly matched (white) diagonals. See the [sample dataset](http://openfabmap.googlecode.com/files/openFABMAPsample.zip) for an example.