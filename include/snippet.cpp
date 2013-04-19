#include<zlib.h>

stringstream decompressed;
try{
    boost::iostreams::zlib_params p;
    p.window_bits = 16 + MAX_WBITS;        
    ifstream file(FileName.c_str(), ios_base::in | ios_base::binary);
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;        
    in.push(boost::iostreams::zlib_decompressor(p));
    in.push(file);        
    boost::iostreams::copy(in,decompressed);    
}    
catch(boost::iostreams::zlib_error& e)
{
    cout << "zlib_error: " << e.error()<< endl;
} 
