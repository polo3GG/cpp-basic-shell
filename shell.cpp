#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

class shell
{
public:
    fs::path pwd = fs::current_path();
    void pwdd()
    {
        cout << pwd;
    }
    void cdd(const string &path)
    {
        fs::path target = path;
        fs::current_path(target);
    }
    void mkdirr(const string &path)
    {
        fs::path folder = path;
        fs::create_directory(path);
    }
    void rmm(const string &path)
    {
        fs::path folderr = path;
        fs::remove(path);
    }
    void lss()
    {
        for (const auto &entry : fs::directory_iterator(pwd))
        {
            cout << entry.path().filename() << endl;
        }
    }
    void cls()
    {
        system("cls");
    }
};

int main()
{
    shell sh;
    string inp, arg;

    while (true)
    {

        cout << "$> ";
        cin >> inp;
        if (inp == "pwd")
        {
            sh.pwdd();
            cout << endl;
        }
        else if (inp == "cd")
        {
            getline(cin, arg); // boşluğu al
            if (!arg.empty() && arg[0] == ' ')
                arg.erase(0, 1);

            sh.cdd(arg);
        }
        else if (inp == "mkdir")
        {
            getline(cin, arg);
            if (!arg.empty() && arg[0] == ' ')
                arg.erase(0, 1);

            sh.mkdirr(arg);
        }
        else if (inp == "rm")
        {
            getline(cin, arg);
            if (!arg.empty() && arg[0] == ' ')
                arg.erase(0, 1);

            sh.rmm(arg);
        }
        else if (inp == "ls")
        {
            sh.lss();
        }
        else if (inp == "clear")
        {
            sh.cls();
        }
        else if (inp == "exit")
        {
            break;
        }
    }
    return 0;
}