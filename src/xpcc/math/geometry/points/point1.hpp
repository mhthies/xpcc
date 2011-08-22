// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2011, Roboterclub Aachen e.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
// ----------------------------------------------------------------------------

#ifndef XPCC_POINTS__POINT1_HPP
#define XPCC_POINTS__POINT1_HPP

#include <stdint.h>
#include "point.hpp"

namespace xpcc {
	/**
	 * \brief	Class for handling common point operations
	 *
	 * Adapted from the implementation of Gaspard Petit (gaspardpetit@gmail.com).
	 *
	 * \see <a href"http://www-etud.iro.umontreal.ca/~petitg/cpp/point.html">Homepage</a>
	 * 
	 * \ingroup	points
	 * \author Niklas Hauser
	 */
	template<typename T>
	class Point<T, 1>
	{
	public:
		Point();
		Point(T inX);
		Point(const Matrix<T, 1, 1> &rhs);
		Point(const Point &rhs);
		
		Point& operator = (const Point &rhs);
		Point& operator = (const Matrix<T, 1, 1> &rhs);
		
		bool operator == (const Point &rhs) const;
		bool operator != (const Point &rhs) const;
		bool operator < (const Point &rhs) const;
		bool operator <= (const Point &rhs) const;
		bool operator > (const Point &rhs) const;
		bool operator >= (const Point &rhs) const;
		
		const T& operator [] (uint8_t index) const;
		T& operator [] (uint8_t index);
		T* ptr();
		const T* ptr() const;
		
		Point operator + (const Point &rhs) const;
		Point operator - (const Point &rhs) const;
		T operator * (const Point &rhs) const;
		Point operator * (const T &rhs) const;
		Point operator / (const T &rhs) const;
		Point& operator += (const Point &rhs);
		Point& operator -= (const Point &rhs);
		Point& operator *= (const T &rhs);
		Point& operator /= (const T &rhs);
		Point& operator - ();
		
		T length() const;
		T length2() const;
		Matrix<T, 1, 1>& asMatrix();
		const Matrix<T, 1, 1>& asMatrix() const;
		bool hasNan() const;
		bool hasInf() const;
		
	public:
		T x;
		
	public:
		IMPLEMENT_POINT_ACCESSOR2(x,x)
		IMPLEMENT_POINT_ACCESSOR3(x, x, x)
		IMPLEMENT_POINT_ACCESSOR4(x, x, x, x)
		
	};
	
	template<typename U, typename T>
	static inline Point<T, 1> operator * (const U &lhs, const Point<T, 1> &rhs);
	
	typedef Point<float, 1> 	Point1f;
	typedef Point<int16_t, 1> 	Point1i;
}

#include "point1_impl.hpp"

#endif // XPCC_POINTS__POINT1_HPP