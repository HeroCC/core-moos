/*
 * CommandLineParser.h
 *
 *  Created on: Nov 12, 2012
 *      Author: pnewman
 */

#ifndef COMMANDLINEPARSER_H_
#define COMMANDLINEPARSER_H_
#include <memory>
#include <vector>
#include <string>
/*
 *
 */

class GetPot;

namespace MOOS {

class CommandLineParser {
public:
	CommandLineParser();
	CommandLineParser(int argc, char * argv[]);

	virtual ~CommandLineParser();

	bool Open(int argc, char * argv[]);

	/** return true if command line parameters have been set*/
	bool IsAvailable();

	// -x=7 or -name=fred  (s var name=value)
	bool GetVariable(const std::string var,  double & result);
	bool GetVariable(const std::string var,  std::string  & result);
	bool GetVariable(const std::string var,  int & result);
	bool GetVariable(const std::string var,  unsigned int & result);

	//-x 7  -name fred    (so no equals)
	bool GetOption(const std::string option,  double & result);
	bool GetOption(const std::string option,  std::string  & result);
	bool GetOption(const std::string option,  int & result);
	bool GetOption(const std::string option,  unsigned int & result);

	// -k -t  -s   (so test is a single flag is set)
	bool GetFlag(const std::string flag);

	//get the ith parameter (that is not x=8 variable form). returning default
	//if not present
	std::string GetFreeParameter(unsigned int ndx, const std::string & default_value);

	/**
	 * fill in all command line parameters that are not like x=7
	 * @param result
	 * @return
	 */
	bool  GetFreeParameters(std::vector<std::string> & result);

	/**
	 * return true if var=X is somewhere in the command line
	 * @param var
	 * @return
	 */
	bool VariableExists(const std::string & var);
private:
	std::auto_ptr<GetPot> pcl_;

};








}

#endif /* COMMANDLINEPARSER_H_ */
