#include <algorithm>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

std::string calculateSize(double bytes);

int main(int argc, char *argv[]) {

  if (argc == 1) {
    std::cout << "Checkout Docs at https://example.com";
    return 0;
  }

  std::string command = argv[1];

  if (command == "size") {

    switch (argc) {

    case 2:
      std::cout << "Please enter a valid path";
      break;

    case 3: {
      std::string path = argv[2];
      double totalSize = 0;

      for (const auto &entry : fs::recursive_directory_iterator(path)) {

        if (entry.is_regular_file()) {
          totalSize += entry.file_size();
        }
      }

      std::cout << "Total size: " << calculateSize(totalSize) << '\n';

      break;
    }
    }
  }

  if (command == "biggest") {

    if (argc < 3) {
      std::cout << "Please enter a valid path\n";
      return 0;
    }

    std::string path = argv[2];

    if (!fs::exists(path)) {
      std::cout << "Path does not exist\n";
      return 0;
    }

    int amount = 1;

    if (argc >= 4) {
      amount = std::stoi(argv[3]);
    }

    std::vector<std::pair<double, std::string>> files;

    try {
      for (const auto &entry : fs::recursive_directory_iterator(
               path, fs::directory_options::skip_permission_denied)) {

        if (entry.is_regular_file()) {
          files.push_back(
              {static_cast<double>(entry.file_size()), entry.path().string()});
        }
      }
    } catch (const fs::filesystem_error &e) {
      std::cout << "Filesystem error: " << e.what() << '\n';
    }

    std::sort(files.begin(), files.end(),
              [](const auto &a, const auto &b) { return a.first > b.first; });

    amount = std::min(amount, static_cast<int>(files.size()));

    for (int i = 0; i < amount; i++) {
      std::cout << i + 1 << ". " << calculateSize(files[i].first) << " - "
                << files[i].second << '\n';
    }
  }
}

std::string calculateSize(double bytes) {

  double size = bytes;
  std::string unit = "B";

  if (size >= 1024) {
    size /= 1024;
    unit = "KB";
  }

  if (size >= 1024) {
    size /= 1024;
    unit = "MB";
  }

  if (size >= 1024) {
    size /= 1024;
    unit = "GB";
  }

  std::ostringstream result;
  result << std::fixed << std::setprecision(2) << size << unit;

  return result.str();
}
