#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

/// <summary>
/// Reads a file by path into a string
/// </summary>
/// <param name="path">The path of the file to read</param>
/// <returns>The file contents as a string</returns>
std::string read_file(fs::path path);
