#ifndef _INTERDEPART_TIME_TEST_HANDLER_H_
#define _INTERDEPART_TIME_TEST_HANDLER_H_

#include <fstream> //std::fstream
#include <time.h> // struct timeval
#include <list> // std::list
#include <map> // std::map
#include <inttypes.h> //in_addr_t

#include "FeatureTestHandler.h"



class InterdepartTimeTestHandler : public FeatureTestHandler{
	public:

		InterdepartTimeTestHandler(std::fstream *modelFile);
		void initCapture();
		void ComputeDistribution(int type);
		virtual void loadDataToModel();
		virtual Json::Value *DataToJson() const ;
		virtual std::string getFeatureName() const;
		virtual void runTest();
		virtual int getTestResult();
		void printDistribution() const;
	private:
		void ComputeInterdeparture(std::map<uint32_t, std::list<uint64_t> > *packetTiming);
		std::map<uint32_t, std::list<uint64_t> > * interdepTiming_;
		static const std::string FEATURE_NAME ;

};

#endif // _INTERDEPART_TIME_TEST_HANDLER_H_