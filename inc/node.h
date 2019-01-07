#pragma once
#include "resource.h"

enum Node_type
{
	water,
	earth
};

class Node
{
public:
	Node() { type = water; };
	Node(const Node &node)
	{
		type = node.type;
		resource = node.resource;
	};
	Resource resource;

private:
	Node_type type;
};

bool operator<(const Node &lhs, const Node &rhs);
