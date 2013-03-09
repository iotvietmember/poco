//
// Array.cpp
//
// $Id$
//
// Library: MongoDB
// Package: MongoDB
// Module:  Array
//
// Implementation of the Array class.
//
// Copyright (c) 2012, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
#include <sstream>

#include "Poco/MongoDB/Array.h"

namespace Poco {
namespace MongoDB {

Array::Array() : Document()
{
}


Array::~Array()
{
}


Element::Ptr Array::get(int pos) const
{
	std::string name = Poco::NumberFormatter::format(pos);
	return Document::get(name);
}


std::string Array::toString(int indent) const
{
	std::ostringstream oss;

	oss << "[";

	if ( indent > 0 ) oss << std::endl;

	for(ElementSet::const_iterator it = _elements.begin(); it != _elements.end(); ++it)
	{
		if ( it != _elements.begin() )
		{
			oss << ",";
			if ( indent > 0 ) oss << std::endl;
		}

		for(int i = 0; i < indent; ++i) oss << ' ';

		oss << (*it)->toString();
	}

	if ( indent > 0 )
	{
		oss << std::endl;
		if ( indent >= 2 ) indent -= 2;
		for(int i = 0; i < indent; ++i) oss << ' ';
	}

	oss << "]";

	return oss.str();
}


}} // Namespace Poco::Mongo
