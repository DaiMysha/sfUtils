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

#include <cmath>

#include <SFML/Graphics.hpp>

namespace dm {
namespace utils {
namespace sf {

    template <typename T>
    T norm2(const sf::Vector2<T>& v) 
	{
        return (v.x*v.x + v.y*v.y);
    }

    template <typename T>
    float getAngleBetweenVectors(const sf::Vector2<T>& o, const sf::Vector2<T>& v) 
	{
        return -(atan2(static_cast<double>(o.y),static_cast<double>(o.x)) - atan2(static_cast<double>(v.y),static_cast<double>(v.x)));
    }
	
	template <typename T>
	T dot(const sf::Vector2<T>& a, const sf::Vector2<T>& b)
	{
		return a.x*b.x + a.y*b.y;
	}

    ///If you don't know the angle of your base vector use the function with 2 parameters
    ///if you do know this angle pass it to this function, it saves time
    template <typename T>
    sf::Vector2<T> rotate(const sf::Vector2<T>& v, float alpha, float vecRot) 
	{
        float totAngle = alpha + vecRot;
        float n = sqrt(static_cast<float>(norm2<T>(v)));
        return sf::Vector2<T>(static_cast<T>(-sin(totAngle) * n),static_cast<T>(cos(totAngle) * n));
    }

    template <typename T>
    sf::Vector2<T> rotate(const sf::Vector2<T>& v, float alpha) 
	{
        return rotate(v,alpha,getAngleBetweenVectors(sf::Vector2f(0.0f,1.0f),v));
    }

	template <typename T>
	sf::Vector2<T> rotate(const sf::Vector2<T>& v, float alpha, const sf::Vector2<T>& o) 
	{
		return rotate(v-o,alpha)+o;
	}

}
}
}
