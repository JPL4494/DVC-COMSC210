/************************************
Lab 4a, Introduction To Dynamic Arrays
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#ifndef SERVERGROUP_H
#define SERVERGROUP_H

class ServerGroup
{
  int* servers;
  int spServer;
  int freeServer;
  int Size;

public:
  ServerGroup(const int&);
  bool spServerFree() const;
  bool serverFree();
  void useServer(const int&)const;
  void usespServer(const int&);
  void decServers();
};

#endif // SERVERGROUP_H
