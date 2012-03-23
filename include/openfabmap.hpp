/*
 * FabMap.h
 *
 *  Created on: 16/03/2012
 *      Author: will
 */

#ifndef OPENFABMAP_H_
#define OPENFABMAP_H_

#include <vector>
#include <list>
#include <map>
using std::vector;
using std::list;
using std::map;

#include <opencv2/opencv.hpp>
using cv::Mat;

namespace of2
{

struct IMatch {

	IMatch() : queryIdx(-1), imgIdx(-1), likelihood(-DBL_MAX), match(-DBL_MAX) {}
	IMatch(int _queryIdx, int _imgIdx, double _likelihood, double _match) :
		queryIdx(_queryIdx), imgIdx(_imgIdx), likelihood(_likelihood), match(_match) {}

	int queryIdx;
	int imgIdx;

	double likelihood;
	double match;

	bool operator>(const IMatch& m) const {
		return match > m.match;
	}

};

class FabMap {
public:

	enum {MEAN_FIELD = 0, SAMPLED = 1};
	enum {NAIVE_BAYES = 3, CHOW_LIU = 4};

	FabMap(const Mat& codebook, const Mat& clTree, double PzGe, double PzGNe, int flags);
	virtual ~FabMap();

	void addTraining(const Mat& imgDescriptors);

	void match(const Mat& queryImgDescriptors, vector<IMatch>& matches);
	void match(const Mat& queryImgDescriptors, const Mat& testImgDescriptors,
				vector<IMatch>& matches);

protected:

	virtual void match(const vector<Mat>& queryImgDescriptors,
			const vector<Mat>& testImgDescriptors, vector<IMatch>& matches);

	int parent(int word);
	double P(int word, bool q);
	double PqGp(int word, bool q, bool p);

	Mat codebook;
	Mat clTree;

	vector<Mat> trainingImgDescriptors;
	vector<Mat> testImgDescriptors;

	double PzGe;
	double PzGNe;

	int flags;

};

class FabMap1 : public FabMap {
public:
	FabMap1(const Mat& codebook, const Mat& clTree, double PzGe, double PzGNe, int flags);
	virtual ~FabMap1();
protected:
	void match(const vector<Mat>& queryImgDescriptors,
			const vector<Mat>& testImgDescriptors, vector<IMatch>& matches);
};

class FabMapLUT : public FabMap {
public:
	FabMapLUT(const Mat& codebook, const Mat& clTree, double PzGe, double PzGNe, int precision, int flags);
	virtual ~FabMapLUT();
protected:
	void match(const vector<Mat>& queryImgDescriptors,
				const vector<Mat>& testImgDescriptors, vector<IMatch>& matches);

	int precision;
};

class FabMapFBO : public FabMap {
public:
	FabMapFBO(const Mat& codebook, const Mat& clTree, double PzGe, double PzGNe, double PS_D, double LOFBOH, int bisectionStart, int bisectionIts, int flags);
	virtual ~FabMapFBO();
protected:
	void match(const vector<Mat>& queryImgDescriptors,
				const vector<Mat>& testImgDescriptors, vector<IMatch>& matches);

	double PS_D;
	double LOFBOH;
	int bisectionStart;
	int bisectionIts;
};

class FabMap2 : public FabMap {
public:
	FabMap2(const Mat& codebook, const Mat& clTree, double PzGe, double PzGNe, int flags);
	virtual ~FabMap2();
protected:
	void match(const vector<Mat>& queryImgDescriptors,
				const vector<Mat>& testImgDescriptors, vector<IMatch>& matches);
};

class ChowLiuTree {
public:
	ChowLiuTree();
	virtual ~ChowLiuTree();

	void add(const Mat& imgDescriptor);
	Mat make(double infoThreshold);

private:
	vector<Mat> imgDescriptors;

	class TrainData {
	private:
		vector<float> absolutes;
		int numSamples;
		int sampleSize;
		Mat data;

	public:
		TrainData();
		~TrainData();
		void make(const Mat& imgDescriptors);
		double P(int a, bool ais);
		double JP(int a, bool ais, int b, bool bis); //a & b
		double CP(int a, bool ais, int b, bool bis);	// a | b
	};

	typedef struct clNode {
		int nodeID;
		int parentNodeID;
		float Pq;
		float Pq_p;
		float Pq_np;
	} clNode;

	typedef struct info {
		float score;
		short word1;
		short word2;
	} info;

	vector<clNode> nodes;

	void recAddToTree(int node, int parentNode, TrainData& trainData, list<info>& edges);
	static bool clNodeCompare(const clNode& first, const clNode& second);
	static bool sortInfoScores(const info& first, const info& second);
	double calcMutInfo(TrainData& trainData, int word1, int word2);
	void createBaseEdges(list<info>& edges, TrainData& trainData, double infoThreshold);
	bool reduceEdgesToMinSpan(list<info>& edges);

};

class BOWMSCTrainer : public cv::BOWTrainer
{
public:
    BOWMSCTrainer( double clusterSize );
    virtual ~BOWMSCTrainer();

    // Returns trained vocabulary (i.e. cluster centers).
    virtual Mat cluster() const;
    virtual Mat cluster( const Mat& descriptors ) const;

protected:

    double clusterSize;

};


}
#endif /* OPENFABMAP_H_ */
