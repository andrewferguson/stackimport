/*

 WOBA Decoder for C++
 (c) 2005 Jonathan Bettencourt / Kreative Korporation

 This decodes the compressed bitmap format that HyperCard uses to store card images.
 The format is called WOBA, which stands for Wrath Of Bill Atkinson, because it was
 written by Bill Atkinson and we had a heck of a time figuring it out.


 This code is under the MIT license.

 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in the
 Software without restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
 Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies
 or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef _____WOBA_H_____
#define _____WOBA_H_____

#include "picture.h"
using namespace std;

inline int __min(int x, int y);

void xornstr(char * dest, const char * src, int n);
void xorstr(char * dest, const char * src);
void shiftnstr(char * s, int n, int sh);
void shiftstr(char * s, int sh);

void woba_decode(picture & p, char * woba);

class CBuf
{
public:
	explicit CBuf( size_t inSize = 0 );
	~CBuf();
	
	void	resize( size_t inSize );
	
	void	memcpy( size_t toOffs, const char* fromPtr, size_t fromOffs, size_t amount );
	void	memcpy( size_t toOffs, const CBuf& fromPtr, size_t fromOffs, size_t amount );
	
	const char operator [] ( int idx ) const;
	char& operator [] ( int idx );
	
	char*		buf( size_t offs = 0, size_t amount = SIZE_MAX );
	const char*	buf( size_t offs = 0, size_t amount = SIZE_MAX ) const;
	
	void	xornstr( size_t dstOffs, char * src, size_t srcOffs, size_t amount );
	void	xornstr( size_t dstOffs, const CBuf& src, size_t srcOffs, size_t amount );

	void	shiftnstr( size_t dstOffs, int amount, int shiftAmount );
	
	size_t	size()		{ return mSize; };
	
protected:
	char*		mBuffer;
	size_t		mSize;
};

#endif
