/*
\file:     Colour.cpp
\author:   Darian Benam
\date:     Saturday, May 9, 2020
\brief:    Equivalent C++ file for the header file 'Colour.hpp'.
*/

#include "Colour.hpp"

Colour::Colour()
{
	Red = 0;
	Green = 0;
	Blue = 0;
}

Colour::Colour(unsigned r, unsigned g, unsigned b)
{
	Red = r;
	Green = g;
	Blue = b;
}