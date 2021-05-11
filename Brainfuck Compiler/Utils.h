#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

/// Simplify the namespace for std::filesystem
namespace fs = std::filesystem;

/// <summary>
/// Flags for parameters passed to the application
/// </summary>
struct Parameters
{
	fs::path InFile;
	fs::path OutFile;
	bool c_only;
	bool has_error;
};

/// <summary>
/// Reads a file by path into a string
/// </summary>
/// <param name="path">The path of the file to read</param>
/// <returns>The file contents as a string</returns>
std::string read_file(fs::path path);
/// <summary>
/// Parses parameters into an organized array
/// </summary>
/// <param name="argc">The number of parameters passed</param>
/// <param name="argv">The parameters that were passed</param>
/// <returns>An parameters struct containing all the flags arguments</returns>
Parameters parse_parameters(int argc, char **argv);
