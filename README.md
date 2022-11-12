# fcgisrv
FastCGI C++11 Server Library

This project includes a copy of the old and venerable reference FCGI library. The implementation was available from [fastcgi.com](http://www.fastcgi.com) site, but at the time of writing that site is down.

The version of the fastcgi used in this library is version 2.4.0 . A simple CMake file was made for the purpose of compiling the FCGI library, through the CMake `add_subdirectory` function (See the project root CMake file for an example).


### Licensing

Version 2.4.0 of the FCGI reference library is owned by the Open Market corporation, see the `LICENSE.TERMS` file included in the FCGI library folder for more licensing information with respect to the FCGI reference library.

ASIO, used in example code, is licensed under the Boost Software License Version 1.0. (See the accompanying
file LICENSE_1_0.txt, in the ASIO directory, or copy at http://www.boost.org/LICENSE_1_0.txt)

My code is licensed under the permissive MIT license. See the `LICENSE` file in the project root directory for the full license description.
