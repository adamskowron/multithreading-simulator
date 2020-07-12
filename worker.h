#pragma once
#include <thread>
#include <vector>
#include <string>
#include "part.h"

class Worker
{
public:

std::string name;
int x,y;
int precentDone;
int thirsty;
int quality;
std::string partProducedName;

//Part produced;
std::vector<Part> partsNeeded;

Worker(int type, std::vector<Part> parts);
void work();

};
