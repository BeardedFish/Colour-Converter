/*
\file:     Colour.hpp
\author:   Darian Benam
\date:     Saturday, May 9, 2020
\brief:    Header file for the Colour class. This class can contain three values that describe a colour. The three values are red, blue, and green.
*/

#pragma once

class Colour
{
public:
	unsigned Red;
	unsigned Green;
	unsigned Blue;

	Colour();
	Colour(unsigned r, unsigned g, unsigned b);
};