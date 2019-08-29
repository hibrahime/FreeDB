#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
  bool _isExecuted = false;

public:
  Command(freeDBCommands commandType, string commandString)
  {
    _commandType = commandType;
    _commandString = commandString;
  }

  freeDBCommands GetCommand()
  {
    return _commandType;
  }

  void setIsExecuted()
  {
    _isExecuted = true;
  }

  bool getIsExecuted()
  {
    return _isExecuted;
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

  bool controlIsExist(freeDBCommands command)
  {
    for (int i = 0; i < commands.size(); i++)
    {
      if (commands.at(i).GetCommand() == command)
      {
        return true;
      }
    }
    return false;
  }

  void addCommandToCommands(freeDBCommands command, string commandString, char *argv[], int i)
  {
    if (controlIsExist(command))
    {
      cerr << argv[i] << " command used twice!\n"
           << endl;
      showHelp(argv[0]);
    }
    else
    {
      commands.push_back(Command(command, commandString));
    }
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
        string commandString = argv[++i];
        freeDBCommands command;

        if ((arg == "-h") || (arg == "--help"))
        {
          showHelp(argv[0]);
        }
        else if ((arg == "-d") || (arg == "--database"))
        {
          command = freeDBCommands::d;
          addCommandToCommands(command, commandString, argv, i);
        }
        else if ((arg == "-q") || (arg == "--query"))
        {
          command = freeDBCommands::q;
          addCommandToCommands(command, commandString, argv, i);
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

class Execute
{
private:
  bool sortBycommandName(Command c1, Command c2)
  {
    return c1.GetCommand() > c2.GetCommand();
  }

  void sortCommands(vector<Command> commands)
  {
    sort(commands.begin(), commands.end(), sortBycommandName);
  }

public:
  Execute(vector<Command> commands)
  {
    sortCommands(commands);
    for (int i = 0; i < commands.size(); i++)
    {
    }
  }
};

int main(int argc, char *argv[])
{
  Input inputString(argc, argv);

  vector<Command> cmnd = inputString.getCommands();
}
