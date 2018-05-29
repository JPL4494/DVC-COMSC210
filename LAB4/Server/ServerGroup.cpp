/************************************
Lab 4a, Introduction To Dynamic Arrays
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
************************************/

#include "ServerGroup.h"

ServerGroup::ServerGroup(const int& s)
{
  if(s > 0)
  {
    servers = new int[s]();
    Size = s;
  }

  else
  {
    servers = new int[1];
    Size = 1;
  }

  spServer = 0;
  freeServer = 0;
}

bool ServerGroup::spServerFree() const
{
  if(spServer == 0)return true;
  else return false;
}

bool ServerGroup::serverFree()
{
  for(int i = 0; i < Size; i++)
  {
    if(servers[i] == 0)
    {
      freeServer = i;
      return true;
    }
  }
  return false;
}

void ServerGroup::useServer(const int& avTransTime)const
{
  servers[freeServer] = avTransTime;
}

void ServerGroup::usespServer(const int& avTransTime)
{
  spServer = avTransTime;
}

void ServerGroup::decServers()
{
  for(int i = 0; i < Size; i++)
  {
    if(servers[i] > 0)
    {
      int temp = servers[i];
      servers[i] = (temp - 1);
    }
  }
  if(spServer > 0)spServer--;
}
