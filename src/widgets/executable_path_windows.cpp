#include <sdl_cpp/widgets/executable_path.h>
#include <string>
#include "Windows.h"
//#error Still to implement

using namespace ::std;

string executable_path()
{
	char buffer[16 * 1024];

	int bytes = GetModuleFileName(nullptr, buffer, sizeof(buffer));
	if (bytes == 0)
	{
		throw unable_to_find_executable_path{};
	}
	buffer[bytes] = '\0';
	string executable_path{buffer};

	return std::string{executable_path.cbegin(),
					   executable_path.cbegin() +
					   executable_path.find_last_of('\\')};
}
