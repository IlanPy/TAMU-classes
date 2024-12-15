#include "STCF.h"
#include <getopt.h>
#include <iostream>
/**
 * @brief Example is from this website: https://codeyarns.com/2015/01/30/how-to-parse-program-options-in-c-using-getopt_long/
 *
 */
std::string input_file = "";

void PrintHelp()
{

	cout << "Usage: ./schedule -i <file> \n\n";
	cout<<"--------------------------------------------------------------------------\n";
	cout<<"<file>:    "<<"file with PID, Arrival_Time, CPU burst time, I/O burst time, I/O Bound or CPU Bound, Critical, separated with a tab\n";
	exit(1);
}

/**
 * @brief ProcessArgs to handle the arguments
 *
 */
void ProcessArgs(int argc, char** argv)
{
	/**
	* @brief PrintHelp if odd number of args are provided
	*
	*/
	if (argc < 3) {
		PrintHelp();
	}

	while (true)
	{
		const auto opt = getopt(argc, argv, "i:h");

		if (-1 == opt)
			break;

		switch (opt)
		{
		case 'i':
			input_file = std::string(optarg);
			break;

		case 'h': // -h or --help
		default:
			PrintHelp();
			break;
		}
	}

}

/**
 * @brief main function
 *
 */
int main(int argc, char **argv)
{
	ProcessArgs(argc, argv);

	STCF stcf_scheduler = STCF(input_file);
	stcf_scheduler.schedule_tasks();

	return 0;
}
