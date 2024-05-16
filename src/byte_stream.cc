#include "byte_stream.hh"
#include <algorithm>
#include <cstdint>
#include <string>
#include <string_view>

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ), buf() {}

bool Writer::is_closed() const
{
    // Your code here.
    return closed_;
}

void Writer::push( string data )
{
    uint64_t pushed_count = min( available_capacity(), data.length() );
    buf.append( data, 0, pushed_count );
    pushed_count_ += pushed_count;
    return;
}

void Writer::close()
{
    closed_ = true;
}

uint64_t Writer::available_capacity() const
{
    // Your code here.
    return capacity_ - buf.length();
}

uint64_t Writer::bytes_pushed() const
{
    // Your code here.
    return pushed_count_;
}

bool Reader::is_finished() const
{
    // Your code here.
    return buf.empty() && closed_;
}

uint64_t Reader::bytes_popped() const
{
    // Your code here.
    return popped_count_;
}

string_view Reader::peek() const
{
    // Your code here.
    return string_view( &buf.front(), buf.length() );
}

void Reader::pop( uint64_t len )
{
    // Your code here.
    uint64_t popped_count = min( buf.length(), len );
    buf.erase( 0, popped_count );
    popped_count_ += popped_count;
    return;
}

uint64_t Reader::bytes_buffered() const
{
    // Your code here.
    return buf.length();
}
