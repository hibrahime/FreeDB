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

public:
  // Default constructor
  Command()
  {
  }

  void showHelp(string name)
  {
    cerr << "Using of: " << name << " <command(s)>"
         << "Commands:\n"
         << "\t-q,--query\t\tYour query.\n"
         << "\t-d,--database\t\tYour selected database name."
         << "\t-h,--help\t\tHelp..."
         << endl;
  }

  // Command parser constructor
  Command(int argc, char *argv[])
  {

    if (argc < 1)
    {
      showHelp(argv[0]);
    }

    vector<string> commands;

    for (int i = 1; i < argc; ++i)
    {
      string arg = argv[i];
      if ((arg == "-h") || (arg == "--help"))
      {
        showHelp(argv[0]);
      }
      else if ((arg == "-d") || (arg == "--database"))
      {
      }
      else if ((arg == "-q") || (arg == "--query"))
      {
      }
      else
      {
      }
    }

    for (int i = 0; i < argc; i++)
    {
      cout << "argv " << i << " " << argv[i] << endl;
    }
  }
};

int main(int argc, char *argv[])
{
  //cout << argc << endl;
  //cout << *argv << endl;

  Command inputCommand(argc, argv);
}
