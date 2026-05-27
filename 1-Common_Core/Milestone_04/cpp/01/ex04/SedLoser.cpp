/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedLoser.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 05:08:20 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/27 05:29:39 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLoser.hpp"

// Constructor: Initializes the object and parameters via Initialization List
SedLoser::SedLoser(std::string filename, std::string s1, std::string s2)
    : _filename(filename), _s1(s1), _s2(s2) {}

// Destructor:
SedLoser::~SedLoser() {}

// Core Method: Opens, Replaces and Writes
bool SedLoser::replace(void)
{
    // 1. Safety check: Cannot find and replace an empty string
    if (_s1.empty())
    {
        std::cerr << "Error: The string to find (s1) cannot be empty." << std::endl;
        return (false);
    }

    // 2. Input File Stream: Open and Error check
    std::ifstream infile(_filename.c_str());

    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open input file '" << _filename << "'." << std::endl;
        return (false);
    }

    // 3. Output File Stream: Create, Open and Error check
    std::string outfilename = _filename + ".replace";

    std::ofstream outfile(outfilename.c_str());

	if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create output file '" << outfilename << "'." << std::endl;
        infile.close();
        return (false);
    }

    // 4. Read, Replace and Write
    std::string line;

    while (std::getline(infile, line))
    {
        std::size_t pos = 0;

        while ((pos = line.find(_s1, pos)) != std::string::npos)
        {
            line.erase(pos, _s1.length());
            line.insert(pos, _s2);
            pos += _s2.length();
        }
        outfile << line << std::endl;
    }

    // 5. Close and Report Success
    infile.close();
    outfile.close();

    return (true);
}

