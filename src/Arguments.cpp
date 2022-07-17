#include "Arguments.hpp"

bool Utils::Arguments::isSet(const std::string &arg) const
{
    for (int i = 0; i < _argc; i++) {
        if (_argv[i] == arg)
            return true;
    }
    return false;
}

int Utils::Arguments::getArgIndex(const std::string &arg) const {
    for (int i = 0; i < _argc; i++) {
        if (_argv[i] == arg)
            return i;
    }
    return -1;
}

std::vector<std::string> Utils::Arguments::getArgs() const
{
    return _argv;
}

int Utils::Arguments::getArgc() const {
    return _argc;
}