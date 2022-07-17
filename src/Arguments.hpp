#ifndef ENHANCED_PUSH_ARGUMENTS_HPP
#define ENHANCED_PUSH_ARGUMENTS_HPP
#include "../include/push.hpp"

namespace Utils {
    class Arguments {
        public:
            Arguments(int argc, char *argv[]): _argc(argc) {
                for (int i = 0; i < argc; i++)
                    _argv.push_back(argv[i]);
            };
            ~Arguments() {};

            bool isSet(const std::string &arg) const;
            int getArgIndex(const std::string &arg) const;

            std::vector<std::string> getArgs() const;
            int getArgc() const;

        private:
            std::vector<std::string> _argv;
            int _argc;
    };
}

#endif //ENHANCED_PUSH_ARGUMENTS_HPP
