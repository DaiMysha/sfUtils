/**
BSD 2-Clause License

Copyright (c) 2017, Christophe Gire
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef HEADER_DMUTILS_SFML
#define HEADER_DMUTILS_SFML

#include <dmUtils/maths.hpp>
#include <SFML/Graphics.hpp>

namespace dm {
namespace utils {
namespace sfml {

    template <typename T>
    T norm2(const sf::Vector2<T>& v);

    template <typename T>
    T norm(const sf::Vector2<T>& v);

    template <typename T>
    sf::Vector2<T> normalize(sf::Vector2<T> v);

    template <typename T>
    float getAngleBetweenVectors(const sf::Vector2<T>& o, const sf::Vector2<T>& v);

    template <typename T>
	T dot(const sf::Vector2<T>& a, const sf::Vector2<T>& b);

    ///If you don't know the angle of your base vector use the function with 2 parameters
    ///if you do know this angle pass it to this function, it saves time
    /// rads
    template <typename T>
    sf::Vector2<T> rotate(const sf::Vector2<T>& v, float alpha, float vecRot);

    template <typename T>
    sf::Vector2<T> rotate(const sf::Vector2<T>& v, float alpha);

    ///Rotates the point v around the origin o of alpha degrees
    template <typename T>
    sf::Vector2<T> rotate(const sf::Vector2<T>& v, float alpha, const sf::Vector2<T>& o);

	///tests if p2 is left of the line p0 -> p1
	///returns >0 if left, 0 if on the line, <0 if right
	template <typename T>
	T isLeft(const sf::Vector2<T>& p0, const sf::Vector2<T>& p1, const sf::Vector2<T>& p2);

	///returns true if the point p is inside the shape s
	template <typename T>
	bool contains(const sf::ConvexShape& s, sf::Vector2<T> p);

	///Projects the point point onto the line passing through L1 and L2
    template <typename T>
    sf::Vector2<T> project(const sf::Vector2<T>& point, const sf::Vector2<T>& l1, const sf::Vector2<T>& l2);

    ///Checks for the intersection between the line
    ///passing through P0 of direction S1
    ///and the line
    ///passing through P2 of direction S2
    ///R is the point of intersection if there is one
    ///D0 is the distance between R and P0
    ///D2 is the distance between R and P2
    template <typename T>
    void genericIntersection(const sf::Vector2<T>& p0, sf::Vector2<T> s1, const sf::Vector2<T>& p2, sf::Vector2<T> s2, float& d0, float& d2, sf::Vector2<T>* r = nullptr);

    ///Calculate the intersection between
    ///the half line starting at p0 of directon S1
    ///And the line passing through p2 of direction s2
    template <typename T>
    T halfLineToLineIntersection(const sf::Vector2<T>& p0, sf::Vector2<T> s1, const sf::Vector2<T>& p2, sf::Vector2<T> s2, sf::Vector2<T>* r = nullptr);

    ///Calculate the intersection between
    ///the half line start at p0 of directon S1
    ///And the half line startint at p2 of direction s2
    template <typename T>
    T halfLineToHalfLineIntersection(const sf::Vector2<T>& p0, sf::Vector2<T> s1, const sf::Vector2<T>& p2, sf::Vector2<T> s2, sf::Vector2<T>* r = nullptr);

    ///Calculate the intersection between
    ///the half line start at p0 of directon S1
    ///and the segment [a;b]
    template <typename T>
    T halfLineToSegmentIntersection(const sf::Vector2<T>& p0, sf::Vector2<T> s1, const sf::Vector2<T>& a, const sf::Vector2<T>& b, sf::Vector2<T>* r = nullptr);

    ///Calculate the intersection between
    ///the segment [a1;b1]
    ///and the segment [a2;b2]
    template <typename T>
    T segmentToSegmentIntersection(const sf::Vector2<T>& a1, sf::Vector2<T> b1, const sf::Vector2<T>& a2, const sf::Vector2<T>& b2, sf::Vector2<T>* r = nullptr);
}
}
}

#include "sfml.tpl"
#endif // HEADER_dm::utils_SFML
