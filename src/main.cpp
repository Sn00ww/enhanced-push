#include "push.hpp"
#include "Arguments.hpp"

int main(int argc, char *argv[])
{
    Utils::Arguments args(argc, argv);

    if (!args.isSet("-m") || args.getArgIndex("-m") + 1 >= args.getArgc()) {
        std::cout << "Usage: " << argv[0] << " -m <message> [-a] [-p]" << std::endl;
        return 1;
    }

    system("git status");

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

    std::string commit_command = "git commit -m \"["+ branch +"] => "+ message +"\"";

    system(commit_command.c_str());

    if (args.isSet("-p"))
        system("git push");
    return 0;
}