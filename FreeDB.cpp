#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum freeDBCommands
{
  q = 0,
  d = 1,
  f = 2,
  l = 3,
  v = 4,
  h = 99
};

class Command
{
private:
  freeDBCommands commandType;
  string commandString;

public:
};

class Input
{
private:
  //Helper method.
  void showHelp(string name)
  {
    cerr << "Using of: " << name << " <command(s)> Commands:\n"
         << "\t-q,--query\t\tYour query.\n"
         << "\t-d,--database\t\tYour selected database name.\n"
         << "\t-h,--help\t\tHelp...\n"
         << endl;
  }

public:
  //Command parser constructor.
  Input(int argc, char *argv[])
  {
    if (argc < 2)
    {
      showHelp(argv[0]);
    }
    else
    {
      for (int i = 1; i < argc; ++i)
      {
        string arg = argv[i];

        if ((arg == "-h") || (arg == "--help"))
        {
          showHelp(argv[0]);
        }
        else if ((arg == "-d") || (arg == "--database"))
        {
          cout << argv[++i] << endl;
        }
        else if ((arg == "-q") || (arg == "--query"))
        {
          cout << argv[++i] << endl;
        }
        else
        {
          cout << "There is no command like " << arg << endl;
        }
      }
    }
  }

  void getCommands()
  {
  }
};

int main(int argc, char *argv[])
{
  Input inputString(argc, argv);
}
