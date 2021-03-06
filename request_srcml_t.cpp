/*
  @file request_srcml_t.cpp

  Test program for request_srcml()
*/

#include "request_srcml.hpp"
#include <cassert>

int main() {

		// all filenames and languages empty
    {
		//make sure empty request works
    	srcml_request request = { "", "", "", ""};
    	assert(request_filename(request) == "");
    	assert(request_language(request, "") == "");
    }
	
    {   
        //make sure the local_filename is correct from a request
		srcml_request request2 = {"", "file", "data", ""};
    	assert(request_filename(request2) == "file");
    }

    {   
        //make sure the option_filename supersedes everything
        srcml_request request3 = {"file", "file2", "file3", ""};
    	assert(request_filename(request3) == "file");
    }
        
    {   
        //Make sure that the entry_filename works for filename
        srcml_request request4 = {"", "", "file.zip", ""};
    	assert(request_filename(request4) == "file.zip");
    }

    {
        //make sure that option language works
        srcml_request request4 = {"", "", "", "C++"};
    	assert(request_filename(request4) == "");
        assert(request_language(request4, "") == "C++");
    }

    {
		//check for valid language from file extension
        srcml_request request = {"", "file.cpp", "data", ""};
    	assert(request_filename(request) == "file.cpp");
        assert(request_language(request, "file.cpp") == "C++");
    }

	{
		//test when local file name is '-'
        srcml_request request = {"", "-", "data", ""};
    	assert(request_filename(request) == "");
        assert(request_language(request, "") == "");
    }

	{
		//test for language when local name is '-'
		srcml_request request = {"", "-", "data", "C++"};
    	assert(request_filename(request) == "");
        assert(request_language(request, "") == "C++");
	}

    return 0;
}
