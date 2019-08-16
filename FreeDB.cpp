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
  freeDBCommands _commandType;
  string _commandString;

public:
  Command(freeDBCommands commandType, string commandString)
  {
    _commandType = commandType;
    _commandString = commandString;
  }
};

class Input
{
private:
  vector<Command> commands;
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
          string database = argv[++i];
          commands.push_back(Command(freeDBCommands::d, database));
        }
        else if ((arg == "-q") || (arg == "--query"))
        {
          string database = argv[++i];
          commands.push_back(Command(freeDBCommands::q, database));
        }
        else
        {
          cout << "There is no command like " << arg << endl;
        }
      }
    }
  }

  vector<Command> getCommands()
  {
    return commands;
  }
};

int main(int argc, char *argv[])
{
  Input inputString(argc, argv);

  vector<Command> cmnd = inputString.getCommands();
}
