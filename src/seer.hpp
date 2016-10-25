/*
 *
 * seer.hpp
 * Header file for seer package
 *
 */

// Common headers
//#include "seercommon.hpp"
#include "linkFunction.hpp" // This includes seercommon.hpp

// dlib headers
#include <dlib/optimization.h>

// Constants
//    Default options
const std::string pval_default = "10e-8";
const double convergence_limit = 10e-8;
const unsigned int max_nr_iterations = 1000;
const double se_limit = 3;

// Starting value for beta vectors (except intercept)
// Should be >0. This value is based on RMS in example study
const double bfgs_start_beta = 1;

// seerCmdLine headers
int parseCommandLine (int argc, char *argv[], boost::program_options::variables_map& vm);
void printHelp(boost::program_options::options_description& help);

// seerStats headers
double chiTest(Kmer& k, const arma::vec& y);
double welchTwoSamplet(const Kmer& k, const arma::vec& y);
double nullLogLikelihood(const arma::mat& x, const arma::vec& y, const int continuous);
double likelihoodRatioTest(Kmer& k, const double null_ll);
double normalPval(double testStatistic);

// seerBinaryAssoc headers
void logisticTest(Kmer& k, const arma::vec& y, const double null_ll);
void logisticTest(Kmer& k, const arma::vec& y_train, const double null_ll, const arma::mat& mds);

void doLogit(Kmer& k, const arma::vec& y_train, const arma::mat& x_design);
void newtonRaphson(Kmer& k, const arma::vec& y_train, const arma::mat& x_design, const bool firth = 0);

arma::mat varCovarMat(const arma::mat& x, const arma::mat& b);
arma::vec predictLogitProbs(const arma::mat& x, const arma::vec& b);

// seerContinuousAssoc headers
void linearTest(Kmer& k, const arma::vec& y_train, const double null_ll);
void linearTest(Kmer& k, const arma::vec& y_train, const double null_ll, const arma::mat& mds);

void doLinear(Kmer& k, const arma::vec& y_train, const arma::mat& x_design);
arma::vec predictLinearProbs(const arma::mat& x, const arma::vec& b);

