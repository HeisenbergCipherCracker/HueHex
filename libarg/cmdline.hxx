#include "thirdparty/cxxopts/include/cxxopts.hpp"
#ifdef __WIN32__
#include <windows.h>
#pragma warning(disable : 1234)
#endif
#ifdef __LINUX__ || __APPLE__
#define SUDOPRV false
#endif




namespace Cmdline {
    cxxopts::ParseResult parse(int argc, char* argv[]) {
        cxxopts::Options options("HueHex", " - command line options");
        options.add_options()
            ("h,help", "Use help menu of the program")
            ("hashfile", "specify the hasfile for rainbow table cracking", cxxopts::value<std::string>())
            ("nohex", "do not use hex expressions", cxxopts::value<bool>()->default_value("false")->implicit_value("true"))
            ("noascii", "do not use ascii expressions", cxxopts::value<bool>()->default_value("false")->implicit_value("true"))
            ("generate", "generate wordlist", cxxopts::value<bool>()->default_value("false")->implicit_value("true"))
            ("genhash", "generate hashwordlists");
        return options.parse(argc, argv);
    }
};