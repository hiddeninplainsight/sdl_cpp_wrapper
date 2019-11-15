#include <sdl_cpp/widgets/executable_path.h>

#include <string>
#include <unistd.h>
#include <cstdio>
#include <algorithm>

using namespace std;

string executable_path()
{
	char exeLinkPath[32];
	sprintf(exeLinkPath, "/proc/%d/exe", getpid());

	char buffer[16 * 1024];
	int bytes = min(readlink(exeLinkPath, buffer, sizeof(buffer)), static_cast<ssize_t>(sizeof(buffer) - 1));
	if (bytes < 0)
	{
		throw unable_to_find_executable_path{};
	}
	buffer[bytes] = '\0';
	string executable_path{buffer};

	return std::string{executable_path.cbegin(),
				executable_path.cbegin() +
				executable_path.find_last_of('/')};
}
