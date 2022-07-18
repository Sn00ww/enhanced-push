#include "push.hpp"
#include "Arguments.hpp"

void printHelp(char *command)
{
    std::cout << "Usage:" << std::endl;
    std::cout << command << " -m <message> [-a] [-p]" << std::endl;
    std::cout << "\nOptions:" << std::endl;
    std::cout << "\t-m <message>: Specify the commit message (not formatted)." << std::endl;
    std::cout << "\t-a: Track all the files (git add .)." << std::endl;
    std::cout << "\t-p: Push after the commit." << std::endl;
    std::cout << "\t-P: Push without commit." << std::endl;
}

int main(int argc, char *argv[])
{
    Utils::Arguments args(argc, argv);

    if (args.isSet("-h") || args.isSet("--help")) {
        printHelp(argv[0]);
        return 0;
    }

    if (args.isSet("-P")) {
        system("git push");
        return 0;
    }

    if (!args.isSet("-m") || args.getArgIndex("-m") + 1 >= args.getArgc()) {
        printHelp(argv[0]);
        return 1;
    }

    std::string message = args.getArgs()[args.getArgIndex("-m") + 1];
    FILE* output = popen("git branch -ra | grep \"^*\" | sed -e 's/* //g'", "r");
    std::string branch;

    char buf[1000];
    while (fgets (buf, 1000, output))
        branch += buf;
    pclose(output);
    branch.pop_back();

    std::cout << "[" << branch << "] => " << message << std::endl;

    if (args.isSet("-a"))
        system("git add .");

    system("git status");

    std::string commit_command = "git commit -m \"["+ branch +"] => "+ message +"\"";

    system(commit_command.c_str());

    if (args.isSet("-p"))
        system("git push");
    return 0;
}